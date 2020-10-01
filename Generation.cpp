#include "classes.h"



/** Constructor of the class Generation.
*
* Modification of the constructor of Clan
* Initialisation of a Parsetext reference 
* before the Nature constructor be initialised
*
* @param textParser reference of Parsetext object
*
*/


vampireGameproject::Generation::Generation(Parsetext& textParser): textParser(textParser){}



/** Destructor of the class Clan.
*
* Modification of the destructor of Clan
*
*
*
*/


vampireGameproject::Generation::~Generation(){}



/** Implementation of the getGeneration method.
*
* Implementation of the getGeneration method
* 
*
* 
*/



std::string vampireGameproject::Generation::getGeneration(void){
    return generation;
}




/** Implementation of the setGeneration method.
*
* Implementation of the setGeneration method
* 
* @param generation generation categorie to set
* 
*/


void vampireGameproject::Generation::setGeneration(std::string generation){
    Generation::generation = generation;
}



/** Implementation of the getAge method.
*
* Implementation of the getAge method
* 
*
* 
*/



int vampireGameproject::Generation::getAge(void){
    return age;
}



/** Implementation of the setAge method.
*
* Implementation of the setAge method
* 
* @param age age value to set
* 
*/


void vampireGameproject::Generation::setAge(int age){
    Generation::age = age;
}


/** Implementation of the setDescription method.
*
* Implementation of the setDescription method
* 
*
* 
*/

void vampireGameproject::Generation::setDescription(void){
    description = textParser.parse_text();
}

