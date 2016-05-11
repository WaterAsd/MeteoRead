#ifndef __METEOREAD__GAME__
#define __METEOREAD__GAME__

#include "cocos2d.h"
#include "KBT/UILayer.h"

class GameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();//ゲームシーンの作成
	virtual bool init();//初期化宣言
	CREATE_FUNC(GameScene);//クラスの宣言
	static UILayer* uiLayer;//UILayerを使えるようにする。
};

#endif //__METEOREAD__GAME__