#include "Earth.h"
USING_NS_CC;
bool Earth::init(){

	//画像が存在しない場合はfalseを返す
	if (!Sprite::initWithFile("Earth.png")){
		return false;
	}

	//一つの画面のサイズを確定しておく。
	auto framesize = Size(this->getContentSize().width / Frame_Count,
		this->getContentSize().height / UP_PIC);

	//表示サイズを変更する
	this->setTextureRect(Rect(0, 0, framesize.width, framesize.height));

	//盾の画面
	for (int y = 0; y <= 1; y++){
		//横の画面
		for (int x = 0; x < Frame_Count - y;++x)

	}

	return true;
}