#pragma once
#include "Fighter.h"
using namespace std;
class Robot: public Fighter {
  protected:
    int extraDamage;
    int energy;
    int maxEnergy;
  public:
    Robot(string name, int maxHP, int strength, int speed, int magic);
    int getDamage();
    bool useAbility();
    void reset();
    
};