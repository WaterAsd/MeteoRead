#include "asada/Goal.h"
#include "ui/CocosGUI.h"
#include "isiwaki\SelectScene.h"
#include "GameScene.h"
USING_NS_CC;
bool Goal::init(){
	if (!Layer::init())return false;

	//��ʂ̉摜�T�C�Y���擾����
	auto visiblesize = Director::getInstance()->getWinSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	//�����摜���o��������
	auto image = Sprite::create("Clear.png");
	image->setPosition(visiblesize.width/2,
								visiblesize.height/2+100);
	this->addChild(image);
	_goalimage = image;


	//�X�e�[�W�Z���N�g�ɖ߂�{�^�����쐬����
	auto backimage = ui::Button::create("backStage.png");
	backimage->setPosition(Vec2(visiblesize.width/2-200,visiblesize.height/2-100));
	this->addChild(backimage);
	backimage->addTouchEventListener(CC_CALLBACK_2(Goal::backtouchEvent, this));
	_backimage = backimage;


	//���̃X�e�[�W�ɐi��
	auto nextimage = ui::Button::create("nextStage.png");
	nextimage->setPosition(Vec2(visiblesize.width / 2 +200, visiblesize.height / 2 - 100));
	this->addChild(nextimage);
	nextimage->addTouchEventListener(CC_CALLBACK_2(Goal::nexttouchEvent, this));
	_nextimage = nextimage;

	return true;
}

//�X�V����
void Goal::update(float dt){

}

//���̃X�e�[�W�ɐi�ނ��߂̊֐�����
void Goal::nexttouchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type){
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

//���̃X�e�[�W�ɐi�ނ��߂̊֐�����
void Goal::backtouchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type){
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