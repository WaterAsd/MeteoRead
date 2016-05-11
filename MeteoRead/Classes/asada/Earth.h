#ifndef __METEOREAD__EARTH__
#define __METEOREAD__EARTH__

#include "cocos2d.h"

class Earth : public cocos2d::Sprite{
protected:
	Earth();
	virtual ~Earth();
	virtual bool init();
	const int UP_PIC = 2;//上下に何枚の画像があるか？
	const int Frame_Count = 8;//一枚の中にあう画像の総合数
	const float Anemation = 0.11;//次の画像に進むまでの時間
public:
	CC_SYNTHESIZE_PASS_BY_REF(cocos2d::Vector<cocos2d::SpriteFrame *>, _earth,earth);//歩きの画像のVector
	CREATE_FUNC(Earth);
};

#endif//__METEOREAD__EARTH__