#include "classes.h"



/** Constructor of the class Chronicle.
*
* Modification of the constructor of Chronicle
* Initialisation of a Parsetext reference 
* before the Nature constructor be initialised
*
* @param textParse: reference of Parsetext object
*
*/



vampireGameproject::Chronicle::Chronicle(Parsetext& textParse): textParser(textParse){}



/** Destructor of the class Chronicle.
*
* Modification of the destructor of Chronicle
*
*
*
*/


vampireGameproject::Chronicle::~Chronicle(){}



/** Implementation of the getChronicle method.
*
* Implementation of the getChronicle method
* Method returning the chronicle value
*
* 
*/



std::string vampireGameproject::Chronicle::getChronicle(void){
    return chronicle;
}



/** Implementation of the setChronicle method.
*
* Implementation of the setChronicle method
* Method setting the chronicle value 
*
* @param chronicle: chronicle categorie to set
* 
*/



void vampireGameproject::Chronicle::setChronicle(std::string chronicle){
    Chronicle::chronicle = chronicle;
}



/** Implementation of the setDescription method.
*
* Implementation of the setDescription method
* Method setting the description of Chronicle
*
* 
*/



void vampireGameproject::Chronicle::setDescription(void){
    //description = textParser.parse_text();
    description = "test";
}



/** Implementation of the getDescription method.
*
* Implementation of the getDescription method
* Method getting the description of Chronicle
*
* 
*/


std::string vampireGameproject::Chronicle::getDescription(void){
    return description;
}