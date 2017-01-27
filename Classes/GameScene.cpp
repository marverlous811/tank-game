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

	player = Tank::create(100,100,0);
    this->addChild(player);

    auto eventListener = EventListenerKeyboard::create();

    eventListener->onKeyPressed = CC_CALLBACK_2(GameScene::keyPressed, this);

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener,this);
    
    return true;
}

void GameScene::keyPressed(EventKeyboard::KeyCode keyCode, Event* event){
    switch(keyCode){
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
			this->control(1);
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            this->control(2);
            break;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            this->control(3);
            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            this->control(4);
            break;
        case EventKeyboard::KeyCode::KEY_SPACE:
			this->control(5);
			break;
    }
}

void GameScene::control(int mode) {
	switch (mode) {
	case 1:
		player->rotateLeft();
		break;
	case 2:
		player->rotateRight();
		break;
	case 3:
		player->moveForward();
		break;
	case 4:
		player->moveBack();
		break;
	case 5:
		Sprite* bullet = player->bullet();
		this->addChild(bullet);
		player->fire(bullet);
		break;
	}
}