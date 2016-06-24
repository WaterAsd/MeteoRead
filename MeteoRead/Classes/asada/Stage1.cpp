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
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	//ゴールする星に入れる名前の設定
	goalset = false;
	goalmai = std::string("goal");

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
	/*auto hosi1 = stars.at(2);
	auto hosi2 = stars.at(3);

	_Cal->hosiangle(hosi1, hosi2, 1.0f);*/
}

void Stage1::setRoad(){
	auto hoge = Sprite::createWithTexture(_star->getTexture());
	hoge->setPosition(_rocket->getPosition());
	this->addChild(hoge,-1);
}

//ステージによって星を配置する
void Stage1::stageSelect(int count){
	auto hosimei = std::string("Earth.png");
	auto rocket = Rocket::create();

	switch (count)
	{
	case 1:
		/*ここに星を配置するものを入力してください。*/
		StarSet(Vec2(visibleSize.width / 2 + 300, visibleSize.height / 2 - 200), hosimei);
		StarSet(Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 - 200), hosimei);
		StarSet(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 + 100), hosimei);
		StarSet(Vec2(visibleSize.width / 2, visibleSize.height / 2), hosimei);
		GoalStarset(Vec2(200, visibleSize.height - 200), goalmai);

		/*ここにロケットの配置場所を入力してください。*/
		rocket->setPosition(visibleSize.width,0);
		rocket->setRotation(-90);
		follorRocket(rocket);
		this->addChild(rocket);
		_rocket = rocket;
		break;
	case 2:
		StarSet(Vec2(visibleSize.width / 2 + 300, visibleSize.height / 2 - 200), hosimei);
		StarSet(Vec2(visibleSize.width / 2 - 300, visibleSize.height / 2 - 200), hosimei);
		StarSet(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 + 100), hosimei);
		StarSet(Vec2(visibleSize.width / 2, visibleSize.height / 2), hosimei);
		GoalStarset(Vec2(200, visibleSize.height - 200), goalmai);

		rocket->setPosition(visibleSize.width, 0);
		rocket->setRotation(-90);
		this->addChild(rocket);
		_rocket = rocket;
		break;

	default:
		break;
	}
}

void Stage1::setStageSelect(const int count){
	_stageselect = count;
}

//rocketにカメラを追尾するための処理
void Stage1::follorRocket(Rocket* rocket){
	_setrocket = Follow::create(rocket);
	_setrocket->setTag(20);
	this->runAction(_setrocket);
}

//Rocketの自動追尾をやめるための処理
void Stage1::stopRocket(){
	this->stopActionByTag(20);
}

void Stage1::moveLayer(Vec2 move){
	this->setPosition(this->getPosition() + move);
}