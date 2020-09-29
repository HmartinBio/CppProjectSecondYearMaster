#include "classes.h"

vampireGameproject::Meritsflows::Meritsflows(){
    merits.insert(std::make_pair("Physical", std::map<std::string, int>()));
    flaws.insert(std::make_pair("Physical", std::map<std::string, int>()));
    merits.insert(std::make_pair("Social", std::map<std::string, int>()));
    flaws.insert(std::make_pair("Social", std::map<std::string, int>()));
    merits.insert(std::make_pair("Supernatural", std::map<std::string, int>()));
    flaws.insert(std::make_pair("Supernatural", std::map<std::string, int>()));
}

vampireGameproject::Meritsflows::~Meritsflows(){}

std::map<std::string,int> vampireGameproject::Meritsflows::getMerits(std::string type){
    return merits[type];
}

std::map<std::string,int> vampireGameproject::Meritsflows::getFlaws(std::string type){
    return flaws[type];
}

void vampireGameproject::Meritsflows::setMerits(std::string table, std::string meritsName, int number){
    merits[table].insert(std::make_pair(meritsName, number));
}

void vampireGameproject::Meritsflows::setFlaws(std::string table, std::string flawsName, int number){
    flaws[table].insert(std::make_pair(flawsName, number));
}

