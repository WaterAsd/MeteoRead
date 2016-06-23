#ifndef __METEOREAD__EARTH__
#define __METEOREAD__EARTH__

#include "cocos2d.h"
using namespace std;

class Earth : public cocos2d::Sprite{
protected:
	Earth();
	virtual ~Earth();
	virtual bool init();
	const int UP_PIC = 2;//ã‰º‚É‰½–‡‚Ì‰æ‘œ‚ª‚ ‚é‚©H
	const int Frame_Count = 4;//‰¡‚ÉŒü‚©‚Á‚Ä‰æ‘œ‚ª‚¢‚­‚Â‚ ‚é‚©
	const float ANIMETION= 0.5f;//Ÿ‚Ì‰æ‘œ‚Éi‚Ş‚Ü‚Å‚ÌŠÔ
public:
	void planetcreate(std::string hosi);
	CC_SYNTHESIZE_PASS_BY_REF(cocos2d::Vector<cocos2d::SpriteFrame *>, _earth,earth);//•à‚«‚Ì‰æ‘œ‚ÌVector
	CREATE_FUNC(Earth);
};

#endif//__METEOREAD__EARTH__