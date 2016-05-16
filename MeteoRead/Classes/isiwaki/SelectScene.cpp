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
	//�{�^���摜
	auto Button0 = Sprite::create("botan01.png");
	//�{�^�����W
	Button0->setPosition(Vec2(visibleSize.width / 5+origin.x, visibleSize.height/1.5f +origin.y));
	//���s��
	this->addChild(Button0, 1);
    //�w�i�摜
    auto Back = Sprite::create("BackSample.png");
    //�w�i���W
    Back->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	//���O����ԉ����I�|���i���t�b!!!
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
