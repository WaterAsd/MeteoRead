#include "SelectScene.h"

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
	for (int i = 0; i < 4; i++)
	{
		ButtonSp[i] = Sprite::create("botan01.png");
		ButtonSp[i]->setPosition(Vec2(visibleSize.width / 5 + origin.x, visibleSize.height / i + origin.y));
		this->addChild(ButtonSp[i], 1);

	}
	//ボタン画像
	auto Button0 = Sprite::create("botan01.png");
	//ボタン座標
	Button0->setPosition(Vec2(visibleSize.width / 5+origin.x, visibleSize.height/1.5f +origin.y));
	//奥行き
	this->addChild(Button0, 1);
    //背景画像
    auto Back = Sprite::create("BackSample.png");
    //背景座標
    Back->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	//お前が一番下だ！ポルナレフッ!!!
    this->addChild(Back, 0);
    
    return true;
}


void SelectScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
