#include "GameScene.h"
#include "KBT/Road.h"

#include "cocos2d.h"

class GameScene2 :public cocos2d::Layer{
protected:
	virtual bool init();
	Scene* createScene();
public:
	CREATE_FUNC(GameScene2);
};
