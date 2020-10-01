#include "classes.h"



/** Constructor of the class Nature.
*
* Modification of the constructor of Daemenor
* Initialisation of a Parsetext reference 
* before the Nature constructor be initialised
*
* @param textParser reference of Parsetext object
*
*/


vampireGameproject::Nature::Nature(Parsetext& textParser): textParser(textParser){}




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
* 
*
* 
*/


std::string vampireGameproject::Nature::getNature(void){
    return nature;
}



/** Implementation of the setNature method.
*
* Implementation of the setNature method
* 
* @param nature nature categorie to set
* 
*/


void vampireGameproject::Nature::setNature(std::string nature){
    Nature::nature = nature;
}





void vampireGameproject::Nature::setDescription(){
    description = textParser.parse_text();
}

