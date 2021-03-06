#ifndef __METEOREAD__EARTH__
#define __METEOREAD__EARTH__

#include "cocos2d.h"
using namespace std;

class Earth : public cocos2d::Sprite{
protected:
	Earth();
	virtual ~Earth();
	virtual bool init();
	const int UP_PIC = 2;//上下に何枚の画像があるか？
	const int Frame_Count = 4;//横に向かって画像がいくつあるか
	const float ANIMETION= 0.5f;//次の画像に進むまでの時間
public:
	void planetcreate(std::string hosi);
	CC_SYNTHESIZE_PASS_BY_REF(cocos2d::Vector<cocos2d::SpriteFrame *>, _earth,earth);//歩きの画像のVector
	CREATE_FUNC(Earth);
};

#endif//__METEOREAD__EARTH__