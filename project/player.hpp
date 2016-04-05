#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"

class Player : public Entity
{
	public:
		Player();
		void move(sf::Vector2f movement);
		sf::CircleShape getBody();
		sf::CircleShape getShadow();
		sf::RectangleShape getShadowBar();
		void advanceCooldowns();
		void swap();
		void setMovingUp(bool isPressed);
		void setMovingDown(bool isPressed);
		void setMovingLeft(bool isPressed);
		void setMovingRight(bool isPressed);
		void setInLight(bool l);
		bool isMovingUp();
		bool isMovingDown();
		bool isMovingLeft();
		bool isMovingRight();
		bool isInLight();

	private:
		sf::CircleShape body;
		sf::CircleShape shadow;
		sf::RectangleShape shadowBar;
		float shadowCooldown;
		bool movingUp;
		bool movingDown;
		bool movingLeft;
		bool movingRight;
		bool inLight;

};

#endif