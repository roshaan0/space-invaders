#pragma once
class Tween
{
public:
	static float TweenPositionX(float targetPositionX, float targetPositionY, float currentPositionX, float currentPositionY);
	static float TweenPositionY(float targetPositionX, float targetPositionY,  float currentPositionX, float currentPositionY);
	static float TweenAtAngleX(float angle);
	static float TweenAtAngleY(float angle);
};
