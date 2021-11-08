#ifndef Item_H_
#define Item_H_

#include <cstdlib>
#include <ctime>
#include <list>
#include "Ball.h"
#include "Font.h"
#include "Block.h"
#include "Paddle.h"

class Item
{
private:
	sprite ITEM;
	int TYPE;

public:
	int random(int min, int max);//hàm random
	Item();
	void setItem(int n);//khởi tạo loại item và vị trí xuất phát
	int getType();//lấy loại item
	void setType(int n);//khởi tạo loại item
	bool InIt(int, int, string);//load file ảnh item
	void setOrigin(int, int);
	void setPosition(Item item);//set vị trí item
	Vector2f getPosition();//Lấy vị trí item
	void draw(RenderWindow&);//Vẽ item lên màn hình
	void moveDown(float tocdo);// Cho item di chuyen tu tren xuong.
	void setItem();// Cai dat ngau nhien 1 hieu ung cho item.
	void setItemEffectLoop(int& score, int n, Ball& ball1, list<Block> lBlock, Vector2f d, double& u, double& v, font& f3, int& dx);// Cac hieu ung item can lap lai nhu x2, x4, tang toc.
	void setItemEffectNoLoop(int& score, int n, int& turn, font& f3, font& f4);// Cac hieu ung item chi goi ham 1 lan nhu +1 turn, cong diem.

};

#endif