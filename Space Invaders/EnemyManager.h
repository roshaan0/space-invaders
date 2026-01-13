#pragma once
#include "Enemy.h"
#include "Animation.h"
#include "Bullet.h"
#include <list> 

class EnemyManager
{
	std::uniform_int_distribution<unsigned short> distributionforShoot;
	std::uniform_int_distribution<unsigned short> timerDistributionforBoss;
	std::list<Enemy> enemies;
	std::list<Animation> animations;
	std::list<Bullet> bulletforEnemies;
	sf::Sprite enemyBulletSprite;
	sf::Texture enemyBulletTexture;
	unsigned short spawnTimerforBoss;
	bool isBossSpawned;
	unsigned short level;
	
public:
	EnemyManager();
	void Draw(sf::RenderWindow& window, float delatTime);
	std::list<Enemy>& GetEnemies();
	std::list<Bullet>& GetbulletforEnemies();
	void Reset(unsigned short i_level, unsigned short i_phase);
	void Update(std::mt19937_64& i_random_engine, float x, float y);
	void SpawnBoss();
	void SpawnDelayEnemies(std::string level_sketch);
	std::string DifficultyGenerator();
};