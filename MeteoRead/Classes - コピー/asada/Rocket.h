#ifndef __METEOROAD__ROCKET__
#define __METEOROAD__ROCKET__

#include "cocos2d.h"
#include "asada/booster.h"
#include "asada\Earth.h"
using namespace cocos2d;

enum rocketstate{
	FLY = 0,	//飛んでいる
	Prelaunch,	//発射前
	revolution,	//公転している
	MAX = 3
};

class Rocket : public cocos2d::Node{
private:
	//パワーの列挙方を作成する
	enum Speed{
	ONE = 1,
	TWO,
	THREE,
	FOUR,
	};
	Speed _speed;
	int speed;
	float rot;

	Sprite *_arrow;//矢印画像を入れておくためのポインター変数
	bool _flgarrow;//矢印を出してもよいかを確認するbool型

	Sprite* _Rocket;//ロケット扱える様にする為のポインター
	Booster* _booster;//ブースターを扱える様にするためのポインター

	
	Rect RocketRect;//ロケットの矩形

	bool revolutionflg;//公転を実行させるフラグ

	void update(float dt);

public:
	//ロケットの状態を表している変数
	CC_SYNTHESIZE(rocketstate, _rockcetstate, RocketState);

	static Vec2 RocketPos;//ロケットの座標
	//画像の最大サイズ
	const int MAXSPRITEX = 40;
	const int MAXSPRITEY = 60;

	//ロケットの座標にまつわる関数
	void setRocketPos(Vec2 pos);
	Vec2 getRocketPos();

	//ロケットの矩形にまつわる関数
	void setRocketRect(Rect re);
	Rect getRocketRect();

	//ロケットの速さにまつわる変数
	float getSpeed();

	//ロケットが公転するためにフラグ
	void setRevolutionflg(bool flg);
	bool getRevolutionflg();

	//移動に関する関数処理
	void move(float speed);
	void Col(const Earth*,int speed);

	//矢印を出してもよいかを確認する処理
	void setArrow(const bool flg);

	//ブースターの画像を一枚ずつ保存しておくための入れ物
	CC_SYNTHESIZE_PASS_BY_REF(cocos2d::Vector<cocos2d::SpriteFrame*>, _but, But);

	virtual bool init();
	CREATE_FUNC(Rocket);
};

#endif//__METEOROAD__ROCKET__