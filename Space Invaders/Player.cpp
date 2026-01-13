#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Graphics.hpp>
#include <array>
#include <chrono>
#include <random>
#include <iostream>
#include <C:\Users\rosha\OneDrive\Desktop\Space Invaders\Space Invaders\Space Invaders\External Dependencies\SFML-2.5.1\include\SFML\Window\Keyboard.hpp>
#include "Player.h"
#include "Global.h"
#include "Powerup.h"
#include "Tween.h"
#include "Animation.h"

Player::Player()
{
	//Resetting all the values
	Reset();
	texture.loadFromFile("Assets/img/player_ship.png");
	sprite.setTexture(texture);

	bulletTexture.loadFromFile("Assets/img/PNG/Lasers/laserBlue01.png");
	bulletSprite.setTexture(bulletTexture);

	bulletFireTexture.loadFromFile("Assets/img/PNG/Effects/fire00.png");
	bulletPowerTexture.loadFromFile("Assets/img/PNG/Lasers/laserGreen15.png");
	
}

bool Player::GetisDead() const
{
	return isDead;
}

bool Player::GetAnimationOver() const
{
	return animationOver;
}

unsigned short Player::GetPowerTimer() const
{
	return powerTimer;
}

unsigned char Player::GetcPower() const
{
	return cPower;
}

unsigned short Player::GetX() const
{
	return x;
}

unsigned short Player::GetY() const
{
	return y;
}

unsigned short Player::GetScore() const
{
	return score;
}

void Player::Die()
{
	isDead = 1;
}

void Player::Draw(sf::RenderWindow& window, float deltaTime)
{
	if (isDead == false)	//checking if the player is alice
	{
		//setting the position and scale
		sprite.setPosition(x, y);
		sprite.setScale(0.4, 0.4);

		for (Bullet& bullet : bullets)
		{
			bullet.DrawTheBullet(window, deltaTime);
		}

		for (Explosion& explosion : explosions)
		{
			explosion.Draw(window, deltaTime);
		}

		window.draw(sprite);
	}
}

void Player::Reset()
{
	//resetting the values
	health = 3;
	x = 0.5f * WIDTH;
	y = 0.8f * HEIGHT;
	bullets.clear();
}

