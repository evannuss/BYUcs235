#ifndef ARCHER_H
#define ARCHER_H

#include "Fighter.h"
#include <string>

class Archer : public Fighter{
public:
    Archer(std::string archerName, int archerHP, int archerStrength, int archerSpeed, int archerMagic):
        Fighter(archerName, archerHP, archerStrength, archerSpeed, archerMagic){initialSpeed = archerSpeed;}
    ~Archer(){}
    int getDamage();
    bool useAbility();
    void reset();
private:
    int initialSpeed;
};

#endif