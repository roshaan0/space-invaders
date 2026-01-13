#pragma once
class Animation
{
	float width;
	float height;
	float imageX;	//Image counter for x
	float imageY;	//Image counter for y
	float currentimageX;	//gives the current image at x
	float currentimageY;	//gives the current image at y
	float totalTime; 	
	float switchTime;
	bool end;
	
public:
	sf::IntRect uvRect;
	Animation() {};
	void SetAnimation(sf::Texture& texture, float i_imageCountX, float i_imageCountY, float switchTime);
	void Draw(short x, short y, sf::RenderWindow& window);
	void Update(int row, float deltaTime);
	bool GetEnd();
};