#include "Game.h"
#include "Menu.h"
#include "Paddle.h"
#include "Windows.h"
#include "BlocksField.h"
#include "GlobalObjects.h"
#include "Item.h"
#include <fstream>


int main()
{
	int highscore = 0;//Khởi tạo điểm cao nhất
	vector<string> achievement_record;//list điểm 
	fstream f;
	f.open("Diem.txt", ios_base::in);
	string diem;
	//Đọc file điểm
	while (!f.eof())
	{
		getline(f, diem, '\n');
		if (diem == "")
		{
			continue;
		}
		achievement_record.push_back(diem);//thêm điểm vào list điểm
	}
	f.close();
	highscore = stoi(achievement_record[0]);//Lấy điểm cao nhất trong list điểm

	int test = 0, test2 = 0;
	bool testItem = false, testVaCham = false;
	int dx = 275;
	int dy = 770;
	int a = 275;
	int b = 10;
	double u = 1;
	double v = -1;
	double mucTieu;
	sf::RenderWindow window(sf::VideoMode(595, 850), L"HockeyGame", Style::Close); // Khung game

	//Thiet ke giao dien game
	sprite table;
	table.InIt(0, 0, "AssetGame\\Matban.jpg");//Khởi tạo background

	Paddle paddle1;
	paddle1.InIt(dx, dy, "AssetGame\\GiaDo.png");//Khởi tạo thanh đỡ
	paddle1.setOrigin(50, 0);

	Ball ball1;
	ball1.InIt(275, 750, "AssetGame\\2.png");//Khởi tạo trái banh

	sprite messeagewin;
	//Các font chữ về lượt chơi
	font f1;
	f1.InIt(10, 820, "brushsbi.ttf", "Luot choi: ");
	font f4;
	int turn = 3;
	f4.InIt(110, 820, "brushsbi.ttf", to_string(turn));
	//Các font chữ về điểm
	int score = 0;
	font f2;
	f2.InIt(170, 820, "brushsbi.ttf", "Diem: ");
	font f3;
	f3.InIt(235, 820, "brushsbi.ttf", "0");
	//Các font chữ về điểm cao nhất
	font f5;
	f5.InIt(320, 820, "brushsbi.ttf", "Diem cao nhat: ");
	font f6;
	f6.InIt(468, 820, "brushsbi.ttf", to_string(highscore));

	Image Icon;//Tao icon cho game.
	Icon.loadFromFile("AssetGame\\icon.jpg");
	window.setIcon(Icon.getSize().x, Icon.getSize().y, Icon.getPixelsPtr());

	BlocksField blocksField(sf::Vector2f(GlobalObjects::windowWidth, 200.f), sf::Vector2f(0.f, 0.f), 10, 7);// Ve mang cac vien gach len man hinh choi.
	//Khởi tạo item
	Item item;
	item.setItem();
	Item temp;

	sound win;// Am thanh trong game.
	sound eat;// Am thanh an item.
	Game game;
	Menu menu(595, 805);//Khởi tạo menu
	win.soundPlay(win.backgroundsound);//Phát âm thanh menu
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::KeyReleased://Thao tác với bàn phím
			{
				switch (event.key.code)
				{
				case Keyboard::Up:
				{
					menu.MoveUp();//Di chuyển lên để chọn menu
					break;
				}
				case Keyboard::Down:
				{
					menu.MoveDown();//Di chuyển xuống để chọn menu
					break;
				}
				case Keyboard::Return:
				{
					win.soundPlay(win.choose);//Âm thanh khi chọn menu

					switch (menu.GetPressedItem())
					{
					case 0:
					{
						while (window.isOpen())
						{
							//Vẽ các sprite
							window.clear();
							table.draw(window);
							paddle1.draw(window);
							ball1.draw(window);
							f1.draw(window);
							f2.draw(window);
							f3.draw(window);
							f4.draw(window);
							f5.draw(window);
							f6.draw(window);
							blocksField.Draw(window);
							window.setFramerateLimit(300); // So lan lap tren 1 giay.

							paddle1.InIt(dx, dy, "AssetGame\\GiaDo.png");//Khởi tạo thanh đỡ
							paddle1.MovePlayer(dx);//Di chuyển của người chơi
							Vector2f d2 = paddle1.getPosition();//Lấy vị trí của thanh đỡ

							Vector2f dI = item.getPosition();//Lấy vị trí của item

							// Giu trai banh dung im cho den khi nguoi choi nhan space thi cho banh di chuyen.
							if (test2 != 0) {
								ball1.Move(u, v);//banh di chuyển
							}
							else {
								ball1.setPosition(dx, 750);//set vị trí của banh
								if (Keyboard::isKeyPressed(Keyboard::Space)) {//điều kiện để banh di chuyển
									test2 = 1;
								}
							}
							Vector2f d = ball1.getPosition(); // lấy vị trí của banh
							ball1.HandlingCollisions(d, d2, u, v);//xử lý va chạm của banh
							// Xu ly item tu dong roi xuong va hieu ung khi nguoi choi an item.
							game.xuLyItem(window, score, turn, testItem, testVaCham, item, temp, ball1, blocksField.blocks, d, d2, dI, u, v, f3, f4, dx);
							// Xu ly am thanh khi nguoi choi an item.
							if (game.xuLyVaChamItem(d2, dI) == true) {
								if (item.getType() == 5 || item.getType() == 6 || item.getType() == 7 || item.getType() == 8) {
									eat.soundPlay(eat.unLuckey);//Âm thanh ăn được item không may mắn
								}
								else {
									eat.soundPlay(eat.luckey);//Âm thanh ăn được item may mắn
								}
							}
							//Xu ly thua				
							if (d.y > 790) {
								win.soundPlay(win.lose1);//Âm thanh thua cuộc
								game.xuLyMang(window, turn, f4, test, test2, 820, ball1, u, v);//Xử lý lượt chơi
								if (turn == 0)
								{
									f4.draw(window);
									achievement_record.push_back(to_string(score));//thêm điểm vào list điểm
									game.Sort(achievement_record);//sắp xếp giảm dần list điểm
									if (highscore < score)
									{
										highscore = score;//cập nhật highscore
									}
									game.xuLyThua(window, messeagewin);//Hiện màn hình thua
									game.xuLyBangThanhTich(window, table, achievement_record, score, main);//Hiện bảng thành tích
								}
							}
							//Xu ly thang
							if (blocksField.blocks.empty())
							{
								achievement_record.push_back(to_string(score));//thêm điểm vào list điểm
								game.Sort(achievement_record);//sắp xếp giảm dần list điểm
								if (highscore < score)
								{
									highscore = score;//cập nhật highscore
								}
								game.xuLyThang(window, messeagewin);//Hiện màn hình thắng
								game.xuLyBangThanhTich(window, table, achievement_record, score, main);//Hiện bảng thành tích
							}

							if (Keyboard::isKeyPressed(Keyboard::Escape)) //Nhan esc de thoat ra ngoai menu.
							{
								window.close();
								main();//Tro ve menu chinh.
							}

							game.xuLyVaChamBlock(blocksField.blocks, d, u, v, score, f3);//Xử lý va chạm gạch

							window.display();
						}
						return EXIT_SUCCESS;
						break;
					}
					case 1:
					{
						while (window.isOpen())
						{
							//Vẽ các sprite
							window.clear();
							table.draw(window);
							paddle1.draw(window);
							ball1.draw(window);
							f1.draw(window);
							f2.draw(window);
							f3.draw(window);
							f4.draw(window);
							f5.draw(window);
							f6.draw(window);
							blocksField.Draw(window);
							window.setFramerateLimit(300); // So lan lap tren 1 giay.

							paddle1.InIt(dx, dy, "AssetGame\\GiaDo.png");//Khởi tạo thanh đỡ
							Vector2f d2 = paddle1.getPosition();//Lấy vị trí của thanh đỡ

							Vector2f dI = item.getPosition();//Lấy vị trí của item

							// Giu trai banh dung im cho den khi nguoi choi nhan space thi cho banh di chuyen.
							if (test2 != 0) {
								ball1.Move(u, v);
							}
							else {
								ball1.setPosition(dx, 750);
								if (Keyboard::isKeyPressed(Keyboard::Space)) {//điều kiện để banh di chuyển
									test2 = 1;
								}
							}
							Vector2f d = ball1.getPosition();//Lấy vị trí của banh
							ball1.HandlingCollisions(d, d2, u, v);//Xử lý va chạm của banh

							paddle1.MoveAI(dx, d, v, dI);//thanh đỡ tự động di chuyển để hứng bóng và ăn item
							// Xu ly item tu dong roi xuong va hieu ung khi nguoi choi an item.
							game.xuLyItem(window, score, turn, testItem, testVaCham, item, temp, ball1, blocksField.blocks, d, d2, dI, u, v, f3, f4, dx);
							// Xu ly am thanh khi nguoi choi an item.
							if (game.xuLyVaChamItem(d2, dI) == true) {
								if (item.getType() == 5 || item.getType() == 6 || item.getType() == 7 || item.getType() == 8) {
									eat.soundPlay(eat.unLuckey);//Âm thanh ăn được item không may mắn
								}
								else {
									eat.soundPlay(eat.luckey);//Âm thanh ăn được item may mắn
								}
							}
							//Xu ly thua				
							if (d.y > 790) {
								win.soundPlay(win.lose1);//Âm thanh thua cuộc
								game.xuLyMang(window, turn, f4, test, test2, 820, ball1, u, v); // Xử lý lượt chơi
								if (turn == 0)
								{
									f4.draw(window);
									achievement_record.push_back(to_string(score));//thêm điểm vào list điểm
									game.Sort(achievement_record);//sắp xếp giảm dần list điểm
									if (highscore < score)
									{
										highscore = score;//cập nhật highscore
									}
									game.xuLyThua(window, messeagewin);//Hiện màn hình thua
									game.xuLyBangThanhTich(window, table, achievement_record, score, main);//Hiện bảng thành tích
								}
							}
							//Xu ly thang
							if (blocksField.blocks.empty())
							{
								achievement_record.push_back(to_string(score));//thêm điểm vào list điểm
								game.Sort(achievement_record);//sắp xếp giảm dần list điểm
								if (highscore < score)
								{
									highscore = score;//cập nhật highscore
								}
								game.xuLyThang(window, messeagewin);//Hiện màn hình thắng
								game.xuLyBangThanhTich(window, table, achievement_record, score, main);//Hiện bảng thành tích
							}
							if (Keyboard::isKeyPressed(Keyboard::Escape)) //Nhan esc de thoat ra ngoai menu.
							{
								window.close();
								main();//Tro ve menu chinh.
							}

							game.xuLyVaChamBlock(blocksField.blocks, d, u, v, score, f3);//Xử lý va chạm gạch

							window.display();
						}
						return EXIT_SUCCESS;
						break;
					}
					case 2:
					{
						window.close();
						break;
					}
					}
					break;
				}
				}
				break;
			}
			case Event::Closed:
			{
				window.close();
				break;
			}
			}
		}
		window.clear();
		menu.draw(window);
		window.display();
	}
}
