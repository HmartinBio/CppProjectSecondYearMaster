#include "classes.h"




/** Constructor of the class Meritsflaws.
*
* Modification of the constructor of Meritsflaws
* Initialisation of a Parsetext reference 
* before the Meritsflaws constructor be initialised
* Initialisation of map containing Merits and Flaws
* 
* @param textParse reference of Parsetext
*/


vampireGameproject::Meritsflaws::Meritsflaws(Parsetext& textParse): textParser(textParse){
    merits.insert(std::make_pair("Physical", std::map<std::string, int>()));
    flaws.insert(std::make_pair("Physical", std::map<std::string, int>()));
    merits.insert(std::make_pair("Social", std::map<std::string, int>()));
    flaws.insert(std::make_pair("Social", std::map<std::string, int>()));
    merits.insert(std::make_pair("Supernatural", std::map<std::string, int>()));
    flaws.insert(std::make_pair("Supernatural", std::map<std::string, int>()));
}



/** Destructor of the class Meritsflaws.
*
* Modification of the Destructor of Meritsflaws
*
*
*
*/



vampireGameproject::Meritsflaws::~Meritsflaws(){}



/** Implementation of the getMerits method.
*
* Implementation of the getMerits method
* Method returning the Merits
* 
* @param type name of the table to return 
*
*/


std::map<std::string,int> vampireGameproject::Meritsflaws::getMerits(std::string type){
    return merits[type];
}



/** Implementation of the getFlaws method.
*
* Implementation of the getFlaws method
* Method returning the Flaws 
*
* @param type name of the table to return 
*
*/


std::map<std::string,int> vampireGameproject::Meritsflaws::getFlaws(std::string type){
    return flaws[type];
}



/** Implementation of the setMerits method.
*
* Implementation of the setMerits method
* Method setting Merits values
* 
* @param table name of the table to add a merit 
* @param meritsName name of the merit to add
* @param number value of the merit to add
*/


void vampireGameproject::Meritsflaws::setMerits(std::string table, std::string meritsName, int number){
    merits[table].insert(std::make_pair(meritsName, number));
}



/** Implementation of the setFlaws method.
*
* Implementation of the setFlaws method
* Method setting Flaws values
* 
* @param table name of the table to add a flaw 
* @param flawsName name of the flaw to add
* @param number value of the flaw to add
*/


void vampireGameproject::Meritsflaws::setFlaws(std::string table, std::string flawsName, int number){
    flaws[table].insert(std::make_pair(flawsName, number));
}


/** Implementation of the getDescriptionmerits method.
*
* Implementation of the getDescriptionmerits method
* getDescriptionmerits method allows to return the description of 
* a merit 
* 
* @param table name of the table to look for a merit 
* @param attributeName name of the merit to return the description
*/


std::string vampireGameproject::Meritsflaws::getDescriptionmerits(std::string table, std::string attributeName){}




/** Implementation of the getDescriptionflaws method.
*
* Implementation of the getDescriptionflows method
* getDescriptionadvantages method allows to return the description of 
* an advantage 
* 
* @param table name of the table to look for an advantage 
* @param attributeName name of the advantage to return the description
*/


std::string vampireGameproject::Meritsflaws::getDescriptionflaws(std::string table, std::string attributeName){}