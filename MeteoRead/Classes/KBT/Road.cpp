#include "Road.h"
#include "GameScene.h"
#include "asada\Rocket.h"

USING_NS_CC;

using namespace cocos2d;
using namespace std;

bool Road::init()
{
	// �e�N���X�@������ 
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

	// �A�b�v�f�[�g�����s����
	this->scheduleUpdate();
}

void Road::update(float delta)
{
	roadMake();
}

void Road::roadMake()
{
	double roadran;
	roadran = sqrt((GameScene::RoPos.x - roadPos.x)*(GameScene::RoPos.x - roadPos.x) + (GameScene::RoPos.y - roadPos.y)*(GameScene::RoPos.y - roadPos.y));

		myRoad.push_back(Sprite::createWithTexture(roadImg->getTexture()));
		roadSet(myRoad.back());

}
void Road::roadSet(Sprite* road){
	roadRect.push_back({ 64, 0, 64, 64 });
	road->setTextureRect(roadRect.back());
	road->setPosition(GameScene::_rocket->getPosition());
	road->setTag(0);
	this->addChild(myRoad.back(), -1);
	roadPos = road->getPosition();
}
