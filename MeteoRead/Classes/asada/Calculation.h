#ifndef __METEOREAD__CALCULATION__
#define __METEOREAD__CALCULATION__
#include "cocos2d.h"

#include "asada/Earth.h"
#include "asada/Rocket.h"

class Calculation : public cocos2d::Ref{
public:
	static float Angle;
	virtual bool init();
	void move(Rocket*rocket, const int power);
	void angle(const Earth* hosi,Rocket* rocket,const int power);
	void hosiangle(const Earth* hosi, Earth* hosi2, const int power);
	double dot_product(Vec2 moto, Vec2 aite);
	CREATE_FUNC(Calculation);
};

#endif//#ifndef __METEOREAD__CALCULATION__