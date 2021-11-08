package httpsocket;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class HTTPServer {
	public static final int PORT = 80;
	public static final String FOLDERHTML = "filehtml";
	public static final String[] METHODS = { "GET", "POST" };
	public static final String IMAGES = "png";
	public static final String TEXT = "html";

	//Tạo ra 1 socketserver để lắng nghe kết nối
	public void StartServer() {
		ServerSocket server = null;
		try {
			// Mở 1 server lắng nghe ở port 80
			server = new ServerSocket(PORT);
			System.out.println("Waiting for Clients ");
			while (true) {
				//Mở 1 socket riêng để chấp nhận 1 kết nối đến server
				Socket socket = server.accept();
				//Địa chỉ IP của cilent kết nối đến server
				System.out.println("Client Connected From : " + socket.getLocalAddress().toString());
				Handler handler = new Handler(socket);
				handler.run();
				socket.close();
			}

		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				server.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	public static void main(String[] args) throws IOException {
		HTTPServer http = new HTTPServer();
		http.StartServer();
	}
}