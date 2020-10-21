// Noel O' Hara
//first simple game. 

#include "Source.h"

int main()
{
	setUpValues();

	srand(time(NULL));

	int score = 0;
	
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Clock clockForFrameRate;
	clockForFrameRate.restart();

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		timeSinceLastUpdate += clockForFrameRate.restart();

		if (timeSinceLastUpdate > timePerFrame)
		{

			window.clear();
			playerMovement();
			horizontalBrain();
			zombieMovement();
			playerFollowerIntersectionCheck();
			playerHorizontalIntersectionCheck();

			if (player.collisionRectangle.intersects(goalCollisionRectangle))
			{
				score++;
			}

			setShapePosition();
			draw();
			
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}

	return 0;
}

/// <summary>
/// initialises all the shapes and floatrects
/// </summary>
void setUpValues()
{
	goalCollisionRectangle.left = 100;
	goalCollisionRectangle.top = 100;
	goalCollisionRectangle.height = 10;
	goalCollisionRectangle.width = 10;
	goalShape.setSize(sf::Vector2f(goalCollisionRectangle.width, goalCollisionRectangle.height));
	goalShape.setFillColor(sf::Color::Red);

	

	horizontalCollisionRectangle.left = 400;
	horizontalCollisionRectangle.top = 500;
	horizontalCollisionRectangle.height = 30;
	horizontalCollisionRectangle.width = 30;
	horizontalShape.setSize(sf::Vector2f(horizontalCollisionRectangle.width, horizontalCollisionRectangle.height));
	horizontalShape.setFillColor(sf::Color::Magenta);
}

/// <summary>
/// Moves the player when the user hits the arrow keys
/// </summary>
void playerMovement()
{
	float speed = 10;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		player.collisionRectangle.top -= speed;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		player.collisionRectangle.top += speed;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		player.collisionRectangle.left -= speed;


	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		player.collisionRectangle.left += speed;
	}

	player.position.x =  player.collisionRectangle.left;
	player.position.y = player.collisionRectangle.top;
}

void zombieMovement()
{
	follower.calcVelocity(player.position);
	follower.moveZombie();
}

/// <summary>
/// Checks if the player and follower have collided
/// </summary>
void playerFollowerIntersectionCheck()
{
	if (player.collisionRectangle.intersects(follower.collisionRectangle))
	{
		player.shape.setFillColor(sf::Color::Blue);
	}

	else
	{
		player.shape.setFillColor(sf::Color::White);
	}
}

/// <summary>
/// Moves the shape moving horizontally
/// </summary>
void horizontalBrain()
{
	horizontalCollisionRectangle.left += Horizontalspeed;

	if (horizontalCollisionRectangle.left > screenWidth - horizontalCollisionRectangle.width 
		|| horizontalCollisionRectangle.left < 0)
	{
		Horizontalspeed = -Horizontalspeed;
	}
}

/// <summary>
/// Checks to see if the player and horizontal shape have collided
/// </summary>
void playerHorizontalIntersectionCheck()
{
	if (player.collisionRectangle.intersects(horizontalCollisionRectangle))
	{
		horizontalShape.setFillColor(sf::Color::Green);
	}

	else
	{
		horizontalShape.setFillColor(sf::Color::Magenta);
	}
}

/// <summary>
/// Draws all the shapes to the window
/// </summary>
void draw()
{
	player.drawPlayer(window);
	window.draw(goalShape);
	window.draw(horizontalShape);
	follower.drawZombie(window);

	window.display();
}

/// <summary>
/// sets the shapes to match the position given by their floatrects
/// </summary>
void setShapePosition()
{
	goalShape.setPosition(goalCollisionRectangle.left, goalCollisionRectangle.top);
	horizontalShape.setPosition(horizontalCollisionRectangle.left, horizontalCollisionRectangle.top);
}
