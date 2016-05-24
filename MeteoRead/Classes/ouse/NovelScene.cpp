#pragma execution_character_set("utf-8")//日本語が使えるようになる魔法の言葉
#include "ouse/NovelScene.h"
#include "ui/CocosGUI.h"

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

	autoflg = false;
	autoframe = false;
	autocnt = false;
	autospeed = false;
	mojicnt = false;
	mojiframe = false;

	//画面サイズ取得
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//マルチレゾリューション
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto textField = ui::TextField::create("ンゴ", "", 45);
	textField->setPosition(Vec2(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.7 + origin.y));

	this->addChild(textField);

	//画像を表示
	auto sprite = Sprite::create("window2.png");
	////中央に表示されるように座標を設定
	sprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 6 + origin.y));
	sprite->setScale(0.75);
	////画像を追加　第2引数は表示する順番（背景だから一番下つまり0）
	this->addChild(sprite, 3);

	return true;
}