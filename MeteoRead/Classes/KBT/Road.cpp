#include "Road.h"
#include "GameScene.h"
#include "asada\Rocket.h"
#include "asada\/Calculation.h"

USING_NS_CC;

using namespace cocos2d;
using namespace std;

bool Road::init()
{
	// 親クラス　初期化 
	if (!Layer::init())
	{
		return false;
	}
	roadRect.clear();
	myRoad.clear();
	roadImg = SpriteBatchNode::create("Road.png");
	myRoad.push_back(Sprite::createWithTexture(roadImg->getTexture()));
	roadSet(myRoad.back());
	this->addChild(roadImg);

	// アップデートを実行する
	this->scheduleUpdate();
}

void Road::update(float delta)
{
	myRoad.push_back(Sprite::createWithTexture(roadImg->getTexture()));
	roadSet(myRoad.back());
}

void Road::roadSet(Sprite* road){
	roadRect.push_back({ 8, 0, 8, 8 });
	road->setTextureRect(roadRect.back());
	road->setPosition(GameScene::_rocket->getPosition());
	road->setTag(0);
	road->setRotation(Calculation::Angle);
	this->addChild(myRoad.back());
	//roadPos = road->getPosition();
}
