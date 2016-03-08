#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "zone.hpp"

Zone::Zone()
{
	body.setSize(sf::Vector2f(620,400));
	body.setOutlineColor(sf::Color::Red);
	body.setFillColor(sf::Color::Black);
	body.setOutlineThickness(5);
	body.setPosition(10,10);
}

sf::RectangleShape Zone::getBody()
{
	return body;
}