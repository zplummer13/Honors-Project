#ifndef DOORBUTTON_HPP
#define DOORBUTTON_HPP

#include "entity.hpp"
#include "door.hpp"

#define MAXDOORS 9

class DoorButton : public Entity
{
	public:
		DoorButton();
		void setPosition(int x, int y);
		void setSize(int w, int h);
		void setParameters(int x, int y, int w, int h);
		void setState(bool setting);
		sf::RectangleShape getBody();
		int getWidth();
		int getHeight();
		bool getState();
		std::vector<Door> operateLinkedDoors(std::vector<Door> doors);
		void setOperation(int i, int j);

	private:
		sf::RectangleShape body;
		int width;
		int height;
		int operations [MAXDOORS];
		bool state;

};

#endif