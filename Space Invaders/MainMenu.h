#pragma once
#include "Screen.h"
class MainMenu : public Screen
{
private:
	bool isPlaying;
	
public:
	virtual int Run(sf::RenderWindow& window);
};