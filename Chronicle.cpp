#include "classes.h"



/** Constructor of the class Chronicle.
*
* Modification of the constructor of Chronicle
* Initialisation of a Parsetext reference 
* before the Nature constructor be initialised
*
* @param textParser reference of Parsetext object
*
*/



vampireGameproject::Chronicle::Chronicle(Parsetext& textParser): textParser(textParser){}



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
* 
*
* 
*/



std::string vampireGameproject::Chronicle::getChronicle(void){
    return chronicle;
}



/** Implementation of the setChronicle method.
*
* Implementation of the setChronicle method
* 
* @param chronicle nature categorie to set
* 
*/



void vampireGameproject::Chronicle::setChronicle(std::string chronicle){
    Chronicle::chronicle = chronicle;
}



/** Implementation of the setDescription method.
*
* Implementation of the setDescription method
* 
*
* 
*/



void vampireGameproject::Chronicle::setDescription(void){
    description = textParser.parse_text();
}

