#include "UILayer.h"
#include "GameScene.h"
#include "asada\Rocket.h"
#include "asada\/Calculation.h"
#include "Statics.h"

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
	power = 0.0f;
	touch = false;
	buttonColor = Color3B(255, 255, 255);
	//時間の初期化　スタート3分
	for (int i = 0; i < 6; i++)
	{
		timer[i] = 0;
		timer[1] = 1;
	}

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
	if (Statics::touchFlg)
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
	if (upCount % 50 == 0)
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
	//アイコンをロケットに追従させる
	worldPosition = Statics::myPos;
	localPosition = myIcon->getParent()->convertToNodeSpace(ccpAdd(worldPosition / 2.6, Vec2(600, 340)));
	this->myIcon->setPosition(localPosition);
	myIcon->setRotation(Statics::myRot);


	//ミニマップ外に出たらロケット消失
	if (localPosition.x < winSize.width - 360 || localPosition.y < winSize.height - 202.5)
	{
		myIcon->setVisible(false);
	}

	for (int i = 0; i < Statics::starPos.size(); i++)
	{
		starWorldPosition[i] = Statics::starPos.at(i);
		starLocalPosition[i] = starIcon[i]->getParent()->convertToNodeSpace(ccpAdd(starWorldPosition[i] / 2.6, Vec2(600, 340)));
		this->starIcon[i]->setPosition(starLocalPosition[i]);
	}

	//ゴールの位置にアイコン表示
	goalWorldPosition = Statics::goalPos;
	goalLocalPosition = goalIcon->getParent()->convertToNodeSpace(ccpAdd(goalWorldPosition / 2.6, Vec2(600, 340)));
	this->goalIcon->setPosition(goalLocalPosition);
}

void UILayer::Timer()
{
	if (Statics::gameOverFlg != true)
	{
		timer[5]--;
		if (timer[5] < 0)
		{
			timer[5] = 9;
			timer[4]--;
		}
		if (timer[4] < 0)
		{
			timer[4] = 5;
			timer[3]--;
		}
		if (timer[3] < 0)
		{
			timer[3] = 9;
			timer[2]--;
		}
		if (timer[2] < 0)
		{
			timer[2] = 5;
			timer[1]--;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		number[i]->setTextureRect(Rect(62 * timer[i], 0, 62, 102));
	}

	if (timer[1] == 0 && timer[2] == 0 && timer[3] == 0 &&
		timer[4] == 0 && timer[5] == 0)
	{
		Statics::gameOverFlg = true;
	}
}

void UILayer::CreateSprite()
{
	//ボタン
	button = Sprite::create("button.png");
	button->setPosition(Vec2(150, 90));
	this->addChild(button);
	buttonRect = button->boundingBox();

	//メーター
	meter = Sprite::create("meter.png");
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

	for (int i = 0; i < Statics::starPos.size(); i++)
	{
		starIcon[i] = Sprite::create("starIcon.png");
		this->addChild(starIcon[i]);
	}

	goalIcon = Sprite::create("goalIcon.png");
	this->addChild(goalIcon);

	//数字
	for (int i = 0; i < 6; i++)
	{
		number[i] = Sprite::create("count.png");
		number[i]->setAnchorPoint(Vec2::ZERO);
		if (i == 0 || i == 2 || i == 4)number[i]->setPosition(50 + (i * 50), 450);
		if (i == 1 || i == 3 || i == 5)number[i]->setPosition(90 + ((i - 1) * 50), 450);
		number[i]->setScale(0.4);
		this->addChild(number[i]);
	}
}

bool UILayer::onTouchBegan(cocos2d::Touch* ptouch, cocos2d::Event* pEvent)
{
	touchPoint = ptouch->getLocation();
	if (buttonRect.containsPoint(touchPoint))
	{
		Statics::touchFlg = true;
	}
	return true;
}

void UILayer::onTouchEnded(cocos2d::Touch *ptouch, cocos2d::Event *pEvent)
{
	Statics::touchFlg = false;
}

//タッチしているかどうかを確認するために関数
bool UILayer::getTouch(){
	return touch;
}

int UILayer::getmeterReturn()
{
	return power;
}

