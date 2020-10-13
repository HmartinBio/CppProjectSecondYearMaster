#include "classes.h"



/** Constructor of the class Advantages.
*
* Modification of the constructor of Advantages
* Initialisation of a Parsetext reference 
* before the Advantages constructor be initialised
*
* @param textParse reference of Parsetext
*/


vampireGameproject::Advantages::Advantages(Parsetext& textParse): textParser(textParse){}


/** Destructor of the class Advantages.
*
* Modification of the destructor of Advantages
*
*
*
*/



vampireGameproject::Advantages::~Advantages(){}


/** Implementation of the getAdvantages method.
*
* Implementation of the getAdvantages method
* Method returning the Advantages
* 
* @param tableName
*
*/




std::map<std::string, int> vampireGameproject::Advantages::getAdvantages(std::string tableName){
    if(tableName == "backgrounds"){
        return backgrounds;
    }

    // else if(tableName == "virtues"){

    return virtues; 
}



/** Implementation of the setAdvantages method.
*
* Implementation of the setAdvantages method
* Method setting the advantages
* 
* @param tableName name of the table where setting the abilitie
* @param abilitieName name of the abilitie to set
* @param value value of the abilitie to set
*/


 void vampireGameproject::Advantages::setAdvantages(std::string tableName, std::string abilitieName, int value){
     if(tableName == "backgrounds"){
         backgrounds.insert(std::pair<std::string, int>(abilitieName, value));
     }

     else if(tableName == "virtues"){
         virtues.insert(std::pair<std::string, int>(abilitieName, value));

     }
 }

 
/** Implementation of the getDescriptionadvantages method.
*
* Implementation of the getDescriptionadvantages method
* getDescriptionadvantages method allows to return the description of 
* an advantage 
* 
* @param table name of the table to look for an advantage 
* @param attributeName name of the advantage to return the description
*/


std::string vampireGameproject::Advantages::getDescriptionadvantages(std::string table, std::string attributeName){
    return textParser.parse_text(table, attributeName);
}