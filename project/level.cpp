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
	setStage(4);
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
	else if (stage == 3)
	{
		Wall wall0; Wall wall1; Wall wall2; Wall wall3;
		Wall wall4; Wall wall5; Wall wall6; Wall wall7;
		Wall wall8; Wall wall9; Wall wall10; Wall wall11;
		Wall wall12; Wall wall13;

		wall0.setParameters(90,60,20,100);
		wall1.setParameters(240,60,20,100);
		wall2.setParameters(390,60,20,100);
		wall3.setParameters(540,60,20,100);

		wall4.setParameters(90,250,20,100);
		wall5.setParameters(240,250,20,100);
		wall6.setParameters(390,250,20,100);
		wall7.setParameters(540,250,20,100);

		wall8.setParameters(10,140,90,20);
		wall9.setParameters(10,250,90,20);
		wall10.setParameters(560,140,70,20);
		wall11.setParameters(560,250,70,20);

		wall12.setParameters(90,40,470,20);
		wall13.setParameters(90,350,470,20);

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
		walls.push_back(wall10);
		walls.push_back(wall11);
		walls.push_back(wall12);
		walls.push_back(wall13);

		Door door0; Door door1; Door door2;
		Door door3; Door door4; Door door5;
		Door door6; Door door7; Door door8;
		door0.setParameters(110,140,130,20);
		door1.setParameters(260,140,130,20);
		door2.setParameters(410,140,130,20);
		door3.setParameters(110,250,130,20);
		door4.setParameters(260,250,130,20);
		door5.setParameters(410,250,130,20);
		door6.setParameters(240,160,20,90);
		door7.setParameters(390,160,20,90);
		door8.setParameters(540,160,20,90);

		doors.push_back(door0);
		doors.push_back(door1);
		doors.push_back(door2);
		doors.push_back(door3);
		doors.push_back(door4);
		doors.push_back(door5);
		doors.push_back(door6);
		doors.push_back(door7);
		doors.push_back(door8);

		DoorButton button0; DoorButton button1; DoorButton button2;
		DoorButton button3; DoorButton button4; DoorButton button5;
		DoorButton button6; DoorButton button7; DoorButton button8;

		button0.setParameters(165,85,20,20);
		button1.setParameters(315,85,20,20);
		button2.setParameters(465,85,20,20);
		button3.setParameters(165,195,20,20);
		button4.setParameters(315,195,20,20);
		button5.setParameters(465,195,20,20);
		button6.setParameters(165,305,20,20);
		button7.setParameters(315,305,20,20);
		button8.setParameters(465,305,20,20);

		button0.setOperation(0,0);
		button0.setOperation(1,0);
		button0.setOperation(2,1);
		button0.setOperation(3,0);
		button0.setOperation(4,1);
		button0.setOperation(5,0);
		button0.setOperation(6,1);
		button0.setOperation(7,0);
		button0.setOperation(8,1);

		button1.setOperation(0,1);
		button1.setOperation(1,0);
		button1.setOperation(2,1);
		button1.setOperation(3,1);
		button1.setOperation(4,1);
		button1.setOperation(5,1);
		button1.setOperation(6,3);
		button1.setOperation(7,0);
		button1.setOperation(8,3);

		button2.setOperation(0,0);
		button2.setOperation(1,1);
		button2.setOperation(2,0);
		button2.setOperation(3,1);
		button2.setOperation(4,0);
		button2.setOperation(5,1);
		button2.setOperation(6,0);
		button2.setOperation(7,1);
		button2.setOperation(8,1);

		button3.setOperation(0,1);
		button3.setOperation(1,1);
		button3.setOperation(2,1);
		button3.setOperation(3,1);
		button3.setOperation(4,0);
		button3.setOperation(5,1);
		button3.setOperation(6,2);
		button3.setOperation(7,1);
		button3.setOperation(8,1);

		button4.setOperation(0,1);
		button4.setOperation(1,0);
		button4.setOperation(2,1);
		button4.setOperation(3,1);
		button4.setOperation(4,1);
		button4.setOperation(5,1);
		button4.setOperation(6,0);
		button4.setOperation(7,1);
		button4.setOperation(8,1);

		button5.setOperation(0,1);
		button5.setOperation(1,1);
		button5.setOperation(2,1);
		button5.setOperation(3,0);
		button5.setOperation(4,0);
		button5.setOperation(5,1);
		button5.setOperation(6,1);
		button5.setOperation(7,1);
		button5.setOperation(8,1);

		button6.setOperation(0,1);
		button6.setOperation(1,0);
		button6.setOperation(2,0);
		button6.setOperation(3,0);
		button6.setOperation(4,1);
		button6.setOperation(5,1);
		button6.setOperation(6,1);
		button6.setOperation(7,1);
		button6.setOperation(8,1);

		button7.setOperation(0,3);
		button7.setOperation(1,3);
		button7.setOperation(2,3);
		button7.setOperation(3,3);
		button7.setOperation(4,3);
		button7.setOperation(5,3);
		button7.setOperation(6,2);
		button7.setOperation(7,3);
		button7.setOperation(8,2);

		button8.setOperation(0,3);
		button8.setOperation(1,3);
		button8.setOperation(2,3);
		button8.setOperation(3,3);
		button8.setOperation(4,3);
		button8.setOperation(5,0);
		button8.setOperation(6,2);
		button8.setOperation(7,2);
		button8.setOperation(8,1);

		buttons.push_back(button0);
		buttons.push_back(button1);
		buttons.push_back(button2);
		buttons.push_back(button3);
		buttons.push_back(button4);
		buttons.push_back(button5);
		buttons.push_back(button6);
		buttons.push_back(button7);
		buttons.push_back(button8);
	}
	else if (stage == 4)
	{
		Wall wall0;
		Wall wall1;
		Wall wall2;
		Wall wall3;
		Wall wall4;
		Wall wall5;
		Wall wall6;
		wall0.setParameters(10,250,90,20);
		wall1.setParameters(80,150,20,100);
		wall2.setParameters(80,70,200,20);
		wall3.setParameters(170,90,20,100);
		wall4.setParameters(260,90,20,180);
		wall5.setParameters(170,270,20,80);
		wall6.setParameters(80,330,260,20);

		walls.push_back(wall0);
		walls.push_back(wall1);
		walls.push_back(wall2);
		walls.push_back(wall3);
		walls.push_back(wall4);
		walls.push_back(wall5);
		walls.push_back(wall6);

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