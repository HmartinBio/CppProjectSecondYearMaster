#include "classes.h"

/** Constructor of the class Character.
*
* Modification of the Constructor of Character
* for this one gives the Parsetext reference to 
* the other class members contained in Character 
*
* @param textParser reference of Parsetext
*/


vampireGameproject::Character::Character(Parsetext& textParser)
    : characterDaemenor(textParser), characterClan(textParser), 
    characterHealth(textParser), characterNature(textParser), 
    characterChronicle(textParser), characterGeneration(textParser){}



/** Constructor of the class Character.
*
* Modification of the Constructor of Character
* for this one gives the Parsetext reference to 
* the other class members contained in Character 
*
* @param textParser reference of Parsetext
*/



vampireGameproject::Character::~Character(){}




/** Constructor of the class Character.
*
* Modification of the Constructor of Character
* for this one gives the Parsetext reference to 
* the other class members contained in Character 
*
* @param textParser reference of Parsetext
*/



std::string vampireGameproject::Character::getPlayername(void){
    return playerName;
}



/** Constructor of the class Character.
*
* Modification of the Constructor of Character
* for this one gives the Parsetext reference to 
* the other class members contained in Character 
*
* @param textParser reference of Parsetext
*/


void vampireGameproject::Character::setPlayername(std::string name){
    playerName = name;
}

