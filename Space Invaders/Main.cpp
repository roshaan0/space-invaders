#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Graphics.hpp>
#include <array>
#include <chrono>
#include <random>

#include "Player.h"
#include "Global.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Powerup.h"
#include "Animation.h"
#include "PowerUpManager.h"
#include "EnemyManager.h"
#include "GameScene.h"
#include "MainMenu.h"
#include "GameOverScene.h"
#include "PauseScreen.h"
#include "HighScoreScene.h"
#include "Screen.h"
int main()
{
    int screen = 0;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Space Invaders");
    window.setVerticalSyncEnabled(true);

    //creating all the scenes
    GameScene game_Scene;
    MainMenu menu_Scene;
    GameOverScene gameOverScene;
    PauseScreen pause_Screen;
    HighScoreScene highScoreScreen;
    Screen* Screens[4] = { &menu_Scene, &game_Scene, &gameOverScene, &highScoreScreen};
    
    while (screen >= 0)
    {  
        screen = Screens[screen]->Run(window);
    }
    
    return EXIT_SUCCESS;
}