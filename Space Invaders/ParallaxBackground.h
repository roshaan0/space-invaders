#pragma once

class ParallaxBackground
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	short x;
	short y;
	float step_x;
	float step_y;
	float real_x;
	float real_y;
	
public:
	ParallaxBackground(float i_step_x, float i_step_y, short i_x, short i_y);
	void Draw(sf::RenderWindow& window);
	void Update();
};