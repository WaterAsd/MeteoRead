#include "asada/Goal.h"
#include "ui/CocosGUI.h"
#include "isiwaki\SelectScene.h"
#include "GameScene.h"
USING_NS_CC;
bool Goal::init(){
	if (!Layer::init())return false;

	//画面の画像サイズを取得する
	auto visiblesize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	//到着画像を出現させる
	auto image = Sprite::create("Clear.png");
	image->setPosition(visiblesize.width/2,
								visiblesize.height/2+100);
	this->addChild(image);
	_goalimage = image;


	//ステージセレクトに戻るボタンを作成する
	auto backimage = ui::Button::create("backStage.png");
	backimage->setPosition(Vec2(visiblesize.width/2-200,visiblesize.height/2-100));
	this->addChild(backimage);
	backimage->addTouchEventListener(CC_CALLBACK_2(Goal::backtouchEvent, this));
	_backimage = backimage;


	//次のステージに進む
	auto nextimage = ui::Button::create("nextStage.png");
	nextimage->setPosition(Vec2(visiblesize.width / 2 +200, visiblesize.height / 2 - 100));
	this->addChild(nextimage);
	nextimage->addTouchEventListener(CC_CALLBACK_2(Goal::nexttouchEvent, this));
	_nextimage = nextimage;

	//モーダル処理
	auto listrner = EventListenerTouchOneByOne::create();
	listrner->setSwallowTouches(true);
	listrner->onTouchBegan = [](Touch *touch, Event*event)->bool{
		return true;
	};
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->addEventListenerWithSceneGraphPriority(listrner, this);

	return true;
}

//更新処理
void Goal::update(float dt){

}

//次のステージに進むための関数処理
void Goal::nexttouchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type){
	auto Scenes = GameScene::createScene();
	GameScene::SelectCount++;
	auto trnscene = TransitionFade::create(1.0f, Scenes);
	Director::getInstance()->replaceScene(trnscene);
}

//ステージセレクトに戻る為の関数処理
void Goal::backtouchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type){
	auto Scenes = SelectScene::createScene();
	auto trnscene = TransitionFade::create(1.0f, Scenes);
	Director::getInstance()->replaceScene(trnscene);
}