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
	myRoad.clear();
	roadSize.clear();
	roadImg = SpriteBatchNode::create("star2.png");
	myRoad.push_back(Sprite::createWithTexture(roadImg->getTexture()));
	roadSet(myRoad.back());
	this->addChild(roadImg);
	// アップデートを実行する
	//this->scheduleUpdate();
	this->schedule(schedule_selector(Road::update));
}

void Road::update(float delta)
{
	myRoad.push_back(Sprite::createWithTexture(roadImg->getTexture()));
	roadSet(myRoad.back());
	for (int i = 0; i < myRoad.size(); i++)
	{
		roadRect = myRoad[i]->boundingBox();
		if (roadRect.intersectsRect(roadRect))
		{
			//myRoad[i]->removeFromParent();
			//myRoad.erase(myRoad.begin());
		}

	}
	log("%d", myRoad.size());
}

void Road::roadSet(Sprite* road){
	/*road->setPosition(GameScene::_rocket->getPosition());
	road->setTag(0);
	road->setRotation(Calculation::Angle);
	this->addChild(myRoad.back());
	*/
}
