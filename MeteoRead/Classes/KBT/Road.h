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
	Vec2 roadPos;							//�g�̍��W
	SpriteBatchNode* roadImg;				// �g�̉摜
	std::vector<Rect> roadRect;
	void roadSet(Sprite* road);				// �g�������ɔg������������֐�

	std::vector<Sprite*> myRoad;	// �g�̕`��
	static std::vector<float> roadSize;
private:

public:
	virtual bool init();
	static cocos2d::Scene* scene();
	void update(float delta);

	CREATE_FUNC(Road);
};
#endif //__ROAD_H__