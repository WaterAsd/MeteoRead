#ifndef __METEOREAD__BOOSTER__
#define __METEOREAD__BOOSTER__

#include "cocos2d.h"

class Booster : public cocos2d::Sprite{
protected:
	Booster();
	virtual ~Booster();
	virtual bool init();
	const int Frame_Count = 4;//‰¡‚ÉŒü‚©‚Á‚Ä‰æ‘œ‚ª‚¢‚­‚Â‚ ‚é‚©
	float ANIMETION = 0.1f;//Ÿ‚Ì‰æ‘œ‚Éi‚Ş‚Ü‚Å‚ÌŠÔ
public:
	void SetPower(int power);
	CC_SYNTHESIZE_PASS_BY_REF(cocos2d::Vector<cocos2d::SpriteFrame *>, _boost, Boost);//•à‚«‚Ì‰æ‘œ‚ÌVector
	CREATE_FUNC(Booster);
};

#endif//__METEOREAD__Booster__