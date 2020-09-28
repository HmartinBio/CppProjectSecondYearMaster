#include "classes.h"

vampireGameproject::Clan::Clan(){}
vampireGameproject::Clan::~Clan(){}

std::string vampireGameproject::Clan::getClan(void){
    return clan;
}

void vampireGameproject::Clan::setClan(std::string clan){
    Clan::clan = clan;
}

void vampireGameproject::Clan::setVampirename(){
    // function parsing the Vampirename
}

void vampireGameproject::Clan::setDescription(void){
    textParse.parse_text();
}

std::string vampireGameproject::Clan::getVampirename(void){
    return vampireName;
}

