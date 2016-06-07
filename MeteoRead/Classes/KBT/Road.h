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
	Vec2 roadPos;							//”g‚ÌÀ•W
	SpriteBatchNode* roadImg;				// ”g‚Ì‰æ‘œ
	std::vector<Rect> roadRect;
	void roadSet(Sprite* road);				// ”g¶¬‚É”g‚ğ‰Šú‰»‚·‚éŠÖ”

	std::vector<Sprite*> myRoad;	// ”g‚Ì•`‰æ
	static std::vector<float> roadSize;
private:

public:
	virtual bool init();
	static cocos2d::Scene* scene();
	void update(float delta);

	CREATE_FUNC(Road);
};
#endif //__ROAD_H__