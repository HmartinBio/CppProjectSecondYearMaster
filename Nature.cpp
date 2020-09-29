#include "classes.h"

vampireGameproject::Nature::Nature(Parsetext& textParser): textParser(textParser){}

vampireGameproject::Nature::~Nature(){}

std::string vampireGameproject::Nature::getNature(void){
    return nature;
}

void vampireGameproject::Nature::setNature(std::string nature){
    Nature::nature = nature;
}

void vampireGameproject::Nature::setDescription(){
    description = textParser.parse_text();
}

