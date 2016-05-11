#ifndef __METEOREAD__GAME__
#define __METEOREAD__GAME__

#include "cocos2d.h"
#include "KBT/UILayer.h"

class GameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameScene);

	static UILayer* uiLayer;
};

#endif //__METEOREAD__GAME__