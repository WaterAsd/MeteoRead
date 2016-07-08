#include "Statics.h"

USING_NS_CC;

using namespace cocos2d;
using namespace std;

Vec2 Statics::myPos;
int Statics::myRot;
int Statics::myPower;
std::vector<Vec2> Statics::starPos;
Vec2 Statics::goalPos;
Vec2 Statics::gimmickPos;
Rect Statics::stageRect;

bool Statics::clearFlg;
bool Statics::gameOverFlg;
bool Statics::touchFlg;
bool Statics::flyFlg;

int Statics::stageSelect;