#include "classes.h"



/** Constructor of the class Clan.
*
* Modification of the constructor of Clan
* Initialisation of a Parsetext reference 
* before the Nature constructor be initialised
*
* @param textParser reference of Parsetext object
*
*/


vampireGameproject::Clan::Clan(Parsetext& textParser): textParser(textParser){}




/** Destructor of the class Clan.
*
* Modification of the destructor of Clan
*
*
*
*/


vampireGameproject::Clan::~Clan(){}





std::string vampireGameproject::Clan::getClan(void){
    return clan;
}



/** Implementation of the setClan method.
*
* Implementation of the setClan method
* 
* @param clan clan categorie to set
* 
*/



void vampireGameproject::Clan::setClan(std::string clan){
    Clan::clan = clan;
}




/** Implementation of the setVampirename method.
*
* Implementation of the setVampirename method
* 
*
* 
*/




void vampireGameproject::Clan::setVampirename(void){
    // function parsing the Vampirename
    vampireName = textParser.parse_text();
}    



/** Implementation of the setDescription method.
*
* Implementation of the setDescription method
* 
*
* 
*/



void vampireGameproject::Clan::setDescription(void){
    description = textParser.parse_text();
}



/** Implementation of the getVampirename method.
*
* Implementation of the getVampirename method
* 
*
* 
*/


std::string vampireGameproject::Clan::getVampirename(void){
    return vampireName;
}

