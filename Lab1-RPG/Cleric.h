#pragma once
#include "Fighter.h"
using namespace std;
class Cleric: public Fighter{
    protected:
        int mana;
        int maxMana;
    public:
        Cleric(string name, int hitPoints, int strength, int speed, int magic);
        void regenerate();
        int getDamage();
        void reset();
        bool useAbility();
};