void Player::Update(std::mt19937_64& i_random_engine, std::list<Enemy>& i_enemies, std::list<Bullet>& enemy_bullets, PowerUpManager& powerupManager, unsigned short level)
{
	if (hitTimer > 0)
	{
		if (hitTimer == 1)
		{
			sprite.setColor(sf::Color(255, 255, 255, 255));
		}

		else if (hitTimer > 1)
		{
			sprite.setColor(sf::Color(255, 0, 0, 255));
		}

		hitTimer--;
	}

	if (isDead == false)
	{
		unsigned char powerUpType;
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			x = std::max<int>(x - PLAYERSPEED, sprite.getGlobalBounds().width / 2);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			x = std::min<int>(PLAYERSPEED + x, WIDTH - sprite.getGlobalBounds().width);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			y = std::min<int>(PLAYERSPEED + y, HEIGHT - sprite.getGlobalBounds().height);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			y = std::max<int>(y - PLAYERSPEED, sprite.getGlobalBounds().height / 2);
		}

		if (reloadTimer == 0)
		{
			if (cPower == 1)	//checking if the power up is picked
			{	
				//fire the bullets faster
				sprite.setColor(sf::Color(255, 255, 255, 100));
				reloadTimer = RELODTIME;
				bullets.push_back(Bullet(0, -BULLETSPEEDFORPLAYER, x, y, "Assets/img/PNG/Effects/fire00.png", cPower));
			}

			else
			{
				reloadTimer = RELOADTIME;
			}

			if (cPower == 2)
			{
				sprite.setColor(sf::Color(255, 255, 255, 100));
				bullets.push_back(Bullet(-BULLETSPEEDFORPLAYER + 7, -BULLETSPEEDFORPLAYER, x, y, "Assets/img/PNG/Lasers/laserGreen15.png", cPower));
				bullets.push_back(Bullet(-BULLETSPEEDFORPLAYER + 5, -BULLETSPEEDFORPLAYER, x, y, "Assets/img/PNG/Lasers/laserGreen15.png", cPower));
				bullets.push_back(Bullet(-BULLETSPEEDFORPLAYER + 2, -BULLETSPEEDFORPLAYER, x, y, "Assets/img/PNG/Lasers/laserGreen15.png", cPower));
				bullets.push_back(Bullet(0, -BULLETSPEEDFORPLAYER, x, y, "Assets/img/PNG/Lasers/laserGreen15.png", cPower));
				bullets.push_back(Bullet(BULLETSPEEDFORPLAYER - 5, -BULLETSPEEDFORPLAYER, x, y, "Assets/img/PNG/Lasers/laserGreen15.png", cPower));
				bullets.push_back(Bullet(BULLETSPEEDFORPLAYER - 7, -BULLETSPEEDFORPLAYER, x, y, "Assets/img/PNG/Lasers/laserGreen15.png", cPower));
				bullets.push_back(Bullet(BULLETSPEEDFORPLAYER - 2, -BULLETSPEEDFORPLAYER, x, y, "Assets/img/PNG/Lasers/laserGreen15.png", cPower));
			}

			if (cPower == 0)	//checking if the power is 0
			{
				//fire basic bullets
				bullets.push_back(Bullet(0, -BULLETSPEEDFORPLAYER, x, y, "Assets/img/PNG/Lasers/laserBlue01.png", cPower));
				sprite.setColor(sf::Color(255, 255, 255, 255));
			}
		}

		else
		{
			reloadTimer--;
		}
 
		for (Bullet& enemy_bullet : enemy_bullets)
		{
			if (cPower == 0)
			{
				if (GetHitBox().intersects(enemy_bullet.GetHitBox()))
				{
					Damage();
					enemy_bullet.dead = true;
				}
			}
			
		}
		
		powerUpType = powerupManager.CheckPowerupCollision(GetHitBox());
		if (powerUpType > 0)	//checking if the power up is greater than 0
		{
			//setting the power up
			cPower = powerUpType;
			//starting the power up timer
			powerTimer = ADDONTIMER;
		}

		if (powerTimer == 0)
		{
			cPower = 0;
		}

		else
		{
			powerTimer--;
		}

		if (cPower == 3)	//checking if the wrong power up collided
		{
			//taking damage
			Damage();
			powerTimer = 0;
		}

		if (cPower == 4)	//checking if the power up collided
		{
			//increasing health
			IncreaseHealth();
			powerTimer = 0;
		}

		if (health <= 0)	//checkinf if health is 0
		{
			//player is isDead
			isDead = true;
		}
	}
	
	//updating the bullet positiion
	for (Bullet& bullet : bullets)
	{
		bullet.Update();
	}

	//increases the score if enemy collided with player
	for (Enemy& enemy : i_enemies)
	{
		for (Bullet& bullet : bullets)
		{
			if (bullet.dead == false && enemy.GetHealth() > 0 && enemy.GetHitBox().intersects(bullet.GetHitBox()))
			{
				bullet.dead = true;
				enemy.GetHit();
				if (enemy.GetHealth() == 0)
				{
					score += enemy.GetScoreToKill() * level;
					explosions.push_back(Explosion(enemy.GetX(), enemy.GetY()));
				}
				
				break;
				
			}
		}
	}

	//destroy player if collides with enemy (do not destroy if the player has a power up)
	for (Bullet& enemyBullet : enemy_bullets)
	{
		for (Bullet& bullet : bullets)
		{
			if (bullet.GetHitBox().intersects(enemyBullet.GetHitBox()))
			{
				if (cPower == 0)
				{
					bullet.dead = true;
					enemyBullet.dead = true;
					explosions.push_back(Explosion(enemyBullet.x, enemyBullet.y));
					break;
				}

				else
				{
					enemyBullet.dead = true;
				}
			}
		}
	}
	
	std::list<Bullet>::iterator isDead_bullets = remove_if(bullets.begin(), bullets.end(), [](const Bullet& i_bullet) {
		return i_bullet.dead;
		});

	bullets.erase(isDead_bullets, bullets.end());

	std::list<Explosion>::iterator isDead_explosions = remove_if(explosions.begin(), explosions.end(), [](const Explosion& i_explosions) {
		return i_explosions.isDead;
		});

	explosions.erase(isDead_explosions, explosions.end());
}

sf::FloatRect Player::GetHitBox() const
{
	return sprite.getGlobalBounds();
}

unsigned char Player::GetHealth()
{
	return health;
}

void Player::Damage()
{
	hitTimer = HITTIMERFORPLAYER;
	health -= 1;
}

void Player::IncreaseHealth()
{
	if (health < 3)
	{
		health++;
	}
}

float Player::GetFloatPositionX()
{
	return sprite.getPosition().x;
}

float Player::GetFloatPositionY()
{
	return sprite.getPosition().y;
}
