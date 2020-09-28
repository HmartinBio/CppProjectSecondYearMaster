#include "classes.h"

vampireGameproject::Generation::Generation(){}
vampireGameproject::Generation::~Generation(){}

std::string vampireGameproject::Generation::getGeneration(void){
    return Generation::generation = generation;
}

void vampireGameproject::Generation::setGeneration(std::string generation){
    Generation::generation = generation;
}

int vampireGameproject::Generation::getAge(void){
    return age;
}

void vampireGameproject::Generation::setAge(int age){
    Generation::age = age;
}

void vampireGameproject::Generation::setDescription(void){
    textParse.parse_text();
}

