#include "TitleScene.h"
#include "SelectScene.h"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                "
#include "NovelScene.h"
USING_NS_CC;

//�V�[���쐬
Scene* TitleScene::createScene()
{
	auto scene = Scene::create();
	auto layer = TitleScene::create();
	scene->addChild(layer);

	return scene;
}
//������
bool TitleScene::init()
{

	if (!Layer::init())
		return false;

		//�w�i��\��
		initBackground();
		//�{�^����\��
		initButton();

		return true;
}

//�w�i��\��
void TitleScene::initBackground()
{
	//��ʃT�C�Y���擾
	Size winSize = Director::getInstance()->getWinSize();

	//�w�i�̐���
	auto background = Sprite::create("Title_background.png");

	//�w�i�̈ʒu�ݒ�
	background->setPosition(winSize / 2);

	//�w�i�̒ǉ�
	addChild(background, Z_Bg);

	//�^�C�g���̐���
	auto title1 = Sprite::create("rogo1.png");
	auto title2 = Sprite::create("rogo2.png");
	auto title3 = Sprite::create("rogo3.png");
	auto title4 = Sprite::create("rogo4 new.png");
	auto title5 = Sprite::create("rogo5 new.png");
	auto title6 = Sprite::create("rogo6.png");
	auto title7 = Sprite::create("rogo7 new.png");
	auto title8 = Sprite::create("rogo8.png");
	auto title9 = Sprite::create("rogo star.png");

	//�^�C�g���̈ʒu�ݒ�(X���W, Y���W)
	title1->setPosition(Vec2(title1->getContentSize().width / 1.3, winSize.height / 1.3));
	title2->setPosition(Vec2(title2->getContentSize().width / 1.3, winSize.height / 1.3));
	title3->setPosition(Vec2(title3->getContentSize().width / 1.3, winSize.height / 1.3));
	title4->setPosition(Vec2(title4->getContentSize().width / 1.3, winSize.height / 1.3));
	title5->setPosition(Vec2(title5->getContentSize().width / 2.8, winSize.height / 2.8));
	title6->setPosition(Vec2(title6->getContentSize().width / 2.9, winSize.height / 2.9));
	title7->setPosition(Vec2(title7->getContentSize().width / 2.7, winSize.height / 2.7));
	title8->setPosition(Vec2(title8->getContentSize().width / 2.8, winSize.height / 2.8));
	title9->setPosition(Vec2(title9->getContentSize().width / 2  , winSize.height / 2  ));
	
	//�^�C�g���̒ǉ�
	addChild(title1, Z_Title);
	addChild(title2, Z_Title);
	addChild(title3, Z_Title);
	addChild(title4, Z_Title);
	addChild(title5, Z_Title);
	addChild(title6, Z_Title);
	addChild(title7, Z_Title);
	addChild(title8, Z_Title);
	addChild(title9, Z_Title);

	//�A�j���[�V�������쐬�@MoveTo::create(����, (X���W, Y���W));
	auto action1 = MoveTo::create(0.7, Vec2(winSize.width / 2.7   - title1->getContentSize().width / 1.3, winSize.height / 1.3));
	auto action2 = MoveTo::create(0.7, Vec2(winSize.width / 1.9   - title2->getContentSize().width / 1.3, winSize.height / 1.3));
	auto action3 = MoveTo::create(0.7, Vec2(winSize.width / 1.5   - title3->getContentSize().width / 1.3, winSize.height / 1.3));
	auto action4 = MoveTo::create(0.7, Vec2(winSize.width / 1.25  - title4->getContentSize().width / 1.3, winSize.height / 1.3));
	auto action5 = MoveTo::create(0.7, Vec2(winSize.width / 2.9   - title5->getContentSize().width / 2.8, winSize.height / 2.8));
	auto action6 = MoveTo::create(0.7, Vec2(winSize.width / 2.13  - title6->getContentSize().width / 2.9, winSize.height / 2.9));
	auto action7 = MoveTo::create(0.7, Vec2(winSize.width / 1.605 - title7->getContentSize().width / 2.7, winSize.height / 2.7));
	auto action8 = MoveTo::create(0.7, Vec2(winSize.width / 1.33  - title8->getContentSize().width / 2.8, winSize.height / 2.8));
	auto action9 = MoveTo::create(0.7, Vec2(winSize.width / 1.8   - title9->getContentSize().width / 2  , winSize.height / 2  ));


	//�A�j���[�V�����J�n
	title1->runAction(action1);
	title2->runAction(action2);
	title3->runAction(action3);
	title4->runAction(action4);
	title5->runAction(action5);
	title6->runAction(action6);
	title7->runAction(action7);
	title8->runAction(action8);
	title9->runAction(action9);
	
}

//�{�^����\��
void TitleScene::initButton()
{
	//��ʃT�C�Y�̎擾
	Size winSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//�{�^���̐���
	auto button = ui::Button::create("START_Button.png");

	//�w�i�̈ʒu�ݒ�
	button->setPosition(Vec2(winSize.width * 0.5, winSize.height * 0.1));

	//�^�b�v�C�x���g�̊֘A�Â�
	button->addTouchEventListener(CC_CALLBACK_2(TitleScene::touchEvent, this));

	//�w�i�̒ǉ�
	addChild(button, Z_Button);


	
}

void TitleScene::touchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type) 
{

	//�{�^����������V�[���ړ�
	Director::getInstance()->replaceScene(Select::createScene());
	
	//�t�F�[�h�C��&�t�F�[�h�A�E�g
	Director::getInstance()->replaceScene(TransitionFade::create(2.0f, Select::createScene(), Color3B::WHITE));

}
