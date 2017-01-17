#include "GameScene.h"

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

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("tank/tank.plist", "tank/tank.png");
	// Khởi tạo Sprite từ SpriteFrameCache.
	auto mySprite = Sprite::createWithSpriteFrameName("tankicons_03.png");
	// Thiết lập vị trí ban đầu cho sprite tại vị trí (100, 100).
	mySprite->setPosition(100, 100);
	// Thêm mySprite vào Scene.
	this->addChild(mySprite);
    

    return true;
}