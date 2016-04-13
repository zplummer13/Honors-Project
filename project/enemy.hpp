#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "entity.hpp"
#include "graph.hpp"
#include "player.hpp"

class Enemy : public Entity
{
	public:
		Enemy();
		void move(sf::Vector2f movement);
		void setPosition(int x, int y);
		void addEdge(int i, int j);
		void removeEdge(int i, int j);
		sf::CircleShape getBody();
		void setState(int x);
		int getState();
		void script(Player player);
		void update(sf::Time deltaTime);
		void setHome(int x, int y);
		void setTarget(int x, int y);
		void setSpeed(float velocity);
		sf::Vector2f getHome();
		sf::Vector2f getTarget();
		bool checkPositions(sf::Vector2f v1, sf::Vector2f v2);
		void setPatrolParameters();
		void setStandingParameters();

	private:
		sf::CircleShape body;
		Graph behaviorGraph;
		int state;
		sf::Vector2f home;
		sf::Vector2f target;
		sf::Vector2f playerTarget;
		float speed;
		
};

#endif