#ifndef WALL_HPP
#define WALL_HPP

#include "entity.hpp"

class Wall : public Entity
{
	public:
		Wall();
		void setPosition(int x, int y);
		void setSize(int w, int h);
		void setParameters(int x, int y, int w, int h);
		sf::RectangleShape getBody();
		int getWidth();
		int getHeight();

	private:
		sf::RectangleShape body;
		int width;
		int height;

};

#endif