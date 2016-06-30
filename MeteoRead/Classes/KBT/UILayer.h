#ifndef __UILAYER_H__
#define __UILAYER_H__

#include "cocos2d.h"
#include "Math.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace cocos2d;

class MapNode : public cocos2d::Node{
public:
	//画面に表示させる為の素材を獲得するための関数
	void setrocket(Vec2 rocket);
	void setstarpos(std::vector<Vec2> pos);
	void setgoalpos(Vec2 goal);
	void setStagerect(Rect stagesize);

	//画面サイズの調整を図るための変数
	void mapcreate();
	void Mapsize();

	//クラスを作る為に必要なもの
	CREATE_FUNC(MapNode);
private:
	//mapcreateを何度も作成するので制限をかける
	bool oneflg;

	//簡単に必要なもの
	virtual bool init();
	void update(float dt);

	//現在の星の座標を獲得する
	Vec2 _rocketpos;
	Vec2 _goalpos;
	std::vector<Vec2>_starpos;
	Rect _stagesize;

	//ロケットの画像や必要な素材の画像の種類
	Sprite *_rocket;
	cocos2d::Vector<CCDrawNode*> _star;
	CCDrawNode *_goal;

	//マップの平均的なサイズを獲得する
	Vec2 mapsize;

	//マップの背景を取得するためのもの
	Sprite *_map;
};

/*--------------------------------------------------------------------------------------------------------------------

ここからUiLayerです。




---------------------------------------------------------------------------------------------------------------------*/

class UILayer : public cocos2d::Layer
{
protected:
	Size winSize;				// 画面サイズ

	//Sprite
	Sprite* meter;              //メーターの画像
	Sprite* button;             //ボタンの画像
	Sprite* myIcon;             //ロケットのアイコン
	Sprite* starIcon;
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

	//Color3B
	Color3B buttonColor;//ボタンの色

	virtual bool onTouchBegan(cocos2d::Touch* ptouch, cocos2d::Event* pEvent);		// タッチした時の準備
	virtual void onTouchEnded(cocos2d::Touch* ptouch, cocos2d::Event* pEvent);		// タッチを離した時の準備

	void Button();
	void MeterMove();//メーターのクラス
	void Map();//マップのクラス
	void Timer();//時間のクラス

	void CreateSprite();	// 画像作成クラス

	//現在の星の座標を獲得する
	Vec2 _rocket;
	Vec2 _goal;
	std::vector<Vec2>_starpos;
	//マップの平均的なサイズを獲得する
	Rect mapsize;

private:

public:
	MapNode *_minimap;

	virtual bool init();
	static cocos2d::Scene* scene();
	void update(float delta);

	bool getTouch();

	int getmeterReturn();

	bool touch;

	CREATE_FUNC(UILayer);
};

#endif //__UILAYER_H__