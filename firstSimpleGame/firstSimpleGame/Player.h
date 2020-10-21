#pragma once
#include <SFML/Graphics.hpp>
struct Player
{
	sf::RectangleShape shape;
	sf::RectangleShape spell;
	sf::FloatRect collisionRectangle;
	sf::Vector2f position;

	Player();
	void drawPlayer(sf::RenderWindow &t_window);
	void shootSpell();
};

