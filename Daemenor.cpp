#include "classes.h"

vampireGameproject::Daemenor::Daemenor(Parsetext& textParser): textParser(textParser){}
vampireGameproject::Daemenor::~Daemenor(){}

void vampireGameproject::Daemenor::setDaemenor(std::string daemenor){
    Daemenor::daemenor = daemenor;
}

std::string vampireGameproject::Daemenor::getDaemenor(void){
    return daemenor;
}

void vampireGameproject::Daemenor::setDescription(void){
    description = textParser.parse_text();
}

