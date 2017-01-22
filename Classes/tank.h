#ifndef __TANK_H__
#define __TANK_H__

#include "cocos2d.h"

USING_NS_CC;

typedef enum{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT
} direction;

typedef enum {
	NORMAL_GUN = 0,
	GATING_GUN,
	SHOT_GUN,
	FLAME_GUN,
	ELECTRIC_GUN,
	LASER_GUN
} TypeOfTank;

class Tank : public Sprite
{
public:
	Tank();
	Tank(int x, int y);
	static Tank* create(int x, int y, int type);
	void moveForward();
	void moveBack();
	void rotateLeft();
	void rotateRight();
	// void fire();
	// ~Tank();
private:
	float positionX, positionY;
	direction _tankDirection;
	TypeOfTank _typeGun;
};

#endif