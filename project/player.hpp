#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"

class Player : public Entity
{
	public:
		Player();
		void move(sf::Vector2f movement);
		sf::CircleShape getBody();
		void setMovingUp(bool isPressed);
		void setMovingDown(bool isPressed);
		void setMovingLeft(bool isPressed);
		void setMovingRight(bool isPressed);
		bool isMovingUp();
		bool isMovingDown();
		bool isMovingLeft();
		bool isMovingRight();

	private:
		sf::CircleShape body;
		bool movingUp;
		bool movingDown;
		bool movingLeft;
		bool movingRight;

};

#endif