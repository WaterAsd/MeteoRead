#ifndef  _NOVEL_SCENE_H_
#define  _NOVEL_SCENE_H_

#include "cocos2d.h"

class NovelScene : public cocos2d::Layer
{
public:
	//シーンを作成する
	static cocos2d::Scene* createScene();

	//初期化メソッド
	virtual bool init();

	Sprite *background;

	int mojiframe;
	int mojicnt;
	int mojicnt2;
	bool mojinext;

	//CREATE_FUNCマクロを使用して、staticなcreateメソッドを実装する
	CREATE_FUNC(NovelScene);

	//コールバックメソッド
private:
	virtual void menuCloseCallback(cocos2d::Ref* pSender);

};

#endif // _NOVEL_SCENE_H_