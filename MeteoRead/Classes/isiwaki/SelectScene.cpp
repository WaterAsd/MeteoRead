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
    
	//���X�g�r���[�̕\��
	auto liseView = ui::ListView::create();
	liseView->setContentSize(Size(800,340));
	liseView->setPosition((visibleSize - liseView->getContentSize()) / 2);
	//liseView->setDirection(ui::ScrollView::Direction::VERTICAL);
	liseView->setDirection(ui::ScrollView::Direction::HORIZONTAL);
	liseView->setBounceEnabled(true);
	this ->addChild(liseView);

	for (int i= 1; i <= 20;i++)
	{
		auto button = ui::Button::create("botan01.png");
		button->setScale9Enabled(true);
		button->setContentSize(Size(150,150));
		button->setPosition(button->getContentSize() / 2 );
		button->setTitleText(StringUtils::format("stage- %d",i));

		auto layout = ui::Layout::create();
		layout->setContentSize(button->getContentSize());
		layout->addChild(button);
		liseView->addChild(layout);
	}
	
	//for (int z = 0; z <=  3; z++)//�X�e�[�W�{�^���̕\��4��
	//{
	//	//cocos2d::ui::Button *ButtnSET;
	//	ButtnSET = new ui::Button();
	//	float BTPos[] = { 120, 360, 600, 840 };//�{�^����Y��
	//
	//	StageText = z + SelectCount;
	//	std::string str = std::to_string(StageText);
	//	Size visibleSize = Director::getInstance()->getVisibleSize();
	//	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//	//�摜�̓ǂݍ��݁@�{�^�����W�@�e�L�X�g�̕\���E�T�C�Y
	//	ButtnSET = ui::Button::create("botan01.png");
	//	ButtnSET->setPosition(Vec2(BTPos[z], visibleSize.height / 2));
	//	ButtnSET->setTitleText(str);
	//	ButtnSET->setTitleFontSize(25);

	//}

	
	
	/*auto RBT = ui::Button::create("RBT.png");
	RBT->setSize(Size(75,150));
	RBT->setPosition(Vec2(visibleSize.width-32.5f,visibleSize.height/2));
	RBT->addTouchEventListener(CC_CALLBACK_2(SelectScene::touchEvent, this, 99));
	this->addChild(RBT, 1);*/

	//ButtnSET->addTouchEventListener(CC_CALLBACK_2(SelectScene::touchEvent, this, StageText));

	//�w�i�摜
	auto Back = Sprite::create("BackSample.png");
	//�w�i���W
	Back->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	////�E�E�E�E�E���O����ԉ����I�w�i�b!!!
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
	case ui::Widget::TouchEventType::BEGAN:
		
		
		break;
	case ui::Widget::TouchEventType::ENDED:

		break;
	case ui::Widget::TouchEventType::CANCELED:
		break;


	default:
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
