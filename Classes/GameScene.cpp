#include "GameScene.h"
#include "tank.h"

USING_NS_CC;

Scene* GameScene::createScene(){
	// 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
} 

bool GameScene::init(){
	if ( !Layer::init() )
    {
        return false;
    }
    
	auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    Tank *player = Tank::create(100,100,0);
    this->addChild(player);
    
    player->move();

    return true;
}