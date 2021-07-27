#ifndef ARENA_H
#define ARENA_H

#include "ArenaInterface.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"
#include <string>
#include <vector>

class Arena : public ArenaInterface{
public:
    Arena(){}
    ~Arena(){}
    bool addFighter(std::string info);
    bool removeFighter(std::string name);
    FighterInterface* getFighter(std::string name);
    int getSize() const;
private:
    std::vector<FighterInterface*> arenaFighters;
    
};

#endif