#ifndef __STAGE__H__
#define __STGAE__H__

#include "cocos2d.h"
#include "Statics.h"
#include "asada/Rocket.h"
#include "asada/Earth.h"

class Stage :public cocos2d::Layer{
private:

	Size _gamewindou;
	int hosikouten;
	bool touchOK;

	//星の名前を入れる変数
	std::string goalmai;

	//自作変数
	Rocket *_rocket;				//ロケットの情報
	std::vector<Earth*> _stars;		//星の情報
	Earth* _goal;					//ゴールの情報
	Rect _stagerect;				//ステージの大きさ

	bool _gameover, _gameclear;		//ゲームオーバーとゲームクリア
	bool _col;						//公転しているかどうか

	Earth *_axishosi;				//現在選択している星

	//自作クラス
	void SetStar(Vec2 Pos, std::string hosimei);
	void Setgoalstar(Vec2 Pos, std::string hosimei);

public:
	void StageCreate(int count);

	void staticset();

	//クラス生成に必要最低限のクラス
	virtual bool init();			
	void update(float delta);

	CREATE_FUNC(Stage);
};

#endif//__STAGE__H__