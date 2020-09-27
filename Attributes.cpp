#include "classes.h"

vampireGameproject::Attributes::Attributes(){
    physicalAttributes.insert(std::pair<char,int>("Strength", 0));
    physicalAttributes.insert(std::pair<char,int>("Dexterity", 0));
    physicalAttributes.insert(std::pair<char,int>("Stamina", 0));
    socialAttributes.insert(std::pair<char,int>("Charisma",0));
    socialAttributes.insert(std::pair<char,int>("Manipulation",0));
    socialAttributes.insert(std::pair<char,int>("Appearance",0));
    mentalAttributes.insert(std::pair<char,int>("Perception",0));
    mentalAttributes.insert(std::pair<char,int>("Intelligence",0));
    mentalAttributes.insert(std::pair<char,int>("Wits",0)); 
}

std::map<char,int> vampireGameproject::Attributes::getAttributes(char attributeTable){
    switch(attributeTable){
        case 'physical': return physicalAttributes;  
            break;
        case 'social': return socialAttributes;
           break;
        case 'mental': return mentalAttributes;
            break;
        default:
            break;
    }
}

void vampireGameproject::Attributes::setAttributes(char tableName,char attributeName, int value){
    switch(tableName){
        case 'physical': physicalAttributes[attributeName] += value;
            break;
        case 'social': socialAttributes[attributeName] += value;
            break;
        case 'mental': mentalAttributes[attributeName] += value;
            break;
        default:
            break; 
    }
}

