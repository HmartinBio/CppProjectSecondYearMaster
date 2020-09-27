#include "classes.h"

vampireGameproject::Attributes::Attributes(){
    physicalAttributes.insert(std::pair<std::string,int>("Strength", 0));
    physicalAttributes.insert(std::pair<std::string,int>("Dexterity", 0));
    physicalAttributes.insert(std::pair<std::string,int>("Stamina", 0));
    socialAttributes.insert(std::pair<std::string,int>("Charisma",0));
    socialAttributes.insert(std::pair<std::string,int>("Manipulation",0));
    socialAttributes.insert(std::pair<std::string,int>("Appearance",0));
    mentalAttributes.insert(std::pair<std::string,int>("Perception",0));
    mentalAttributes.insert(std::pair<std::string,int>("Intelligence",0));
    mentalAttributes.insert(std::pair<std::string,int>("Wits",0)); 
}

std::map<std::string,int> vampireGameproject::Attributes::getAttributes(char attributeTable){
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

void vampireGameproject::Attributes::setAttributes(char tableName,std::string attributeName, int value){
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

