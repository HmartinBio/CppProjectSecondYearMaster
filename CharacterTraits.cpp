#include "classes.h"



/** Constructor of the class CharacterTraits.
*
* Modification of the constructor of CharacterTraits
* Initialisation of the Parsetext reference before
* the constructor of CharacterTraits class be initialised
*
* @param textParse: reference of Parsetext
*/


vampireGameproject::CharacterTraits::CharacterTraits(Parsetext& textParse): textParser(textParse){}



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
* @param number: humanity value to set
* 
*/



void vampireGameproject::CharacterTraits::setHumanity(int number){
    humanity = number;
}



/** Implementation of the setWillpower method.
*
* Implementation of the setWillpower method
* Method setting the willPower value
* 
* @param number: value of points of life to set
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
* @param number: value of points of bloodPool to set
* 
*/



void vampireGameproject::CharacterTraits::setBloodpool(float number){
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
    
    if (humanity == 0){
        return "Monstruous";
    }

    if (humanity == 1){
        return "Horrific";
    }

    if (humanity == 2){
        return "Bestial";
    }

    if (humanity == 3){
        return "Cold";
    }

    if (humanity == 4){
        return "Unfeeling";
    }

    if (humanity == 5){
        return "Distant";
    }

    if (humanity == 6){
        return "Removed";
    }

    if (humanity == 7){
        return "Normal";
    }

    if (humanity == 8){
        return "Caring";
    }

    if (humanity == 9){
        return "Compassionate";
    }

    if (humanity == 10){
        return "Saintly";
    }

    else{
        return "";
    }
}


/** Implementation of the getWillpower method.
*
* Implementation of the getWillpower method
* Method returning the willPower value
*
* 
*/


std::string vampireGameproject::CharacterTraits::getWillpower(void){

    if (willPower == 1){
        return "Spineless";
    }

    if (willPower == 2){
        return "Weak";
    }

    if (willPower == 3){
        return "Unassertive";
    }

    if (willPower == 4){
        return "Diffident";
    }

    if (willPower == 5){
        return "Certain";
    }

    if (willPower == 6){
        return "Confident";
    }

    if (willPower == 7){
        return "Determined";
    }

    if (willPower == 8){
        return "Controlled";
    }

    if (willPower == 9){
        return "Iron-willed";
    }

    if (willPower == 10){
        return "Unshakable";
    }

    else{
        return "";
    }

    
} 


/** Implementation of the getBloodpool method.
*
* Implementation of the getBloodpool method
* Method returning the bloodPool value 
*
* 
*/


float vampireGameproject::CharacterTraits::getBloodpool(void){
    return bloodPool;
}

