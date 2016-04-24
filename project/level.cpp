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
		Wall wall7;
		Wall wall8;
		Wall wall9;
		Wall wall10;
		wall0.setParameters(10,250,90,20);
		wall1.setParameters(80,150,20,100);
		wall2.setParameters(80,70,370,20);
		wall3.setParameters(170,90,20,100);
		wall4.setParameters(260,90,20,180);
		wall5.setParameters(170,270,20,80);
		wall6.setParameters(80,330,270,20);
		wall7.setParameters(350,250,20,100);
		wall8.setParameters(350,170,100,20);
		wall9.setParameters(450,330,80,20);
		wall10.setParameters(530,70,20,280);

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

		Door door0;
		Door door1;
		Door door2;
		Door door3;
		Door door4;
		Door door5;
		Door door6;
		door0.setParameters(280,170,70,20);
		door1.setParameters(260,10,20,60);
		door2.setParameters(430,90,20,80);
		door3.setParameters(550,70,80,20);
		door4.setParameters(550,130,80,20);
		door5.setParameters(550,270,80,20);
		door6.setParameters(550,330,80,20);
		doors.push_back(door0);
		doors.push_back(door1);
		doors.push_back(door2);
		doors.push_back(door3);
		doors.push_back(door4);
		doors.push_back(door5);
		doors.push_back(door6);

		Light light0;
		Light light1;
		Light light2;
		Light light3;
		light0.setParameters(205,90,40,40);
		light1.setParameters(15,370,35,35);
		light2.setParameters(490,290,40,40);
		light3.setParameters(280,90,40,40);

		lights.push_back(light0);
		lights.push_back(light1);
		lights.push_back(light2);
		lights.push_back(light3);

		DoorButton button0;
		DoorButton button1;
		DoorButton button2;
		DoorButton button3;

		button0.setParameters(215,100,20,20);
		button1.setParameters(20,380,20,20);
		button2.setParameters(500,300,20,20);
		button3.setParameters(290,100,20,20);

		button0.setOperation(0,0);
		button0.setOperation(1,1);
		button0.setOperation(2,1);
		button0.setOperation(3,1);
		button0.setOperation(4,1);
		button0.setOperation(5,1);
		button0.setOperation(6,1);

		button1.setOperation(0,1);
		button1.setOperation(1,0);
		button1.setOperation(2,0);
		button1.setOperation(3,1);
		button1.setOperation(4,1);
		button1.setOperation(5,1);
		button1.setOperation(6,1);

		button2.setOperation(0,1);
		button2.setOperation(1,1);
		button2.setOperation(2,1);
		button2.setOperation(3,0);
		button2.setOperation(4,1);
		button2.setOperation(5,0);
		button2.setOperation(6,1);

		button3.setOperation(0,1);
		button3.setOperation(1,1);
		button3.setOperation(2,1);
		button3.setOperation(3,1);
		button3.setOperation(4,0);
		button3.setOperation(5,1);
		button3.setOperation(6,0);

		buttons.push_back(button0);
		buttons.push_back(button1);
		buttons.push_back(button2);
		buttons.push_back(button3);

		Enemy enemy0;
		enemy0.setPosition(400,10);
		enemy0.setHome(470,10);
		enemy0.setTarget(130,10);
		enemy0.setPatrolParameters();

		Enemy enemy1;
		enemy1.setPosition(150,350);
		enemy1.setHome(460,350);
		enemy1.setTarget(20,350);
		enemy1.setPatrolParameters();

		Enemy enemy2;
		enemy2.setPosition(90,100);
		enemy2.setHome(90,100);
		enemy2.setTarget(490,280);
		enemy2.setPatrolParameters();

		enemies.push_back(enemy0);
		enemies.push_back(enemy1);
		enemies.push_back(enemy2);

	}
	else if (stage == 5)
	{
		Light light0;  Light light1;  Light light2;  Light light3;
		Light light4;  Light light5;  Light light6;
		Light light7;  Light light8;  Light light9;  Light light10;
		Light light11; Light light12; Light light13;
		Light light14; Light light15; Light light16; Light light17;
		Light light18; Light light19; Light light20;
		Light light21; Light light22; Light light23; Light light24;
		Light light25; Light light26; Light light27;
		Light light28; Light light29; Light light30; Light light31;
		Light light32; Light light33; Light light34;
		Light light35; Light light36; Light light37; Light light38;

		light0.setParameters(50,35,50,50);
		light1.setParameters(50,135,50,50);
		light2.setParameters(50,235,50,50);
		light3.setParameters(50,335,50,50);
		light4.setParameters(100,85,50,50);
		light5.setParameters(100,185,50,50);
		light6.setParameters(100,285,50,50);

		light7.setParameters(150,35,50,50);
		light8.setParameters(150,135,50,50);
		light9.setParameters(150,235,50,50);
		light10.setParameters(150,335,50,50);
		light11.setParameters(200,85,50,50);
		light12.setParameters(200,185,50,50);
		light13.setParameters(200,285,50,50);

		light14.setParameters(250,35,50,50);
		light15.setParameters(250,135,50,50);
		light16.setParameters(250,235,50,50);
		light17.setParameters(250,335,50,50);
		light18.setParameters(300,85,50,50);
		light19.setParameters(300,185,50,50);
		light20.setParameters(300,285,50,50);

		light21.setParameters(350,35,50,50);
		light22.setParameters(350,135,50,50);
		light23.setParameters(350,235,50,50);
		light24.setParameters(350,335,50,50);
		light25.setParameters(400,85,50,50);
		light26.setParameters(400,185,50,50);
		light27.setParameters(400,285,50,50);

		light28.setParameters(450,35,50,50);
		light29.setParameters(450,135,50,50);
		light30.setParameters(450,235,50,50);
		light31.setParameters(450,335,50,50);
		light32.setParameters(500,85,50,50);
		light33.setParameters(500,185,50,50);
		light34.setParameters(500,285,50,50);

		light35.setParameters(550,35,50,50);
		light36.setParameters(550,135,50,50);
		light37.setParameters(550,235,50,50);
		light38.setParameters(550,335,50,50);

		lights.push_back(light0);
		lights.push_back(light1);
		lights.push_back(light2);
		lights.push_back(light3);
		lights.push_back(light4);
		lights.push_back(light5);
		lights.push_back(light6);
		lights.push_back(light7);
		lights.push_back(light8);
		lights.push_back(light9);
		lights.push_back(light10);
		lights.push_back(light11);
		lights.push_back(light12);
		lights.push_back(light13);
		lights.push_back(light14);
		lights.push_back(light15);
		lights.push_back(light16);
		lights.push_back(light17);
		lights.push_back(light18);
		lights.push_back(light19);
		lights.push_back(light20);
		lights.push_back(light21);
		lights.push_back(light22);
		lights.push_back(light23);
		lights.push_back(light24);
		lights.push_back(light25);
		lights.push_back(light26);
		lights.push_back(light27);
		lights.push_back(light28);
		lights.push_back(light29);
		lights.push_back(light30);
		lights.push_back(light31);
		lights.push_back(light32);
		lights.push_back(light33);
		lights.push_back(light34);
		lights.push_back(light35);
		lights.push_back(light36);
		lights.push_back(light37);
		lights.push_back(light38);

		Enemy enemy0;
		enemy0.setPosition(-60,-60);
		enemy0.setHome(-60,-60);
		enemy0.setTarget(10,10);
		enemy0.setStandingParameters();

		Enemy enemy1;
		enemy1.setPosition(300,-60);
		enemy1.setHome(300,-60);
		enemy1.setTarget(10,10);
		enemy1.setStandingParameters();

		Enemy enemy2;
		enemy2.setPosition(600,-60);
		enemy2.setHome(600,-60);
		enemy2.setTarget(10,10);
		enemy2.setStandingParameters();

		Enemy enemy3;
		enemy3.setPosition(-60,490);
		enemy3.setHome(-60,490);
		enemy3.setTarget(10,10);
		enemy3.setStandingParameters();

		Enemy enemy4;
		enemy4.setPosition(300,490);
		enemy4.setHome(300,490);
		enemy4.setTarget(10,10);
		enemy4.setStandingParameters();

		Enemy enemy5;
		enemy5.setPosition(600,490);
		enemy5.setHome(600,490);
		enemy5.setTarget(10,10);
		enemy5.setStandingParameters();

		Enemy enemy6;
		enemy6.setPosition(660,190);
		enemy6.setHome(660,190);
		enemy6.setTarget(10,10);
		enemy6.setStandingParameters();

		Enemy enemy7;
		enemy7.setPosition(10,10);
		enemy7.setHome(10,10);
		enemy7.setTarget(10,400);
		enemy7.setPatrolParameters();

		enemies.push_back(enemy0);
		enemies.push_back(enemy1);
		enemies.push_back(enemy2);
		enemies.push_back(enemy3);
		enemies.push_back(enemy4);
		enemies.push_back(enemy5);
		enemies.push_back(enemy6);
		enemies.push_back(enemy7);
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