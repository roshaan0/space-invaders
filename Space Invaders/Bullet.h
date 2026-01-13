#pragma once
#include "Animation.h"
class Bullet
{
	sf::Texture texture;	
	sf::Sprite sprite;
	bool interpolate;	//interjection along x and y (?)
	Animation anim;	//aggregation (animation will exist on its own without the bullet)
	bool animate;	
	short previousX;
	short previousY;

public:
	Bullet(float, float, short, short, const std::string& textPath, unsigned char = 0, bool i_interpolate = false, bool animate = false);
	float real_x;
	float real_y;
	float step_x;
	float step_y;
	short x;
	short y;
	float width;
	float height;
	bool dead;
	unsigned char type;
	void Update();
	void DrawTheBullet(sf::RenderWindow& window, float dTime);
	//sf::IntRect GetHitbox() const;
	sf::FloatRect GetHitBox() const;
	short InterpolateX(short i_x);
	short InterpolateY(short i_y);
};