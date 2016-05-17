#include "Title.h"

USING_NS_CC;

Scene* Title::createScene()
{
    auto scene = Scene::create();
    
    auto layer = Title::create();

    scene->addChild(layer);

    return scene;
}

bool Title::init()
{

    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	
	//�X�^�[�g�{�^����ݒu
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",    // �ʏ��Ԃ̉摜
                                           "CloseSelected.png",  // ������Ԃ̉摜
                                           CC_CALLBACK_1(Title::menuCloseCallback, this));  // �������̃A�N�V����
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    this->addChild(label, 1);

    auto sprite = Sprite::create("HelloWorld.png");

    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    this->addChild(sprite, 0);


    return true;
}


void Title::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
