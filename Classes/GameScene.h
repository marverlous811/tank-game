#ifndef __GAMESCENE__H_
#define __GAMESCENE__H_

#include "cocos2d.h"
#include "tank.h"

class GameScene : public cocos2d::Layer{
	public:
    static cocos2d::Scene* createScene();

    virtual bool init();     
    void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
	void control(int mode);
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

private:
	Tank *player = new Tank();

};

#endif