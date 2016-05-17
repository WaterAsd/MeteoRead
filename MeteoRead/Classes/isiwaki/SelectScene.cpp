#include "SelectScene.h"
#include "GameScene.h"


USING_NS_CC;

Scene* SelectScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = SelectScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SelectScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//Button‚Ìì¬
	auto button = ui::Button::create("botan01.png");
	button->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2)+origin);
	button->addTouchEventListener(CC_CALLBACK_2(SelectScene::touchEvent, this));
	this->addChild(button,1);


	//”wŒi‰æ‘œ
	auto Back = Sprite::create("BackSample.png");
	//”wŒiÀ•W
	Back->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	//EEEEE‚¨‘O‚ªˆê”Ô‰º‚¾I”wŒiƒb!!!
	this->addChild(Back, 0);
	
	
    return true;
}
void SelectScene::update(float delta)
{
}
void SelectScene::touchEvent(Ref *pSender,ui::Widget::TouchEventType type)
{
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN:
		log(0123);
		Director::getInstance()->replaceScene(TransitionFade::create(2.0f, SelectScene::createScene() ,ccc3(0,0,0)));
		break;
	case ui::Widget::TouchEventType::ENDED:
		break;
	case ui::Widget::TouchEventType::CANCELED:
		break;


	default:
		break;
	}
}

void SelectScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
