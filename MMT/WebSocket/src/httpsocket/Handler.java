package httpsocket;

import java.io.*;
import java.net.Socket;
import java.net.URLDecoder;

public class Handler implements Runnable {
	private Socket socket;
	private PrintWriter out;
	private BufferedReader reader;
	private String message;

	public Handler() {
	}

	public Handler(Socket socket) {
		this.socket = socket;
	}

	@Override
	public void run() {
		try {
			// Đọc các byte dữ liệu từ client gửi về và giải mã chúng thành các ký tự
			InputStreamReader inputStreamReader = new InputStreamReader(socket.getInputStream());

			// chuyển sang BufferedReader để đọc hiệu quả hơn
			reader = new BufferedReader(inputStreamReader);

			// Trả về đầu ra cho socket
			OutputStream outputStream = socket.getOutputStream();
			// Đọc các lý tự server phản hồi về client và mã hóa thành byte

			out = new PrintWriter(outputStream);
			// Đọc từng dòng dữ liệu gửi từ client về server
			message = reader.readLine();

			String method = "";
			String filePath = "";
			if (message != null) {
				method = message.split(" ")[0];// Trả về phương thức
				filePath = message.split(" ")[1];// Trả về đường dẫn request
			}

			// Nếu đường dẫn client nhập vào là địa chỉ ip thì chuyển đến trang 404.html
			if (filePath.equals("/") || filePath.isEmpty())
				filePath = "/404.html";

			// Xử lý phương thức GET
			if (method.equals(HTTPServer.METHODS[0])) {

				System.out.println("requesting: " + filePath);

				// Nếu url không tồn tại thì chuyển đến trang 404.html
				if (!(new File(HTTPServer.FOLDERHTML + filePath)).exists()) {
					String response = HandleMethodGet(false, filePath);
					// Xuất dữ liệu mới đọc được ra lên client(code của 404.html)
					PrintWriter pw = new PrintWriter(out);
					pw.print(response);
					pw.close();
				}

				// Nếu url tồn tại thì chuyển đến trang request
				if (HTTPServer.TEXT.equals(filePath.split("[.]")[1])) {
					String response = HandleMethodGet(true, filePath);
					// Xuất dữ liệu mới đọc được ra lên client(code file request)
					PrintWriter pw = new PrintWriter(out);
					pw.print(response);
					pw.close();
				}

				// Xử lý ảnh .png
				else if (HTTPServer.IMAGES.equals(filePath.split("[.]")[1])) {
					FileInputStream is = new FileInputStream(HTTPServer.FOLDERHTML + filePath);
					OutputStream os = socket.getOutputStream();
					int s;
					// Lấy dữ liệu của ảnh
					while ((s = is.read()) > -1) {
						os.write(s);
					}
					os.flush();
					is.close();
					os.close();
				}
			}

			// Phương thức POST
			else if (HTTPServer.METHODS[1].equals(method)) {
				while (!(message = reader.readLine()).equals(""))
					// System.out.println(message);
					;
				// Đọc dữ liệu đã bị mã hóa từ method post
				StringBuilder builder = new StringBuilder();

				while (reader.ready())
					builder.append((char) reader.read());

				// Chuyển dữ liệu bị mã hóa sang UTF-8
				String data = URLDecoder.decode(builder.toString(), "UTF-8");
				// System.out.println(data);
				String response = HandleMethodPost(data);
				out.write(response);

			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		out.close();
		try {
			reader.close();
			socket.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	private String HandleMethodGet(boolean temp, String filepath) throws IOException {
		// Nếu temp = false (url khong tồn tại) thì chuyển hướng đến 404.html
		String response = "";
		if (!temp) {
			response += "HTTP/1.1 404 \r\n";
			response += "\r\n";
			response += "<head><meta http-equiv='Refresh' content='0; URL=/404.html'></head>";
			return response;
		}
		// Lấy đường đẫn đi vào file hrml tương ứng của request
		File returnFile = new File(HTTPServer.FOLDERHTML + filepath);
		// Đọc code html lưu vào trong respone để gửi lên client
		FileInputStream fileInputStream = new FileInputStream(returnFile);
	
		response += "HTTP/1.1 200 \r\n";
		response += "\r\n";
		int s;
		while ((s = fileInputStream.read()) != -1) {
			response += (char) s;
		}
		fileInputStream.close();
		return response;
	}

	private String HandleMethodPost(String data) {
		String response = "";
		int count = 0;
		String[] pairs = data.split("&");
		// Kiểm tra tài khoản mật khẩu client nhập vào
		for (String pair : pairs) {
			if (pair.equals("username=admin") || pair.equals("pass=admin")) {
				count++;
			}
		}
		// Nếu đúng chuyển hướng sang trang info.html nếu sai thì 404.html
		if (count == 2) {
			response += "HTTP/1.1 301 \r\n";
			response += "\r\n";
			response += "<head><meta http-equiv='Refresh' content='0; URL=/info.html'></head>";
		} else {
			response += "HTTP/1.1 301 \r\n";
			response += "\r\n";
			response += "<head><meta http-equiv='Refresh' content='0; URL=/404.html'></head>";
		}
		return response;
	}

}