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
	Sprite* button;             //ボタンの画像
	Sprite* map;                //マップ画像
	Sprite* myIcon;             //ロケットのアイコン
	Sprite* number;             //数字

	//int
	int up;                     //メーターの表示用の変数　0～5
	int upCount;                //カウント
	int timer[3];	//0=分　1=秒　2=コンマ
	int j;

	//float
	float power;//ロケットの移動量

	//Point
	Point touchPoint;				// タッチされた場所

	//Rect
	Rect buttonRect;             //ボタンのレクト

	//Label
	Label *clock[3];

	//Color3B
	Color3B buttonColor;//ボタンの色

	virtual bool onTouchBegan(cocos2d::Touch* ptouch, cocos2d::Event* pEvent);		// タッチした時の準備
	virtual void onTouchEnded(cocos2d::Touch* ptouch, cocos2d::Event* pEvent);		// タッチを離した時の準備

	void Button();
	void MeterMove();//メーターのクラス
	void Map();//マップのクラス
	void Timer();//時間のクラス

	void CreateSprite();	// 画像作成クラス

private:

public:
	virtual bool init();
	static cocos2d::Scene* scene();
	void update(float delta);

	int getmeterReturn();

	bool touch;

	CREATE_FUNC(UILayer);
};

#endif //__UILAYER_H__