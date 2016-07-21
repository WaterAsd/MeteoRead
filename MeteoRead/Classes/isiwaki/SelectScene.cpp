#pragma execution_character_set("utf-8")

#include "SelectScene.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
//BGM（SimpleAudioEngine）使うために必要
using namespace CocosDenshion;


USING_NS_CC;

Scene* SelectScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = SelectScene::create();



    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SelectScene::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//init()内
	//あらかじめ、音楽データを読み込む
	SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.5);
	SimpleAudioEngine::sharedEngine()->preloadEffect("botanSE1.mp3");

	//int SelectCount;
	//SelectCount = 1;
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	//リストビューの表示
	auto liseView = ui::ListView::create();
	liseView->setContentSize(Size(850,370));
	liseView->setPosition((visibleSize - liseView->getContentSize()) / 2);
	//横に並ぶ
	liseView->setDirection(ui::ScrollView::Direction::HORIZONTAL);
	liseView->setBounceEnabled(true);
	this ->addChild(liseView);

	//Button20個
	for (int i= 1; i <= 20;i++)
	{
		//画像の読み込み
		auto button = ui::Button::create("botan01.png");
		button->setScale9Enabled(true);
		//サイズの設定
		button->setContentSize(Size(150,150));
		//中心
		button->setPosition(button->getContentSize() / 2 );
		//Buttonの中にテキスト表示
		button->setTitleText(StringUtils::format("エリア%d",i)); 

		button->setTitleFontSize(30);
		//button->addTouchEventListener(CC_CALLBACK_2(NN[i]::touchEvent,this,i));
		button->addTouchEventListener(CC_CALLBACK_2(SelectScene::thochButton, this, i));

		auto layout = ui::Layout::create();
		layout->setContentSize(button->getContentSize());
		layout->addChild(button);
		liseView->addChild(layout);
	}
		auto GOButton = ui::Button::create("GOButton.png");
		GOButton->setScale9Enabled(true);
		GOButton->setContentSize(Size(150, 91));
		GOButton->setPosition(Vec2(GOButton->getSize() / 2));
		GOButton->setTitleText(StringUtils::format("出発"));
		GOButton->setTitleFontSize(40);
		GOButton->addTouchEventListener(CC_CALLBACK_2(SelectScene::touchEvent, this));
		this->addChild(GOButton);


	/*SelectText->setPosition(Vec2(visibleSize.width/2,visibleSize.height/3));
	this->addChild(SelectText);*/

	//背景画像
	auto Back = Sprite::create("SelectBack.png");
	//背景座標
	Back->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	////・・・・・お前が一番下だ！背景ッ!!!
	this->addChild(Back, -1);
	//背景グラデーション
	auto _Gbg = LayerGradient::create(Color4B(255,0,0,55), Color4B::BLUE);
	_Gbg->setVector(Point(1, 1));
	this->addChild(_Gbg,-2);

	//BGM
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("BGM/BGMSelect.mp3");
	SimpleAudioEngine::getInstance()->stopBackgroundMusic("BGM/BGMSelect.mp3");
	SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
	SimpleAudioEngine::getInstance()->playBackgroundMusic("BGM/BGMSelect.mp3", true);
	
	
    return true;
}

void SelectScene::update(float delta)
{

}
//きらボタンで選んでるステージへジャンプ
void SelectScene::touchEvent(Ref *pSender,ui::Widget::TouchEventType type)
{
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN:
		if (GameScene::SelectCount == 1)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, GameScene::createScene(), Color3B(0, 0, 0)));
		/*if (SelectCount ==  2)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));
		if (SelectCount ==  3)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));
		if (SelectCount ==  4)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));
		if (SelectCount ==  5)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));
		if (SelectCount ==  6)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));
		if (SelectCount ==  7)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));
		if (SelectCount ==  8)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));
		if (SelectCount ==  9)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));
		if (SelectCount == 10)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));
		if (SelectCount == 11)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));
		if (SelectCount == 12)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));
		if (SelectCount == 13)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));
		if (SelectCount == 14)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));
		if (SelectCount == 15)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));
		if (SelectCount == 16)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));
		if (SelectCount == 17)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));
		if (SelectCount == 18)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));
		if (SelectCount == 19)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));
		if (SelectCount == 20)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), Color3B(0, 0, 0)));*/
			break;
	case ui::Widget::TouchEventType::ENDED:

		break;
	case ui::Widget::TouchEventType::CANCELED:
		break;


	default:
		break;
	}
}
//選んでるステージのText表示
void SelectScene::thochButton(Ref *pSender, ui::Widget::TouchEventType type, int i)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	string SelectText;
	SelectText = StringUtils::format("エリア-%d", i);
	GameScene::SelectCount = i; ButtonFlashing = 1;




	switch (type)
	{

	case ui::Widget::TouchEventType::BEGAN:
		//LabelにButtonの文字の表示
		auto SelectLabel = Label::create();
		SelectLabel->setString(SelectText);

		//サイズ
		SelectLabel->setSystemFontSize(120);	//サイズ;
		//カラー　（赤　青　緑）
		//SelectLabel->setColor(Color3B::WHITE);
		SelectLabel->setTextColor(Color4B::BLUE);
		SelectLabel->enableShadow(Color4B(80,0,25,255),Size(5,-4),50.0f);
		//座標設定
		SelectLabel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height- 100));

		//SelectLabel->setOpacity(fontopacity);
		//５のタグのついたオブジェクトを消す
		this->removeChildByTag(5);
		//Labelの表示（string レイヤー:５　タグ:５）
		this->addChild(SelectLabel, 5, 5);


		int soundID;
		soundID = SimpleAudioEngine::sharedEngine()->playEffect("botanSE1.mp3");


		break;
	}


}

void SelectScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
