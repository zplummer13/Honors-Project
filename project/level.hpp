#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "entity.hpp"
#include "wall.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "level.hpp"

class Level
{
	public:
		Level();
		void initiate();
		void won();

		void setStage(int z);
		int getStage();
		std::vector<Wall> getWalls();

	private:
		int stage;
		std::vector<Wall> walls;
};

#endif