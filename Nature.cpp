#include "classes.h"



/** Constructor of the class Nature.
*
* Modification of the constructor of Daemenor
* Initialisation of a Parsetext reference 
* before the Nature constructor be initialised
*
* @param textParse reference of Parsetext object
*
*/


vampireGameproject::Nature::Nature(Parsetext& textParse): textParser(textParse){}




/** Destructor of the class Nature.
*
* Modification of the destructor of Nature
*
*
*
*/



vampireGameproject::Nature::~Nature(){}



/** Implementation of the getNature method.
*
* Implementation of the getNature method
* Method returning the nature value
*
* 
*/


std::string vampireGameproject::Nature::getNature(void){
    return nature;
}



/** Implementation of the setNature method.
*
* Implementation of the setNature method
* Method setting the nature value
* 
* @param nature nature categorie to set
* 
*/


void vampireGameproject::Nature::setNature(std::string nature){
    Nature::nature = nature;
}


/** Implementation of the setDescription method.
*
* Implementation of the setDescription method
* Method setting the description value
* 
* 
*/


void vampireGameproject::Nature::setDescription(void){
   // description = textParser.parse_text("Nature", nature);
   description = "test";
}


/** Implementation of the getDescription method.
*
* Implementation of the getDescription method
* Method getting the description value
* 
* 
*/

std::string vampireGameproject::Nature::getDescription(void){
    return description;
}