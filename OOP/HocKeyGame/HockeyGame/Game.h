#ifndef Game_H_
#define Game_H_

#include <sstream>
#include "Font.h"
#include "Item.h"
#include "BlocksField.h"
#include <fstream>

class Game
{
private:
	sf::Clock CLOCK;
	sf::Time TIME;
	sf::Clock CLOCK2;
	sf::Time TIME2;
public:
	void xuLyMang(RenderWindow& window, int& score2, font& f4, int& test, int& test2, int position, Ball& ball1, double& u, double& v);//Xử lý lượt chơi còn lại
	void xuLyThua(RenderWindow& window, sprite& messeagewin);//Hiện hình ảnh thua
	void xuLyThang(RenderWindow& window, sprite& messeagewin);//Hiện hình ảnh thắng
	void xuLyBangThanhTich(RenderWindow& window, sprite& table, vector<string> achievement_record, int score, int main());//Xu ly hiện bảng thành tích
	void xuLyVaChamBlock(list<Block>& lBlock, Vector2f d, double& u, double& v, int& score, font& f3); // Khi banh va cham vao vien gach nao do thi no se bien mat.
	bool xuLyVaChamItem(Vector2f dP, Vector2f dI);  // Xu ly khi nguoi choi an duoc item.
	void xuLyItem(sf::RenderWindow& window, int& score, int& turn, bool& test, bool& testVaCham, Item& item, Item& temp, Ball& ball1,
		list<Block> lBlock, Vector2f d, Vector2f dP, Vector2f dI, double& u, double& v, font& f3, font& f4, int& dx);//Xử lý các tác động của item
	void Sort(vector<string>& a)//Sắp xếp bảng thành tích
	{
		int min;
		for (int i = 0; i < a.size() - 1; i++)
		{
			min = i;
			for (int j = i + 1; j < a.size(); j++)
			{
				if (stoi(a[i]) < stoi(a[j]))
				{
					min = j;
				}
			}
			string c = a[i];
			a[i] = a[min];
			a[min] = c;
		}
	}
};

#endif