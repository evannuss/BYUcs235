#include "Arena.h"
#include <string>
#include <vector>
#include <sstream>

bool Arena::addFighter(std::string info){
    std::stringstream fighterString(info);
    std::string fighterType;
    std::string fighterName;
    
    int fighterHP;
    int fighterStrength;
    int fighterSpeed;
    int fighterMagic;
    int dummy;
    
    if (fighterString >> fighterName >> fighterType >> fighterHP >> fighterStrength >> fighterSpeed >> fighterMagic){
        if (fighterString >> dummy){
            return false;
        }
        for (int i  = 0; i < arenaFighters.size(); i++){
            if (fighterName == arenaFighters.at(i)->getName()){
                return false;
            }
        }
        if (fighterType == "A"){
            arenaFighters.push_back(new Archer(fighterName, fighterHP, fighterStrength, fighterSpeed, fighterMagic));
        }
        else if (fighterType == "C"){
            arenaFighters.push_back(new Cleric(fighterName, fighterHP, fighterStrength, fighterSpeed, fighterMagic));
        }
        else if (fighterType == "R"){
            arenaFighters.push_back(new Robot(fighterName, fighterHP, fighterStrength, fighterSpeed, fighterMagic));
        }
    }
    else {
        return false;
    }
    return true;
}

bool Arena::removeFighter(std::string name){
    for (int i = 0; i < arenaFighters.size(); i++){
        if (name == arenaFighters.at(i)->getName()){
            arenaFighters.erase(arenaFighters.begin() + i);
            return true;
        }
    }
    return false;
}

FighterInterface* Arena::getFighter(std::string name){
    for (int i = 0; i < arenaFighters.size(); i++){
        if (name == arenaFighters.at(i)->getName()){
            return arenaFighters.at(i);
        }
    }
    return NULL;
}

int Arena::getSize() const {
    return arenaFighters.size();
}
