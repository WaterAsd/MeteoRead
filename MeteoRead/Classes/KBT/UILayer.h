#ifndef __UILAYER_H__
#define __UILAYER_H__

#include "cocos2d.h"
#include "Math.h"

USING_NS_CC;

using namespace cocos2d;

class UILayer : public cocos2d::Layer
{
protected:
	Size winSize;				// 画面サイズ

	Sprite *button;

	void CreateSprite();	// 画像作成クラス

private:

public:
	virtual bool init();
	static cocos2d::Scene* scene();
	void update(float delta);
	CREATE_FUNC(UILayer);
};

#endif //__UILAYER_H__