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

	//初期化
	up = 0;
	upCount = 1;

	buttonColor = Color3B(255, 255, 255);

	// イベントリスナー準備
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = CC_CALLBACK_2(UILayer::onTouchBegan, this);		// タッチした時をイベントリスナーに登録
	listener->onTouchMoved = CC_CALLBACK_2(UILayer::onTouchMoved, this);		// タッチしている時をイベントリスナーに登録
	listener->onTouchEnded = CC_CALLBACK_2(UILayer::onTouchEnded, this);		// タッチを離した時をイベントリスナーに登録

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
	if (upCount % 5 == 0)
	{
		//1段階上げる
		up++;
		//5より上になったら0に戻す
		if (up >5)up=0;
	}
	meter->setTextureRect(Rect(120 * up, 0, 120, 160));
}

void UILayer::CreateSprite()
{
	button = Sprite::create("button.png");
	button->setPosition(Vec2(150, 90));
	this->addChild(button);
	buttonRect = button->boundingBox();

	meter=Sprite::create("meter.png");
	meter->setPosition(Vec2(220, 91));
	this->addChild(meter);

	map = Sprite::create();
	map->setTextureRect(Rect(0, 0, 240, 135));
	map->setColor(Color3B::WHITE);
	map->setPosition(Vec2(800,500));
	this->addChild(map);
	map->setOpacity(100);
}

bool UILayer::onTouchBegan(cocos2d::Touch* ptouch, cocos2d::Event* pEvent)
{
	return true;
}

void UILayer::onTouchMoved(cocos2d::Touch* ptouch, cocos2d::Event* pEvent)
{
	touchPoint = ptouch->getLocation();
	//ボタンにタッチされている間
	if (buttonRect.containsPoint(touchPoint))
	{
		//カウントを上げる
		upCount++;
		//色の変更
		buttonColor = Color3B(255, 0, 0);
		button->setColor(buttonColor);
	}
}

void UILayer::onTouchEnded(cocos2d::Touch *ptouch, cocos2d::Event *pEvent)
{
	//ボタンが離されたら数値を元に戻す
	up = 0;
	upCount = 1;
	//色を元に戻す
	buttonColor = Color3B(255, 255, 255);
	button->setColor(buttonColor);
}

int UILayer::getmeterReturn()
{
	return up;
}
