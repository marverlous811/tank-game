#include "tank.h"

#define NUMBER_TANK = 6

typedef enum {
	NORMAL_GUN = 0,
	GATING_GUN,
	SHOT_GUN,
	FLAME_GUN,
	ELECTRIC_GUN,
	LASER_GUN
} TypeOfTank;

static const char *iconOfTank[6]{
	"tankicons_03.png",
	"tankicons_01.png",
	"tankicons_02.png",
	"tankicons_04.png",
	"tankicons_07.png",
	"tankicons_08.png",
};

Tank::Tank()
{}

Tank::Tank(int x, int y)
{
	positionX = x;
	positionY = y;
}

void Tank::move(){
	auto moveBy = MoveBy::create(1, Point(0,-10));
	this->runAction(moveBy);
}

Tank *Tank::create(int x, int y, int type){
	
	Tank *tankSprite = new Tank();
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("tank/tank.plist", "tank/tank.png");
	tankSprite->setPosition(Point(x,y));
	tankSprite->setScale(0.5);
	tankSprite->initWithSpriteFrameName(iconOfTank[type]);

	return tankSprite;
}