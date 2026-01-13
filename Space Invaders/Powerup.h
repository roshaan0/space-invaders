#pragma once
class Powerup
{
	sf::Sprite sprite;
	sf::Texture texture;

public:
	unsigned short powerDuration;
	bool dead;
	short x;
	short y;
	float width;
	float height;
	unsigned char type;
	
	Powerup(short i_x, short i_y, unsigned char i_type);
	sf::FloatRect GetHitBox() const;
	unsigned short GetDuration();
	void Draw(sf::RenderWindow& window);
};