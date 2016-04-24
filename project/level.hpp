#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "entity.hpp"
#include "wall.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "door.hpp"
#include "doorButton.hpp"
#include "winZone.hpp"
#include "light.hpp"

#define MAXLEVEL 6

class Level
{
	public:
		Level();
		void initiate();
		void win();

		void setStage(int z);
		int getStage();
		Player getPlayer();
		std::vector<Wall> getWalls();
		std::vector<Enemy> getEnemies();
		std::vector<Door> getDoors();
		std::vector<DoorButton> getButtons();
		std::vector<Light> getLights();
		WinZone getWinZone();

	private:
		int stage;
		Player player;
		std::vector<Wall> walls;
		std::vector<Enemy> enemies;
		std::vector<Door> doors;
		std::vector<DoorButton> buttons;
		std::vector<Light> lights;
		WinZone winZone;
};

#endif