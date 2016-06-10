#include "Earth.h"
USING_NS_CC;

Earth::Earth(){

}

Earth::~Earth(){

}

bool Earth::init(){

	//画像が存在しない場合はfalseを返す
	if (!Sprite::initWithFile("Earth.png")){
		return false;
	}

	return true;
}

//星を出すためのクラスを作成する
void Earth::planetcreate(std::string hosi){

	//もし星が存在しない場合
	if (!Sprite::initWithFile(hosi)){
		
	}
	else{
		//一つの画面のサイズを確定しておく。
		auto framesize = Size(this->getContentSize().width / Frame_Count,
			this->getContentSize().height / UP_PIC);

		//表示サイズを変更する
		this->setTextureRect(Rect(0, 0, framesize.width, framesize.height));

		Vector<SpriteFrame *>frames;

		//１コマずつアニメーションを設定する
		for (int y = 0; y <= 1; y++){
			for (int x = 0; x < Frame_Count; ++x){
				auto frame = SpriteFrame::create(hosi, Rect(framesize.width*x,
					framesize.height*y,
					framesize.width,
					framesize.height));
				_earth.pushBack(frame);
			}
		}

		//アニメーションを実行させる
		auto animetion = Animation::createWithSpriteFrames(_earth);
		animetion->setDelayPerUnit(ANIMETION);
		this->runAction(RepeatForever::create(Animate::create(animetion)));
	}
}