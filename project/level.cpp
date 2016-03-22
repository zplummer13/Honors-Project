#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "wall.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "doorButton.hpp"
#include "winZone.hpp"
#include "level.hpp"

Level::Level()
{
	setStage(0);
}

void Level::initiate()
{
	walls.clear();
	enemies.clear();
	doors.clear();
	for(std::vector<DoorButton>::iterator it = buttons.begin(); it != buttons.end(); it++)
	{
		it->removeLinks();
	}
	buttons.clear();
	
	if (stage == 0)
	{
		Wall wall0;
		Wall wall1;
		Wall wall2;
		wall0.setParameters(400,200,150,100);
		wall1.setParameters(40,300,30,75);
		wall2.setParameters(37,81,51,32);
		walls.push_back(wall0);
		walls.push_back(wall1);
		walls.push_back(wall2);

		Enemy enemy0;
		enemy0.setPosition(200,100);
		enemies.push_back(enemy0);

		Door door0;
		Door door1;
		door0.setParameters(250,300,50,50);
		door1.setParameters(150,250,50,50);
		door1.setState(false);
		doors.push_back(door0);
		doors.push_back(door1);

		DoorButton button1;
		button1.setParameters(20,20,20,20);
		button1.addLinks(doors);
		buttons.push_back(button1);

	}
	else if (stage == 1)
	{
		Wall wall0;
		wall0.setParameters(70,100,30,75);
		walls.push_back(wall0);

		Door door0;
		door0.setParameters(400,100,50,50);
		doors.push_back(door0);

		DoorButton button1;
		button1.setParameters(400,20,20,20);
		button1.addLinks(doors);
		buttons.push_back(button1);
	}

}

void Level::win()
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

std::vector<Wall> Level::getWalls()
{
	return walls;
}

std::vector<Enemy> Level::getEnemies()
{
	return enemies;
}

std::vector<Door> Level::getDoors()
{
	return doors;
}

std::vector<DoorButton> Level::getButtons()
{
	return buttons;
}

WinZone Level::getWinZone()
{
	return winZone;
}