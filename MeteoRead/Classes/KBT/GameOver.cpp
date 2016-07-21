#include "GameOver.h"
#include "ui/CocosGUI.h"
#include "isiwaki\SelectScene.h"
#include "GameScene.h"

USING_NS_CC;

bool GameOver::init(){
	if (!Layer::init())return false;

	//��ʂ̉摜�T�C�Y���擾����
	auto visiblesize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	//�����摜���o��������
	auto image = Sprite::create("GameOver.png");
	image->setPosition(visiblesize.width / 2,
		visiblesize.height / 2 + 100);
	this->addChild(image);
	_goalimage = image;

	//�X�e�[�W�Z���N�g�ɖ߂�{�^�����쐬����
	auto backimage = ui::Button::create("backStage.png");
	backimage->setPosition(Vec2(visiblesize.width / 2 - 200, visiblesize.height / 2 - 100));
	this->addChild(backimage);
	backimage->addTouchEventListener(CC_CALLBACK_2(GameOver::backtouchEvent, this));
	_backimage = backimage;

	//���X�^�[�g
	auto restart = ui::Button::create("retry.png");
	restart->setPosition(Vec2(visiblesize.width / 2 + 200, visiblesize.height / 2 - 100));
	this->addChild(restart);
	restart->addTouchEventListener(CC_CALLBACK_2(GameOver::restarttouchEvent, this));
	_restart = restart;

	//�Q�[���I�[�o�[
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

//���X�^�[�g����
void GameOver::restarttouchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type){
	auto Scenes = GameScene::createScene();
	auto trnscene = TransitionFade::create(1.0f, Scenes);

	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:
		//�^�b�v�J�n���̏���
		break;
	case cocos2d::ui::Widget::TouchEventType::MOVED:
		//�X���C�v���̏���
		break;
	case cocos2d::ui::Widget::TouchEventType::ENDED:
		//�������Ƃ��̏���
		Director::getInstance()->replaceScene(trnscene);
		break;
	case cocos2d::ui::Widget::TouchEventType::CANCELED:
		//�L�����Z�����̏���
		break;
	}
}

//�Z���N�g����
void GameOver::backtouchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type){
	auto Scenes = SelectScene::createScene();
	auto trnscene = TransitionFade::create(1.0f, Scenes);
	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:
		//�^�b�v�J�n���̏���
		break;
	case cocos2d::ui::Widget::TouchEventType::MOVED:
		//�X���C�v���̏���
		break;
	case cocos2d::ui::Widget::TouchEventType::ENDED:
		//�������Ƃ��̏���
		Director::getInstance()->replaceScene(trnscene);
		break;
	case cocos2d::ui::Widget::TouchEventType::CANCELED:
		//�L�����Z�����̏���
		break;
	}
}