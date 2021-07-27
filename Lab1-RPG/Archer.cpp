#include "Archer.h"
#include <string>


int Archer::getDamage(){
    damage = inputSpeed;
    return damage;
}

bool Archer::useAbility(){
    inputSpeed++;
    return true;
}

void Archer::reset(){
    Fighter::reset();
    inputSpeed = initialSpeed;
}

