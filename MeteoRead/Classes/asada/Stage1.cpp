#include "asada/Stage1.h"

//公転する星との距離
const float Hosikoutenn = 80.0f;

//初期化の作成しました。
bool Stage1::init(){
	if (!Layer::init())return false;

	_startflg=false;		
	_goalflg=false;		
	_buttontouch=false;	
	_rocketspeed = 1;
	_rocketpower = 1;

	_star = SpriteBatchNode::create("star2.png");
	this->addChild(_star);

	//画面サイズを獲得する
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//背景画像の作成
	auto Space = Sprite::create("Space.jpg");
	Space->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(Space);

	//星を出現させる
	auto hosimei = std::string("Earth.png");
	StarSet(Vec2(visibleSize.width / 2 + 300, visibleSize.height / 2 - 200), hosimei);
	StarSet(Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 - 200), hosimei);
	StarSet(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 + 100), hosimei);
	StarSet(Vec2(visibleSize.width / 2, visibleSize.height / 2), hosimei);

	//ゴールする星に入れる名前の設定
	goalmai = std::string("goal");
	goalset = false;
	GoalStarset(Vec2(200, visibleSize.height - 200), goalmai);

	//ロケットを出現させる
	auto rocket = Rocket::create();
	rocket->setPosition(visibleSize.width, 0);
	rocket->setRotation(-90);
	this->addChild(rocket);
	_rocket = rocket;

	//計算機を作成する
	auto Cal = Calculation::create();
	_Cal = Cal;

	this->scheduleUpdate();

	return true;
}

//更新処理
void Stage1::update(float delta){

	auto speed = _rocketspeed + _rocketpower*0.5f;

	//配列に入っている星の数までfor分で処理する
	//内容：ロケットに近く星があるかどうか（複数個あるなら一番近い場所を選択する）
	if (_rocket->getRevolutionflg() == false){
		Earth*karihosi = axishosi;
		float smoleLength = NULL;
		for (auto hosis : stars){
			float length = ccpDistance(hosis->getPosition(), _rocket->getPosition());
			if (length <= Hosikoutenn && (length < smoleLength || smoleLength == NULL) && karihosi != hosis){
				axishosi = hosis;
				smoleLength = length;
				_rocket->setRevolutionflg(true);
			}
		}
	}

	//ゴールの星に公転できたらクリア画面を出す。
	if (_rocket->getRevolutionflg() == true &&
		axishosi->getName() == goalmai&&
		_goalflg == false){
		_goalflg = true;
	}

	/*公転フラグがtrueでUiLayerのtouchがtrueなら
	touchOKをfalseにして発射する*/
	if (_rocket->getRevolutionflg() == true &&
		_buttontouch == false &&
		touchOK == true){
		touchOK = false;
		_rocket->setRevolutionflg(false);
	}

	/*公転フラグがtrueで、UiLayerのtouchがfalseなら
	touchOKをtrueにして発射の準備をする*/
	if (_rocket->getRevolutionflg() == true &&
		_buttontouch == true){
		touchOK = true;
	}
	//もし公転フラグがtrueならば公転させて、
	//falseならば、向いてる方向に移動させる。
	if (_rocket->getRevolutionflg() == true){
		_Cal->angle(axishosi, _rocket, speed);//公転させる
	}
	else{
		_Cal->move(_rocket,speed);//直進運動させる
	}

	//もしボタンを押しているのなら矢印を表示させる。

	auto hosi1 = stars.at(2);
	auto hosi2 = stars.at(3);

	_Cal->hosiangle(hosi1, hosi2, 1.0f);
}

void Stage1::setRoad(){
	auto hoge = Sprite::createWithTexture(_star->getTexture());
	hoge->setPosition(_rocket->getPosition());
	this->addChild(hoge,-1);
}