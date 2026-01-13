#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Graphics.hpp>
#include <array>
#include <iostream>
#include <cmath>
#include <chrono>

#include "Bullet.h"
#include "Global.h"
#include "Tween.h"

Bullet::Bullet(float i_step_x, float i_step_y, short i_x, short i_y, const std::string& textPath, unsigned char i_type, bool i_interpolate, bool animate)
{
	dead = 0;
	step_x = i_step_x;	//Interpolate step x
	step_y = i_step_y;	//Interpolate step y
	real_x = i_x;
	real_y = i_y;
	type = i_type;
	interpolate = i_interpolate;
	this->animate = animate;
	texture.loadFromFile(textPath);
}

void Bullet::DrawTheBullet(sf::RenderWindow& window, float dTime)
{
	//setting the sprite scale
	sprite.setScale(1, 1);
	//setting the texture of sprite
	sprite.setTexture(texture);
	//setting the position of sprite
	sprite.setPosition(x, y);
	//displays it to the window
	window.draw(sprite);
}

void Bullet::Update()
{
	//checking if interpolate is true
	if (!interpolate)
	{
		//if interpolate is not true, then just increment position by step x and step y
		real_x += step_x;
		real_y += step_y;
		//rounding the number from float to neareast int number
		x = round(real_x);
		y = round(real_y);
	}

	else
	{
		//checking the direction between current position and target position
		float toReachPositionX = Tween::TweenPositionX(step_x, step_y, sprite.getPosition().x, sprite.getPosition().y);
		float toReachPositionY = Tween::TweenPositionY(step_x, step_y, sprite.getPosition().x, sprite.getPosition().y);

		//adding the direction with speed value to increment the position
		real_x += (toReachPositionX * BULLETSPEEDFORENEMY);
		real_y += (toReachPositionY * BULLETSPEEDFORENEMY);

		//putting the rounded value in x pos and y pos
		x = round(real_x);
		y = round(real_y);

		//taking the rounded value of the distance between target sprite and bullet sprite
		previousX = round(step_x - sprite.getPosition().x);
		previousY = round(step_y - sprite.getPosition().y);
		
		//checking if distance between them is less than 5 then destroy the bullet (we use 5 as the distance is not always exact so we use a placeholder value or else it will stay on the screen)
		if (previousX < 5 && previousY < 5)
		{
			dead = true;
		}
		
	}

	//destroying the bullet is it goes out the screen
	if (y >= HEIGHT || x >= WIDTH || y <= 0 || x <= 0)
	{
		dead = true;
	}

}
	
sf::FloatRect Bullet::GetHitBox() const
{
	return sprite.getGlobalBounds();
}

short Bullet::InterpolateX(short i_x)
{
	return 1;
}
short Bullet::InterpolateY(short i_y)
{
	return 1;
}