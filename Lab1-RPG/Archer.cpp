#include "Archer.h"
using namespace std;

Archer::Archer(string name, int maxHP, int strength, int speed, int magic){
    this->name = name;
    this->maxHP = maxHP;
    this->strength = strength;
    this->speed = speed;
    this->magic = magic;
    baseSpeed = speed;
    currentHP = maxHP;
}

void Archer::reset(){
    Fighter::reset();
    speed = baseSpeed;
}
bool Archer::useAbility(){
    speed++;
    return true;
}