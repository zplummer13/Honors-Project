#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "player.hpp"

Player::Player()
{
	body.setRadius(10.f);
	body.setPosition(16, 200);
	body.setFillColor(sf::Color::Cyan);
	movingUp = false;
	movingDown = false;
	movingLeft = false;
	movingRight = false;
}

void Player::move(sf::Vector2f movement)
{
	body.move(movement);
}

sf::CircleShape Player::getBody()
{
	return body;
}

void Player::setMovingUp(bool isPressed)
{
	movingUp = isPressed;
}

void Player::setMovingDown(bool isPressed)
{
	movingDown = isPressed;
}

void Player::setMovingLeft(bool isPressed)
{
	movingLeft = isPressed;
}

void Player::setMovingRight(bool isPressed)
{
	movingRight = isPressed;
}

bool Player::isMovingUp()
{
	return movingUp;
}

bool Player::isMovingDown()
{
	return movingDown;
}

bool Player::isMovingLeft()
{
	return movingLeft;
}

bool Player::isMovingRight()
{
	return movingRight;
}