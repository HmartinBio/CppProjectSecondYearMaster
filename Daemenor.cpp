#include "classes.h"

vampireGameproject::Daemenor::Daemenor(){}
vampireGameproject::Daemenor::~Daemenor(){}

void vampireGameproject::Daemenor::setDaemenor(std::string daemenor){
    Daemenor::daemenor = daemenor;
}

std::string vampireGameproject::Daemenor::getDaemenor(void){
    return daemenor;
}

void vampireGameproject::Daemenor::setDescription(std::string description){
    Daemenor::description = description;
}

