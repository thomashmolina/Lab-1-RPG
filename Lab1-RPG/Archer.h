#pragma once
#include "Fighter.h"

using namespace std;

class Archer: public Fighter{
    
    protected: 
       int baseSpeed;
	public:
	    Archer(string name, int hitPoints, int strength, int speed, int magic);
	    int getDamage(){return speed;}
	    void reset();
	    bool useAbility();
};
