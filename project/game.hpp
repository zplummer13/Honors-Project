#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "zone.hpp"
#include "level.hpp"
#include "wall.hpp"
#include "door.hpp"
#include "doorButton.hpp"
#include "enemy.hpp"
#include "light.hpp"
#include "winZone.hpp"

class Game 
{
	public:
		Game();
		void run();

	private:
		sf::RenderWindow window;
		bool gameOver;
		sf::Text gameOverText;
		bool wonLevel;
		sf::Text wonLevelText;
		Player player;
		Zone zone;
		
		Level level;
		std::vector<Wall> walls;
		std::vector<Enemy> enemies;
		std::vector<Door> doors;
		std::vector<DoorButton> buttons;
		std::vector<Light> lights;
		WinZone winZone;
		sf::Font font;

		void processEvents();
		void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
		void update(sf::Time deltaTime);
		void render();		

};

#endif