#include "asada/Start.h"
USING_NS_CC;
bool Start::init(){
	if (!Node::init()){return false;}

	OK = false;

	//必要な素材
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//spriteの画像
	Sprite *Sp1, *Sp2, *Sp3, *SpGo;//表示させるための画像を表示させる。
	Sp1 = Sprite::create("1.png");
	Sp1->setPosition(visibleSize / 2);
	Sp1->setRotation(180.0f);
	Sp1->setScale(0.0f);

	Sp2 = Sprite::create("2.png");
	Sp2->setPosition(visibleSize / 2);
	Sp2->setRotation(180.0f);
	Sp2->setScale(0.0f);

	Sp3 = Sprite::create("3.png");
	Sp3->setPosition(visibleSize / 2);
	Sp3->setRotation(180.0f);
	Sp3->setScale(0.0f);

	SpGo = Sprite::create("GO.png");
	SpGo->setPosition(visibleSize / 2);
	SpGo->setRotation(180.0f);
	SpGo->setScale(0.0f);

	this->addChild(Sp1);
	this->addChild(Sp2);
	this->addChild(Sp3);
	this->addChild(SpGo);

	//動きに関するものを実行する
	auto big = ScaleTo::create(0.5f,0.7f);
	auto rot = RotateBy::create(0.5f,180.0f);
	auto bigrot = Spawn::create(big, rot, NULL);
	auto smole = ScaleTo::create(0.3f,0.0f);
	auto stop = DelayTime::create(0.5f);
	auto sequ = Sequence::create(bigrot,smole,NULL);

	//アクションを実行させる
	this->runAction(Sequence::create(
		TargetedAction::create(Sp3, sequ),
		TargetedAction::create(Sp2, sequ),
		TargetedAction::create(Sp1, sequ),
		TargetedAction::create(SpGo, sequ),
		CallFunc::create([this](){this->OK=true;}),
		nullptr
		));

	return true;
}

bool Start::getStart(){
	return OK;
}