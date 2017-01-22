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

	Tank* player = new Tank();
    player = Tank::create(100,100,0);
    this->addChild(player);

    auto eventListener = EventListenerKeyboard::create();

    eventListener->onKeyPressed = [player](EventKeyboard::KeyCode keyCode, Event* event){
        switch(keyCode){
            case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            case EventKeyboard::KeyCode::KEY_A:
                player->rotateLeft();
                break;
            case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            case EventKeyboard::KeyCode::KEY_D:
                player->rotateRight();
                break;
            case EventKeyboard::KeyCode::KEY_UP_ARROW:
            case EventKeyboard::KeyCode::KEY_W:
                player->moveForward();
                break;
            case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            case EventKeyboard::KeyCode::KEY_S:
                player->moveBack();
                break;
        }
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener,player);
    
    return true;
}
