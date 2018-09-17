#include "Arena.h"
#include "Fighter.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"
#include <string>
#include <sstream>
using namespace std;

int getInputCount(string info){
    stringstream ss(info);
    string word;
    int count = 0;
    while (ss >> word){count++;}
    return count;
}
int Arena::getSize() const{
    return fighters_in_arena.size();
}
bool Arena::addFighter(string info){
    if(!getInputCount(info) == 6){
        return false;
    }
    stringstream ss(info);
    string name;
    ss >> name;
    if(getFighter(name) != NULL){
        return false;
    }
    char type;
    int maxHP, strength, speed, magic;
    string garbage;
    
    ss >> type;
    if(ss.fail()){
        return false;
    }
    ss >> maxHP;
    if(ss.fail()){
        return false;
    }
    ss >> strength;
    if(ss.fail()){
        return false;
    }
    ss >> speed;
    if(ss.fail()){
        return false;
    }
    ss >> magic;
    if(ss.fail()){
        return false;
    }
    
    ss >> garbage;
    if (!ss.fail()){
        return false;
    }
    
    if(maxHP <= 0){
        return false;
    }
    if (strength <= 0){
        return false;
    }
    if (speed <= 0){
        return false;
    }
    if (magic <= 0){
       return false;
    }
	
    switch (type){
        case 'A':
            fighters_in_arena.push_back(new Archer(name, maxHP,  strength,  speed,  magic));
            return true;
            //break;
        case 'C':
            fighters_in_arena.push_back(new Cleric(name,  maxHP,  strength,  speed,  magic));
            return true;
            //break;
        case 'R':
            fighters_in_arena.push_back(new Robot(name,  maxHP,  strength,  speed,  magic));
            return true;
            //break;
        default:
            return false;
    };
    //return true;
    return false;
}
FighterInterface* Arena::getFighter(string name){
    //returns memory address of a fighter using their name.
    for(vector<FighterInterface*>::iterator iter = fighters_in_arena.begin(); iter != fighters_in_arena.end(); iter++){// changed this to iterator notation b/c fighter isn't defined.
        if((*iter)->getName() == name){
            return *iter;
        }
    }
    return NULL;
}
bool Arena::removeFighter(string name){
    for(vector<FighterInterface*>::iterator iter = fighters_in_arena.begin(); iter != fighters_in_arena.end(); iter++){
        if((*iter)->getName() == name){
            fighters_in_arena.erase(iter);
            return true;
        }
        return NULL;
    }
}

