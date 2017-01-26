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
		auto moveBy = MoveBy::create(1, Point(-10,0));
		this->runAction(moveBy);
	}
	else if(this->_tankDirection == RIGHT){
		auto moveBy = MoveBy::create(1, Point(10,0));
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
		auto moveBy = MoveBy::create(1, Point(10,0));
		this->runAction(moveBy);
	}
	else if(this->_tankDirection == RIGHT){
		auto moveBy = MoveBy::create(1, Point(-10,0));
		this->runAction(moveBy);
	}
	
}

void Tank::rotateRight(){
	if(_tankDirection == UP){
		_tankDirection = RIGHT;
	}
	else if(_tankDirection == RIGHT){
		_tankDirection = DOWN;
	}
	else if(_tankDirection == DOWN){
		_tankDirection = LEFT;
	}
	else if(_tankDirection == LEFT){
		_tankDirection = UP;
	}
	auto rotateBy = RotateBy::create(0.01f, 90.0f);
	this->runAction(rotateBy);
}

void Tank::rotateLeft(){
	if(_tankDirection == UP){
		_tankDirection = LEFT;
	}
	else if(_tankDirection == RIGHT){
		_tankDirection = UP;
	}
	else if(_tankDirection == DOWN){
		_tankDirection = RIGHT;
	}
	else if(_tankDirection == LEFT){
		_tankDirection = DOWN;
	}
	auto rotateBy = RotateBy::create(0.01f, -90.0f);
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

Sprite* Tank::bullet(){
	Sprite* _bullet = Sprite::create("bullet/armor_bullet.png");
	_bullet->setPosition(this->getPosition());
	_bullet->setScale(1.0);
	//_bullet->setOpacity(0);
	return _bullet;
}

void Tank::fire(Sprite* bullet){
	//bullet->setOpacity(1);
	auto moveBy = MoveBy::create(1, Point(0, 1000));
	bullet->runAction(moveBy);
}