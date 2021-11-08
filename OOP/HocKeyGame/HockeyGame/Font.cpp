#include "Font.h"

void font::getText()
{
	this->text.setFillColor(Color::Red);
}

font::font()
{
}

font::font(int x, int y, string file, string name)
{
	_font.loadFromFile(file);//load file
	text.setFont(_font);//set font chữ
	text.setString(name);//set ký tự
	text.setPosition(x, y);//set vị trí
	text.setCharacterSize(23);//set kích cỡ
}

bool font::InIt(int x, int y, string file, string name)
{
	if (!_font.loadFromFile(file))//load file
	{
		return false;
	}
	else
	{
		text.setFont(_font);//set font chữ
		text.setFillColor(sf::Color::Yellow);//set mau chữ
		text.setString(name);//set ký tự
		text.setPosition(x, y);//set vị trí
		text.setCharacterSize(23);//set kích cỡ
	}
}

void font::draw(RenderWindow& window)
{
	window.draw(text);//Ghi chữ lên màn hình
}

