#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Graphics.hpp>
#include <iostream>
#include "Animation.h"

void Animation::SetAnimation(sf::Texture& texture, float imageCountX, float imageCountY, float switchTime)
{
	this->imageX = imageCountX;
	this->imageY = imageCountY;
	this->switchTime = switchTime;
	totalTime = 0;
	currentimageX = 0;
	uvRect.width = texture.getSize().x / imageX;
	uvRect.height = texture.getSize().y / imageY;
	end = false;
}

//void Animation::Draw(short x, short y, sf::RenderWindow& window)
//{
//	sprite.setPosition(x, y);
//	sprite.setScale(1, 1);
//	sprite.setTexture(texture);
//	width = sprite.getGlobalBounds().width;
//	height = sprite.getGlobalBounds().height;
//	window.draw(sprite);
//}

void Animation::Update(int row, float dTime)
{
	currentimageY = row;
	totalTime += dTime;
	
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentimageX++;
		
		if (currentimageX >= imageX)
		{
			end = true;
			currentimageX = 0;
		}
	}
	uvRect.left = currentimageX * uvRect.width;
	uvRect.top = currentimageY * uvRect.height;
}

bool Animation::GetEnd()
{
	return end;
}




