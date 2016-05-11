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

	// スプライト作成クラス呼び出し
	CreateSprite();

	// アップデートを実行する。
	this->scheduleUpdate();

	return true;

}

void UILayer::update(float delta)
{

}

void UILayer::CreateSprite()
{
	Sprite* button = Sprite::create("button.png");
	button->setPosition(Vec2(150, 90));
	this->addChild(button);

	Sprite* meter=Sprite::create("button02.png");
	meter->setPosition(Vec2(190, 91));
	this->addChild(meter);

	Sprite* box = Sprite::create();
	box->setTextureRect(Rect(0, 0, 100, 100));
	box->setColor(Color3B::WHITE);
	box->setPosition(Vec2(800, 100));
	this->addChild(box);
}