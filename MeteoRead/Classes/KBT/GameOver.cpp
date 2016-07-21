#include "GameOver.h"
#include "ui/CocosGUI.h"
#include "isiwaki\SelectScene.h"
#include "GameScene.h"

USING_NS_CC;

bool GameOver::init(){
	if (!Layer::init())return false;

	//画面の画像サイズを取得する
	auto visiblesize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	//到着画像を出現させる
	auto image = Sprite::create("GameOver.png");
	image->setPosition(visiblesize.width / 2,
		visiblesize.height / 2 + 100);
	this->addChild(image);
	_goalimage = image;

	//ステージセレクトに戻るボタンを作成する
	auto backimage = ui::Button::create("backStage.png");
	backimage->setPosition(Vec2(visiblesize.width / 2 - 200, visiblesize.height / 2 - 100));
	this->addChild(backimage);
	backimage->addTouchEventListener(CC_CALLBACK_2(GameOver::backtouchEvent, this));
	_backimage = backimage;

	//リスタート
	auto restart = ui::Button::create("retry.png");
	restart->setPosition(Vec2(visiblesize.width / 2 + 200, visiblesize.height / 2 - 100));
	this->addChild(restart);
	restart->addTouchEventListener(CC_CALLBACK_2(GameOver::restarttouchEvent, this));
	_restart = restart;

	//ゲームオーバー
	auto lister = EventListenerTouchOneByOne::create();
	lister->setSwallowTouches(true);
	lister->onTouchBegan = [](Touch*touch, Event*event)->bool{
		return true;
	};
	auto dis = Director::getInstance()->getEventDispatcher();
	dis->addEventListenerWithSceneGraphPriority(lister, this);

	return true;
}

void GameOver::update(float dt){

}

//リスタート処理
void GameOver::restarttouchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type){
	auto Scenes = GameScene::createScene();
	auto trnscene = TransitionFade::create(1.0f, Scenes);

	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:
		//タップ開始時の処理
		break;
	case cocos2d::ui::Widget::TouchEventType::MOVED:
		//スワイプ時の処理
		break;
	case cocos2d::ui::Widget::TouchEventType::ENDED:
		//離したときの処理
		Director::getInstance()->replaceScene(trnscene);
		break;
	case cocos2d::ui::Widget::TouchEventType::CANCELED:
		//キャンセル時の処理
		break;
	}
}

//セレクト処理
void GameOver::backtouchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type){
	auto Scenes = SelectScene::createScene();
	auto trnscene = TransitionFade::create(1.0f, Scenes);
	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:
		//タップ開始時の処理
		break;
	case cocos2d::ui::Widget::TouchEventType::MOVED:
		//スワイプ時の処理
		break;
	case cocos2d::ui::Widget::TouchEventType::ENDED:
		//離したときの処理
		Director::getInstance()->replaceScene(trnscene);
		break;
	case cocos2d::ui::Widget::TouchEventType::CANCELED:
		//キャンセル時の処理
		break;
	}
}