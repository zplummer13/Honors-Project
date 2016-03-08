#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "enemy.hpp"

Enemy::Enemy()
{
	body = sf::CircleShape(30,12);
	body.setFillColor(sf::Color(255,255,255,180));
	movingRight = true;
}

void Enemy::move(sf::Vector2f movement)
{
	body.move(movement);
}

void Enemy::setPosition(int x, int y)
{
	body.setPosition(x,y);
}

void Enemy::setMovingRight(bool k)
{
	movingRight = k;
}

bool Enemy::getMovingRight()
{
	return movingRight;
}

sf::CircleShape Enemy::getBody()
{
	return body;
}

