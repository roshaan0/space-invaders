#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include/SFML\Graphics.hpp>
#include <array>
#include <list>
#include <chrono>
#include <random>
#include <fstream>
#include <iostream>
#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Window\Event.hpp>

#include "HighScoreScene.h"
#include "Button.h"
#include "Global.h"
#include "PlayerData.h"
#include "Animation.h"

void HighScoreScene::LoadHighScores() {
    std::ifstream inFile("highscores.txt");
    if (!inFile) {
        std::cerr << "Unable to open high scores file for reading!" << std::endl;
        return;
    }
    
    highScores.clear();
    int score;
    while (inFile >> score) {
        highScores.push_back(score);
    }
    inFile.close();

    std::cout << "Loaded " << highScores.size() << " high scores." << std::endl;
    for (const auto& score : highScores) {
        std::cout << "Score: " << score << std::endl;
    }
}

void HighScoreScene::SaveHighScores() {
    std::ofstream outFile("highscores.txt");
    if (!outFile) {
        std::cerr << "Unable to open high scores file for writing!" << std::endl;
        return;
    }
    
    for (const auto& score : highScores) {
        outFile << score << std::endl;
        std::cout << "Saving score: " << score << std::endl; // Debug output
    }
    outFile.close();
}

int HighScoreScene::Run(sf::RenderWindow& window)
{
    sf::Font font;
    if (!font.loadFromFile("ARCADECLASSIC.TTF")) {
        std::cerr << "Error loading font!" << std::endl;
        return -1;
    }

    sf::Sprite spriteList[10];
    sf::Texture textureList[10];
    Button buttonsList[10];

    LoadHighScores();

    for (int i = 0; i < 10 && i < highScores.size(); i++)
    {
        sf::Texture texture;
        texture.loadFromFile("Assets/img/PNG/UI/numeral" + std::to_string(i) + ".png");
        textureList[i] = texture;
        
        sf::Sprite sprite;
        sprite.setTexture(texture);
        
        Button button(std::to_string(highScores[i]), "Assets/img/PNG/UI/buttonBlue.png", 20, 0.5, sf::Color(255, 255, 255, 255), sf::Color(255, 255, 255, 0));
        buttonsList[i] = button;
        buttonsList[i].SetTheFont(font);
        
        spriteList[i] = sprite;
    }

    sf::Texture bgtexture;
    sf::Sprite backgroundImage;
    bgtexture.loadFromFile("Assets/img/background1.jpg");
    backgroundImage.setTexture(bgtexture);
    backgroundImage.setPosition(0, 0);
    backgroundImage.setScale(1, 1);
    backgroundImage.setColor(sf::Color(255, 255, 255, 150));
    
    Button backbutton("Back", "Assets/img/PNG/UI/buttonBlue.png", 20, 0.5, sf::Color(0, 0, 0, 255), sf::Color(255, 255, 255, 255));
    backbutton.SetPosition(20, 10);
    backbutton.SetTheFont(font);
    backbutton.SetTextPosition(25, 5);
    
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
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (backbutton.IsMouseOver(window))
                {
                    pause = false;
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

        backbutton.Draw(window);

        for (int i = 0; i < 10 && i < highScores.size(); i++)
        {
            spriteList[i].setTexture(textureList[i]);
            spriteList[i].setPosition(100, 50 * (i + 1));
            buttonsList[i].SetPosition(200, 49 * (i + 1));
            buttonsList[i].SetTextPosition(200, 50 * (i + 1));
            buttonsList[i].Draw(window);
            window.draw(spriteList[i]);
        }
        
        window.display();
    }

    return -1;
}
