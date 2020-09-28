#include "classes.h"

vampireGameproject::Nature::Nature( Parsetext& textParserreference) : textParser(textParserreference){}
vampireGameproject::Nature::~Nature(){}

std::string vampireGameproject::Nature::getNature(void){
    return nature;
}

void vampireGameproject::Nature::setNature(std::string nature){
    Nature::nature = nature;
}

void vampireGameproject::Nature::setDescription(){
    textParser.parse_text();
}

