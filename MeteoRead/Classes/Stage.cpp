#include "Stage.h"
USING_NS_CC;
bool Stage::init(){
	if (!Layer::init()){ return false; }

	//画面サイズを取得する
	_gamewindou = Director::getInstance()->getVisibleSize();

	//ロケットの情報を生成
	auto rocket = Rocket::create();
	this->addChild(rocket);
	_rocket = rocket;

	auto black = Sprite::create("new black hole sample.png");
	black->setPosition(Vec2(_gamewindou.width / 2, _gamewindou.height / 2-100));
	this->addChild(black);

	auto action = RotateTo::create(1, 45);
	auto repeatForever = Repeat::create(action,-1);
	//アニメーション開始
	black->runAction(repeatForever);

	hosikouten = 80;
	goalmai = "goal";
	touchOK = true;
	_gameover = false;

	Statics::flyFlg = true;

	this->scheduleUpdate();

	return true;
}

//
void Stage::update(float dt){
	//値取得
	auto speed = _rocket->getSpeed() + Statics::touchCount*0.5f;
	//ロケットの矢印どうするか・・・
	_rocket->setArrow(Statics::touchFlg);

	if (_stagerect.containsPoint(_rocket->getPosition())==false){
		Statics::gameOverFlg = true;
	}

	//配列に入ってくる星の数までfor分で処理
	if (Statics::flyFlg == true){
		Earth*karihosi = _axishosi;
		float smoleLength = NULL;
		for (auto hosis : _stars){
			float length = ccpDistance(hosis->getPosition(), _rocket->getPosition());
			if (length <= hosikouten && (length < smoleLength || smoleLength == NULL) && karihosi != hosis){
				_rocket->LRCol(hosis, _rocket->getSpeed());
				_axishosi = hosis;
				smoleLength = length;
				Statics::flyFlg = false;
				_rocket->setRocketState(rocketstate::revolution);
			}
		}
	}

	//ゴールの星に公転できたらクリア画面を出す。
	if (_rocket->getRocketState() == rocketstate::revolution&&
		_axishosi->getName() == goalmai&&
		Statics::clearFlg == false){
		Statics::clearFlg = true;
	}

	//状態によって数値を変更していく
	switch (_rocket->getRocketState())
	{
	case rocketstate::FLY:
		Statics::flyFlg = true;
		_rocket->move(_rocket->getSpeed());
		break;
	case rocketstate::Prelaunch:
		if (Statics::touchFlg != true)
			_rocket->setRocketState(rocketstate::FLY);
		else
			_rocket->Col(_axishosi, _rocket->getSpeed());//公転させる
		break;

	case rocketstate::revolution:
		if (Statics::touchFlg == true)
			_rocket->setRocketState(rocketstate::Prelaunch);
		else if(Statics::touchFlg == false)
			_rocket->Col(_axishosi, _rocket->getSpeed());//公転させる
		break;
	}

	_rocket->setArrow(Statics::touchFlg);

	Stage::staticset();
}

//星を生成する
void Stage::SetStar(Vec2 Pos, std::string hosimei){
	auto earth = Earth::create();
	earth->planetcreate(hosimei);
	earth->setPosition(Pos);
	this->addChild(earth);
	_stars.push_back(earth);
}

//ゴールの星を生成する
void Stage::Setgoalstar(Vec2 Pos, std::string hosimei){
	if (_goal == 0){}
	else{
		auto earth = Earth::create();
		earth->planetcreate("goalstars2.png");
		earth->setName(hosimei);
		earth->setPosition(Pos);
		this->addChild(earth);
		_goal = earth;
		_stars.push_back(earth);
	}
}

//staticクラスに情報を入れる
void Stage::staticset(){
	Statics::myPos = _rocket->getPosition();
	Statics::myRot = _rocket->getRotation();
	Statics::starPos.clear();
	for (auto star:_stars){
		Statics::starPos.push_back(star->getPosition());
	}
	Statics::goalPos = _goal->getPosition();
	Statics::stageRect = _stagerect;
}

//ステージを生成するために入れるクラス
void Stage::StageCreate(int count){
	auto hosimei = std::string("Earth.png");
	auto rocket = Rocket::create();
	Rect stagerect;
	switch (count)
	{
	case 1:
		/*ここにステージの大きさを設定する*/
		stagerect.setRect(-200, -200, _gamewindou.width + 400, _gamewindou.height + 400);
		_stagerect = stagerect;

		/*ここに星を配置するものを入力してください。*/
		SetStar(Vec2(_gamewindou.width / 2 + 300, _gamewindou.height / 2 - 200), hosimei);
		SetStar(Vec2(_gamewindou.width / 2 - 300, _gamewindou.height / 2 - 200), hosimei);
		SetStar(Vec2(_gamewindou.width / 2 + 100, _gamewindou.height / 2 + 100), hosimei);
		SetStar(Vec2(_gamewindou.width / 2, _gamewindou.height / 2), hosimei);
		Setgoalstar(Vec2(200, _gamewindou.height - 200), goalmai);

		/*ここにロケットの配置場所を入力してください。*/
		rocket->setPosition(Vec2(_gamewindou.width, 1.0f));
		rocket->setRotation(-90);
		this->addChild(rocket);
		_rocket = rocket;
		break;
	case 2:
		/*ここに星を配置するものを入力してください。*/
		SetStar(Vec2(_gamewindou.width / 2 + 300, _gamewindou.height / 2 - 200), hosimei);
		SetStar(Vec2(_gamewindou.width / 2 - 300, _gamewindou.height / 2 - 200), hosimei);
		SetStar(Vec2(_gamewindou.width / 2 + 100, _gamewindou.height / 2 + 100), hosimei);
		SetStar(Vec2(_gamewindou.width / 2, _gamewindou.height / 2), hosimei);
		Setgoalstar(Vec2(200, _gamewindou.height - 200), goalmai);

		/*ここにロケットの配置場所を入力してください。*/
		rocket->setPosition(_gamewindou.width, 0);
		rocket->setRotation(-90);
		this->addChild(rocket);
		_rocket = rocket;
		break;

	case 3:
		/*ここに星を配置するものを入力してください。*/
		SetStar(Vec2(_gamewindou.width / 2 + 300, _gamewindou.height / 2 - 200), hosimei);
		SetStar(Vec2(_gamewindou.width / 2 - 300, _gamewindou.height / 2 - 200), hosimei);
		SetStar(Vec2(_gamewindou.width / 2 + 100, _gamewindou.height / 2 + 100), hosimei);
		SetStar(Vec2(_gamewindou.width / 2, _gamewindou.height / 2), hosimei);
		Setgoalstar(Vec2(200, _gamewindou.height - 200), goalmai);

		/*ここにロケットの配置場所を入力してください。*/
		rocket->setPosition(_gamewindou.width, 0);
		rocket->setRotation(-90);
		this->addChild(rocket);
		_rocket = rocket;
		break;

	default:
		break;
	}
}