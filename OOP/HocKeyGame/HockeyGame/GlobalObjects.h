#ifndef GLOBALOBJECTS_H_
#define GLOBALOBJECTS_H_

#include <SFML/Graphics.hpp>

class GlobalObjects
{
private:
	GlobalObjects() = delete;

public:
	static const float windowWidth, windowHeight;//Chiều dài và chiều rộng của list gạch
	static sf::RenderWindow window;
};

#endif

