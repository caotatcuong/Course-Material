#pragma once
#include "Sprite.h"

constexpr auto bienTrai = 57;
constexpr auto bienPhai = 590 - 90;

class Paddle
{
public:
	bool InIt(int, int, string);//Khởi tạo thanh đỡ
	void setOrigin(int, int);//set vị trí thanh đỡ
	Vector2f getPosition();//Lấy vị trí thanh đỡ
	void draw(RenderWindow&);//Vẽ thanh đỡ lên màn hình
	void MovePlayer(int&);//Dieu khien thanh do cua nguoi choi qua trai, phai khi nguoi choi an A hoac D.
	void MoveAI(int&, Vector2f, double, Vector2f);//Dieu khien thanh do cua may tinh di chuyen voi toc do bang voi toc do thanh do cua nguoi choi.
private:
	sprite paddle;
};

