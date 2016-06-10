#ifndef __ROAD_H__
#define __ROAD_H__

#include "cocos2d.h"
#include "Math.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace cocos2d;
class Road : public cocos2d::Layer
{
protected:
	Vec2 roadPos;							//“¹‚ÌÀ•W
	SpriteBatchNode* roadImg;				// “¹‚Ì‰æ‘œ
	Rect roadRect;
	int a;
	void roadSet(Sprite* road);				// “¹‚ğ‰Šú‰»‚·‚éŠÖ”

	std::vector<Sprite*> myRoad;	// “¹‚Ì•`‰æ
	std::vector<float> roadSize;

private:

public:
	virtual bool init();
	static cocos2d::Scene* scene();
	void update(float delta);

	CREATE_FUNC(Road);
};
#endif //__ROAD_H__