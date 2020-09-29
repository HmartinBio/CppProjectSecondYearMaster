#include "classes.h"


/** Constructor of the class Attributes.
*
* Modification of the Constructor of Attributes
* Declaration of attributes in the different map with 
* the constructor of Attributes
*
*/


vampireGameproject::Attributes::Attributes(){
    /*
    physicalAttributes.insert(std::pair<std::string,int>("Strength", 0));
    physicalAttributes.insert(std::pair<std::string,int>("Dexterity", 0));
    physicalAttributes.insert(std::pair<std::string,int>("Stamina", 0));
    socialAttributes.insert(std::pair<std::string,int>("Charisma",0));
    socialAttributes.insert(std::pair<std::string,int>("Manipulation",0));
    socialAttributes.insert(std::pair<std::string,int>("Appearance",0));
    mentalAttributes.insert(std::pair<std::string,int>("Perception",0));
    mentalAttributes.insert(std::pair<std::string,int>("Intelligence",0));
    mentalAttributes.insert(std::pair<std::string,int>("Wits",0));
    */ 
}



/** Implementation of the getAttributes method.
*
* Implementation of the getAttributes method
*  
* @param attributeTable name of the table to return 
*
*/


std::map<std::string,int> vampireGameproject::Attributes::getAttributes(std::string attributeTable){
    if(attributeTable == "physical"){
        return physicalAttributes;
    }
    else if(attributeTable == "social"){
        return socialAttributes;
    }

    else if(attributeTable == "mental"){
        return mentalAttributes;
    }
    
}


/** Implementation of the setAttributes method.
*
* Implementation of the setAttributes method
* setAttributes method allows to allocate Attributes 
* to character 
* 
* @param tableName name of the table to add an attribute 
* @param attributeName name of the attribute to add
* @param value value of the attribute to add
*/


void vampireGameproject::Attributes::setAttributes(std::string tableName,std::string attributeName, int value){
    if(tableName == "physical"){
        physicalAttributes.insert(std::pair<std::string,int>(attributeName, value));
    }
    else if(tableName == "social"){
        socialAttributes.insert(std::pair<std::string,int>(attributeName, value));
    }

    else if(tableName == "mental"){
          mentalAttributes.insert(std::pair<std::string,int>(attributeName, value));
    }
}

