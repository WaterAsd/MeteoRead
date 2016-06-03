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
		//button->addTouchEventListener(CC_CALLBACK_2(SelectScene::touchEvent,this,i));
		//button->addTouchEventListener(CC_CALLBACK_2(SelectScene::thochButton, this, i,BT));

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
void SelectScene::touchEvent(Ref *pSender,ui::Widget::TouchEventType type,int i)
{
	switch (type)
	{
		ui::Widget::TouchEventType TP2;
	case ui::Widget::TouchEventType::BEGAN:
	
			//Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(25, 0, 0)));

			break;
		//Director::getInstance()->replaceScene(TransitionFade::create(1.0f, SelectScene::createScene(), ccc3(25, 0, 0)));

		break;
	case ui::Widget::TouchEventType::ENDED:

		break;
	case ui::Widget::TouchEventType::CANCELED:
		break;


	default:
		break;
	}
}
void SelectScene::thochButton(Ref *pSender, ui::Widget::TouchEventType type, int i, string str)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	switch (type)
	{
		Label* T = Label::create(str, "Arial", 48);
		T->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 200));
		this->addChild(T);
	}


}

void SelectScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
