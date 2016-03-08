#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity
{
	public:
		void setVelocity(sf::Vector2f v);
		void setVelocity(float vx, float vy);
		sf::Vector2f getVelocity();

	private:
		sf::Vector2f velocity;

};

#endif