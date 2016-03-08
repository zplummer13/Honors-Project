#include <SFML/Graphics.hpp>
#include "entity.hpp"

void Entity::setVelocity(sf::Vector2f v)
{
	velocity = v;
}

void Entity::setVelocity(float vx, float vy)
{
	velocity.x = vx;
	velocity.y = vy;
}

sf::Vector2f Entity::getVelocity()
{
	return velocity;
}

