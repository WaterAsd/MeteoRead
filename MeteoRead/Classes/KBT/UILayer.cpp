#include "UILayer.h"
#include "asada\Rocket.h"
#include "asada\Calculation.h"

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
		timer[1] = 3;
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
	////アイコンをロケットに追従させる
	//Vec2 localPosition = myIcon->getParent()->convertToNodeSpace(ccpAdd(worldPosition/2.6 , Vec2(600, 340)));
	//this->myIcon->setPosition(localPosition);
	//myIcon->setRotation(Calculation::Angle);
	
}

void UILayer::Timer()
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
	if (timer[2]<0)
	{
		timer[2] = 5;
		timer[1]--;
	}

	for (int i = 0; i < 6; i++)
	{
		number[i]->setTextureRect(Rect(62 * timer[i], 0, 62, 102));
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
	meter=Sprite::create("meter.png");
	meter->setPosition(Vec2(220, 91));
	this->addChild(meter);

	//マップ
	_minimap = MapNode::create();
	_minimap->setPosition(Vec2(600,340));
	this->addChild(_minimap);

	//ロケットのアイコン
	myIcon = Sprite::create("icon01.png");
	this->addChild(myIcon);

	//数字
	for (int i = 0; i < 6; i++)
	{
		number[i] = Sprite::create("count.png");
		number[i]->setAnchorPoint(Vec2::ZERO);
		number[i]->setPosition(100+(i*80), 450);
		number[i]->setScale(0.6);
		this->addChild(number[i]);
	}

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

//タッチしているかどうかを確認するために関数
bool UILayer::getTouch(){
	return touch;
}

int UILayer::getmeterReturn()
{
	return power;
}
/*-------------------------------------------------------------------------------------------------------------------------------
----------------------------ここまでがUILayerのクラスの関数----------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------*/

//マップの初期化処理
bool MapNode::init(){
	if (!Node::init()){
		return false;
	}
	
	oneflg = false;

	//後ろの背景を作成する
	_map = Sprite::create();
	_map->setAnchorPoint(Vec2::ZERO);
	_map->setTextureRect(Rect(0, 0, 360, 202.5));
	_map->setColor(Color3B::WHITE);
	_map->setOpacity(128);
	this->addChild(_map,-1);

	return true;
}

//マップの更新処理
void MapNode::update(float dt){
	//マップが移動するかもしれないので一応
	_rocket->setPosition(Vec2((_rocketpos.x*mapsize.x), (_rocketpos.y*mapsize.y)));
	for (int i = 0; i < _starpos.size(); i++){
		auto starpos = _starpos.at(i);
		auto star = _star.at(i);
		star->setPosition(Vec2((starpos.x*mapsize.x), (starpos.y*mapsize.y)));
	}
	_goal->setPosition(Vec2((_goalpos.x*mapsize.x), (_goalpos.y*mapsize.y)));
}

//ほしい場所から取ってくる。
void MapNode::setrocket(Vec2 rocket){ _rocketpos = rocket; }
void MapNode::setstarpos(std::vector<Vec2> pos){
	_starpos=pos;
}
void MapNode::setgoalpos(Vec2 goal){ _goalpos = goal; }
void MapNode::setStagerect(Rect stagesize){	_stagesize = stagesize;}

//画像を作成するための物
void MapNode::mapcreate(){

	if (oneflg != true){
		Mapsize();

		_rocket = Sprite::create("icon01.png");
		_rocket->setPosition(Vec2((_rocketpos.x*mapsize.x), (_rocketpos.y*mapsize.y)));
		this->addChild(_rocket);

		for (int i = 0; i < _starpos.size(); i++){
			auto Star = CCDrawNode::create();
			auto starpos = _starpos.at(i);
			Star->drawDot(Vec2((starpos.x*mapsize.x), (starpos.y*mapsize.y))
				, 5, Color4F::BLUE);
			this->addChild(Star);
			_star.pushBack(Star);
		}

		_goal = CCDrawNode::create();
		_goal->drawDot(Vec2((_goalpos.x*mapsize.x), (_goalpos.y*mapsize.y))
			, 5, Color4F::BLUE);
		this->addChild(_goal);

		//アップデートを実行させる
		this->scheduleUpdate();

		oneflg = true;
	}
}

//マップの比率を一緒にする
void MapNode::Mapsize(){
	//画像/ステージのサイズで割って値を導き出す。
	mapsize.x = (_map->getTextureRect().getMaxX()) / (_stagesize.getMaxX() - _stagesize.getMinX());
	mapsize.y = (_map->getTextureRect().getMaxY()) / (_stagesize.getMaxY() - _stagesize.getMinY());
}