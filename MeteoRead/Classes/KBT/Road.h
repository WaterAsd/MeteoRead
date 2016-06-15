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
	Vec2 roadPos;							//���̍��W
	SpriteBatchNode* roadImg;				// ���̉摜
	Rect roadRect;
	int a;
	void roadSet(Sprite* road);				// ��������������֐�

	std::vector<Sprite*> myRoad;	// ���̕`��
	std::vector<float> roadSize;

private:

public:
	virtual bool init();
	static cocos2d::Scene* scene();
	void update(float delta);

	CREATE_FUNC(Road);
};
#endif //__ROAD_H__