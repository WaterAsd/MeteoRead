#include "UILayer.h"

USING_NS_CC;

using namespace cocos2d;
using namespace std;

bool UILayer::init()
{
	// 親クラス　初期化 
	if (!Layer::init())
	{
		return false;
	}

	//int初期化
	up = 0;
	upCount = 0;


	// イベントリスナー準備
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = CC_CALLBACK_2(UILayer::onTouchBegan, this);		// タッチした時をイベントリスナーに登録
	listener->onTouchMoved = CC_CALLBACK_2(UILayer::onTouchMoved, this);		// タッチした時をイベントリスナーに登録

	////イベントリスナーを登録
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	// スプライト作成クラス呼び出し
	CreateSprite();

	// アップデートを実行する。
	this->scheduleUpdate();

	return true;

}

void UILayer::update(float delta)
{
	meterMove();
}

void UILayer::meterMove()
{
	upCount++;
	if (upCount % 5 == 0)
	{
		//1段階上げる
		up++;
		//5より上になったら0に戻す
		if (up >5)up=0;
	}
	meter->setTextureRect(Rect(120 * up, 0, 120, 160));
}

bool UILayer::onTouchBegan(cocos2d::Touch* ptouch, cocos2d::Event* pEvent)
{
	log("aaaaaa");
	return true;
}

void UILayer::onTouchMoved(cocos2d::Touch* ptouch, cocos2d::Event* pEvent)
{
	log("bbbbb");
}

int UILayer::getmeterReturn()
{
	return up;
}

void UILayer::CreateSprite()
{
	Sprite* button = Sprite::create("button.png");
	button->setPosition(Vec2(150, 90));
	this->addChild(button);

	meter=Sprite::create("meter.png");
	meter->setPosition(Vec2(190, 91));
	this->addChild(meter);
}