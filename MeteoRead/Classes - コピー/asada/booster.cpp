#include "asada\booster.h"
USING_NS_CC;

Booster::Booster(){

}
Booster::~Booster(){

}
bool Booster::init(){

	if (!Sprite::initWithFile("Booster1.png")){
		return false;
	}

	//画像設定
	auto framesize = Size(this->getContentSize().width / Frame_Count,
		this->getContentSize().height/Frame_County);
	this->setTextureRect(Rect(0, 0, framesize.width, framesize.height));

	//１コマずつアニメーションを設定する
	for (int y = 0; y < Frame_County; ++y){
		for (int x = 0; x < Frame_Count; ++x){
			auto frame = SpriteFrame::create("Booster1.png", Rect(framesize.width*x,
				framesize.height*y,
				framesize.width,
				framesize.height));
			_boost.pushBack(frame);
		}
	}

	//アニメーションを実行させる
	auto animetion = Animation::createWithSpriteFrames(_boost);
	animetion->setDelayPerUnit(ANIMETION);
	this->runAction(RepeatForever::create(Animate::create(animetion)));

	return true;
}

//パワーをいれてアニメーションの速度を変える
void Booster::SetPower(int power){


}