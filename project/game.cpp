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
			,sf::ContextSettings(0,0,0)
			)
		, zone()
{
	gameOver = false;
	wonLevel = false;

	if (!font.loadFromFile("OpenSans.ttf")) { /* Nothing */}
	gameOverText.setString("Game Over!\nPress Return to Restart");
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(30);
	gameOverText.setPosition(100,200);
	gameOverText.setColor(sf::Color::Red);
	wonLevelText.setString("Level Complete!\nPress Return to Continue");
	wonLevelText.setFont(font);
	wonLevelText.setCharacterSize(30);
	wonLevelText.setPosition(100,200);
	wonLevelText.setColor(sf::Color::Red);

	level.initiate();
	player = level.getPlayer();
	walls = level.getWalls();
	enemies = level.getEnemies();
	doors = level.getDoors();
	buttons = level.getButtons();
	lights = level.getLights();
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

	if (!gameOver && !wonLevel)
	{
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

		if (key == sf::Keyboard::Space)
		{
			player.swap();
		}
	}
	else if (gameOver)
	{
		if (key == sf::Keyboard::Return)
		{
			gameOver = false;
			level.initiate();
			player = level.getPlayer();
			walls = level.getWalls();
			enemies = level.getEnemies();
			doors = level.getDoors();
			buttons = level.getButtons();
			lights = level.getLights();
			winZone = level.getWinZone();
		}
	}
	else
	{
		if (key == sf::Keyboard::Return)
		{
			wonLevel = false;
			level.win();
			level.initiate();
			player = level.getPlayer();
			walls = level.getWalls();
			enemies = level.getEnemies();
			doors = level.getDoors();
			buttons = level.getButtons();
			lights = level.getLights();
			winZone = level.getWinZone();
		}
	}

}

void Game::update(sf::Time deltaTime)
{
	player.advanceCooldowns();
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
					doors = it->operateLinkedDoors(doors);
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

	for(std::vector<Light>::iterator it = lights.begin(); it != lights.end(); it++)
	{
		if(player.isInLight())
		{
			if (player.getBody().getPosition().y + 20 < it->getBody().getPosition().y ||
				player.getBody().getPosition().y > it->getBody().getPosition().y + it->getHeight())
			{
				player.setInLight(false);
			}
			if (player.getBody().getPosition().x + 20 < it->getBody().getPosition().x ||
				player.getBody().getPosition().x > it->getBody().getPosition().x + it->getWidth())
			{
				player.setInLight(false);
			}
		}
		//else
		//{
			if (player.getBody().getPosition().y + 20 > it->getBody().getPosition().y &&
				player.getBody().getPosition().y < it->getBody().getPosition().y + it->getHeight())
			{
				if (player.getBody().getPosition().x + 20 > it->getBody().getPosition().x &&
					player.getBody().getPosition().x < it->getBody().getPosition().x + it->getWidth())
				{
					player.setInLight(true);
					break;
				}
			}
		//}
	}

	for(std::vector<Enemy>::iterator it = enemies.begin(); it != enemies.end(); it++)
	{
		it->script(player);
		it->update(deltaTime);

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
	}
	if (player.getBody().getPosition().y + 20 > winZone.getBody().getPosition().y &&
			player.getBody().getPosition().y < winZone.getBody().getPosition().y + winZone.getHeight())
		{
			if (player.getBody().getPosition().x + 20 > winZone.getBody().getPosition().x &&
			player.getBody().getPosition().x < winZone.getBody().getPosition().x + winZone.getWidth())
			{
				if (level.getStage() >= 0 && level.getStage() < 3)
				{
					wonLevel = true;
				}
			}
		}
}

void Game::render()
{
	window.clear();
	if(!gameOver && !wonLevel)
	{
		window.draw(zone.getBody());
		for(std::vector<Light>::iterator it = lights.begin(); it != lights.end(); it++)
		{
			window.draw(it->getBody());
		}
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
		window.draw(player.getShadow());
		window.draw(player.getShadowBar());
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
	if(wonLevel)
	{
		window.draw(wonLevelText);
	}
	window.display();
}

