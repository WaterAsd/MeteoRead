#include "Stagebase.h"

//星を作成することができます
void Stagebase::StarSet(Vec2 Pos, std::string hosimei){
	auto earth = Earth::create();
	earth->planetcreate(hosimei);
	earth->setPosition(Pos);
	this->addChild(earth);
	starCount++;//星の数増やす。
	stars.pushBack(earth);//星の情報を保存する。
	//starsname.pushBack(hosimei);//星の名前を取得しておく
}

//ゴールとなる星を作成することができます。
void Stagebase::GoalStarset(Vec2 Pos, std::string hosimei){
	if (goalset == true){}

	else{
		auto earth = Earth::create();
		earth->planetcreate("goalstars2.png");
		earth->setName(hosimei);
		earth->setPosition(Pos);
		this->addChild(earth);
		starCount++;//星の数増やす。
		stars.pushBack(earth);//星の情報を保存する。
		goalset == false;
	}
}

//公転するほしが近くにあるかどうか
void Stagebase::selectSter(Earth* hosi){
	float smoleLength = NULL;
	Earth*karihosi = 0;
	//配列に入っている星の数までfor分で処理する
	//内容：ロケットに近く星があるかどうか（複数個あるなら一番近い場所を選択する）
	for (auto hosis : stars){
		float length = ccpDistance(hosis->getPosition(), _rocket->getPosition());
		if (length <= 100.0f && (length < smoleLength || smoleLength == NULL)){
			karihosi = hosis;
			smoleLength = length;
			_rocket->setRevolutionflg(true);
		}
	}
	hosi = karihosi;
}

//スタートしてもよいかのフラグ
void Stagebase::setstartflg(const bool flg){
	_startflg = flg;
}

//ロケットのパワーをもらう関数
void Stagebase::setrocketpower(const int power){
	_rocketpower = power;
}

//ボタンをタッチしたかどうかを判定する関数
void Stagebase::setbottontouch(bool touch){
	_buttontouch = touch;
}

//ゴールしたかどうかを返すための関数
bool Stagebase::getgoalflg(){
	return _goalflg;
}

//ロケットのパワーを受け取るフラグ
int Stagebase::getRocketPower(){
	return _rocketpower;
}