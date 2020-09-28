#include "classes.h"

vampireGameproject::Character::Character(Parsetext& textParser){
    characterDaemenor()
    
}

vampireGameproject::Character::~Character(){}

std::string vampireGameproject::Character::getPlayername(void){
    return playerName;
}

void vampireGameproject::Character::setPlayername(std::string name){
    playerName = name;
}

