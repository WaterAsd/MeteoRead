#ifndef  _NOVEL_SCENE_H_
#define  _NOVEL_SCENE_H_

#include "cocos2d.h"

class NovelScene : private cocos2d::Layer
{
public:
	//シーンを作成する
	static cocos2d::Scene* createScene();

	//初期化メソッド
	virtual bool init();

	//コールバックメソッド
	void menuCloseCallback(cocos2d::Ref* pSender);

	//CREATE_FUNCマクロを使用して、staticなcreateメソッドを実装する
	CREATE_FUNC(HelloWorld);
};

#endif // _NOVEL_SCENE_H_