#ifndef CLERIC_H
#define CLERIC_H

#include "Fighter.h"
#include <string>

class Cleric : public Fighter{
public:
    Cleric(std::string clericName, int clericHP, int clericStrength, int clericSpeed, int clericMagic):
        Fighter(clericName, clericHP, clericStrength, clericSpeed, clericMagic){initialMana = inputMagic * 5; mana = initialMana;}
    ~Cleric(){}
    int getDamage();
    void reset();
    void regenerate();
    bool useAbility();
private:
    int mana;
    int initialMana;
};

#endif