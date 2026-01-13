#pragma once
#include "Screen.h"

class GameOverScene : public Screen
{
private:
	bool isPlaying;

public:
	virtual int Run(sf::RenderWindow& window);
};