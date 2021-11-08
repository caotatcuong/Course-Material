#include "Block.h"

Block::Block(const sf::Vector2f& size, const sf::Vector2f& position)
{
	int r = rand() % 255;//Random màu của viên gạch
	int g = rand() % 255;
	int b = rand() % 255;
	rect.setSize(size);//Set kích thước của viên gạch
	rect.setPosition(position);//Set vị trí của viên gạch
	rect.setFillColor(sf::Color(r,g,b));//Set mau vừa random
}

void Block::Draw(sf::RenderWindow& window)
{
	window.draw(rect);//Vẽ gạch lên màn hình
}