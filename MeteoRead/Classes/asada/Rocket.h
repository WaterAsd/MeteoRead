#ifndef __METEOROAD__ROCKET__
#define __METEOROAD__ROCKET__

#include "cocos2d.h"
#include "asada/booster.h"
using namespace cocos2d;

class Rocket : public cocos2d::Node{
private:

	//パワーの列挙方を作成する
	enum Power{
	ONE = 1,
	TWO,
	THREE,
	FOUR,
	};
	Power _power;

	Sprite* _Rocket;//ロケット扱える様にする為のポインター
	Booster* _booster;//ブースターを扱える様にするためのポインター

	Vec2 RocketPos;//ロケットの座標
	Rect RocketRect;//ロケットの矩形

	void update(float dt);

public:

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
	void setPower(int pw);
	int  getPower();

	//ブースターの画像を一枚ずつ保存しておくための入れ物
	CC_SYNTHESIZE_PASS_BY_REF(cocos2d::Vector<cocos2d::SpriteFrame*>, _but, But);

	virtual bool init();
	CREATE_FUNC(Rocket);
};

#endif//__METEOROAD__ROCKET__