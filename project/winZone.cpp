#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "winZone.hpp"

WinZone::WinZone()
{
	body.setFillColor(sf::Color(0,90,180,255));
	setParameters(620,200,10,20);
}

void WinZone::setPosition(int x, int y)
{
	body.setPosition(x,y);
}

void WinZone::setSize(int w, int h)
{
	width = w;
	height = h;
	body.setSize(sf::Vector2f(w,h));
}

void WinZone::setParameters(int x, int y, int w, int h)
{
	setPosition(x,y);
	setSize(w,h);
}

sf::RectangleShape WinZone::getBody()
{
	return body;
}

int WinZone::getWidth()
{
	return width;
}

int WinZone::getHeight()
{
	return height;
}