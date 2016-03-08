#ifndef ZONE_HPP
#define ZONE_HPP

#include "entity.hpp"

class Zone : public Entity
{
	public:
		Zone();
		sf::RectangleShape getBody();

	private:
		sf::RectangleShape body;

};

#endif