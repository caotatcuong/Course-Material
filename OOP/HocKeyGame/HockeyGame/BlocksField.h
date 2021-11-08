#ifndef BLOCKSFIELD_H_
#define BLOCKSFIELD_H_

#include <list>
#include "Block.h"

class BlocksField
{
public:
	std::list<Block> blocks;//List cac viên gạch
	BlocksField(const sf::Vector2f& size, const sf::Vector2f& position, int columns, int rows);//Khởi tạo list gạch
	void Draw(sf::RenderWindow& window);//Vẽ list gạch
};

#endif
