#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "wall.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "level.hpp"

Level::Level()
{
	setStage(0);
}

void Level::initiate()
{
	if (stage == 0)
	{
		Wall wall0;
		Wall wall1;
		Wall wall2;
		wall0.setParameters(400,200,200,100);
		wall1.setParameters(40,300,30,75);
		wall2.setParameters(37,81,51,32);
		walls.push_back(wall0);
		walls.push_back(wall1);
		walls.push_back(wall2);
	}
	else if (stage == 1)
	{

	}

}

void Level::won()
{
	setStage(getStage() + 1);
}

void Level::setStage(int z)
{
	stage = z;
}

int Level::getStage()
{
	return stage;
}

std::vector<Wall> getWalls()
{
	return walls;
}