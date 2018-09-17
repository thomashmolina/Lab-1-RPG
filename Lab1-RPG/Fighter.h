#pragma once
#include "FighterInterface.h"
#include <string>
using namespace std;

class Fighter: public FighterInterface {
  protected:
  string name;
    int maxHP, currentHP, strength, speed, magic;
  
  public:
  Fighter();
    ~Fighter();
  string getName()    const {return name;}
  int getMaximumHP()  const {return maxHP;}
  int getCurrentHP()  const {return currentHP;}
  int getStrength()   const {return strength;}
  int getMagic()      const {return magic;}
  int getSpeed()      const {return speed;}
  int getDamage()   = 0;
  bool useAbility() = 0;
  void takeDamage(int);
  void reset();
  void regenerate();
};