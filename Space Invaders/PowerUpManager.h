#pragma once
#include "Animation.h"
#include "Powerup.h"
class PowerUpManager
{
	char direction;
	short x;
	unsigned short timer;
	unsigned short y;
	std::uniform_int_distribution<unsigned short> powerup_distribution;
	std::uniform_int_distribution<unsigned short> timer_distribution;
	std::list<Animation> powerUpAnimation;
	std::list<Powerup> powerUps;
	
public:
	PowerUpManager(std::mt19937_64& i_random_engine);
	void Update(std::mt19937_64& i_random_engine);
	void Draw(sf::RenderWindow& window);
	sf::FloatRect GetHitBox() const;
	unsigned char CheckPowerupCollision(const sf::FloatRect& i_player_hitbox);
	void Reset(bool isDead, std::mt19937_64& i_random_engine);
	unsigned short GetPowerDuration(unsigned char type);
};