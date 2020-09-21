#include "classes.h"

vampireGameproject::Character::Character(std::string nature, char playerName, std::string chronicle, int age, std::string demeanor, std::string clan, std::string generation){
    Character::playerName = playerName;
    setNature(nature);
    setChronicle(chronicle);
    setAge(age);
    setDemeanor(demeanor);
    setClan(clan);
    setGeneration(generation);
}

void vampireGameproject::Character::setNature(std::string nature){
    Character::nature = nature;
}
void vampireGameproject::Character::setChronicle(std::string chronicle){
    Character::chronicle = chronicle;
}
void vampireGameproject::Character::setDemeanor(std::string demeanor){
    Character::demeanor = demeanor;
}
void vampireGameproject::Character::setClan(std::string clan){
    Character::clan = clan;
}

void vampireGameproject::Character::setGeneration(std::string generation){
    Character::generation = generation;
}

void vampireGameproject::Character::setAge(int age){
    Character::age = age;
}

std::string vampireGameproject::Character::getNature(void){}
char vampireGameproject::Character::getPlayername(void){}
std::string vampireGameproject::Character::getChronicle(void){}
int vampireGameproject::Character::getAge(void){}
std::string vampireGameproject::Character::getDemeanor(void){}
std::string vampireGameproject::Character::getClan(void){}
std::string vampireGameproject::Character::getGeneration(void){}