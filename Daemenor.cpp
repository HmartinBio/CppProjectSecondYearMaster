/**
 * @file Daemenor.cpp
 *
 * @brief File containing source code of the Daemenor class
 *
 *
 * @author Hugo MARTIN
 * Contact: hugo.martin.1@etu.univ-amu.fr
 *
 */




#include "classes.h"



/** Constructor of the class Daemenor.
*
* Modification of the constructor of Daemenor
* Initialisation of a Parsetext reference 
* before the Daemenor constructor be initialised
*
* @param textParse: reference of Parsetext object
*
*/


vampireGameproject::Daemenor::Daemenor(Parsetext& textParse): textParser(textParse){}



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
* Method setting the Daemenor value
* 
* @param daemenor:: deamenor categorie to set
* 
*/



void vampireGameproject::Daemenor::setDaemenor(std::string daemenor){
    Daemenor::daemenor = daemenor;
}



/** Implementation of the getDaemenor method.
*
* Implementation of the getDaemenor method
* Method returning the Daemenor value
*
*
*/



std::string vampireGameproject::Daemenor::getDaemenor(void){
    return daemenor;
}



/** Implementation of the setDescription method.
*
* Implementation of the setDescription method
* Method setting the description to Daemenor value
*
*
*/



void vampireGameproject::Daemenor::setDescription(void){
    //description = textParser.parseText();
    description = "test";
}


/** Implementation of the getDescription method.
*
* Implementation of the getDescription method
* Method getting the description value
* 
* 
*/

std::string vampireGameproject::Daemenor::getDescription(){
    return description;
}