#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <math.h>
#include "entity.hpp"
#include "enemy.hpp"
#include "player.hpp"

#define MAXSTATES 4

Enemy::Enemy()
{
	body = sf::CircleShape(30,12);
	body.setFillColor(sf::Color(255,255,255,180));
	behaviorGraph = Graph(MAXSTATES);
	state = 0;
	speed = 50.f;
}

void Enemy::move(sf::Vector2f movement)
{
	body.move(movement);
}

void Enemy::setPosition(int x, int y)
{
	body.setPosition(x,y);
}

void Enemy::addEdge(int i, int j)
{
	behaviorGraph.addEdge(i,j);
}

void Enemy::removeEdge(int i, int j)
{
	behaviorGraph.removeEdge(i,j);
}

sf::CircleShape Enemy::getBody()
{
	return body;
}

void Enemy::setState(int x)
{
	state = x;
}

int Enemy::getState()
{
	return state;
}

void Enemy::script(Player player)
{
	for(int j = 0; j < MAXSTATES; j++)
	{
		if (behaviorGraph.getEdge(state,j) == 1)
		{
			if (j == 0)
			{
				if(checkPositions(getBody().getPosition(), getHome()))
				{
					setState(0);
				}
			}
			if (j == 1)
			{
				if(checkPositions(getBody().getPosition(), getHome()))
				{
					setState(1);
				}
			}
			if (j == 2 && player.isInLight())
			{
				playerTarget = player.getBody().getPosition();
				setState(2);
			}
			if (j == 3)
			{
				if (checkPositions(getBody().getPosition(),getTarget()) ||
					checkPositions(getBody().getPosition(),playerTarget))
				{
					setState(3);
				}
			}
		}
	}
}

void Enemy::update(sf::Time deltaTime)
{
	sf::Vector2f direction;
	if (state == 0) 
	{
		direction = sf::Vector2f(0,0);
	}
	if (state == 1)
	{
		direction = target - body.getPosition();
	}
	if (state == 2)
	{
		direction = playerTarget - body.getPosition(); 
	}
	if (state == 3)
	{
		direction = home - body.getPosition(); 
	}
	direction = direction / 
		sqrtf( (direction.x * direction.x) + (direction.y * direction.y) );
	direction.x = speed * direction.x;
	direction.y = speed * direction.y;
	move(direction * deltaTime.asSeconds());
}

void Enemy::setHome(int x, int y)
{
	home = sf::Vector2f(x,y);
}

void Enemy::setTarget(int x, int y)
{
	target = sf::Vector2f(x,y);
}

sf::Vector2f Enemy::getHome()
{
	return home;
}

sf::Vector2f Enemy::getTarget()
{
	return target;
}

bool Enemy::checkPositions(sf::Vector2f v1, sf::Vector2f v2)
{
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if ((int)v1.x == (int)v2.x + i && (int)v1.y == (int)v2.y + j)
			{
				return true;
			}
		}
	}
	return false;
}

