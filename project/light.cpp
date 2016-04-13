#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "light.hpp"

Light::Light()
{
	body.setFillColor(sf::Color(180,180,20,255));
	body.setOutlineColor(sf::Color(140,140,14,255));
	body.setOutlineThickness(5);
}

void Light::setPosition(int x, int y)
{
	body.setPosition(x,y);
}

void Light::setSize(int w, int h)
{
	width = w;
	height = h;
	body.setSize(sf::Vector2f(w,h));
}

void Light::setParameters(int x, int y, int w, int h)
{
	setPosition(x,y);
	setSize(w,h);
}

sf::RectangleShape Light::getBody()
{
	return body;
}

int Light::getWidth()
{
	return width;
}

int Light::getHeight()
{
	return height;
}