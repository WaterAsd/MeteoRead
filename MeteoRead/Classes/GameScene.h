#ifndef __METEOREAD__GAME__
#define __METEOREAD__GAME__

#include "cocos2d.h"
#include "KBT/UILayer.h"
#include "KBT/Road.h"
#include "asada/Earth.h"
#include "asada/Rocket.h"
#include "asada/Calculation.h"
#include "asada/Start.h"

class GameScene : public cocos2d::Layer
{
private:
	Size visibleSize;
	UILayer* _UILayer;//UIのポインター
	Calculation* _Cal;//計算機のポインター
	Start* _start;
	Road* _road;

	std::string goalmai;//星に入れる名前（ゴールフラグ？）
	bool goalset;		//星のゴールは一つなのでフラグを作成
	bool goalflg;		//星にゴールしたかどうかを設定するフラグ

	float PlayerMoveX;
	float PlayerMoveY;

	int starCount;//星の数を覚えておく
	

	void StarSet(Vec2 Pos, std::string hosimei);//画面に星を入れる。
	void GoalStarset(Vec2 Pos, std::string hosimei);
	void selectSter(Earth* hosi);//公転するほしが近くにあるかどうか

	Earth *axishosi;//軸となる公転の星

	bool touchOK;	//公転時に発射の準備を設ける。
					//true:発射準備中
					//false:発射もしくは直進中

public:
	static Vec2 RoPos;
	static Vec2 starPos[4];
	static Vec2 goalPos;
	static Vector<Earth*> stars;//星の座標一覧を取得する。
	static Rocket* _rocket;//ロケットのポインター
	static bool gameOver;//ゲームオーバーフラグ
	static cocos2d::Scene* createScene();//ゲームシーンの作成
	virtual bool init();//初期化宣言
	void update(float delta);	//毎フレーム更新する
	CREATE_FUNC(GameScene);//クラスの宣言
	static UILayer* uiLayer;//UILayerを使えるようにする。
	static Earth* earth;//星クラスを使える様にする。
};

#endif //__METEOREAD__GAME__