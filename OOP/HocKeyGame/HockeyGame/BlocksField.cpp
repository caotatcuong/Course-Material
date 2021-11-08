#include "BlocksField.h"

BlocksField::BlocksField(const sf::Vector2f& size, const sf::Vector2f& position, int columns, int rows)
{
	sf::Vector2f blockSize(size.x / columns, size.y / rows);//Khởi tạo 1 viên gạch

	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			blocks.push_back(Block(blockSize - sf::Vector2f(4.f, 4.f), 
				position + sf::Vector2f(blockSize.x * i + 2.f, blockSize.y * j + 2.f)));//Them 1 viên gạch vào list gạch
		}
	}
}


void BlocksField::Draw(sf::RenderWindow& window)
{
	for (auto& block : blocks)
	{
		block.Draw(window);//Vẽ list gạch
	}
}