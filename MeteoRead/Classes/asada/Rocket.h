#ifndef __METEOROAD__ROCKET__
#define __METEOROAD__ROCKET__

#include "cocos2d.h"

class Rocket : public cocos2d::Node{
private:

	Vec2 RocketPos;//ロケットの座標
	Rect RocketRect;//ロケットの座標
	int Power;//ロケットのパワー力

	void RocketSpeed(int Pw);//ロケットのスピードを設定する

	void boosterCreate();
public:

	Vec2 getRocketPos();
	Rect getRocketRect();
	int  setPower(int pw);

	//ブースターの画像を一枚ずつ保存しておくための入れ物
	CC_SYNTHESIZE_PASS_BY_REF(cocos2d::Vector<cocos2d::SpriteFrame*>, _but, But);

	virtual bool init();
	CREATE_FUNC(Rocket);
};

#endif//__METEOROAD__ROCKET__