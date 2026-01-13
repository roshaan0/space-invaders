#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Graphics.hpp>
#include <iostream>
#include <array>
#include <chrono>
#include "MainMenu.h"
#include "Button.h"
#include "Animation.h"
#include "Global.h"
#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Window\Event.hpp>

int MainMenu::Run(sf::RenderWindow& window)
{
	sf::Font font;
	font.loadFromFile("ARCADECLASSIC.TTF");
	sf::Texture bg;
	bg.loadFromFile("Assets/img/PNG/Effects/spritesheet.png");
	sf::Sprite bgSpriteList[10];

	for (int i = 0; i < 10; i++)
	{
		sf::Sprite bgSprite;
		bgSprite.setTexture(bg);
		bgSprite.setScale(1, 1);
		bgSprite.setPosition(rand() % (WIDTH - 0 + 1) + 0, rand() % (HEIGHT - 0 + 1) + 0);
		bgSpriteList[i] = bgSprite;
	}

	sf::Texture bgtexture;
	sf::Sprite backgroundImage;
	bgtexture.loadFromFile("Assets/img/background1.jpg");
	backgroundImage.setTexture(bgtexture);
	backgroundImage.setPosition(0, 0);
	backgroundImage.setScale(1, 1);
	backgroundImage.setColor(sf::Color(255, 255, 255, 150));
	Button playbutton("Play", "Assets/img/PNG/UI/buttonBlue.png", 20, 1, sf::Color(0, 0, 0, 255), sf::Color(255, 255, 255, 255));
	playbutton.SetPosition(300, 400);
	playbutton.SetTheFont(font);

	Button titleText("SPACE INVADERS", "Assets/img/PNG/UI/buttonBlue.png", 75, 1, sf::Color(255, 255, 255, 255), sf::Color(255, 255, 255, 0));
	titleText.SetPosition(125, 200);
	titleText.SetTheFont(font);

	Button highScoresButton("High Scores", "Assets/img/PNG/UI/buttonBlue.png", 20, 1, sf::Color(0, 0, 0, 255), sf::Color(255, 255, 255, 255));
	highScoresButton.SetPosition(300, 500);
	highScoresButton.SetTheFont(font);

	Animation animation;
	animation.SetAnimation(bg, 3, 1, 0.5f);
	float deltaTime;
	sf::Clock clock;
	sf::Event event;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (playbutton.IsMouseOver(window))
				{
					return (1);
				}
				else if (highScoresButton.IsMouseOver(window))
				{
					return (3);
				}
			}
		}

		animation.Update(0, deltaTime);
		window.clear();
		window.draw(backgroundImage);

		for (int i = 0; i < 10; i++)
		{
			bgSpriteList[i].setTextureRect(animation.uvRect);
			window.draw(bgSpriteList[i]);
		}

		playbutton.Draw(window);
		highScoresButton.Draw(window);
		titleText.Draw(window);
		window.display();
	}


	return(-1);
}