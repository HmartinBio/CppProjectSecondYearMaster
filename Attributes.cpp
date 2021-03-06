/**
 * @file Attributes.cpp
 *
 * @brief File containing source code of the Attributes class
 *
 *
 * @author Hugo MARTIN
 * Contact: hugo.martin.1@etu.univ-amu.fr
 *
 */




#include "classes.h"


/** Constructor of the class Attributes.
*
* Modification of the Constructor of Attributes
* Initialisation of a Parsetext reference 
* before the Attributes constructor be initialised
*
* @param textParse: reference of Parsetext
*/


vampireGameproject::Attributes::Attributes(Parsetext& textParse): textParser(textParse){}



/** Destructor of the class Attributes.
*
* Modification of the destructor of Attributes
*
*
*
*/



vampireGameproject::Attributes::~Attributes(){}




/** Implementation of the getAttributes method.
*
* Implementation of the getAttributes method
* Method returning the attributes
*
* @param attributeTable: name of the table to return
*
*/


std::map<std::string,int> vampireGameproject::Attributes::getAttributes(std::string attributeTable){
    if(attributeTable == "Physical"){
        return physicalAttributes;
    }
    else if(attributeTable == "Social"){
        return socialAttributes;
    }

    else if(attributeTable == "Mental"){
        return mentalAttributes;
    }
    
    else{
        std::cout << "ERROR, the attributeTable is wrong" << std::endl;
        return std::map<std::string, int>();
    }
    
}


/** Implementation of the setAttributes method.
*
* Implementation of the setAttributes method
* setAttributes method allows to allocate Attributes 
* to character 
* 
* @param tableName: name of the table to add an attribute 
* @param attributeName: name of the attribute to add
* @param value: value of the attribute to add
*/


void vampireGameproject::Attributes::setAttributes(std::string tableName,std::string attributeName, int value){
    if(tableName == "Physical"){
        physicalAttributes.insert(std::pair<std::string,int>(attributeName, value));
    }
    else if(tableName == "Social"){
        socialAttributes.insert(std::pair<std::string,int>(attributeName, value));
    }

    else if(tableName == "Mental"){
          mentalAttributes.insert(std::pair<std::string,int>(attributeName, value));
    }

    else{
        std::cout << "ERROR, the tableName is false" << std::endl;
    }
}


/** Implementation of the getDescriptionattributes method.
*
* Implementation of the getDescriptionattributes method
* getDescriptionattributes method allows to return the description of 
* an attribute 
* 
* @param table: name of the table to look for an attribute 
* @param attributeName: name of the attribute to return the description
*/


std::string vampireGameproject::Attributes::getDescriptionattributes(std::string table, std::string attributeName){
    return textParser.parseText(table, attributeName);
}
