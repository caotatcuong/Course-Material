#include "GlobalObjects.h"

const float GlobalObjects::windowWidth = 595.f;//chiều rộng
const float GlobalObjects::windowHeight = 512.f;//chiều cao
sf::RenderWindow GlobalObjects::window(sf::VideoMode(windowWidth, windowHeight), "Arkanoid", sf::Style::Close | sf::Style::Titlebar);
