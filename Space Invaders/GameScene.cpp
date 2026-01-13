#include <iostream>
#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Graphics.hpp>
#include <array>
#include <chrono>
#include <random>
#include <fstream>
#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Window.hpp>
#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Window\Event.hpp>
#include "Player.h"
#include "Global.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Powerup.h"
#include "Animation.h"
#include "PowerUpManager.h"
#include "EnemyManager.h"
#include "GameScene.h"
#include "Button.h"
#include "ParallaxBackground.h"
#include "PlayerData.h"
#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Window\Keyboard.hpp>
#include <algorithm>
#include <vector>
#include <string>

unsigned short score;
bool pause = false;

GameScene::GameScene(void)
{
    isPlaying = false;
}

int GameScene::Run(sf::RenderWindow& window)
{
    bool gameOver = false;
    bool nextLevel = false;
    unsigned short level = 1;
    unsigned short phase = 1;
    unsigned short nextLevelTimer = TRANSITION;
    //creating a randomiser engine
    std::mt19937_64 randomEngine(std::chrono::system_clock::now().time_since_epoch().count());
    //creating a clock for making the frame rate independent
    std::chrono::microseconds lag(0);
    std::chrono::steady_clock::time_point previousTime;
    PlayerData playerData;
    sf::Texture fontTexture;
    fontTexture.loadFromFile("Assets/img/Font/Font.png");
    sf::Texture powerUpBar;
    powerUpBar.loadFromFile("Assets/img/PNG/UI/PowerupBar.png");
    sf::Texture background_texture;
    background_texture.loadFromFile("Assets/img/background1.jpg");
    sf::Event event;
    Player player;
    EnemyManager enemyManager;
    PowerUpManager powerupManager(randomEngine);
    previousTime = std::chrono::steady_clock::now();
    sf::Sprite powerUpBarSprite;
    powerUpBarSprite.setTexture(powerUpBar);
    sf::Sprite background_sprite;
    background_sprite.setTexture(background_texture);
    sf::Font font;
    font.loadFromFile("ARCADECLASSIC.TTF");
    Button pauseButton("Pause", "Assets/img/PNG/UI/buttonBlue.png", 20, 0.5f, sf::Color(255, 0, 0, 255), sf::Color(255, 255, 255, 255));
    pauseButton.SetTheFont(font);
    pauseButton.SetPosition(50, 10);
    pauseButton.SetTextPosition(75, 5);
    Button scoreText("", "Assets/img/PNG/UI/buttonBlue.png", 20, 1, sf::Color(255, 255, 255, 255), sf::Color(255, 255, 255, 0));
    scoreText.SetTheFont(font);
    scoreText.SetPosition(100, 50);
    sf::Texture bgtexture;
    sf::Sprite backgroundImage;
    bgtexture.loadFromFile("Assets/img/background1.jpg");
    backgroundImage.setTexture(bgtexture);
    backgroundImage.setPosition(0, 0);
    backgroundImage.setScale(1, 1);
    backgroundImage.setColor(sf::Color(255, 255, 255, 150));
    //moving the background
    ParallaxBackground pBg1(0, MOVESPEED, 0, 0);
    ParallaxBackground pBg2(0, MOVESPEED, 0, -HEIGHT);
    Button healthText("", "Assets/img/PNG/UI/buttonBlue.png", 20, 1, sf::Color(0, 255, 0, 255), sf::Color(255, 255, 255, 0));
    healthText.SetTheFont(font);
    healthText.SetPosition(700, 50);
    Button phaseText("", "Assets/img/PNG/UI/buttonBlue.png", 30, 1, sf::Color(255, 255, 255, 255), sf::Color(255, 255, 255, 0));
    phaseText.SetTheFont(font);
    phaseText.SetPosition(400, 100);
    phaseText.SetTextPosition(400, 30);
    Button levelText("", "Assets/img/PNG/UI/buttonBlue.png", 40, 1, sf::Color(0, 0, 255, 255), sf::Color(255, 255, 255, 0));
    levelText.SetTheFont(font);
    levelText.SetPosition(400, 50);
    levelText.SetTextPosition(400, -10);
    Button nextLevelText("Next Level", "Assets/img/PNG/UI/buttonBlue.png", 50, 1, sf::Color(255, 0, 0, 255), sf::Color(255, 255, 255, 0));
    nextLevelText.SetTheFont(font);
    nextLevelText.SetPosition(800 / 2, 600 / 2);
    Button gameOverText("Game Over", "Assets/img/PNG/UI/buttonBlue.png", 50, 1, sf::Color(255, 0, 0, 255), sf::Color(255, 255, 255, 0));
    gameOverText.SetTheFont(font);
    gameOverText.SetPosition(800 / 2, 600 / 2);
    Button continuebutton("Continue", "Assets/img/PNG/UI/buttonBlue.png", 20, 1, sf::Color(0, 0, 0, 255), sf::Color(255, 255, 255, 255));
    continuebutton.SetPosition(500, 400);
    continuebutton.SetTheFont(font);
    Button quitButton("Quit To Main", "Assets/img/PNG/UI/buttonBlue.png", 20, 1, sf::Color(0, 0, 0, 255), sf::Color(255, 255, 255, 255));
    quitButton.SetPosition(100, 400);
    quitButton.SetTheFont(font);
    Button highScoresText("Score " + std::to_string(score), "Assets/img/PNG/UI/buttonBlue.png", 40, 1, sf::Color(0, 255, 0, 255), sf::Color(255, 255, 255, 0));
    highScoresText.SetPosition(350, 200);
    highScoresText.SetTheFont(font);
    float deltaTimeAnim;
    sf::Clock clock;

    while (window.isOpen())
    {
        std::chrono::microseconds deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previousTime);
        lag += deltaTime;
        previousTime += deltaTime;
        while (lag >= FRAME_DURATION)
        {
            deltaTimeAnim = clock.restart().asSeconds();
            lag -= FRAME_DURATION;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                if (event.type == sf::Event::MouseButtonPressed)    //checking to see if pause is pressed
                {
                    //pause the game
                    if (pauseButton.IsMouseOver(window))
                    {
                        pause = true;

                    }

                    else if (continuebutton.IsMouseOver(window))
                    {
                        pause = false;

                    }

                    else if (quitButton.IsMouseOver(window))
                    {
                        pause = false;
                        return (0);
                    }
                }
            }

            if (!pause) //checking is the pause is not pressed
            {
                //play the game

                if (player.GetHealth() == 0)    //checking if the player health is 0 for game over
                {
                    gameOver = true;
                }

                if (!gameOver)  //checking to see if game is still being player
                {
                    //destroying all the and going to next level
                    if (enemyManager.GetEnemies().size() == 0)
                    {
                        if (nextLevelTimer == 0)
                        {
                            nextLevel = false;
                            phase++;

                            if (phase == 4)
                            {
                                level++;
                                phase = 1;
                            }

                            nextLevelTimer = TRANSITION;
                            player.Reset();
                            enemyManager.Reset(level, phase);
                            powerupManager.Reset(1, randomEngine);
                        }

                        else
                        {
                            nextLevel = true;
                            nextLevelTimer--;
                        }

                    }

                    else
                    {
                        nextLevel = false;
                        //updating the players and managers
                        player.Update(randomEngine, enemyManager.GetEnemies(), enemyManager.GetbulletforEnemies(), powerupManager, level);
                        enemyManager.Update(randomEngine, player.GetFloatPositionX(), player.GetFloatPositionY());
                        powerupManager.Update(randomEngine);
                        //updating the backgrounds
                        pBg1.Update();
                        pBg2.Update();
                    }
                }

                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    //resetting all the values
                    gameOver = false;
                    level = 1;
                    phase = 1;
                    player.Reset();
                    enemyManager.Reset(level, phase);
                    powerupManager.Reset(1, randomEngine);
                }

                if (lag < FRAME_DURATION)
                {
                    window.clear();
                    //drawing the backgrounds
                    pBg1.Draw(window);
                    pBg2.Draw(window);

                    if (!player.GetisDead())  //checking if the player is not dead
                    {
                        //drawing everything to the screen
                        enemyManager.Draw(window, deltaTimeAnim);
                        powerupManager.Draw(window);

                        if (player.GetcPower() > 0)
                        {
                            powerUpBarSprite.setPosition(WIDTH - 100, 100);
                            powerUpBarSprite.setScale(player.GetPowerTimer() / ADDONTIMER, 1);
                            window.draw(powerUpBarSprite);
                        }
                    }

                    player.Draw(window, deltaTimeAnim);
                    levelText.ChangeTheText("Level " + std::to_string(level));
                    scoreText.ChangeTheText("Score " + std::to_string(player.GetScore()));
                    phaseText.ChangeTheText("Phase " + std::to_string(phase));
                    healthText.ChangeTheText("Health   " + std::to_string(player.GetHealth()));

                    if (gameOver)   //checking if the game is over
                    {
                        //saving the score and going to the next screen
                        score = player.GetScore();
                        playerData.highScore = score;
                        playerData.playerName = "abnc";
                        std::ofstream out;
                        out.open("data.txt", std::ios::app);
                        out.write((char*)&playerData, sizeof(playerData));
                        out.close();

                        // Save the high score to a text file
                        std::ofstream highScoreFile("highscores.txt", std::ios::app);
                        highScoreFile << score << "\n";
                        highScoreFile.close();

                        // Read all scores from the file
                        std::ifstream inFile("highscores.txt");
                        std::vector<int> highScores;
                        int s;
                        while (inFile >> s)
                        {
                            highScores.push_back(s);
                        }
                        inFile.close();

                        // Sort the scores and keep the top 10
                        std::sort(highScores.rbegin(), highScores.rend());
                        if (highScores.size() > 10)
                        {
                            highScores.resize(10);
                        }

                        // Write the top 10 scores back to the file
                        std::ofstream outFile("highscores.txt");
                        for (const int& hs : highScores)
                        {
                            outFile << hs << "\n";
                        }
                        outFile.close();

                        gameOverText.Draw(window);
                        return (2);
                    }

                    else if (nextLevel)
                    {
                        nextLevelText.ChangeTheText("Next Level");
                        nextLevelText.Draw(window);
                    }

                    levelText.Draw(window);
                    phaseText.Draw(window);
                    healthText.Draw(window);
                    scoreText.Draw(window);
                    pauseButton.Draw(window);
                    window.display();
                }
            }

            else    //checking if the pause button is clicked
            {
                //these UI will be drawn to the screen
                window.clear();
                window.draw(backgroundImage);
                continuebutton.Draw(window);
                quitButton.Draw(window);
                highScoresText.Draw(window);
                highScoresText.ChangeTheText("Score " + std::to_string(player.GetScore()));
                window.display();
            }
        }
    }

    return (-1);
}
