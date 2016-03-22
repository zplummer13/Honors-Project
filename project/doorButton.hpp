#ifndef DOORBUTTON_HPP
#define DOORBUTTON_HPP

#include "entity.hpp"
#include "door.hpp"

#define MAXDOORS 8

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
		void addLinks(std::vector<Door> doors);
		std::vector<Door> getLinkedDoors();
		void removeLinks();
		void operateLinkedDoors();
		void setOperation(int i, int j);

	private:
		sf::RectangleShape body;
		int width;
		int height;
		std::vector<Door> linkedDoors;
		int operations [MAXDOORS];
		bool state;

};

#endif