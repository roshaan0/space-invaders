#pragma once
#include "Bullet.h"
#include <list>

class Enemy
{
	sf::Texture texture;
	sf::Sprite sprite;
	unsigned short x;	//bound along x axis
	unsigned short y;	//bound along y axis
	unsigned char health;	//health bar for the enemy
	unsigned char TimerforHit;	//how many times it has been hit
	char direction;	//placement for the enemy
	bool dead;	//determines if the enemy is dead or not
	unsigned short durationforShots;	//duration of shots fired
	unsigned short waitTimerforShots;	//wait timer
	unsigned short defaultdurationforShots;	//default duration for shots
	unsigned char type;	//enemy type
	bool isBoss;
	char shootDirection;	//direction of the shot
	unsigned short scoreToKill;
	unsigned short index;
	float targetMoveToPositionX;
	float targetMoveToPositionY;
	short lastX;
	short lastY;
	bool startMove;
	unsigned short bossTimer;

public:
	Enemy(unsigned char i_type, unsigned char i_health, unsigned short i_x, unsigned short i_y, const std::string& textPath, unsigned short KillScore, bool isBoss = false);
	void Draw(sf::RenderWindow& window);
	void Update();
	void Shoot(std::list<Bullet>& enemies_bullets, float x, float y);
	unsigned short GetX();
	unsigned short GetY();
	unsigned short GetScoreToKill();	//returns the score for killing a certain type enemy
	sf::FloatRect GetHitBox() const;	//returns the hit box of the sprite
	unsigned char GetHealth() const;
	unsigned char GetTimerforHit() const;
	unsigned char GetType() const;
	void GetHit();
	float width;
	float height;
	unsigned short GetdurationforShots();
	bool GetIsBoss();
	void DestroySelf();
	void BossAbilities();
	void CanMove(); 
};