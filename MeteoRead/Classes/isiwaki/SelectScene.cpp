#include "SelectScene.h"
#include "GameScene.h"


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


	int fontswitch;
	if (fontswitch = 0)fontopacity -= 0.5;
	if (fontopacity <= 127.5f) fontswitch = 1;

	if (fontswitch = 1)fontopacity += 0.5;
	if (fontopacity >= 255) fontswitch = 0;

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
	liseView->setContentSize(Size(800,500));
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
		button->setTitleText(StringUtils::format("stage- %d",i)); 

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
	GOButton->setPosition(Vec2(visibleSize.width-75,45));
	GOButton->setTitleText(StringUtils::format("GO"));
	GOButton->addTouchEventListener(CC_CALLBACK_2(SelectScene::touchEvent,this));
	this->addChild(GOButton);


	/*SelectText->setPosition(Vec2(visibleSize.width/2,visibleSize.height/3));
	this->addChild(SelectText);*/

	//背景画像
	auto Back = Sprite::create("BackSample.png");
	//背景座標
	Back->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	////・・・・・お前が一番下だ！背景ッ!!!
	this->addChild(Back, -1);


	
	
    return true;
}

void SelectScene::update(float delta)
{

}
void SelectScene::touchEvent(Ref *pSender,ui::Widget::TouchEventType type)
{
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN:
		if (SelectCount ==  1)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, GameScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount ==  2)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount ==  3)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount ==  4)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount ==  5)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount ==  6)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount ==  7)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount ==  8)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount ==  9)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount == 10)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount == 11)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount == 12)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount == 13)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount == 14)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount == 15)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount == 16)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount == 17)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount == 18)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount == 19)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
		if (SelectCount == 20)Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(0, 0, 0)));
			break;
	case ui::Widget::TouchEventType::ENDED:

		break;
	case ui::Widget::TouchEventType::CANCELED:
		break;


	default:
		break;
	}
}
void SelectScene::thochButton(Ref *pSender, ui::Widget::TouchEventType type, int i)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	string SelectText;
	SelectText = StringUtils::format("stage- %d", i);

	switch (type)
	{

	case ui::Widget::TouchEventType::BEGAN:
		//LabelにButtonの文字の表示
		auto SelectLabel = Label::create();
		SelectLabel->setString(SelectText);



		//サイズ
		SelectLabel->setSystemFontSize(120);	//サイズ
		//カラー　（赤　青　緑）
		SelectLabel->setColor(Color3B(255, 0, 0));
		//座標設定
		SelectLabel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 200));
		SelectLabel->setOpacity(fontopacity);
		//５のタグのついたオブジェクトを消す
		this->removeChildByTag(5);
		//Labelの表示（string レイヤー:５　タグ:５）
		this->addChild(SelectLabel, 5, 5);

		auto action = FadeTo::create(1, 128);
		SelectLabel->runAction(action);
		SelectCount = i;

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
