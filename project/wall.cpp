#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "wall.hpp"

Wall::Wall()
{
	body.setFillColor(sf::Color(200,0,0,255));
}

void Wall::setPosition(int x, int y)
{
	body.setPosition(x,y);
}

void Wall::setSize(int w, int h)
{
	width = w;
	height = h;
	body.setSize(sf::Vector2f(w,h));
}

void Wall::setParameters(int x, int y, int w, int h)
{
	setPosition(x,y);
	setSize(w,h);
}

sf::RectangleShape Wall::getBody()
{
	return body;
}

int Wall::getWidth()
{
	return width;
}

int Wall::getHeight()
{
	return height;
}

