#pragma once
#include "Screen.h"

class GameScene : public Screen
{
private:
	bool isPlaying;
public:
	GameScene(void);
	virtual int Run(sf::RenderWindow& window);
};
