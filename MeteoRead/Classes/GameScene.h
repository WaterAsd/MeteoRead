#ifndef __METEOREAD__GAME__
#define __METEOREAD__GAME__

#include "cocos2d.h"
#include "KBT/UILayer.h"
#include "asada/Earth.h"
#include "asada/Rocket.h"
#include "asada/Calculation.h"
#include "asada/StartScene.h"
#include "KBT/Road.h"
#include "asada/Goal.h"
#include "asada/Stage1.h"
#include "Stage.h"

//ゲームの状態を表している列挙形
enum GameState{
	START = 0,
	GAME,
	CLEAR,
	GAMEOVER,
	GAMEEND,
	MAXGAMESTATE
};

class GameScene : public cocos2d::Layer
{
private:
	//ゲーム状態を表している変数
	GameState _gamestate;

	UILayer* uiLayer;

	bool _startflg;

	Vec2 touchpoint;

	Size visibleSize;
	Vec2 origin;

	Stage *_stage1;
	
	Calculation* _Cal;//計算機のポインター
	StartScene* _start;
	Road* _road;

	std::string goalmai;//星に入れる名前（ゴールフラグ？）
	bool goalset;		//星のゴールは一つなのでフラグを作成
	bool goalflg;

	UILayer* _UILayer;

	float PlayerMoveX;
	float PlayerMoveY;

	int starCount;//星の数を覚えておく
	Vector<Earth*> stars;//星の座標一覧を取得する。

	void StarSet(Vec2 Pos, std::string hosimei);//画面に星を入れる。
	void GoalStarset(Vec2 Pos, std::string hosimei);
	void selectSter(Earth* hosi);//公転するほしが近くにあるかどうか

	Earth *axishosi;//軸となる公転の星

	bool touchOK;	//公転時に発射の準備を設ける。
					//true:発射準備中
					//false:発射もしくは直進中

	//ＵＩのミニマップに必要な情報を入れる
	void minimapdate();

public:
	void Start();
	void GameOver();
	void GameClear();

	static int SelectCount;
	void getStage(int count);
	Stagebase craeateStage(int count);

	static bool gameOver;

	static Vec2 RoPos;
	static Vec2 starPos[4];
	static Vec2 goalPos;

	static cocos2d::Scene* createScene();//ゲームシーンの作成
	virtual bool init();//初期化宣言
	void update(float delta);	//毎フレーム更新する
	CREATE_FUNC(GameScene);//クラスの宣言
	static Earth* earth;//星クラスを使える様にする。
};

#endif //__METEOREAD__GAME__