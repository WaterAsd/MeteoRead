#include "Earth.h"
USING_NS_CC;

Earth::Earth(){

}

Earth::~Earth(){

}

bool Earth::init(){

	//�摜�����݂��Ȃ��ꍇ��false��Ԃ�
	if (!Sprite::initWithFile("Earth.png")){
		return false;
	}

	return true;
}

//�����o�����߂̃N���X���쐬����
void Earth::planetcreate(std::string hosi){

	//�����������݂��Ȃ��ꍇ
	if (!Sprite::initWithFile(hosi)){
		
	}
	else{
		//��̉�ʂ̃T�C�Y���m�肵�Ă����B
		auto framesize = Size(this->getContentSize().width / Frame_Count,
			this->getContentSize().height / UP_PIC);

		//�\���T�C�Y��ύX����
		this->setTextureRect(Rect(0, 0, framesize.width, framesize.height));

		Vector<SpriteFrame *>frames;

		//�P�R�}���A�j���[�V������ݒ肷��
		for (int y = 0; y <= 1; y++){
			for (int x = 0; x < Frame_Count; ++x){
				auto frame = SpriteFrame::create(hosi, Rect(framesize.width*x,
					framesize.height*y,
					framesize.width,
					framesize.height));
				_earth.pushBack(frame);
			}
		}

		//�A�j���[�V���������s������
		auto animetion = Animation::createWithSpriteFrames(_earth);
		animetion->setDelayPerUnit(ANIMETION);
		this->runAction(RepeatForever::create(Animate::create(animetion)));
	}
}