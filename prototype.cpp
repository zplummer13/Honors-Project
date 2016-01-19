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
			body.setPosition(640.f/2.f, 480.f/2.f);
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

class Game 
{
	public:
		Game() : window(sf::VideoMode(640,480), "Prototype")
		, player()
		, zone()
		{
			//sf::View view;
			//view.setViewport(sf::FloatRect(0,0,48.f/64.f,1.f));
			//window.setView(view);
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
		sf::View view;

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
			//view.move(movement * deltaTime.asSeconds());
			//window.setView(view);

		}

		void render()
		{
			window.clear();
			window.draw(zone.getBody());
			window.draw(player.getBody());
			window.display();
		}

};

int main()
{
	Game game;
	game.run();
}