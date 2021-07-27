#ifndef FIGHTER_H
#define FIGHTER_H

#include "FighterInterface.h"
#include <string>

class Fighter : public FighterInterface{
public:
    Fighter(std::string name = "none", int maxHP = 0, int strength = 0, int speed = 0, int magic = 0);
    ~Fighter(){}
    std::string getName() const;
    int getMaximumHP() const;
    int getCurrentHP() const;
    int getStrength() const;
    int getSpeed() const;
    int getMagic() const;
    
    void takeDamage(int damage);
    void reset();
    void regenerate();
    
    virtual int getDamage() = 0;
    virtual bool useAbility() = 0;
protected:
    std::string inputName;
    int inputMaxHP;
    int currentHP;
    int inputStrength;
    int inputSpeed;
    int inputMagic;
    int damage;
};

#endif