#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Graphics.hpp>
#include <random>
#include <array>
#include <list>
#include <chrono>
#include "Global.h"
#include "PowerUpManager.h"

PowerUpManager::PowerUpManager(std::mt19937_64& i_random_engine) : powerup_distribution(0, ADDONTYPES - 1), timer_distribution(ADDONTIMER_MIN, ADDONTIMER)
{
	y = 0;
	direction = 1;
	Reset(0, i_random_engine);
	
}

sf::FloatRect PowerUpManager::GetHitBox() const
{
	return sf::FloatRect(x, y, 100, 100);
}

void PowerUpManager::Draw(sf::RenderWindow& window)
{
	//drawing all the power ups on screen
	for (Powerup& power : powerUps)
	{
		power.Draw(window);
	}
}

void PowerUpManager::Update(std::mt19937_64& i_random_engine)
{
	if (0 == timer)	//checking if the random timer is 0
	{
		//spawn a power at a random location on the screen
		x = rand() % (WIDTH - 10 + 1) + 10;
		powerUps.push_back(Powerup(x, y, powerup_distribution(i_random_engine)));
		//resetting 
		Reset(0, i_random_engine);
	}

	else
	{
		timer--;
	}

	for (Powerup& power : powerUps)
	{
		power.y += SPEEDADDON;

		if (power.y >= HEIGHT)
		{
			power.dead = 1;
		}
	}

	powerUps.erase(std::remove_if(powerUps.begin(), powerUps.end(), [](const Powerup& i_powerup)
		{
			return i_powerup.dead;
		}), powerUps.end());
}

void PowerUpManager::Reset(bool isDead, std::mt19937_64& i_random_engine)
{
	//resetting the timer to a random value
	timer = timer_distribution(i_random_engine);
}

unsigned char PowerUpManager::CheckPowerupCollision(const sf::FloatRect& playerHitBox)
{
	//if power up is collided with player, it is cancelled 
	for (Powerup& powerup : powerUps)
	{
		if (powerup.dead == false && powerup.GetHitBox().intersects(playerHitBox))
		{
			powerup.dead = true;
			return 1 + powerup.type;
		}
	}
	return 0;
}

unsigned short PowerUpManager::GetPowerDuration(unsigned char type)
{
	//getting the duration of a particular power up
	for (Powerup& powerup : powerUps)
	{
		if (powerup.type == type)
		{
			return powerup.powerDuration;
		}
	}
	return 0;
}