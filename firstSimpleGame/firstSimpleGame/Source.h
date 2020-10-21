#pragma once
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include "Zombie.h"
#include "Player.h"
#include <iostream>
#include <stdlib.h> 
#include <time.h> 

void setUpValues();
void playerFollowerIntersectionCheck();
void horizontalBrain();
void playerMovement();
void zombieMovement();
void playerHorizontalIntersectionCheck();
void draw();
void setShapePosition();

int screenWidth = 800;
int screenHeight = 600;

sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Collisions in C++");

sf::RectangleShape goalShape;
sf::FloatRect goalCollisionRectangle;

Zombie follower;
Player player;

sf::RectangleShape horizontalShape;
sf::FloatRect horizontalCollisionRectangle;
int Horizontalspeed{ 5 };