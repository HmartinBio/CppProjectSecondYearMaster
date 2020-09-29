#include "classes.h"

vampireGameproject::Chronicle::Chronicle(Parsetext& textParser): textParser(textParser){}
vampireGameproject::Chronicle::~Chronicle(){}

std::string vampireGameproject::Chronicle::getChronicle(void){
    return chronicle;
}

void vampireGameproject::Chronicle::setChronicle(std::string chronicle){
    Chronicle::chronicle = chronicle;
}

void vampireGameproject::Chronicle::setDescription(void){
    description = textParser.parse_text();
}

