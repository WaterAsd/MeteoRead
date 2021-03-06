#ifndef __METEOREAD__BOOSTER__
#define __METEOREAD__BOOSTER__

#include "cocos2d.h"

class Booster : public cocos2d::Sprite{
protected:
	Booster();
	virtual ~Booster();
	virtual bool init();
	const int Frame_Count = 5;//横に向かって画像がいくつあるか
	const int Frame_County = 2;//たてに向かって画像がいくつあるか
	float ANIMETION = 0.1f;//次の画像に進むまでの時間
public:
	void SetPower(int power);
	CC_SYNTHESIZE_PASS_BY_REF(cocos2d::Vector<cocos2d::SpriteFrame *>, _boost, Boost);//歩きの画像のVector
	CREATE_FUNC(Booster);
};

#endif//__METEOREAD__Booster__