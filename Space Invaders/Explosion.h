#pragma once
class Explosion
{
	sf::Sprite sprite;
	sf::Texture texture;
	Animation animation;
	float x;
	float y;

public:
	Explosion(float x, float y);
	void Draw(sf::RenderWindow& window, float deltaTime);
	bool isDead;
};