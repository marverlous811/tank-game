#ifndef __TANK_H__
#define __TANK_H__

#include "cocos2d.h"

USING_NS_CC;

class Tank : public Sprite
{
public:
	Tank();
	Tank(int x, int y);
	static Tank* create(int x, int y, int type);
	void move();
	// void rotate();
	// void fire();
	// ~Tank();
private:
	float positionX, positionY;
};

#endif