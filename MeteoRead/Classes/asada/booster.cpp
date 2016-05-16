#include "asada\booster.h"
USING_NS_CC;

Booster::Booster(){

}
Booster::~Booster(){

}
bool Booster::init(){
	if (!Sprite::initWithFile("Booster.png")){
		return false;
	}

	//�摜�ݒ�
	auto framesize = Size(this->getContentSize().width / Frame_Count,
		this->getContentSize().height);
	this->setTextureRect(Rect(0, 0, framesize.width, framesize.height));

	//�P�R�}���A�j���[�V������ݒ肷��
	for (int y = 0; y <= 1; y++){
		for (int x = 0; x < Frame_Count; ++x){
			auto frame = SpriteFrame::create("Booster.png", Rect(framesize.width*x,
				framesize.height*y,
				framesize.width,
				framesize.height));
			_boost.pushBack(frame);
		}
	}

	//�A�j���[�V���������s������
	auto animetion = Animation::createWithSpriteFrames(_boost);
	animetion->setDelayPerUnit(ANIMETION);
	this->runAction(RepeatForever::create(Animate::create(animetion)));

	return true;
}

//�p���[������ăA�j���[�V�����̑��x��ς���
void Booster::SetPower(int power){


}