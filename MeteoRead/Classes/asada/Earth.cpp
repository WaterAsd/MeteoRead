#include "Earth.h"
USING_NS_CC;
bool Earth::init(){

	//�摜�����݂��Ȃ��ꍇ��false��Ԃ�
	if (!Sprite::initWithFile("Earth.png")){
		return false;
	}

	//��̉�ʂ̃T�C�Y���m�肵�Ă����B
	auto framesize = Size(this->getContentSize().width / Frame_Count,
		this->getContentSize().height / UP_PIC);

	//�\���T�C�Y��ύX����
	this->setTextureRect(Rect(0, 0, framesize.width, framesize.height));

	//���̉��
	for (int y = 0; y <= 1; y++){
		//���̉��
		for (int x = 0; x < Frame_Count - y;++x)

	}

	return true;
}