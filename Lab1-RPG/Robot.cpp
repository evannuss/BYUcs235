#include "Robot.h"
#include <string>
#include <math.h>

int Robot::getDamage(){
    damage = inputStrength + bonusDamage;
    bonusDamage = 0;
    return damage;
}

void Robot::reset(){
    Fighter::reset();
    energy = initialEnergy;
    bonusDamage = 0;
}

bool Robot::useAbility(){
    const double DAMAGE_FACTOR = 4.0;
    if (energy >= ROBOT_ABILITY_COST){
        bonusDamage = ((double)inputStrength * (pow(((double)energy / (double)initialEnergy), DAMAGE_FACTOR)));
        energy -= ROBOT_ABILITY_COST;
        return true;
    }
    else {
        return false;
    }
}