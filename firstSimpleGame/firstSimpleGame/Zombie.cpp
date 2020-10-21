#include "Zombie.h"

Zombie::Zombie()
{
	srand(time(NULL));

	collisionRectangle.left = 400;
	collisionRectangle.top = 300;
	collisionRectangle.height = 20;
	collisionRectangle.width = 20;

	shape.setSize(sf::Vector2f(collisionRectangle.width, collisionRectangle.height));
	shape.setFillColor(sf::Color::Cyan);

	position = sf::Vector2f(1,1);
	rotation = 0;
	speed = (rand() % 5) + 1;

}

void Zombie::calcVelocity(sf::Vector2f t_playerPosition)
{
	velocity = t_playerPosition - position;
	thor::setLength(velocity, speed);
	rotation = thor::polarAngle(velocity);
}

void Zombie::moveZombie()
{
	position += velocity;
	collisionRectangle.top = position.y;
	collisionRectangle.left = position.x;
}

void Zombie::drawZombie(sf::RenderWindow& t_window)
{
	shape.setPosition(position);
	shape.setRotation(rotation);
	t_window.draw(shape);
}
