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
#include "winZone.hpp"

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

		/*
		Wall wall0;
		Wall wall1;
		Wall wall2;
		Door door1;
		Door door2;
		DoorButton button1;
		Door* doorptr1;
		Door* doorptr2;
		Enemy enemy1;
		*/
		Level level;
		std::vector<Wall> walls;
		std::vector<Enemy> enemies;
		std::vector<Door> doors;
		std::vector<DoorButton> buttons;
		WinZone winZone;
		sf::Font font;

		void processEvents();
		void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
		void update(sf::Time deltaTime);
		void render();		

};

#endif