#include "UILayer.h"
#include "GameScene.h"

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

	// 画面サイズ初期化
	winSize = Director::sharedDirector()->getWinSize();

	//初期化
	up = 0;
	upCount = 1;
	for (int i = 1; i < 3; i++)
	{
		timer[0] = 2;
		timer[i] = 60;
	}
	power = 0.0f;
	touch = false;
	j = 0;
	buttonColor = Color3B(255, 255, 255);

	// イベントリスナー準備
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = CC_CALLBACK_2(UILayer::onTouchBegan, this);		// タッチした時をイベントリスナーに登録
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
	Button();
	MeterMove();
	Map();
	Timer();
}

void UILayer::Button()
{
	if (touch)
	{
		//カウントを上げる
		upCount++;
		//色の変更
		buttonColor = Color3B(255, 0, 0);
		button->setColor(buttonColor);
	}
	else
	{
		//ボタンが離されたら数値を元に戻す
		up = 0;
		upCount = 1;
		//色を元に戻す
		buttonColor = Color3B(255, 255, 255);
		button->setColor(buttonColor);
	}
}

void UILayer::MeterMove()
{
	//カウントが50あがるたび、移動量が1増える
	if (upCount %50 ==0)
	{
		power++;
	}
	//速さが4段階上がるたび、メーターの量が1増える
	if (upCount % 200 == 0)
	{
		up++;
	}

	meter->setTextureRect(Rect(120 * up, 0, 120, 160));
}

void UILayer::Map()
{
	//ワールド座標に変換
	Vec2 worldPosition = GameScene::RoPos;

	//アイコンをロケットに追従させる
	Vec2 localPosition = myIcon->getParent()->convertToNodeSpace(ccpAdd(worldPosition/2.6 , Vec2(600, 340)));
	this->myIcon->setPosition(localPosition);
}

void UILayer::Timer()
{
	for (int i = 0; i < 3; i++)
	{
		if (timer[i] > 9)
		{
			clock[i]->setString(StringUtils::toString(timer[i]));
		}
		else
		{
			clock[i]->setString("0" + StringUtils::toString(timer[i]));
		}
	}

	timer[2] -= 1;
	if (timer[2] == 0)
	{
		timer[1]--;
		timer[2] = 60;
	}
	if (timer[1] == 00)
	{
		timer[0]--;
		timer[1] = 60;
	}
	
	if (upCount % 50 == 0)
	{
		j++;
	}

	number->setTextureRect(Rect(62 * j, 0, 62, 110));
}

void UILayer::CreateSprite()
{
	//ボタン
	button = Sprite::create("button.png");
	button->setPosition(Vec2(150, 90));
	this->addChild(button);
	buttonRect = button->boundingBox();

	//メーター
	meter=Sprite::create("meter.png");
	meter->setPosition(Vec2(220, 91));
	this->addChild(meter);

	//マップ
	map = Sprite::create();
	map->setAnchorPoint(Vec2::ZERO);
	map->setTextureRect(Rect(0, 0, 360, 202.5));
	map->setColor(Color3B::WHITE);
	map->setPosition(Vec2(winSize.width - 360, winSize.height - 202.5));
	this->addChild(map);
	map->setOpacity(100);

	//ロケットのアイコン
	myIcon = Sprite::create("icon01.png");
	this->addChild(myIcon);

	//時間
	for (int i = 0; i < 3; i++)
	{
		clock[i] = cocos2d::Label::createWithSystemFont("0" + cocos2d::StringUtils::toString(timer[i]), "arial", 100.0f);
		clock[i]->setAnchorPoint(Vec2::ZERO);
		clock[i]->setPosition(Vec2(150 * i, winSize.height*0.85f));
		clock[i]->setColor(Color3B::RED);
		this->addChild(clock[i]);
	}

	//数字
	number = Sprite::create("Number.png");
	number->setAnchorPoint(Vec2::ZERO);
	number->setPosition(100, 100);
	this->addChild(number);

}

bool UILayer::onTouchBegan(cocos2d::Touch* ptouch, cocos2d::Event* pEvent)
{
	touchPoint = ptouch->getLocation();
	if (buttonRect.containsPoint(touchPoint))
	{
		touch = true;
	}
	return true;
}

void UILayer::onTouchEnded(cocos2d::Touch *ptouch, cocos2d::Event *pEvent)
{
	touch = false;
}

int UILayer::getmeterReturn()
{
	return power;
}
