#include <SFML/Graphics.hpp>

class Entity 
{
	public:
		void setVelocity(sf::Vector2f v)
		{
			velocity = v;
		}

		void setVelocity(float vx, float vy)
		{
			velocity.x = vx;
			velocity.y = vy;
		}

		sf::Vector2f getVelocity()
		{
			return velocity;
		}
	private:
		sf::Vector2f velocity;

};

class Wall : public Entity
{
	public:
		Wall()
		{
			body.setFillColor(sf::Color::Red);
		}

		void setPosition(int x, int y)
		{
			body.setPosition(x,y);
		}

		void setSize(int w, int h)
		{
			width = w;
			height = h;
			body.setSize(sf::Vector2f(w,h));
		}

		void setParameters(int x, int y, int w, int h)
		{
			setPosition(x,y);
			setSize(w,h);
		}

		sf::RectangleShape getBody()
		{
			return body;
		}

		int getWidth()
		{
			return width;
		}

		int getHeight()
		{
			return height;
		}

	private:
		sf::RectangleShape body;
		int width;
		int height;

};

class Zone : public Entity
{
	public:
		Zone()
		{
			body.setSize(sf::Vector2f(620,400));
			body.setOutlineColor(sf::Color::Red);
			body.setFillColor(sf::Color::Black);
			body.setOutlineThickness(5);
			body.setPosition(10,10);
		}

		sf::RectangleShape getBody()
		{
			return body;
		}

	private:
		sf::RectangleShape body;
};

class Player : public Entity
{
	public:
		Player()
		{
			body.setRadius(10.f);
			body.setPosition(16, 200);
			body.setFillColor(sf::Color::Cyan);
			movingUp = false;
			movingDown = false;
			movingLeft = false;
			movingRight = false;
		}

		void move(sf::Vector2f movement)
		{
			body.move(movement);
		}

		sf::CircleShape getBody()
		{
			return body;
		}

		void setMovingUp(bool isPressed)
		{
			movingUp = isPressed;
		}

		void setMovingDown(bool isPressed)
		{
			movingDown = isPressed;
		}

		void setMovingLeft(bool isPressed)
		{
			movingLeft = isPressed;
		}

		void setMovingRight(bool isPressed)
		{
			movingRight = isPressed;
		}

		bool isMovingUp()
		{
			return movingUp;
		}

		bool isMovingDown()
		{
			return movingDown;
		}

		bool isMovingLeft()
		{
			return movingLeft;
		}

		bool isMovingRight()
		{
			return movingRight;
		}


	private:
		sf::CircleShape body;
		bool movingUp;
		bool movingDown;
		bool movingLeft;
		bool movingRight;

};

class Enemy : public Entity
{
	public:
		Enemy()
		{
			body = sf::CircleShape(30,12);
			body.setFillColor(sf::Color(255,255,255,180));
			movingRight = true;
		}

		void move(sf::Vector2f movement)
		{
			body.move(movement);
		}

		void setPosition(int x, int y)
		{
			body.setPosition(x,y);
		}

		void setMovingRight(bool k)
		{
			movingRight = k;
		}

		bool getMovingRight()
		{
			return movingRight;
		}

		sf::CircleShape getBody()
		{
			return body;
		}

	private:
		sf::CircleShape body;
		bool movingRight;

};

class Game 
{
	Wall wall0;
	Wall wall1;
	Wall wall2;
	std::vector<Wall> walls;
	Enemy enemy1;
	sf::Font font;
	
	public:
		Game() : window(
					sf::VideoMode(640,480)
					,"Prototype"
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

			
			wall0.setParameters(400,200,200,100);
			wall1.setParameters(40,300,30,75);
			wall2.setParameters(37,81,51,32);
			walls.push_back(wall0);
			walls.push_back(wall1);
			walls.push_back(wall2);

			enemy1.setPosition(200,100);
		}

		void run()
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
	private:
		sf::RenderWindow window;
		Player player;
		Zone zone;
		bool gameOver;
		sf::Text gameOverText;

		void processEvents()
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

		void handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
		{
			if (key == sf::Keyboard::Escape)
			{
				window.close();
			}

			else if (key == sf::Keyboard::W)
			{
				player.setMovingUp(isPressed);
			}

			else if (key == sf::Keyboard::S)
			{
				player.setMovingDown(isPressed);
			}

			else if (key == sf::Keyboard::A)
			{
				player.setMovingLeft(isPressed);
			}

			else if (key == sf::Keyboard::D)
			{
				player.setMovingRight(isPressed);
			}

		}

		void update(sf::Time deltaTime)
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

			player.move(correctMove);

			sf::Vector2f enemyMovement(0.f,0.f);
			if (enemy1.getBody().getPosition().x > 400)
			{
				enemy1.setMovingRight(false);
			}
			if (enemy1.getBody().getPosition().x < 160)
			{
				enemy1.setMovingRight(true);
			}
			if (enemy1.getMovingRight())
			{
				enemy1.setVelocity(enemyMovement.x + 50.f, enemyMovement.y);
				enemyMovement = enemy1.getVelocity();

			}
			if (!enemy1.getMovingRight())
			{
				enemy1.setVelocity(enemyMovement.x - 50.f, enemyMovement.y);
				enemyMovement = enemy1.getVelocity();
			}

			enemy1.move(enemyMovement * deltaTime.asSeconds());

			if (player.getBody().getPosition().y + 20 > enemy1.getBody().getPosition().y &&
				player.getBody().getPosition().y < enemy1.getBody().getPosition().y + 30)
			{
				if (player.getBody().getPosition().x + 20 > enemy1.getBody().getPosition().x &&
					player.getBody().getPosition().x < enemy1.getBody().getPosition().x + 30)
				{
					gameOver = true;
				}
			}
			if (player.getBody().getPosition().x + 20 > enemy1.getBody().getPosition().x &&
				player.getBody().getPosition().x < enemy1.getBody().getPosition().x + 30)
			{
				if (player.getBody().getPosition().y + 20 > enemy1.getBody().getPosition().y &&
					player.getBody().getPosition().y < enemy1.getBody().getPosition().y + 30)
				{
					gameOver = true;
				}
			}

		}

		void render()
		{
			window.clear();
			if(!gameOver)
			{
				window.draw(zone.getBody());
				for(std::vector<Wall>::iterator it = walls.begin(); it != walls.end(); it++)
				{
					window.draw(it->getBody());
				}
				window.draw(player.getBody());
				window.draw(enemy1.getBody());
			}
			if(gameOver)
			{
				window.draw(gameOverText);
			}
			window.display();
		}

};

int main()
{
	Game game;
	game.run();
}