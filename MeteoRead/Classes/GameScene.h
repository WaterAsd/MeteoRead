#ifndef __METEOREAD__GAME__
#define __METEOREAD__GAME__

#include "cocos2d.h"
#include "KBT/UILayer.h"
#include "asada/Earth.h"
#include "asada/Rocket.h"

class GameScene : public cocos2d::Layer
{
private:
	Rocket* _rocket;//ロケットのポインター

	int starCount;//星の数を覚えておく
	Vector<Earth*> stars;//星の座標一覧を取得する。
	void StarSet(Vec2 Pos);//画面に星を入れる。

public:
	static cocos2d::Scene* createScene();//ゲームシーンの作成
	virtual bool init();//初期化宣言
	void update(float delta);	//毎フレーム更新する
	CREATE_FUNC(GameScene);//クラスの宣言
	static UILayer* uiLayer;//UILayerを使えるようにする。
	static Earth* earth;//星クラスを使える様にする。
};

#endif //__METEOREAD__GAME__