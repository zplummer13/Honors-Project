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
	buttons.clear();
	lights.clear();

	if (stage == 0)
	{
		Wall wall0;
		Wall wall1;
		Wall wall2;
		Wall wall3;
		Wall wall4;
		Wall wall5;
		Wall wall6;
		Wall wall7;
		Wall wall8;
		Wall wall9;
		wall0.setParameters(100,80,20,270);
		wall1.setParameters(120,80,60,20);
		wall2.setParameters(120,330,60,20);	
		wall3.setParameters(120,200,200,20);
		wall4.setParameters(320,80,20,270);
		wall5.setParameters(260,80,60,20);
		wall6.setParameters(260,330,60,20);
		wall7.setParameters(500,10,20,160);
		wall8.setParameters(500,250,20,160);
		wall9.setParameters(320,350,20,60);
		walls.push_back(wall0);
		walls.push_back(wall1);
		walls.push_back(wall2);
		walls.push_back(wall3);
		walls.push_back(wall4);
		walls.push_back(wall5);
		walls.push_back(wall6);
		walls.push_back(wall7);
		walls.push_back(wall8);
		walls.push_back(wall9);

		Door door0;
		Door door1;
		Door door2;
		door0.setParameters(180,330,80,20);
		door1.setParameters(320,10,20,70);
		door2.setParameters(500,170,20,80);
		doors.push_back(door0);
		doors.push_back(door1);
		doors.push_back(door2);

		DoorButton button0;
		DoorButton button1;
		button0.setParameters(280,140,20,20);
		button1.setParameters(150,270,20,20);
		button0.setOperation(1,1);
		button1.setOperation(0,1);
		buttons.push_back(button0);
		buttons.push_back(button1);

		Light light0;
		Light light1;
		light0.setParameters(180,100,140,100);
		light1.setParameters(120,220,140,110);
		lights.push_back(light0);
		lights.push_back(light1);

		Enemy enemy0;
		enemy0.setPosition(390,50);
		enemy0.setHome(390,50);
		enemy0.setTarget(390,300);
		enemy0.setPatrolParameters();
		enemies.push_back(enemy0);
	}
	
	else if (stage == 1)
	{
		Light light0;
		Light light1;
		Light light2;
		Light light3;
		Light light4;
		light0.setParameters(60,10,60,400);
		light1.setParameters(180,10,60,400);
		light2.setParameters(300,10,60,400);
		light3.setParameters(420,10,60,400);
		light4.setParameters(540,10,60,400);
		lights.push_back(light0);
		lights.push_back(light1);
		lights.push_back(light2);
		lights.push_back(light3);
		lights.push_back(light4);

		Enemy enemy0;
		enemy0.setPosition(589,180);
		enemy0.setHome(590,180);
		enemy0.setTarget(1,1);
		enemy0.setStandingParameters();
		enemies.push_back(enemy0);
	}
	else if (stage == 2)
	{
		Wall wall0;
		Wall wall1;
		wall0.setParameters(100,100,530,20);
		wall1.setParameters(100,300,530,20);
		walls.push_back(wall0);
		walls.push_back(wall1);

		Door door0;
		Door door1;
		door0.setParameters(120,120,20,180);
		door1.setParameters(550,120,20,180);
		doors.push_back(door0);
		doors.push_back(door1);

		DoorButton button0;
		DoorButton button1;
		button0.setParameters(550,50,20,20);
		button1.setParameters(550,350,20,20);
		button0.setOperation(1,1);
		button1.setOperation(0,1);
		buttons.push_back(button0);
		buttons.push_back(button1);

		Enemy enemy0;
		enemy0.setPosition(395,120);
		enemy0.setHome(470,120);
		enemy0.setTarget(170,120);
		enemy0.setPatrolParameters();

		Enemy enemy1;
		enemy1.setPosition(320,180);
		enemy1.setHome(470,180);
		enemy1.setTarget(170,180);
		enemy1.setPatrolParameters();

		Enemy enemy2;
		enemy2.setPosition(245,240);
		enemy2.setHome(470,240);
		enemy2.setTarget(170,240);
		enemy2.setPatrolParameters();

		Enemy enemy3;
		enemy3.setPosition(170,25);
		enemy3.setHome(170,25);
		enemy3.setTarget(470,25);
		enemy3.setPatrolParameters();

		Enemy enemy4;
		enemy4.setPosition(470,335);
		enemy4.setHome(170,335);
		enemy4.setTarget(470,335);
		enemy4.setPatrolParameters();

		enemies.push_back(enemy0);
		enemies.push_back(enemy1);
		enemies.push_back(enemy2);
		enemies.push_back(enemy3);
		enemies.push_back(enemy4);
	}

	else
	{
		//blank stage for any number past the created stages
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

Player Level::getPlayer()
{
	return player;
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

std::vector<Light> Level::getLights()
{
	return lights;
}

WinZone Level::getWinZone()
{
	return winZone;
}