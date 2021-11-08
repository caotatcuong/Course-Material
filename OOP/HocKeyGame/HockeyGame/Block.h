#pragma once
#include <cmath>
#define M_PI 3.14159265358979323846

#include <SFML/Graphics.hpp>

class Block
{
private:
	sf::RectangleShape rect;
public:
	Block(const sf::Vector2f& size, const sf::Vector2f& position);//Khởi tạo 1 viên gạch

	void Draw(sf::RenderWindow& window);//Vẽ một viên gạch

	float left()   const { return rect.getPosition().x; }//Lấy biên trái của gạch
	float rigth()  const { return rect.getPosition().x + rect.getSize().x; } // Lấy biên phải của gạch
	float top()    const { return rect.getPosition().y; } // Lấy biên trên của gạch
	float bottom() const { return rect.getPosition().y + rect.getSize().y; } // Lấy biên dưới của gạch
};

