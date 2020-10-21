#include "Player.h"

Player::Player()
{
	collisionRectangle.left = 0;
	collisionRectangle.top = 0;
	collisionRectangle.height = 40;
	collisionRectangle.width = 40;
	shape.setSize(sf::Vector2f(collisionRectangle.width, collisionRectangle.height));

	position = sf::Vector2f(1, 1);
}

void Player::drawPlayer(sf::RenderWindow& t_window)
{
	shape.setPosition(position);
	t_window.draw(shape);

}
