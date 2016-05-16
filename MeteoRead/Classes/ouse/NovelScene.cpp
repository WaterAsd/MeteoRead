#include "ouse/NovelScene.h"
#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* NovelScene::createScene()
{
	// scene 自動生成オブジェクト
	auto scene = Scene::create();
	// layer 自動生成オブジェクト
	auto layer = NovelScene::create();
	// layer sceneの子として追加
	scene->addChild(layer);
	// scene の値を返す
	return scene;
}

// 初期化メソッド
bool NovelScene::init()
{
	// 親であるLayerクラスの初期化
	if (!Layer::init())
	{
		return false;
	}

	mojicnt = false;
	mojiframe = false;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//画像を表示
	auto sprite = Sprite::create("HelloWorld.png");
	background = Sprite::create("window2.png");
	////中央に表示されるように座標を設定
	background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 6 + origin.y));
	background->setScale(0.75);
	////画像を追加　第2引数は表示する順番（背景だから一番下つまり0）
	this->addChild(background, 3);

	//表示位置
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	//レイヤーに追加
	this->addChild(sprite, 0);

	return true;
}