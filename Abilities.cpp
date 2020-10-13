#include "classes.h"



/** Constructor of the class Abilities.
*
* Modification of the constructor of Abilities
* Initialisation of a Parsetext reference 
* before the Abilities constructor be initialised
* 
* @param textParse reference of Parsetext
*/



vampireGameproject::Abilities::Abilities(Parsetext& textParse): textParser(textParse){}


/** Implementation of the getAbilities method.
*
* Implementation of the getAbilities method
* Method returning the abilities
* 
* @param tableName name of the table to return 
*
*/


std::map<std::string, int> vampireGameproject::Abilities::getAbilities(std::string tableName){
    if(tableName == "talents"){
        return talents;
    }

    else if(tableName == "skills"){
        return skills;
    }
    
    else if(tableName == "knowledges"){
        return knowledges;
    }

    else{
        std::cout << "ERROR, the tableName is false" << std::endl;
        return std::map<std::string, int>(); 
    }

}


/** Implementation of the setAbilities method.
*
* Implementation of the setAbilities method
* Method setting the abilities
* 
* @param tableName name of the table to add an attribute 
* @param abilitieName name of the abilitie to add
* @param value value of the abilitie to add
*/


void vampireGameproject::Abilities::setAbilities(std::string tableName, std::string abilitieName, int value){
    if(tableName == "talents"){
        talents.insert(std::pair<std::string,int>(abilitieName, value));
    }

    else if(tableName == "skills"){
        skills.insert(std::pair<std::string,int>(abilitieName, value));
    }

    else if(tableName == "knowledges"){
        knowledges.insert(std::pair<std::string,int>(abilitieName, value));
    }

    else{
        std::cout << "ERROR, the tableName is false" << std::endl;
    }

}



/** Implementation of the getDescriptionabilities method.
*
* Implementation of the getDescriptionabilities method
* getDescriptionabilities method allows to return the description of 
* an abilitie 
* 
* @param table name of the table to look for an abilitie 
* @param attributeName name of the abilitie to return the description
*/


std::string vampireGameproject::Abilities::getDescriptionabilities(std::string table, std::string attributeName){
    return textParser.parse_text(table, attributeName);
}