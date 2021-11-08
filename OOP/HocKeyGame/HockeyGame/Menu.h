#ifndef MENU_H_
#define MENU_H_
#include "SFML/Graphics.hpp"
#include "Sprite.h"

class Menu
{
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[3];
	sprite background;
public:
	Menu(float width, float height);//Khởi tạo menu
	~Menu();
	void draw(sf::RenderWindow& window);//Vẽ menu lên màn hình
	void MoveUp();//Di chuyển lên để chọn menu
	void MoveDown();//Di chuyển xuống để chọn menu
	int GetPressedItem() { return selectedItemIndex; }//Lấy loại menu
};

#endif