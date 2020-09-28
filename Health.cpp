#include "classes.h"

vampireGameproject::Health::Health(){}

int vampireGameproject::Health::getPointlife(void){
    return pointLife;
}

void vampireGameproject::Health::setPointlife(int pointLife){
    Health::pointLife = pointLife;
}

std::string vampireGameproject::Health::getPointlifeDescription(void){
    return pointLifedescription;
}

std::list<char> vampireGameproject::Health::getWeakness(void){
    return weakness;
}

