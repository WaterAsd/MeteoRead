#ifndef __UILAYER_H__
#define __UILAYER_H__

#include "cocos2d.h"
#include "Math.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace cocos2d;

class UILayer : public cocos2d::Layer
{
protected:
	Size winSize;				// 画面サイズ

	//Sprite
	Sprite* meter;              //メーターの画像

	//int
	int up;                     //メーターの量　0～5
	int upCount;//upのカウント

	Point touchPoint;				// タッチされた場所

	virtual bool onTouchBegan(cocos2d::Touch* ptouch, cocos2d::Event* pEvent);		// タッチした時の準備
	virtual void onTouchMoved(cocos2d::Touch* ptouch, cocos2d::Event* pEvent);		// タッチした時の準備

	void CreateSprite();	// 画像作成クラス

private:

public:
	virtual bool init();
	static cocos2d::Scene* scene();
	void update(float delta);
	void meterMove();//メーターの関数
	int getmeterReturn();

	CREATE_FUNC(UILayer);
};

#endif //__UILAYER_H__