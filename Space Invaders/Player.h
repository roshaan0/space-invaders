#pragma once
#include "Bullet.h"
#include "Explosion.h"
#include "Enemy.h"
#include "PowerUpManager.h"
#include <list>

class Player
{
	std::list<Bullet> bullets; 
	std::list<Explosion> explosions;
	sf::Texture texture;
	sf::Texture bulletTexture;
	sf::Texture bulletFireTexture;
	sf::Texture bulletPowerTexture;
	sf::Texture explosionTexture;
	sf::Sprite bulletSprite;
	sf::Sprite sprite;
	sf::Sprite explosionSprite;
	bool isDead;
	bool animationOver;
	unsigned char cPower;
	unsigned char reloadTimer;
	unsigned short x;
	unsigned short y;
	unsigned short score;
	unsigned char health;
	unsigned short powerTimer;
	unsigned char hitTimer;
	unsigned short explosionX;
	unsigned short explosionY;
	Animation animation;
	
public:
	Player();
	bool GetisDead() const;
	bool GetAnimationOver() const;
	unsigned char GetcPower() const;
	unsigned short GetX() const;
	unsigned short GetY() const;
	unsigned short GetScore() const;
	void Die();
	void Draw(sf::RenderWindow& window, float deltaTime);
	void Reset();
	void Update(std::mt19937_64& random_engine, std::list<Enemy>& i_enemies, std::list<Bullet>& enemy_bullets, PowerUpManager& powerupManager, unsigned short level);
	sf::FloatRect GetHitBox() const;
	unsigned char GetHealth();
	void Damage();
	void IncreaseHealth();
	unsigned short GetPowerTimer() const;
	float GetFloatPositionX();
	float GetFloatPositionY();
};