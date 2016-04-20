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
	paused = false;

	if (!font.loadFromFile("j_d_handcrafted/j.d.ttf")) { /* Nothing */}
	gameOverText.setString("Game Over!");
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(80);
	gameOverText.setPosition(100,140);
	gameOverText.setColor(sf::Color::Red);
	wonLevelText.setString("Level Complete!");
	wonLevelText.setFont(font);
	wonLevelText.setCharacterSize(56);
	wonLevelText.setPosition(100,150);
	wonLevelText.setColor(sf::Color::Red);
	promptReturn.setString("Press Return to Continue");
	promptReturn.setFont(font);
	promptReturn.setCharacterSize(32);
	promptReturn.setPosition(100,240);
	promptReturn.setColor(sf::Color::Red);
	pausedText.setString("Paused\nPress Return to Continue\nPress Q to Restart level\nPress M to go to the Title\nPress Esc to Quit");
	pausedText.setFont(font);
	pausedText.setCharacterSize(30);
	pausedText.setPosition(100,120);
	pausedText.setColor(sf::Color::Red);
	pausedScreen.setPosition(0,0);
	pausedScreen.setSize(sf::Vector2f(640,480));
	pausedScreen.setFillColor(sf::Color(0,0,0,180));

	titleTexts = titleMenu.getTexts();

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

	if (!gameOver && !wonLevel && !paused && !titleMenu.getOnMenu())
	{
		if (key == sf::Keyboard::W || key == sf::Keyboard::Up)
		{
			player.setMovingUp(isPressed);
		}

		if (key == sf::Keyboard::S || key == sf::Keyboard::Down)
		{
			player.setMovingDown(isPressed);
		}

		if (key == sf::Keyboard::A || key == sf::Keyboard::Left)
		{
			player.setMovingLeft(isPressed);
		}

		if (key == sf::Keyboard::D || key == sf::Keyboard::Right)
		{
			player.setMovingRight(isPressed);
		}

		if (key == sf::Keyboard::P)
		{
			paused = true;
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
	else if (paused)
	{
		if (key == sf::Keyboard::Return)
		{
			paused = false;
		}
		if (key == sf::Keyboard::Q)
		{
			paused = false;
			level.initiate();
			player = level.getPlayer();
			walls = level.getWalls();
			enemies = level.getEnemies();
			doors = level.getDoors();
			buttons = level.getButtons();
			lights = level.getLights();
			winZone = level.getWinZone();
		}
		if (key == sf::Keyboard::M)
		{
			paused = false;
			titleMenu.setOnMenu(true);
			titleMenu.setScreen(0);
			titleTexts = titleMenu.getTexts();
			level.setStage(0);
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
	else if (titleMenu.getOnMenu())
	{
		if (key == sf::Keyboard::Return && titleMenu.getCooldown() == 0)
		{
			titleMenu.incrementScreen();
			titleTexts = titleMenu.getTexts();
			titleMenu.setCooldown(40);
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
	if (titleMenu.getOnMenu() && titleMenu.getCooldown() > 0)
	{
		titleMenu.setCooldown(titleMenu.getCooldown() - 1);
	}
	if (!paused && !titleMenu.getOnMenu())
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
				if (level.getStage() >= 0 && level.getStage() < MAXLEVEL)
				{
					wonLevel = true;
				}
			}
		}
	}
}

void Game::render()
{
	window.clear();
	if(!gameOver && !wonLevel && !titleMenu.getOnMenu())
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
		if (paused)
		{
			window.draw(pausedScreen);
			window.draw(pausedText);
		}
	}
	if(titleMenu.getOnMenu())
	{
		for(std::vector<sf::Text>::iterator it = titleTexts.begin(); it != titleTexts.end(); it++)
		{
			window.draw(*it);
		}
	}
	if(gameOver)
	{
		window.draw(gameOverText);
		window.draw(promptReturn);
	}
	if(wonLevel)
	{
		window.draw(wonLevelText);
		window.draw(promptReturn);
	}
	window.display();
}

