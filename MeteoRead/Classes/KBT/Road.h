#ifndef __ROAD_H__
#define __ROAD_H__

#include "cocos2d.h"
#include "Math.h"

USING_NS_CC;

using namespace cocos2d;
class Road : public cocos2d::Layer
{
protected:
	Vec2 roadPos;							//道の座標
	SpriteBatchNode* roadImg;				// 道の画像
	Rect roadRect;
	void roadSet(Sprite* road);				// 道を初期化する関数

	std::vector<Sprite*> myRoad;	// 道の描画
	std::vector<float> roadSize;

private:

public:
	virtual bool init();
	static cocos2d::Scene* scene();
	void update(float delta);

	CREATE_FUNC(Road);
};
#endif //__ROAD_H__