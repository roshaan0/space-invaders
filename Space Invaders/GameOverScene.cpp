#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Graphics.hpp>
#include <array>
#include <chrono>
#include <random>
#include <iostream>

#include "GameOverScene.h"
#include "Button.h"
#include "Global.h"
#include "Animation.h"
#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Window\Event.hpp>
int GameOverScene::Run(sf::RenderWindow& window)
{
	//elements to be drawn
	sf::Font font;
	font.loadFromFile("ARCADECLASSIC.TTF");
	Button replaybutton("Replay", "Assets/img/PNG/UI/buttonBlue.png", 20, 1, sf::Color(0, 0, 0, 255), sf::Color(255, 255, 255, 255));
	replaybutton.SetPosition(500, 400);
	replaybutton.SetTheFont(font);
	Button quitButton("Quit To Main", "Assets/img/PNG/UI/buttonBlue.png", 20, 1, sf::Color(0, 0, 0, 255), sf::Color(255, 255, 255, 255));
	quitButton.SetPosition(100, 400);
	quitButton.SetTheFont(font);
	Button highScoresText("High Score " + std::to_string(score), "Assets/img/PNG/UI/buttonBlue.png", 20, 1, sf::Color(0, 255, 0, 255), sf::Color(255, 255, 255, 0));
	highScoresText.SetPosition(350, 200);
	highScoresText.SetTheFont(font);
	sf::Texture bgtexture;
	sf::Sprite backgroundImage;
	bgtexture.loadFromFile("Assets/img/background1.jpg");
	backgroundImage.setTexture(bgtexture);
	backgroundImage.setPosition(0, 0);
	backgroundImage.setScale(1, 1);
	backgroundImage.setColor(sf::Color(255, 255, 255, 150));
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

	Animation animation;
	animation.SetAnimation(bg, 3, 1, 0.5f);
	float deltaTime;
	sf::Clock clock;
	sf::Event event;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		while (window.pollEvent(event))	//closing the window
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				//if mouse is clicked and is on our button then button press is true
				if (replaybutton.IsMouseOver(window))
				{
					//return to game screen
					return (1);
				}
				else if (quitButton.IsMouseOver(window))
				{
					//return to Main Menu
					return (0);
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
		
		replaybutton.Draw(window);
		quitButton.Draw(window);
		highScoresText.Draw(window);
		window.display();
	}

	return(-1);
}