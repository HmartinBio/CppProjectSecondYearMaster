#include "classes.h"




/** Constructor of the class Meritsflows.
*
* Modification of the constructor of Meritsflows
* Initialisation of map containing Merits and Flows
*
*
*/


vampireGameproject::Meritsflows::Meritsflows(){
    merits.insert(std::make_pair("Physical", std::map<std::string, int>()));
    flaws.insert(std::make_pair("Physical", std::map<std::string, int>()));
    merits.insert(std::make_pair("Social", std::map<std::string, int>()));
    flaws.insert(std::make_pair("Social", std::map<std::string, int>()));
    merits.insert(std::make_pair("Supernatural", std::map<std::string, int>()));
    flaws.insert(std::make_pair("Supernatural", std::map<std::string, int>()));
}



/** Destructor of the class Meritsflows.
*
* Modification of the Destructor of Meritsflows
*
*
*
*/



vampireGameproject::Meritsflows::~Meritsflows(){}



/** Implementation of the getMerits method.
*
* Implementation of the getMerits method
* 
* @param type name of the table to return 
*
*/


std::map<std::string,int> vampireGameproject::Meritsflows::getMerits(std::string type){
    return merits[type];
}



/** Implementation of the getFlaws method.
*
* Implementation of the getFlaws method
* 
* @param type name of the table to return 
*
*/


std::map<std::string,int> vampireGameproject::Meritsflows::getFlaws(std::string type){
    return flaws[type];
}



/** Implementation of the setMerits method.
*
* Implementation of the setMerits method
* 
* @param table name of the table to add a merit 
* @param meritsName name of the merit to add
* @param number value of the merit to add
*/


void vampireGameproject::Meritsflows::setMerits(std::string table, std::string meritsName, int number){
    merits[table].insert(std::make_pair(meritsName, number));
}



/** Implementation of the setFlaws method.
*
* Implementation of the setFlaws method
* 
* @param table name of the table to add a flaw 
* @param flawsName name of the flaw to add
* @param number value of the flaw to add
*/


void vampireGameproject::Meritsflows::setFlaws(std::string table, std::string flawsName, int number){
    flaws[table].insert(std::make_pair(flawsName, number));
}

