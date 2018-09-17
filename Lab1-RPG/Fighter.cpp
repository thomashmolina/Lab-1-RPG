#include "Fighter.h"
#include <sstream>
#include <cassert>
using namespace std;

Fighter::Fighter(){}
Fighter::~Fighter(){}
void Fighter::takeDamage(int damage_taken){
    const int SPEED_RATIO = 4;
    int damage = damage_taken - (speed/SPEED_RATIO);
        if(damage_taken <= 0){
            damage = 1;
        }
        if(damage >= 1);
        currentHP -= damage;
} 
void Fighter::reset(){
    currentHP = maxHP;
}
void Fighter::regenerate(){
    int strengthRatio = strength/6;
    
    if (strengthRatio <= 0) {
        strengthRatio = 1;
    }
    
    currentHP += strengthRatio;
    if (strengthRatio >= 1); //use assserts for debugging.  The TA says they rarely work well within a program 
    if(currentHP > maxHP){
        currentHP = maxHP;
    }
}