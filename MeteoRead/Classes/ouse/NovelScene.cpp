#include "NovelScene.h"
#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

// 初期化メソッド
bool NovelScene::init()
{
	// 親であるLayerクラスの初期化
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//画像を表示
	auto sprite = Sprite::create("HelloWorld.png");

	//表示位置
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	//レイヤーに追加
	this->addChild(sprite, 0);

	return true;
}