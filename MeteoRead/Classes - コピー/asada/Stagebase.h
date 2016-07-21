#ifndef __MATEOREAD__STAGEBASE__
#define __METEOREAD__STAGEBASE__

#include "cocos2d.h"
#include "asada/Earth.h"
#include "asada\Rocket.h"
#include "asada/Calculation.h"
#include "KBT\Road.h"

class Stagebase :public cocos2d::Layer{

protected:

	bool _startflg;		//スタートしたかどうかのフラグ
	bool _goalflg;		//ゴールしてもよいかのフラグ
	bool _buttontouch;	//ボタンをタッチしたかどうかを確認するフラグ

	int _rocketspeed;	//ロケットのもともとの数値
	int _rocketpower;	//UiLayerで追加された数値分のpower

	Road *_road;		//道の情報
	Calculation *_Cal;	//計算機の情報

	std::string goalmai;//星に入れる名前（ゴールフラグ？）
	bool goalset;		//星のゴールは一つなのでフラグを作成

	SpriteBatchNode *_star;

	int starCount;//星の数を覚えておく
	Vector<Earth*> stars;//星の座標一覧を取得する。

	void StarSet(Vec2 Pos, std::string hosimei);//画面に星を入れる。
	void GoalStarset(Vec2 Pos, std::string hosimei);
	void selectSter(Earth* hosi);//公転するほしが近くにあるかどうか

	Earth *axishosi;//軸となる公転の星

	bool touchOK;	//公転時に発射の準備を設ける。
					//true:発射準備中
					//false:発射もしくは直進中

private:
	

public:
	Rocket *_rocket;	//ロケットの情報

	void setstartflg(bool flg);			//ゲームがスタートしたかどうかを確認するのフラグ
	void setrocketpower(int power);		//ロケットのスピードを受け取るためのフラグ
	void setbottontouch(bool touch);		//ボタンをタッチしたかどうかを確認するためのフラグ

	bool getgoalflg();					//ゴールしたかどうかを確認する関数
	int getRocketPower();				//ロケットのパワー（スピード力）
};

#endif __METEOREAD__STAGEBASE__