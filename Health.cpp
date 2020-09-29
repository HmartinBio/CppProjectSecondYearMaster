#include "classes.h"

vampireGameproject::Health::Health(Parsetext& textParser): textParser(textParser){}
vampireGameproject::Health::~Health(){}

int vampireGameproject::Health::getPointlife(void){
    return pointLife;
}

void vampireGameproject::Health::setPointlife(int pointLife){
    Health::pointLife = pointLife;
}

std::string vampireGameproject::Health::getPointlifeDescription(void){
    return pointLifedescription;
}

std::string vampireGameproject::Health::getWeakness(void){
    return weakness;
}

void vampireGameproject::Health::setPointlifeDescription(void){
    pointLifedescription = textParser.parse_text();
}



