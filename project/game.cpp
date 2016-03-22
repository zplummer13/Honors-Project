#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "wall.hpp"
#include "door.hpp"
#include "zone.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "game.hpp"
#include "level.hpp"
#include "doorButton.hpp"
#include <stdio.h>

Game::Game() : window(
			sf::VideoMode(640,480)
			,"Honors Project"
			,sf::Style::Default
			,sf::ContextSettings(0,0,4)
			)
		, player()
		, zone()
{
	gameOver = false;

	if (!font.loadFromFile("OpenSans.ttf")) { /* Nothing */}
	gameOverText.setString("Game Over! Press Esc to Leave");
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(30);
	gameOverText.setPosition(100,200);
	gameOverText.setColor(sf::Color::Red);

	level.initiate();
	walls = level.getWalls();
	enemies = level.getEnemies();
	doors = level.getDoors();
	buttons = level.getButtons();
	winZone = level.getWinZone();
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	while (window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

//Private Functions

void Game::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event.type == sf::Event::KeyPressed)
		{
			handlePlayerInput(event.key.code, true);
		}

		if (event.type == sf::Event::KeyReleased)
		{
			handlePlayerInput(event.key.code, false);
		}
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Escape)
	{
		window.close();
	}

	if (key == sf::Keyboard::W)
	{
		player.setMovingUp(isPressed);
	}

	if (key == sf::Keyboard::S)
	{
		player.setMovingDown(isPressed);
	}

	if (key == sf::Keyboard::A)
	{
		player.setMovingLeft(isPressed);
	}

	if (key == sf::Keyboard::D)
	{
		player.setMovingRight(isPressed);
	}

}

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f,0.f);
	if (player.isMovingUp())
	{
		player.setVelocity(movement.x, movement.y - 70.f);
		movement = player.getVelocity();
	}
	if (player.isMovingDown())
	{
		player.setVelocity(movement.x, movement.y + 70.f);
		movement = player.getVelocity();
	}
	if (player.isMovingLeft())
	{
		player.setVelocity(movement.x - 70.f, movement.y);
		movement = player.getVelocity();
	}
	if (player.isMovingRight())
	{
		player.setVelocity(movement.x + 70.f, movement.y);
		movement = player.getVelocity();
	}

	player.move(movement * deltaTime.asSeconds());

	sf::Vector2f correctMove(0.f,0.f);
	if (player.getBody().getPosition().x < zone.getBody().getPosition().x ||
		player.getBody().getPosition().x > zone.getBody().getPosition().x + 600)
	{
		correctMove.x = -1 * movement.x * deltaTime.asSeconds();
	}
	if (player.getBody().getPosition().y < zone.getBody().getPosition().y ||
		player.getBody().getPosition().y > zone.getBody().getPosition().y + 380)
	{
		correctMove.y = -1 * movement.y * deltaTime.asSeconds();
	}

	for(std::vector<Wall>::iterator it = walls.begin(); it != walls.end(); it++)
	{
		if(player.getBody().getPosition().y + 20 > it->getBody().getPosition().y &&
			player.getBody().getPosition().y < it->getBody().getPosition().y + it->getHeight())
		{
			if(player.getBody().getPosition().x + 20 > it->getBody().getPosition().x &&
				player.getBody().getPosition().x < it->getBody().getPosition().x + it->getWidth())
			{
				correctMove.x = -1 * movement.x * deltaTime.asSeconds();
			}
		}
		if (player.getBody().getPosition().x + 20 > it->getBody().getPosition().x &&
			player.getBody().getPosition().x < it->getBody().getPosition().x + it->getWidth())
		{
			if (player.getBody().getPosition().y + 20 > it->getBody().getPosition().y &&
				player.getBody().getPosition().y < it->getBody().getPosition().y + it->getHeight())
			{
				correctMove.y = -1 * movement.y * deltaTime.asSeconds();
			}
		}
	}

	for(std::vector<Door>::iterator it = doors.begin(); it != doors.end(); it++)
	{
		if (it->getState())
		{
			if (player.getBody().getPosition().y + 20 > it->getBody().getPosition().y &&
				player.getBody().getPosition().y < it->getBody().getPosition().y + it->getHeight())
			{
				if (player.getBody().getPosition().x + 20 > it->getBody().getPosition().x &&
					player.getBody().getPosition().x < it->getBody().getPosition().x + it->getWidth())
				{
					correctMove.x = -1 * movement.x * deltaTime.asSeconds();
				}
			}

			if (player.getBody().getPosition().x + 20 > it->getBody().getPosition().x &&
				player.getBody().getPosition().x < it->getBody().getPosition().x + it->getWidth())
			{
				if (player.getBody().getPosition().y + 20 > it->getBody().getPosition().y &&
					player.getBody().getPosition().y < it->getBody().getPosition().y + it->getHeight())
				{
					correctMove.y = -1 * movement.y * deltaTime.asSeconds();
				}
			}
		}
	}

	player.move(correctMove);

	for(std::vector<DoorButton>::iterator it = buttons.begin(); it != buttons.end(); it++)
	{
		if (it->getState())
		{
			if (player.getBody().getPosition().y + 20 > it->getBody().getPosition().y &&
				player.getBody().getPosition().y < it->getBody().getPosition().y + it->getHeight())
			{
				if (player.getBody().getPosition().x + 20 > it->getBody().getPosition().x &&
					player.getBody().getPosition().x < it->getBody().getPosition().x + it->getWidth())
				{
					it->operateLinkedDoors();
					doors = it->getLinkedDoors();
					it->setState(false);
				}
			}
		}
		else
		{
			if (player.getBody().getPosition().y + 20 < it->getBody().getPosition().y ||
				player.getBody().getPosition().y > it->getBody().getPosition().y + it->getHeight())
			{
				it->setState(true);
			}
			if (player.getBody().getPosition().x + 20 < it->getBody().getPosition().x ||
				player.getBody().getPosition().x > it->getBody().getPosition().x + it->getWidth())
			{
				it->setState(true);
			}
		}
	}

	for(std::vector<Enemy>::iterator it = enemies.begin(); it != enemies.end(); it++)
	{
		sf::Vector2f enemyMovement(0.f,0.f);
		if (it->getBody().getPosition().x > 400)
		{
			it->setMovingRight(false);
		}
		if (it->getBody().getPosition().x < 160)
		{
			it->setMovingRight(true);
		}
		if (it->getMovingRight())
		{
			it->setVelocity(enemyMovement.x + 50.f, enemyMovement.y);
			enemyMovement = it->getVelocity();

		}
		if (!it->getMovingRight())
		{
			it->setVelocity(enemyMovement.x - 50.f, enemyMovement.y);
			enemyMovement = it->getVelocity();
		}

		it->move(enemyMovement * deltaTime.asSeconds());

		if (player.getBody().getPosition().y + 20 > it->getBody().getPosition().y &&
			player.getBody().getPosition().y < it->getBody().getPosition().y + 55)
		{
			if (player.getBody().getPosition().x + 20 > it->getBody().getPosition().x &&
				player.getBody().getPosition().x < it->getBody().getPosition().x + 55)
			{
				gameOver = true;
			}
		}
		if (player.getBody().getPosition().x + 20 > it->getBody().getPosition().x &&
			player.getBody().getPosition().x < it->getBody().getPosition().x + 55)
		{
			if (player.getBody().getPosition().y + 20 > it->getBody().getPosition().y &&
				player.getBody().getPosition().y < it->getBody().getPosition().y + 55)
			{
				gameOver = true;
			}
		}

		if (player.getBody().getPosition().y + 20 > winZone.getBody().getPosition().y &&
			player.getBody().getPosition().y < winZone.getBody().getPosition().y + winZone.getHeight())
		{
			if (player.getBody().getPosition().x + 20 > winZone.getBody().getPosition().x &&
			player.getBody().getPosition().x < winZone.getBody().getPosition().x + winZone.getWidth())
			{
				if (level.getStage() == 0)
				{
					level.win();
					level.initiate();
					walls = level.getWalls();
					//enemies = level.getEnemies();
					doors = level.getDoors();
					buttons = level.getButtons();
					winZone = level.getWinZone();
				}
			}
		}
	}
}

void Game::render()
{
	window.clear();
	if(!gameOver)
	{
		window.draw(zone.getBody());
		for(std::vector<Wall>::iterator it = walls.begin(); it != walls.end(); it++)
		{
			window.draw(it->getBody());
		}
		for(std::vector<Door>::iterator it = doors.begin(); it != doors.end(); it++)
		{
			window.draw(it->getBody());
		}
		for(std::vector<DoorButton>::iterator it = buttons.begin(); it != buttons.end(); it++)
		{
			window.draw(it->getBody());
		}
		window.draw(winZone.getBody());
		window.draw(player.getBody());
		for(std::vector<Enemy>::iterator it = enemies.begin(); it != enemies.end(); it++)
		{
			window.draw(it->getBody());
		}
	}
	if(gameOver)
	{
		window.draw(gameOverText);
	}
	window.display();
}

