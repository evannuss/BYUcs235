#include "Fighter.h"
#include <string>

Fighter::Fighter(std::string name, int maxHP, int strength, int speed, int magic){
    inputName = name;
    inputMaxHP = maxHP;
    currentHP = maxHP;
    inputStrength = strength;
    inputSpeed = speed;
    inputMagic = magic;
}

std::string Fighter::getName()const{
    return inputName;
}

int Fighter::getMaximumHP()const{
    return inputMaxHP;
}

int Fighter::getCurrentHP()const{
    return currentHP;
}

int Fighter::getStrength()const{
    return inputStrength;
}

int Fighter::getSpeed()const{
    return inputSpeed;
}

int Fighter::getMagic()const{
    return inputMagic;
}

void Fighter::takeDamage(int damage){
    int damageSubtractor = inputSpeed / 4;
    int finalDamage = damage - damageSubtractor;
    if (finalDamage < 1){
        finalDamage = 1;
    }
    currentHP -= finalDamage;
}

void Fighter::reset(){
    currentHP = inputMaxHP;
}

void Fighter::regenerate(){
    int regen = inputStrength / 6;
     if (regen < 1){
         regen = 1;
     }
     currentHP += regen;
     if (currentHP > inputMaxHP){
         currentHP = inputMaxHP;
     }
}

