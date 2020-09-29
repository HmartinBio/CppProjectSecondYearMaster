#include "classes.h"

vampireGameproject::Generation::Generation(Parsetext& textParser): textParser(textParser){}
vampireGameproject::Generation::~Generation(){}

std::string vampireGameproject::Generation::getGeneration(void){
    return generation;
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
    description = textParser.parse_text();
}

