#include "Game.h"
#include <windows.h>
#include "Sound.h"


sound win;

void Game::xuLyMang(sf::RenderWindow& window, int& turn, font& f4, int& test, int& test2, int position, Ball& ball1, double& u, double& v)
{
	std::stringstream ss;
	turn--;
	ss << turn;
	f4.InIt(110, position, "brushsbi.ttf", ss.str());//Ghi diem len man hinh.
	window.display();
	ball1.ResetMove(u, v);//Tao huong di moi cho trai banh.
	test = 0;
	test2 = 0;
	ball1.InIt(275, 750, "AssetGame\\2.png");//Tra trai banh ve vi tri xuat phat.
	Sleep(2000);//Dùng lại một lúc
}

void Game::xuLyThua(sf::RenderWindow& window, sprite& messeagewin)
{
	messeagewin.InIt(120, 220, "AssetGame\\lose.png");//Khởi tạo hình thua
	messeagewin.draw(window);
	window.display();//Hien thi hinh anh bao thuc cuoc.

	win.soundPlay(win.lose);//Am thanh khi thua cuoc.
	Sleep(3000);//Dung lai 1 khoang truoc khi tro ve menu chinh.

}

void Game::xuLyThang(RenderWindow& window, sprite& messeagewin)
{
	messeagewin.InIt(30, 220, "AssetGame\\win2.png");//Khởi tạo hình tháng
	messeagewin.draw(window);
	window.display();//Hien thi hinh anh bao thang cuoc.

	win.soundPlay(win.win);//Phat am thanh thang cuoc.
	Sleep(3000);
}

void Game::xuLyBangThanhTich(RenderWindow& window, sprite& table, vector<string> achievement_record, int score, int main())
{
	window.clear();
	table.draw(window);//Vẽ lại mặt bàn
	font f7;
	f7.InIt(180, 15, "brushsbi.ttf", "BANG THANH TICH");//Ghi bảng thành tích
	f7.draw(window);
	vector<font> list;
	int dem = 0;
	for (int i = 0; i < achievement_record.size(); i++)
	{
		font f;
		f.InIt(280, 50 * (i + 1), "brushsbi.ttf", achievement_record[i]);//Ghi điểm ra màn hình
		if (achievement_record[i] == to_string(score) && dem == 0)
		{
			f.getText();//Đổi màu điểm sang màu đỏ thể hiện điểm cảu bạn vừa mới đạt được
			dem++;
		}
		list.push_back(f);
		list[i].draw(window);//Ghi điểm lên màn hình
	}
	ofstream f;
	f.open("Diem.txt", ios_base::out);
	for (int i = 0; i < achievement_record.size(); i++)
	{
		f << achievement_record[i] << endl;//Ghi điểm ra file
	}
	f.close();
	window.display();
	Sleep(3000);//Dung lai 1 khoang truoc khi tro ve menu chinh.
	window.close();
	main();//Quay về menu chính
}

void Game::xuLyVaChamBlock(list<Block>& lBlock, Vector2f d, double& u, double& v, int& score, font& f3)
{
	list<Block>::iterator it;
	for (it = lBlock.begin(); it != lBlock.end(); it++) {//Duyệt list gạch
		// Phat hien va cham.
		if (d.y > it->top() - 10 && d.y < it->bottom() + 10 && d.x > it->left() - 10 && d.x < it->rigth() + 10) {//Điều kiện chạm vào gạch
			lBlock.erase(it);
			if (d.x > it->left() + 5 && d.x > it->rigth() - 5) { // Doi huong di cua bong.
				u = -u;// Doi huong di cua bong.
			}
			else {
				v = -v;// Doi huong di cua bong.
			}
			it++;
			std::stringstream ss;
			score += 10;//Được cộng 10 điểm
			ss << score;
			f3.InIt(230, 820, "brushsbi.ttf", ss.str());//Ghi điểm ra màn hình
			break;
		}
	}
}

bool Game::xuLyVaChamItem(Vector2f dP, Vector2f dI) // Xu ly khi nguoi choi an duoc item.
{
	if (dI.x > dP.x - 70 && dI.x < dP.x + 90 && dI.y > dP.y - 1 && dI.y < dP.y + 1) {//Điều kiện thanh đỡ va chạm item
		return true;
	}
	return false;
}

void Game::xuLyItem(sf::RenderWindow& window, int& score, int& turn, bool& test, bool& testVaCham, Item& item, Item& temp, Ball& ball1,
	list<Block> lBlock, Vector2f d, Vector2f dP, Vector2f dI, double& u, double& v, font& f3, font& f4, int& dx)
{
	if (xuLyVaChamItem(dP, dI) == true) { // Xu ly khi nguoi choi an duoc item.
		item.moveDown(5);//item di chuyển xuống
		testVaCham = true;
		test = true;
		this->CLOCK2.restart();
		temp.setType(item.getType());//Lấy loại item vùa mới ăn được
	}
	this->TIME = this->CLOCK.getElapsedTime();
	if (this->TIME.asSeconds() < 5) {// Cac item se ngau nhien roi xuong sau moi khoang bang 5 giây.
		if (testVaCham == false) {
			item.moveDown(0.8); // item di chuyển xuống
			item.draw(window);
		}
	}
	else {
		this->CLOCK.restart();
		item.setItem();
		testVaCham = false;
	}
	if (test == true) { // Khi co va cham xay ra thi hieu ung item moi duoc thuc hien.
		int n = temp.getType();//Lấy loại item
		if (n == 1 || n == 2 || n == 6 || n == 7 || n == 8) {
			this->TIME2 = this->CLOCK2.getElapsedTime();//Lấy thời gian hiện tại
			if (this->TIME2.asSeconds() < 5) { // Hieu ung cua cac item se keo dai trong 5 giay.
				temp.setItemEffectLoop(score, n, ball1, lBlock, d, u, v, f3, dx);//Xử lý các tác động của item đến điểm và thanh đỡ
			}
			else {
				this->CLOCK2.restart();//restart lại thời gian
				test = false;
			}
		}
		else {
			temp.setItemEffectNoLoop(score, n, turn, f3, f4);//Xử lý các tác động của item đến điểm và lượt chơi
			test = false;
		}
	}
}
