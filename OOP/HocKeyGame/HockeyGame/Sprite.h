#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class sprite
{
private:
	Texture texture;
	Sprite sprite;
public:
	bool InIt(int, int, string);//Khởi tạo sprite
	void setPosition(double x, double y);//set vị trí sprite
	Vector2f getPosition();//Lấy vị trí sprite
	void setOrigin(int, int);
	void Move(double, double);//Di chuyển
	void draw(RenderWindow&);//Vẽ sprite lên màn hình
};
