#include <SFML/Graphics.hpp>
#include "doorButton.hpp"
#include <stdio.h>

DoorButton::DoorButton()
{
	body.setFillColor(sf::Color(255,255,255,255));
	state = true;
	for (int i = 0; i < MAXDOORS; i++)
	{
		operations[i] = 0;
	}
}

void DoorButton::setPosition(int x, int y)
{
	body.setPosition(x,y);
}

void DoorButton::setSize(int w, int h)
{
	width = w;
	height = h;
	body.setSize(sf::Vector2f(w,h));
}

void DoorButton::setParameters(int x, int y, int w, int h)
{
	setPosition(x,y);
	setSize(w,h);
}

void DoorButton::setState(bool setting)
{
	state = setting;
}

sf::RectangleShape DoorButton::getBody()
{
	return body;
}

int DoorButton::getWidth()
{
	return width;
}

int DoorButton::getHeight()
{
	return height;
}

bool DoorButton::getState()
{
	return state;
}

std::vector<Door> DoorButton::operateLinkedDoors(std::vector<Door> doors)
{
	int count = 0;
	for (std::vector<Door>::iterator it = doors.begin(); it != doors.end(); it++)
	{
		if (operations[count] == 0)
		{
			it->toggle();
		}
		else if (operations[count] == 1)
		{
			//leave the door as is
		}
		else if (operations[count] == 2)
		{
			it->setState(false);
		}
		else if (operations[count] == 3)
		{
			it->setState(true);
		}
		count++;
	}
	return doors;
}

void DoorButton::setOperation(int i, int j)
{
	if (i >= 0 && i < MAXDOORS)
	{
		operations[i] = j;
	}
}