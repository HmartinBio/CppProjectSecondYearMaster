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



/** Implementation of the getClan method.
*
* Implementation of the getClan method
* Method returning the clan 
*
* 
*/



std::string vampireGameproject::Clan::getClan(void){
    return clan;
}



/** Implementation of the setClan method.
*
* Implementation of the setClan method
* Method setting the clan 
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
* Method setting the name of the Vampire
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
* Method setting the Description of the clan
*
* 
*/



void vampireGameproject::Clan::setDescription(void){
    description = textParser.parse_text();
}



/** Implementation of the getVampirename method.
*
* Implementation of the getVampirename method
* Method getting the Vampire name
*
* 
*/


std::string vampireGameproject::Clan::getVampirename(void){
    return vampireName;
}

