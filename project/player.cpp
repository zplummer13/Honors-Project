#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "player.hpp"

Player::Player()
{
	body.setRadius(10.f);
	body.setPosition(16, 200);
	body.setFillColor(sf::Color(0,250,250,255));
	body.setOutlineColor(sf::Color::White);
	body.setOutlineThickness(1);
	shadow.setRadius(10.f);
	shadow.setPosition(16,200);
	shadow.setFillColor(sf::Color(10,10,10,255));
	shadow.setOutlineColor(sf::Color::White);
	shadow.setOutlineThickness(1);
	shadowCooldown = 0;

	shadowBar.setPosition(10, 430);
	shadowBar.setSize(sf::Vector2f(620,20));
	shadowBar.setFillColor(sf::Color(70,70,70,255));
	shadowBar.setOutlineColor(sf::Color::White);
	shadowBar.setOutlineThickness(1);

	movingUp = false;
	movingDown = false;
	movingLeft = false;
	movingRight = false;
	inLight = false;
}

void Player::move(sf::Vector2f movement)
{
	body.move(movement);
}

sf::CircleShape Player::getBody()
{
	return body;
}

sf::CircleShape Player::getShadow()
{
	return shadow;
}

sf::RectangleShape Player::getShadowBar()
{
	return shadowBar;
}

void Player::advanceCooldowns()
{
	if (shadowCooldown > 0)
	{
		shadowCooldown--;
		shadowBar.setSize(sf::Vector2f(620 - 620*(shadowCooldown/200),20));
	}
}

void Player::swap()
{
	if (shadowCooldown == 0 && !inLight)
	{
		float x = shadow.getPosition().x;
		float y = shadow.getPosition().y;
		shadow.setPosition(body.getPosition().x,body.getPosition().y);
		body.setPosition(x,y);
		shadowCooldown = 200;
		shadowBar.setSize(sf::Vector2f(0,20));
	}
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

void Player::setInLight(bool l)
{
	inLight = l;
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

bool Player::isInLight()
{
	return inLight;
}