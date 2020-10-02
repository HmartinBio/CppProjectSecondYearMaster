#include "classes.h"

/** Constructor of the class Character.
*
* Modification of the Constructor of Character
* for this one gives the Parsetext reference to 
* the other class members contained in Character 
*
* @param textParse reference of Parsetext
*/


vampireGameproject::Character::Character(Parsetext& textParser)
    : characterDaemenor(textParser), characterClan(textParser), 
    characterHealth(textParser), characterNature(textParser), 
    characterChronicle(textParser), characterGeneration(textParser),
    characterAttributes(textParser), characterAbilities(textParser),
    characterAdvantages(textParser), characterMeritsflaws(textParser),
    characterTraits(textParser){}



/** Destructor of the class Character.
*
* Modification of the Destructor of Character  
*
*/


vampireGameproject::Character::~Character(){}



/** Implementation of the getPlayername method.
*
* Implementation of the getPlayername method
* Method returning the player name 
*  
*
*/



std::string vampireGameproject::Character::getPlayername(void){
    return playerName;
}



/** Implementation of the setPlayername method.
*
* Implementation of the setPlayername method
* Method modifing the attribute playerName 
*
* @param name string to assign to playerName
*/


void vampireGameproject::Character::setPlayername(std::string name){
    playerName = name;
}

