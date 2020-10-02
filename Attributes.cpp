#include "classes.h"


/** Constructor of the class Attributes.
*
* Modification of the Constructor of Attributes
* Initialisation of a Parsetext reference 
* before the Attributes constructor be initialised
*
*/


vampireGameproject::Attributes::Attributes(Parsetext& textParser): textParser(textParser){}



/** Implementation of the getAttributes method.
*
* Implementation of the getAttributes method
* Method returning the attributes
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


/** Implementation of the getDescriptionattributes method.
*
* Implementation of the getDescriptionattributes method
* getDescriptionattributes method allows to return the description of 
* an attribute 
* 
* @param table name of the table to look for an attribute 
* @param attributeName name of the attribute to return the description
*/


std::string vampireGameproject::Attributes::getDescriptionattributes(std::string table, std::string attributeName){}
