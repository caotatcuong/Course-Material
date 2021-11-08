#pragma once

#include "Sprite.h"
#include "Sound.h"
#include <time.h>

constexpr auto tocdo = 0.1;


class Ball
{
public:
	sound vacham;
	bool InIt(int, int, string);//Load anh trai banh tu file.
	void Move(double,double);//Di chuyen trai banh 1 khoang nhat dinh.
	void ResetMove(double&, double&);//Tao lai huong di ban dau cho trai banh.
	void draw(RenderWindow&);//Vẽ bóng
	void setPosition(double x, double y);//Đặt bóng ở vị trí mặc định
	Vector2f getPosition();//Lấy vi tri của bóng
	void HandlingCollisions(Vector2f, Vector2f, double&, double&);//Xu ly va cham doi voi trai banh tren man hinh.
private:
	sprite sprite;
};

