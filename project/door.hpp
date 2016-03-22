#ifndef DOOR_HPP
#define DOOR_HPP

#include "entity.hpp"

class Door : public Entity
{
	public:
		Door();
		void setPosition(int x, int y);
		void setSize(int w, int h);
		void setParameters(int x, int y, int w, int h);
		sf::RectangleShape getBody();
		int getWidth();
		int getHeight();
		void setState(bool setting);
		bool getState();
		void toggle();
	private:
		bool state;
		sf::RectangleShape body;
		int width;
		int height;
};

#endif