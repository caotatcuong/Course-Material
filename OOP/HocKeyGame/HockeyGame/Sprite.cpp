#include "Sprite.h"

bool sprite::InIt(int x, int y, string name)
{
	if (!texture.loadFromFile(name))//load file
	{
		return false;
	}
	else
	{
		sprite.setTexture(texture);
		sprite.setPosition(x, y);//set vị trí
	}
	return true;
}

void sprite::setPosition(double x, double y)
{
	sprite.setPosition(x, y);//set vị trí
}

Vector2f sprite::getPosition()
{
	return sprite.getPosition();//lấy vị trí
}


void sprite::setOrigin(int x, int y)
{
	sprite.setOrigin(x, y);
}

void sprite::Move(double x, double y)
{
	sprite.move(x, y);//di chuyển
}

void sprite::draw(RenderWindow& window)
{
	window.draw(sprite);//vẽ sprite
}
