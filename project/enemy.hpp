#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "entity.hpp"

class Enemy : public Entity
{
	public:
		Enemy();
		void move(sf::Vector2f movement);
		void setPosition(int x, int y);
		void setMovingRight(bool k);
		bool getMovingRight();
		sf::CircleShape getBody();

	private:
		sf::CircleShape body;
		bool movingRight;

};

#endif