#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Graphics.hpp>
#include <iostream>
#include "Powerup.h"

Powerup::Powerup(short i_x, short i_y, unsigned char i_type)
{
	dead = false;
	x = i_x;
	y = i_y;
	type = i_type;
	texture.loadFromFile("Assets/img/PNG/Power-ups/powerUp" + std::to_string(i_type) + ".png");
	
	if (type == 1 || type == 2)
	{
		powerDuration = 320;
	}

	else
	{
		powerDuration = 1;
	}
}

sf::FloatRect Powerup::GetHitBox() const
{
	return sprite.getGlobalBounds();
}

unsigned short Powerup::GetDuration()
{
	return powerDuration;
}

void Powerup::Draw(sf::RenderWindow& window)
{
	sprite.setPosition(x, y);
	sprite.setScale(1, 1);
	sprite.setTexture(texture);
	window.draw(sprite);
}



