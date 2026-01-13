#pragma once
#include <list>

class Screen
{
public:
	virtual int Run(sf::RenderWindow& window) = 0;
};
