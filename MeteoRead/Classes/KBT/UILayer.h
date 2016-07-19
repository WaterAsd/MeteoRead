#ifndef __UILAYER_H__
#define __UILAYER_H__

#include "cocos2d.h"
#include "Math.h"
#include "ui/CocosGUI.h"

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
	Sprite* starIcon[10];            //星のアイコン
	Sprite* goalIcon;            //ゴールのアイコン
	Sprite* number[6];             //数字

	//int
	int up;                     //メーターの表示用の変数　0～5
	int upCount;                //カウント
	int timer[6];	//0,1=分　2,3=秒　4,5=コンマ

	//float
	float power;//ロケットの移動量

	//Point
	Point touchPoint;				// タッチされた場所

	//Rect
	Rect buttonRect;             //ボタンのレクト

	//Label
	Label *clock[3];

	//Vec2
	Vec2 iconPos;
	//アイコン用
	Vec2 worldPosition;
	Vec2 localPosition;
	std::vector<Vec2>starWorldPosition;
	Vec2 goalWorldPosition;
	std::vector<Vec2>starLocalPosition;
	Vec2 goalLocalPosition;
	Vec2 pos[4];
	Vec2 pos2[4];

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

	void starset(int star);

	bool getTouch();

	int getmeterReturn();

	bool touch;

	CREATE_FUNC(UILayer);
};

#endif //__UILAYER_H__