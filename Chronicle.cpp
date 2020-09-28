#include "classes.h"

vampireGameproject::Chronicle::Chronicle(){}
vampireGameproject::Chronicle::~Chronicle(){}

std::string vampireGameproject::Chronicle::getChronicle(void){
    return chronicle;
}

void vampireGameproject::Chronicle::setChronicle(std::string chronicle){
    Chronicle::chronicle = chronicle;
}

void vampireGameproject::Chronicle::setDescription(void){
    textParse.parse_text();
}

