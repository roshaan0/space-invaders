#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Graphics.hpp>
#include <array>
#include <chrono>
#include <random>
#include <iostream>
#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Window\Event.hpp>
#include "PauseScreen.h"
#include "Button.h"
#include "Global.h"

int PauseScreen::Run(sf::RenderWindow& window)
{
	sf::Font font;
	font.loadFromFile("ARCADECLASSIC.TTF");
	Button continuebutton("Continue", "Assets/img/PNG/UI/buttonBlue.png", 20, 1, sf::Color(0, 0, 0, 255), sf::Color(255, 255, 255, 255));
	continuebutton.SetPosition(500, 400);
	continuebutton.SetTheFont(font);

	Button quitButton("Quit To Main", "Assets/img/PNG/UI/buttonBlue.png", 20, 1, sf::Color(0, 0, 0, 255), sf::Color(255, 255, 255, 255));
	quitButton.SetPosition(100, 400);
	quitButton.SetTheFont(font);

	Button highScoresText("Score " + std::to_string(score), "Assets/img/PNG/UI/buttonBlue.png", 20, 1, sf::Color(0, 255, 0, 255), sf::Color(255, 255, 255, 0));
	highScoresText.SetPosition(350, 200);
	highScoresText.SetTheFont(font);

	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (continuebutton.IsMouseOver(window))
				{
					pause = false;
					return (1);
				}

				else if (quitButton.IsMouseOver(window))
				{
					pause = false;
					return (0);
				}
			}
		}
		
		window.clear();
		continuebutton.Draw(window);
		quitButton.Draw(window);
		highScoresText.Draw(window);
		window.display();
	}

	return(-1);
}