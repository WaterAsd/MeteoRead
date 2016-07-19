#ifndef __STATICS_H__
#define __STATICS_H__

#include "cocos2d.h"
#include "Math.h"

USING_NS_CC;

using namespace cocos2d;

class Statics : public cocos2d::Ref
{
public:
	static Vec2 myPos;  //プレイヤーの位置
	static int myRot;  //プレイヤーの回転量
	static int myPower;//プレイヤーの移動量
	static std::vector<Vec2> starPos;  //星の位置
	static Vec2 goalPos;  //ゴールの位置
	static Vec2 gimmickPos;  //ギミックの位置
	static Rect stageRect;  //ステージの比率

	static bool clearFlg;  //クリアしたかどうか
	static bool gameOverFlg;  //ゲームオーバーのフラグ

	static bool touchFlg;  //タッチしたかどうか
	static bool flyFlg;  //飛んでるかどうか

	static int stageSelect;  //ステージの番号
	static int touchCount;
};


#endif//__STATICS__