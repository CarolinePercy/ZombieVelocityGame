#pragma once
#include <SFML/Graphics.hpp>
#include "VectorAlgebra2D.h"
#include <time.h>

struct Zombie
{
	sf::RectangleShape shape;
	sf::FloatRect collisionRectangle;
	sf::Vector2f velocity;
	sf::Vector2f position;
	float speed;
	int rotation;

	Zombie();
	void calcVelocity(sf::Vector2f t_playerPosition);
	void moveZombie();
	void drawZombie(sf::RenderWindow& t_window);

};

