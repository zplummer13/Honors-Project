#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "entity.hpp"
#include "wall.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "door.hpp"
#include "doorButton.hpp"
#include "winZone.hpp"

class Level
{
	public:
		Level();
		void initiate();
		void win();

		void setStage(int z);
		int getStage();
		std::vector<Wall> getWalls();
		std::vector<Enemy> getEnemies();
		std::vector<Door> getDoors();
		std::vector<DoorButton> getButtons();
		WinZone getWinZone();

	private:
		int stage;
		std::vector<Wall> walls;
		std::vector<Enemy> enemies;
		std::vector<Door> doors;
		std::vector<DoorButton> buttons;
		WinZone winZone;
};

#endif