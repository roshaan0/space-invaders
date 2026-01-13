#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Graphics.hpp>
#include <array>
#include <chrono>
#include <iostream>

#include "Global.h"
#include "Enemy.h"
#include "Tween.h"
using namespace std;

Enemy::Enemy(unsigned char i_type, unsigned char i_health, unsigned short i_x, unsigned short i_y, const std::string& textPath, unsigned short KillScore, bool i_isBoss)
{
	x = 400;
	y = 0;
	targetMoveToPositionX = i_x;
	targetMoveToPositionY = i_y;
	type = i_type;
	health = i_health;
	TimerforHit = 0;
	isBoss = i_isBoss;
	texture.loadFromFile(textPath);
	sprite.setTexture(texture);
	direction = 1;
	scoreToKill = KillScore;
	shootDirection = 1;
	//setting the attack duration of the enemies based on their type
	defaultdurationforShots = 320;
	if (i_type == 0)	//alpha
	{
		defaultdurationforShots = 320;
	}
	else if (i_type == 1)	//beta
	{
		defaultdurationforShots = 192;
	}
	else if (i_type == 2)	//gamma
	{
		defaultdurationforShots = 128;
	}

	durationforShots = defaultdurationforShots;
	waitTimerforShots = 0;
	startMove = true;	
}

void Enemy::Draw(sf::RenderWindow& window)
{
	//drawing the position, texture and scale to the screen
	sprite.setPosition(x, y);
	sprite.setScale(0.5f, 0.5f);
	sprite.setTexture(texture);
	window.draw(sprite);
}

void Enemy::Update()	//to update the position of enemy 
{
	if (startMove)	//checking if the enemy has started moving 
	{
		float toReachPosX = Tween::TweenPositionX(targetMoveToPositionX, targetMoveToPositionY, sprite.getPosition().x, sprite.getPosition().y);
		float toReachPosY = Tween::TweenPositionY(targetMoveToPositionX, targetMoveToPositionY, sprite.getPosition().x, sprite.getPosition().y);
		
		//Adding the direction with speed value to increment the position
		x += (toReachPosX * BULLETSPEEDFORENEMY);
		y += (toReachPosY * BULLETSPEEDFORENEMY);

		//taking the rounded value of the distance between target sprite and bullet sprite
		lastX = round(targetMoveToPositionX - sprite.getPosition().x);
		lastY = round(targetMoveToPositionY - sprite.getPosition().y);
		//if distance between them is less than 5 then destroy the bullet (we use 5 as the distance is not always exact so we use a placeholder value or else it will stay on the screen)
		if (lastX < 5 && lastY < 5)
		{
			x = targetMoveToPositionX;
			y = targetMoveToPositionY;
			startMove = false;
		}
	}
	
	if (isBoss)	//checking if it's a boss, if so then it has its own special abilities
	{
		if (type > 12)	//type greater than 12 means monster
		{
			CanMove();	//can only move side to side	
		}
	}

	if (durationforShots > 0)	//checking to adjust the duration of shots
	{
		durationforShots--;
	}

	else
	{
		durationforShots = 0;
	}
	
	if (TimerforHit > 0)
	{
		if (TimerforHit == 1)
		{
			health = std::max(0, health - 1);
		}

		TimerforHit--;
	}
}

// CODE FOR ALL THE GETTERS OF ENEMY 
unsigned short Enemy::GetX()
{
	return x;
}

unsigned short Enemy::GetScoreToKill()
{
	return scoreToKill;
}

unsigned short Enemy::GetY()
{
	return y;
}

unsigned char Enemy::GetHealth() const
{
	return health;
}

unsigned char Enemy::GetType() const
{
	return type;
}

unsigned char Enemy::GetTimerforHit() const
{
	return TimerforHit;
}

void Enemy::GetHit()
{
	health = std::max(0, health - 1);	//health cannot go below zero
}

sf::FloatRect Enemy::GetHitBox() const
{
	return sprite.getGlobalBounds();
}

void Enemy::Shoot(std::list<Bullet>& i_bulletforEnemies, float i_x, float i_y)
{
	if (isBoss)
	{
		if (type > 9 && type < 13)	//checking to see if the boss is in the range of 10 to 12
		{
			//spawning bullets with this shoot duration and the bullets will follow the player
			i_bulletforEnemies.push_back(Bullet(i_x, i_y, x, y, "Assets/img/PNG/Lasers/laserRed08.png", 0, true, true));
			durationforShots = 22;
		}

		else if(type > 12)	//checking to see if the boss type is greater than 12 (monster)
		{
			//spawning bullets with this shoot duration
			i_bulletforEnemies.push_back(Bullet(0, BULLETSPEEDFORENEMY, x, y, "Assets/img/PNG/Lasers/laserRed12.png"));
			durationforShots = 10;
		}
	}

	else	//if it isn't boss than spawn normal bullets (for enemy and it's types)
	{
		i_bulletforEnemies.push_back(Bullet(0, BULLETSPEEDFORENEMY, x, y, "Assets/img/enemy_laser.png"));
		durationforShots = defaultdurationforShots;
	}
}

unsigned short Enemy::GetdurationforShots()
{
	return durationforShots;
}

bool Enemy::GetIsBoss()
{
	return isBoss;
}

void Enemy::DestroySelf()
{
	health = 0;
}

void Enemy::BossAbilities()
{
	if (isBoss)
	{
		if (type > 12)	//can only move side to side if it's a monster
		{
			CanMove();
		}
	}
}

void Enemy::CanMove()
{
	
	if (direction != 0)	//checking to see if the current direction is not 0
	{
		//move right
		x = std::clamp<short>(x + MOVEMENTSPEED * direction, 10, WIDTH - 20);

		if (x == 10)	//checking to see if the current direction is not 0 and the x position of enemy is left
		{
			//move right
			direction = 1;
			x = std::clamp<short>(x + MOVEMENTSPEED * direction, 10, WIDTH - 20);
		}

		else if(x == WIDTH - 20)	//checking to see if the current direction is not 0 and the x position of enemy is right
		{
			//move left
			direction = -1;
			x = std::clamp<short>(x + MOVEMENTSPEED * direction, 10, WIDTH - 20);
		}
	}
}

