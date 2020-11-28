#include "classes.h"




/** Constructor of the class Meritsflaws.
*
* Modification of the constructor of Meritsflaws
* Initialisation of a Parsetext reference 
* before the Meritsflaws constructor be initialised
* Initialisation of map containing Merits and Flaws
* 
* @param textParse: reference of Parsetext
*/


vampireGameproject::Meritsflaws::Meritsflaws(Parsetext& textParse): textParser(textParse){
    meritsFlaws.insert(std::make_pair("Physical", std::map<std::string, int>()));
    meritsFlaws.insert(std::make_pair("Social", std::map<std::string, int>()));
    meritsFlaws.insert(std::make_pair("Supernatural", std::map<std::string, int>()));
}



/** Destructor of the class Meritsflaws.
*
* Modification of the Destructor of Meritsflaws */



vampireGameproject::Meritsflaws::~Meritsflaws(){}



/** Implementation of the getMeritsFlaws method.
*
* Implementation of the getMeritsFlaws method
* Method returning the Merits and Flaws
* 
* @param type: name of the table to return 
*
*/


std::map<std::string,int> vampireGameproject::Meritsflaws::getMeritsFlaws(std::string type){
    return meritsFlaws[type];
}



/** Implementation of the setMeritsFlaws method.
*
* Implementation of the setMeritsFlaws method
* Method setting Merits and Flaws values
* 
* @param table: name of the table to add a merit or flaw
* @param meritsName: name of the merit or flaw to add
* @param number: value of the merit or flaw to add
*/


void vampireGameproject::Meritsflaws::setMeritsFlaws(std::string table, std::string meritsFlawName, int number){
    meritsFlaws[table].insert(std::make_pair(meritsFlawName, number));
}



/** Implementation of the getDescription method.
*
* Implementation of the getDescription method
* getDescription method allows to return the description of 
* a merit or a flow
* 
* @param table: name of the table to look for a merit or flaw 
* @param attributeName: name of the merit to return the description
*/


std::string vampireGameproject::Meritsflaws::getDescription(std::string table, std::string attributeName){
    return textParser.parse_text("Merits_flaws", table, attributeName);
}




