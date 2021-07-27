#include "Cleric.h"
#include <string>

int Cleric::getDamage(){
    damage = inputMagic;
    return damage;
}

void Cleric::reset(){
    Fighter::reset();
    mana = initialMana;
}

void Cleric::regenerate(){
    Fighter::regenerate();
    int clericRegen = inputMagic / 5;
    if (clericRegen < 1){
        clericRegen = 1;
    }
    mana += clericRegen;
    if (mana > initialMana){
        mana = initialMana;
    }
}

bool Cleric::useAbility(){
    int addToHP = inputMagic / 3;
    if (mana >= CLERIC_ABILITY_COST){
        if (addToHP < 1){
            addToHP = 1;
        }
        currentHP += addToHP;
        if (currentHP > inputMaxHP){
            currentHP = inputMaxHP;
        }
        mana -= CLERIC_ABILITY_COST;
        return true;
    }
    else {
        return false;
    }
}
