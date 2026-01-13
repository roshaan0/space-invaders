#include <iostream>
#include <chrono>
#include <random>
#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Graphics.hpp>

#include "EnemyManager.h"
#include "Global.h"
#include <thread>

EnemyManager::EnemyManager() :distributionforShoot(0, SHOOTCHANCEFORENEMY), timerDistributionforBoss(BOSSTIMER_MIN, BOSSTIMER_MAX)
{
    //Resetting all the values
    Reset(1, 1);
    //Getting Bullet texture
    enemyBulletTexture.loadFromFile("Assets/img/enemy_laser.png");
    enemyBulletSprite.setTexture(enemyBulletTexture);
}

std::list<Enemy>& EnemyManager::GetEnemies()
{
	return enemies;
}

std::list<Bullet>& EnemyManager::GetbulletforEnemies()
{
    return bulletforEnemies;
}

void EnemyManager::Draw(sf::RenderWindow& window, float deltaTime)
{
    //drawing all the bullets to the screen
    for (Bullet& bullet : bulletforEnemies)
    {
        bullet.DrawTheBullet(window, deltaTime);
    }

    unsigned short index = 0;
    //drawing all the enemies to the screen
    for (Enemy& enemy : enemies)
    {
        enemy.Draw(window);   
    }
}

void EnemyManager::Reset(unsigned short i_level, unsigned short i_phase)
{
    //resetting all the values to current level and phase
    unsigned char enemy_x = 0;
    unsigned char enemy_y = 0;
    isBossSpawned = false;
    std::string level_sketch = "";
    
    //clearing all the list of enemies and bullets
    enemies.clear();
    bulletforEnemies.clear();

    //finding random values
    distributionforShoot = std::uniform_int_distribution<unsigned short>(0, std::max<short>(SHOOTCHANCEFORENEMY_MIN, SHOOTCHANCEFORENEMY - SHOOTCHANCEFORENEMY_INCREASE));
    
    //random spawn timer for bosses (monster and dragon)
    spawnTimerforBoss = std::max<unsigned short>(BOSSTIMER_MIN, BOSSTIMER_MAX);
    
    //restart from level 1 if all the levels are completed
    level = i_level;
    if (TLEVELS<= i_level)
    {
        i_level = TLEVELS;
    }

    if (i_level == 3)
    {
        i_phase = rand() % (5 - 1 + 1) + 1;
    }
    
    switch (i_level)
    {
        case 1: 
        {
            switch (i_phase)
            {
                case 1:
                {
                    level_sketch = "/0/0/0/0/0/0/0/0/0/0/0/0 \n 0////////////0 \n 0///////////0 \n 0/0/0/0/0/0/0/0/0/0/0/0";
                    break;
                }

                case 2:
                {
                    level_sketch = "/1/1/1/1/1/1/1/1/1/1/1/1  \n /1/////////1 \n //1///////1// \n ///1/////1/// \n ////1///1//// \n /////1/1///// \n //////1//////";
                    break;
                }

                case 3:
                {
                    level_sketch = "/2/2/2/2/2/2/2/2/2/2/2/2 \n ///2///////// \n ////2////2//// \n /////2//2///// \n ////2////2//// \n ///2//////2/// \n /2/2/2/2/2/2/2/2/2/2/2/2";
                    break;
                }
            }

            break;
        }

        case 2:
        {
            switch (i_phase)
            {
                case 1:
                {
                    level_sketch = "/4/4/4/4/4/4/4/4/4/4/4/4 \n 4///////////4 \n 4///////////4 \n  /4/////////4/ \n //4///////4// \n  ///4/////4/// \n ////4///4//// \n /////4/4/////";
                    break;
                }
                case 2:
                {
                    level_sketch = "//5/////////5// \n 5///5/////5///5/ \n 5///5/////5///5/ \n /5///5///5///5// \n //5///5/5///5/// \n ///5/////5//// \n ////5///5///// \n /////5/5//////";
                    break;
                }
                case 3:
                {
                    level_sketch = "/6/6/6/6/6/6/6/6/6/6/6/6 \n 6///////////6 \n 6///////////6 \n  /6/////////6/ \n //6///////6// \n  ///6/////6/// \n ////6///6//// \n /////6/6/////";
                    break;
                }
            }

            break;
        }
        case 3:
        {
            switch (i_phase)
            {
                case 1:
                {
                    level_sketch = "/7/7/7/7/7/7/7/7/7/7/7/7 \n 7/7/7/7/7/7/7/7/7/7/7/7/7 \n 7/7/7/7/7/7/7/7/7/7/7/7 \n 7/7/7/7/7/7/7/7/7/7/7/7";
                    break;
                }

                case 2:
                {
                    level_sketch = "/8/8/8/8/8/8/8/8/8/8/8/8  \n /8/8/8/8/8/8/8/8/8/8 \n //8/8/8/8/8/8/8/8// \n ///8/8/8/8/8/8/// \n ////8/8/8/8//// \n /////8/8///// \n //////1//////";
                    break;
                }

                case 3:
                {
                    level_sketch = "/9/9/9/9/9/9/9/9/9/9/9/9 \n ///9/9/9/9/9/9/9/// \n ////9/9/9/9/9//// \n /////9/9/9///// \n ////9/9/9/9/9//// \n ///9/9/9/9/9/9/9/// \n /9/9/9/9/9/9/9/9/9/9/9/9";
                    break;
                }

                case 4:
                {
                    level_sketch = "/9/9/9/9/9/9/9/9/9/9/9/9 \n 9/9/9/9/9/9/9/9/9/9/9/9 \n 9/9/9/9/9/9/9/9/9/9/9/9 \n  /9/9/9/9/9/9/9/9/9/9/ \n //9/9/9/9/9/9/9/9// \n  ///9/9/9/9/9/9/// \n ////9/9/9/9//// \n /////9/9/////";
                    break;
                }

                case 5:
                {
                    level_sketch = "//9/////////9// \n 9/9/9/9/////9/9/9/9/ \n 9/9/9/9/////9/9/9/9/ \n /9/9/9/9///9/9/9/9// \n //9/9/9/9/9/9/9/9/// \n ///9/9/9/9/9/9//// \n ////9/9/9/9///// \n /////9/9//////";
                    break;
                }
            }

            break;
        }
    }

    //spawing the enemies with (aslight) delay
    std::thread t(&EnemyManager::SpawnDelayEnemies, this, level_sketch);
    //makes this run seperately from the main thread
    t.detach();
}

