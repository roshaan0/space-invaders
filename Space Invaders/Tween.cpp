#include <iostream>
#include "Tween.h"


float Tween::TweenPositionX(float targetPositionX, float targetPositionY, float currentPositionX, float currentPositionY)
{
	float directionX = targetPositionX - currentPositionX;
	float directionY = targetPositionY - currentPositionY;
	float length = std::sqrt((directionX * directionX) + (directionY * directionY));
	
	if (length != 0)
	{
		directionX = directionX / length;
		return directionX;
	}

	else
	{
		return 0;
	}
}

float Tween::TweenPositionY(float targetPositionX, float targetPositionY, float currentPositionX, float currentPositionY)
{
	float directionX = targetPositionX - currentPositionX;
	float directionY = targetPositionY - currentPositionY;
	float length = std::sqrt((directionX * directionX) + (directionY * directionY));
	
	if (length != 0)
	{
		directionY = directionY / length;
		return directionY;
	}

	else
	{
		return 0;
	}
}

float Tween::TweenAtAngleX(float angle)	//moves at an angle X
{
	float angleRADS = (3.1415926536 / 180) * (angle);
	float directionX = cos(angleRADS);
	return directionX;
}

float Tween::TweenAtAngleY(float angle)	//moves at an angle Y
{
	float angleRADS = (3.1415926536 / 180) * (angle);
	float directionY = sin(angleRADS);
	return directionY;
}

