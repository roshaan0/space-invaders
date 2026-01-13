#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Graphics.hpp>
#include "Animation.h"
#include "Explosion.h"

Explosion::Explosion(float x, float y)
{
	this->x = x;
	this->y = y;
	texture.loadFromFile("Assets/img/explosion.png");
	sprite.setTexture(texture);
	animation.SetAnimation(texture, 4, 1, 0.1f);
	isDead = false;
}

void Explosion::Draw(sf::RenderWindow& window, float deltaTime)
{
	animation.Update(0, deltaTime);
	sprite.setScale(0.5, 0.5);
	sprite.setPosition(x, y);
	sprite.setTexture(texture);
	sprite.setTextureRect(animation.uvRect);
	
	if (animation.GetEnd())
	{
		isDead = true;
	}
	
	window.draw(sprite);
}

