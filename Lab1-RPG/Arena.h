#pragma once 
#include <vector>
#include "ArenaInterface.h"

using namespace std;

class Arena: public ArenaInterface {
    protected:
        vector<FighterInterface*> fighters_in_arena;
    public:
        Arena(){}
        bool addFighter(string info);
        bool removeFighter(string name);
        int getSize() const;
    	FighterInterface* getFighter(string name);
};