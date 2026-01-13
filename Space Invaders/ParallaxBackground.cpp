#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Graphics.hpp>
#include <array>
#include <chrono>
#include <random>
#include <iostream>
#include "ParallaxBackground.h"
#include "Global.h"

ParallaxBackground::ParallaxBackground(float i_step_x, float i_step_y, short i_x, short i_y)
{
	real_x = i_x;
	real_y = i_y;
	step_x = i_step_x;
	step_y = i_step_y;
	texture.loadFromFile("Assets/img/background1.jpg");
}

void ParallaxBackground::Draw(sf::RenderWindow& window)
{
	sprite.setPosition(x, y);
	sprite.setScale(1, 1);
	sprite.setTexture(texture);
	sprite.setColor(sf::Color(255, 255, 255, 150));
	window.draw(sprite);
}

void ParallaxBackground::Update()
{
	real_x += step_x;
	real_y += step_y;
	x = round(real_x);
	y = round(real_y);
	
	if (y >= HEIGHT)
	{
		real_y = -HEIGHT - 300;
	}
}
