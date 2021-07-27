#ifndef ROBOT_H
#define ROBOT_H

#include "Fighter.h"
#include <string>

class Robot : public Fighter{
public:
    Robot(std::string robotName, int robotHP, int robotStrength, int robotSpeed, int robotMagic):
        Fighter(robotName, robotHP, robotStrength, robotSpeed, robotMagic){initialEnergy = inputMagic * 2; energy = initialEnergy;}
    ~Robot(){}
    int getDamage();
    void reset();
    bool useAbility();
private:
    int energy;
    int initialEnergy;
    double bonusDamage;
};


#endif