#include "classes.h"



/** Constructor of the class Daemenor.
*
* Modification of the constructor of Daemenor
* Initialisation of a Parsetext reference 
* before the Daemenor constructor be initialised
*
* @param textParser reference of Parsetext object
*
*/


vampireGameproject::Daemenor::Daemenor(Parsetext& textParser): textParser(textParser){}



/** Destructor of the class Daemenor.
*
* Modification of the destructor of Daemenor
*
*
*
*/


vampireGameproject::Daemenor::~Daemenor(){}



/** Implementation of the setDaemenor method.
*
* Implementation of the setDaemenor method
* 
* @param daemenor deamenor categorie to set
* 
*/



void vampireGameproject::Daemenor::setDaemenor(std::string daemenor){
    Daemenor::daemenor = daemenor;
}



/** Implementation of the getDaemenor method.
*
* Implementation of the getDaemenor method
*
*
*
*/



std::string vampireGameproject::Daemenor::getDaemenor(void){
    return daemenor;
}



/** Implementation of the setDescription method.
*
* Implementation of the setDescription method
*
*
*
*/



void vampireGameproject::Daemenor::setDescription(void){
    description = textParser.parse_text();
}

