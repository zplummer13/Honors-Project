#include <SFML/Graphics.hpp>
#include "door.hpp"

static sf::Color closed = sf::Color(100,0,80,255);
static sf::Color opened = sf::Color(100,0,80,80);

Door::Door()
{
	body.setFillColor(closed);
	body.setOutlineColor(closed);
	body.setOutlineThickness(1);
	state = true;
}

void Door::setPosition(int x, int y)
{
	body.setPosition(x,y);
}

void Door::setSize(int w, int h)
{
	width = w;
	height = h;
	body.setSize(sf::Vector2f(w,h));
}

void Door::setParameters(int x, int y, int w, int h)
{
	setPosition(x,y);
	setSize(w,h);
}

sf::RectangleShape Door::getBody()
{
	return body;
}

int Door::getWidth()
{
	return width;
}

int Door::getHeight()
{
	return height;
}

void Door::setState(bool setting)
{
	state = setting;
	if(state)
	{
		body.setFillColor(closed);
	}
	else
	{
		body.setFillColor(opened);
	}
}

bool Door::getState()
{
	return state;
}

void Door::toggle()
{
	if(getState())
	{
		setState(false);
	}
	else
	{
		setState(true);
	}
}
