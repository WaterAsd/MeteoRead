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
	button->setAnchorPoint(Vec2(0.5, 0));
	button->setPosition(Vec2(250, 45));
	this->addChild(button);
}