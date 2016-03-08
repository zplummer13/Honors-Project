#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "zone.hpp"
#include "wall.hpp"
#include "enemy.hpp"

class Game 
{
	public:
		Game();
		void run();

	private:
		sf::RenderWindow window;
		Player player;
		Zone zone;
		bool gameOver;
		sf::Text gameOverText;

		Wall wall0;
		Wall wall1;
		Wall wall2;
		std::vector<Wall> walls;
		std::vector<Enemy> enemies;
		Enemy enemy1;
		sf::Font font;

		void processEvents();
		void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
		void update(sf::Time deltaTime);
		void render();		

};

#endif