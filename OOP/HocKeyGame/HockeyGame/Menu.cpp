#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("brushsbi.ttf"))//load file
	{
		// handle error
	}
	menu[0].setFont(font);//set font chữ
	menu[0].setFillColor(sf::Color::Red);//set màu chữ
	menu[0].setString("Player");//set ký tự
	menu[0].setCharacterSize(80);//set kích thước
	menu[0].setPosition(sf::Vector2f(width / 2 - 90, -40 + height / (3 + 1) * 1));//set vị trí

	menu[1].setFont(font);//set font chữ
	menu[1].setFillColor(sf::Color::White);//set màu chữ
	menu[1].setString("Computer");//set ký tự
	menu[1].setCharacterSize(80); // set kích thước
	menu[1].setPosition(sf::Vector2f(width / 2 - 90, -40 + height / (3 + 1) * 2));//set vị trí

	menu[2].setFont(font);//set font chữ
	menu[2].setFillColor(sf::Color::White);//set màu chữ
	menu[2].setString("Exit");//set ký tự
	menu[2].setCharacterSize(80); // set kích thước
	menu[2].setPosition(sf::Vector2f(width / 2 - 90, -40 + height / (3 + 1) * 3));//set vị trí

	background.InIt(0, 0, "AssetGame\\menu.jpg");//Nền menu

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	background.draw(window);//Vẽ nền menu
	for (int i = 0; i < 3; i++)
	{
		window.draw(menu[i]);//Vẽ các menu lên màn hình
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)//Điều kiện để di chuyển lựa chọn các menu
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);//Đổi màu các item của menu
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);//Đổi màu các item của menu
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < 3) // Điều kiện để di chuyển lựa chọn các menu
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);//Đổi màu các item của menu
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);//Đổi màu các item của menu
	}
}
