#include "tank.h"

#define NUMBER_TANK = 6


static const char *iconOfTank[6]{
	"tankicons_03.png",
	"tankicons_01.png",
	"tankicons_02.png",
	"tankicons_04.png",
	"tankicons_07.png",
	"tankicons_08.png",
};

Tank::Tank()
{
	_typeGun = NORMAL_GUN;
	_tankDirection = UP;
}

Tank::Tank(int x, int y)
{
	positionX = x;
	positionY = y;
}

void Tank::moveForward(){
	if(this->_tankDirection == UP){
		auto moveBy = MoveBy::create(1, Point(0,10));
		this->runAction(moveBy);
	}
	else if(this->_tankDirection == DOWN){
		auto moveBy = MoveBy::create(1, Point(0,-10));
		this->runAction(moveBy);
	}
	else if(this->_tankDirection == LEFT){
		auto moveBy = MoveBy::create(1, Point(10,0));
		this->runAction(moveBy);
	}
	else if(this->_tankDirection == RIGHT){
		auto moveBy = MoveBy::create(1, Point(-10,0));
		this->runAction(moveBy);
	}
}

void Tank::moveBack(){
	if(this->_tankDirection == UP){
		auto moveBy = MoveBy::create(1, Point(0,-10));
		this->runAction(moveBy);
	}
	else if(this->_tankDirection == DOWN){
		auto moveBy = MoveBy::create(1, Point(0,10));
		this->runAction(moveBy);
	}
	else if(this->_tankDirection == LEFT){
		auto moveBy = MoveBy::create(1, Point(-10,0));
		this->runAction(moveBy);
	}
	else if(this->_tankDirection == RIGHT){
		auto moveBy = MoveBy::create(1, Point(10,0));
		this->runAction(moveBy);
	}
	
}

void Tank::rotateRight(){
	auto rotateBy = RotateBy::create(1.0f, 90.0f);
	this->runAction(rotateBy);
}

void Tank::rotateLeft(){
	auto rotateBy = RotateBy::create(1.0f, -90.0f);
	this->runAction(rotateBy);
}

Tank *Tank::create(int x, int y, int type){
	
	Tank *tankSprite = new Tank();
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("tank/tank.plist", "tank/tank.png");
	tankSprite->setPosition(Point(x,y));
	tankSprite->setScale(0.5);
	tankSprite->initWithSpriteFrameName(iconOfTank[type]);

	return tankSprite;
}