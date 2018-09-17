#include "Robot.h"
#include <math.h>
using namespace std;
Robot::Robot(string name, int maxHP, int strength, int speed, int magic){
    this-> name     = name;
    this-> maxHP = maxHP;
    this-> strength = strength;
    this-> speed    = speed;
    this-> magic    = magic;
    currentHP       = maxHP;
    maxEnergy       = 2 * magic;
    energy          = maxEnergy;
    extraDamage     = 0;
    
}
int Robot::getDamage(){
    int damage  = strength + extraDamage;
    extraDamage = 0;
    return damage;
}
bool Robot::useAbility(){
    if(energy < ROBOT_ABILITY_COST){
        return false;
    }
    //Use of temporary is to assign a double to put into extraDamage
    double temporary = (double)energy / (double)maxEnergy;
    energy -= ROBOT_ABILITY_COST;
    extraDamage = strength * pow(temporary, 4.0);
    return true;
}
void Robot::reset(){
    Fighter::reset();
    energy = maxEnergy;
    extraDamage = 0;
}