#ifndef __UILAYER_H__
#define __UILAYER_H__

#include "cocos2d.h"
#include "Math.h"
#include "ui/CocosGUI.h"
#include "Statics.h"

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
	Sprite* starIcon[4];            //星のアイコン
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
	Vec2 starWorldPosition[4];
	Vec2 goalWorldPosition;
	Vec2 starLocalPosition[4];
	Vec2 goalLocalPosition;

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
	

	//ゲームシーンから送られた情報を保存しておくための変数
	Vec2 _rocketpos;			//ロケットの場所
	std::vector<Vec2> _starspos;		//星の場所
	Rect _rect;					//stageの大きさ
	Vec2 _goalpos;				//ゴールの場所

	//ミニマップを扱うので作成しました
	Sprite *_map;				//マップ画像の情報がほしいので作成します。
	Vec2 _stagesize;			//マップ画面にあわせたRectの変数

	//ミニマップ用のサイズに切り替える関数の作成
	void minimapcreate();


public:
	//ミニマップに必要な変数を獲得するための関数を作成する
	void getRocketPos(const Vec2 rocketpos);	//ロケットの場所
	void getStarsPos(const Vec2 starspos);	//星の場所
	void getStageRect(const Rect Stagerect);	//ステージの大きさ
	void getgoalPos(const Vec2 goalpos);		//ゴールの場所

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