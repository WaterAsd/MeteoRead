#include "Road.h"
#include "GameScene.h"

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
}

void Road::update(float delta)
{}

void Road::roadMake()
{
	double roadran;
	roadran = sqrt((GameScene::RoPos.x - roadPos.x)*(GameScene::RoPos.x - roadPos.x) + (GameScene::RoPos.y - roadPos.y)*(GameScene::RoPos.y - roadPos.y));

	if (myRoad.size() == 0)
	{
		myRoad.push_back(Sprite::createWithTexture(roadImg->getTexture()));
		roadSet(myRoad.back());
	}
}
void Road::roadSet(Sprite* road){
	roadRect.push_back({ 64, 0, 64, 64 });
	road->setTextureRect(roadRect.back());
	road->setPosition(100,100);
	road->setTag(0);
	this->addChild(myRoad.back(), -1);
	roadPos = road->getPosition();
}
