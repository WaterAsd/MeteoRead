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
	Vec2 roadPos;							//波の座標
	SpriteBatchNode* roadImg;				// 波の画像
	std::vector<Rect> roadRect;
	void roadSet(Sprite* road);				// 波生成時に波を初期化する関数

	std::vector<Sprite*> myRoad;	// 波の描画
private:

public:
	virtual bool init();
	static cocos2d::Scene* scene();
	void update(float delta);

	CREATE_FUNC(Road);
};
#endif //__ROAD_H__