#pragma once
#include "Screen.h"
class PauseScreen : public Screen
{
private:
	bool isPlaying;

public:
	virtual int Run(sf::RenderWindow& window);
};