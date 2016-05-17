#ifndef __METEOROAD__ROCKET__
#define __METEOROAD__ROCKET__

#include "cocos2d.h"
#include "asada/booster.h"
using namespace cocos2d;

class Rocket : public cocos2d::Node{
private:
	Sprite* _Rocket;//ロケット扱える様にする為のポインター
	Booster* _booster;//ブースターを扱える様にするためのポインター

	Vec2 RocketPos;//ロケットの座標
	Rect RocketRect;//ロケットの矩形
	int  Power;//ロケットのパワー(力)
	void RocketSpeed(int Pw);//ロケットのスピードを設定する

	void update(float dt);

public:

	//画像の最大サイズ
	const int MAXSPRITEX = 40;
	const int MAXSPRITEY = 60;

	void setRocketPos(Vec2 pos);//ロケットの座標を送る
	void setRocketRect(Rect re);//ロケットの矩形を送る
	void setPower(int pw);//ロケットの速さを変える

	//ブースターの画像を一枚ずつ保存しておくための入れ物
	CC_SYNTHESIZE_PASS_BY_REF(cocos2d::Vector<cocos2d::SpriteFrame*>, _but, But);

	virtual bool init();
	CREATE_FUNC(Rocket);
};

#endif//__METEOROAD__ROCKET__