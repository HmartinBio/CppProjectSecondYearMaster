#include "classes.h"

vampireGameproject::Clan::Clan(Parsetext& textParser): textParser(textParser){}
vampireGameproject::Clan::~Clan(){}

std::string vampireGameproject::Clan::getClan(void){
    return clan;
}

void vampireGameproject::Clan::setClan(std::string clan){
    Clan::clan = clan;
}

void vampireGameproject::Clan::setVampirename(void){
    // function parsing the Vampirename
    vampireName = textParser.parse_text();
}    

void vampireGameproject::Clan::setDescription(void){
    description = textParser.parse_text();
}

std::string vampireGameproject::Clan::getVampirename(void){
    return vampireName;
}

