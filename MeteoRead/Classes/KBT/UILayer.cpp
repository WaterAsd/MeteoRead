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
}