void EnemyManager::Update(std::mt19937_64& i_random_engine, float i_x, float i_y)
{
    //random intervals for spawning the boss
    SpawnBoss();
    std::list<Enemy>::iterator deadEnemies;

    for (Enemy& enemy : enemies)
    {
        //updating all the enemies in the liste
        enemy.Update();
        if (isBossSpawned)  //checking to see if the boss is spawned
        {
            //destroying all the other enemies
            if (!enemy.GetIsBoss())
            {
                enemy.DestroySelf();
            }
        }

        if (enemy.GetdurationforShots() == 0)
        {
            enemy.Shoot(bulletforEnemies, i_x, i_y);
        }
    }

    //if health = 0, then redraw all the enemies
    deadEnemies = std::remove_if(enemies.begin(), enemies.end(), [](const Enemy& enemy){return enemy.GetHealth() == 0;});
    enemies.erase(deadEnemies, enemies.end());

    for (Bullet& enemy_bullet : bulletforEnemies)   //updating all the bullets in the list
    {
        enemy_bullet.Update();
    }

    bulletforEnemies.erase(remove_if(bulletforEnemies.begin(), bulletforEnemies.end(), [](const Bullet& i_bullet)
        {
            return i_bullet.dead;
        }), bulletforEnemies.end());
}

void EnemyManager::SpawnBoss()
{
    if (!isBossSpawned) //checking to see if a boss has been spawned
    {
        //if the timer reaches 0 the spawn the boss
        if (spawnTimerforBoss == 0)
        {
            isBossSpawned = true;
            int randomBoss = rand() % (14 - 10 + 1) + 10;
            enemies.push_back(Enemy(randomBoss, 20 + level, 400, 100, "Assets/img/PNG/Enemies/enemy" + std::to_string(static_cast<int>(randomBoss)) + ".png", 50, true));
        }

        else    //decreases the time to spawn the boss
        {
            spawnTimerforBoss--;
        }
    }
}

void EnemyManager::SpawnDelayEnemies(std::string level_sketch)
{
    unsigned char enemy_x = 2;
    unsigned char enemy_y = 2;

    //running through the characters in the string
    for (char sketchCharacter : level_sketch)
    {
        //creating a slight delay
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        switch (sketchCharacter)
        {
        case '*':
            enemy_y++;
            break;

        case '/':
            enemy_x++;
            break;

        case '\n':
            enemy_x = 3;
            enemy_y++;
            break;

        //cases with number are the type of enemies to be spawned
        case '0':
            enemies.push_back(Enemy(0, 1, 50 * enemy_x, enemy_y * 40, "Assets/img/PNG/Enemies/enemy1.png", 10));
            break;
    
        case '1':
            enemies.push_back(Enemy(1, 1, 50 * enemy_x, enemy_y * 40, "Assets/img/PNG/Enemies/enemy1.png", 10));
            break;

        case '2':
            enemies.push_back(Enemy(2, 1, 50 * enemy_x, enemy_y * 40, "Assets/img/PNG/Enemies/enemy2.png", 20));
            break;
        
        case '3':
            enemies.push_back(Enemy(3, 1, 50 * enemy_x, enemy_y * 40, "Assets/img/PNG/Enemies/enemy3.png", 30));
            break;
        
        case '4':
            enemies.push_back(Enemy(4, 2, 50 * enemy_x, enemy_y * 40, "Assets/img/PNG/Enemies/enemy4.png", 10));
            break;
    
        case '5':
            enemies.push_back(Enemy(5, 2, 50 * enemy_x, enemy_y * 40, "Assets/img/PNG/Enemies/enemy5.png", 20));
            break;
        
        case '6':
            enemies.push_back(Enemy(6, 2, 50 * enemy_x, enemy_y * 40, "Assets/img/PNG/Enemies/enemy6.png", 30));
            break;
        
        case '7':
            enemies.push_back(Enemy(7, 3, 50 * enemy_x, enemy_y * 40, "Assets/img/PNG/Enemies/enemy7.png", 10));
            break;
        
        case '8':
            enemies.push_back(Enemy(8, 4, 50 * enemy_x, enemy_y * 40, "Assets/img/PNG/Enemies/enemy8.png", 20));
            break;
        
        case '9':
            enemies.push_back(Enemy(9, 5, 50 * enemy_x, enemy_y * 40, "Assets/img/PNG/Enemies/enemy9.png", 30));
            break;
        }
    }
}

std::string EnemyManager::DifficultyGenerator()
{
    std::string level = "\n";
    int randomEnemy = 0;

    for (int i = 0; i < 10; i++)
    {
        randomEnemy = rand() % (ENEMYTYPES - 0 + 1) + 0;
        level += " " + std::to_string(randomEnemy);

        if ((i + 1) % 5 == 0)
        {
            level += "\n";
        }
    }
    
    std::cout << level << std::endl;
    return level;;
}




