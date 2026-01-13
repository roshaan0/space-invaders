#include <iostream>
#include<C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Graphics.hpp>

#include "Button.h"
#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Window\Mouse.hpp>

Button::Button(const std::string& t, const std::string& textureLocation, int charSize, float size, sf::Color textColor, sf::Color buttonColor)
{
	//loading the texture from file path
	texture.loadFromFile(textureLocation);
	//filling the text color
	text.setFillColor(textColor);
	//giving the text a string value
	text.setString(t);
	
	//setting the scale of the sprite
	sprite.setScale(size, size);
	//setting the character size
	text.setCharacterSize(charSize);
	//set the sprite color
	sprite.setColor(buttonColor);
}

void Button::SetTheFont(sf::Font& font)
{
	//changing font of text
	text.setFont(font);
}

void Button::ChangeBackTextColor(sf::Color color)
{
	//changing color of text
	sprite.setColor(color);
}

void Button::ChangeTextColor(sf::Color color)
{
	//changing the text color
	text.setFillColor(color);
}

void Button::ChangeTheText(const std::string& t)
{
	//changing the text
	text.setString(t);
}

void Button::SetPosition(float x, float y)
{
	//setting the position of the sprite using its width (x) and height (y)
	sprite.setPosition(x + sprite.getLocalBounds().width / 2, y + sprite.getLocalBounds().height / 2);
	float xPos = (x + sprite.getLocalBounds().width / 2) - text.getLocalBounds().width / 2;
	float yPos = (y + sprite.getLocalBounds().height / 2) - text.getLocalBounds().height / 2;
	
	//setting the text relative to the sprite
	text.setPosition(xPos, yPos);
}

void Button::SetTextPosition(float x, float y)
{
	//setting the position of the text
	text.setPosition(x, y);
}

void Button::Draw(sf::RenderWindow& window)
{
	//setting texture and draws to the screen
	sprite.setTexture(texture);
	window.draw(sprite);
	window.draw(text);
}

bool Button::IsMouseOver(sf::RenderWindow& window)
{
	//checking if the position of mouse is over the sprite
	float mousePositionX = sf::Mouse::getPosition(window).x;
	float mousePositionY = sf::Mouse::getPosition(window).y;

	float buttonPosX = sprite.getPosition().x;
	float buttonPosY = sprite.getPosition().y;

	float buttonWidth = sprite.getPosition().x + sprite.getLocalBounds().width;
	float buttonHeight = sprite.getPosition().y + sprite.getLocalBounds().height;

	//if mouse hovers over the button, then return true else false
	if (mousePositionX < buttonWidth && mousePositionX > buttonPosX && mousePositionY < buttonHeight && mousePositionY > buttonPosY)
	{
		return true;
	}

	return false;
}