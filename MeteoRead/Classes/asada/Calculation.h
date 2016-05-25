#ifndef __METEOREAD__CALCULATION__
#define __METEOREAD__CALCULATION__
#include "cocos2d.h"

#include "asada/Earth.h"
#include "asada/Rocket.h"

class Calculation : public cocos2d::Ref{
public:
	virtual bool init();
	void angle(Earth* hosi,Rocket* rocket,int power);
	CREATE_FUNC(Calculation);
};

#endif//#ifndef __METEOREAD__CALCULATION__