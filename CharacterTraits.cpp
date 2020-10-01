#include "classes.h"



/** Constructor of the class CharacterTraits.
*
* Modification of the constructor of CharacterTraits
*
*
*
*/


vampireGameproject::CharacterTraits::CharacterTraits(){}



/** Destructor of the class CharacterTraits.
*
* Modification of the destructor of CharacterTraits
*
*
*
*/


vampireGameproject::CharacterTraits::~CharacterTraits(){}



/** Implementation of the setHumanity method.
*
* Implementation of the setHumanity method
* Method setting the humanity value 
*
* @param number humanity value to set
* 
*/



void vampireGameproject::CharacterTraits::setHumanity(int number){
    humanity = number;
}



/** Implementation of the setWillpower method.
*
* Implementation of the setWillepower method
* Method setting the willPower value
* 
* @param number value of points of life to set
* 
*/



void vampireGameproject::CharacterTraits::setWillpower(int number){
    willPower = number;
}



/** Implementation of the setBloodpool method.
*
* Implementation of the setBloodpool method
* Method setting the bloodPool value
* 
* @param number value of points of bloodPool to set
* 
*/



void vampireGameproject::CharacterTraits::setBloodpool(int number){
    bloodPool = number;
}


/** Implementation of the getHumanity method.
*
* Implementation of the getHumanity method
* Method returning the humanity value
*
* 
*/


std::string vampireGameproject::CharacterTraits::getHumanity(void){
    /*
    switch(humanity){
        case 0 : return "Monstruous";
            break;
        case 1: return "Horrific";
            break;
        case 2: return "Bestial";
            break;
        case 3: return "Cold";
            break;
        case 4: return "Unfeeling" ;
            break;
        case 5: return "Distant"; 
            break;
        case 6: return "Removed";
            break;
        case 7: return "Normal";
            break;
        case 8: return "Caring";
            break;
        case 9: return "Compassionate";
            break;
        case 10: return "Saintly";
            break;
        default:
            break;
    }
    */
}


/** Implementation of the getWillpower method.
*
* Implementation of the getWillpower method
* Method returning the willPower value
*
* 
*/


std::string vampireGameproject::CharacterTraits::getWillpower(void){
    /*
    switch(willPower){
    case 1: return "Spineless"; 
        break;
    case 2: return "Weak";
        break;
    case 3: return "Unassertive";
        break;
    case 4: return "Diffident";
        break;
    case 5: return "Certain";
        break;
    case 6: return "Confident";
        break;
    case 7: return "Determined";
        break;
    case 8: return "Controlled";
        break;
    case 9: return "Iron-willed";
        break;
    case 10: return "Unshakable";
        break;
    default:
        break;
    }
    */
} 


/** Implementation of the getBloodpool method.
*
* Implementation of the getBloodpool method
* Method returning the bloodPool value 
*
* 
*/


int vampireGameproject::CharacterTraits::getBloodpool(void){
    return bloodPool;
}

