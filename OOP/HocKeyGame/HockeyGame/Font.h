#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class font
{
private:
	Font _font;
	Text text;
public:
	void getText();
	font();
	font(int, int, string, string);//Khơi tạo font chu tu file
	bool InIt(int, int, string, string);//Load font chu tu file.
	void draw(RenderWindow&);//In chu len man hinh.
};


