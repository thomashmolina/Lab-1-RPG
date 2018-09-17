#include "Cleric.h"
Cleric::Cleric(string name, int maxHP, int strength, int speed, int magic){
    this-> name = name;
    this-> maxHP = maxHP;
    this-> strength = strength;
    this-> speed = speed;
    this-> magic = magic;
    maxMana = 5 * magic;
    currentHP = maxHP;
    mana = maxMana;
}
int Cleric::getDamage(){
    return magic;
}

void Cleric::regenerate(){
    Fighter::regenerate();
    int manaScale = magic /5;
    if (manaScale == 0){
        manaScale = 1;
    }
    mana += manaScale;
    if(mana > maxMana){
        mana = maxMana;
    }
    
}
//RESET
void Cleric::reset(){
    Fighter::reset();
    mana = maxMana;
}
//USE ABILITY
bool Cleric::useAbility(){
    if(mana < CLERIC_ABILITY_COST){
        return false;
    }
    else{
        mana -= CLERIC_ABILITY_COST;
        int greaterHealScale = magic / 3;
        
        if(greaterHealScale < 1){
            greaterHealScale = 1;
        }
        
        currentHP += greaterHealScale;
        
        
        if(currentHP > maxHP){
           currentHP = maxHP;
        }
        return true;
    }
    
}