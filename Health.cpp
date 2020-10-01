#include "classes.h"



/** Constructor of the class Health.
*
* Modification of the constructor of Health
* Initialisation of the Parsetext reference before
* the constructor of Health class be initialised
*
*/


vampireGameproject::Health::Health(Parsetext& textParser): textParser(textParser){}


/** Destructor of the class Health.
*
* Modification of the destructor of Health
*
*
*
*/


vampireGameproject::Health::~Health(){}



/** Implementation of the getPointlife method.
*
* Implementation of the getPointlife method
* 
*
*
*/


int vampireGameproject::Health::getPointlife(void){
    return pointLife;
}



/** Implementation of the setPointlife method.
*
* Implementation of the setPointlife method
* 
* @param pointLife value of points of life to set
* 
*/


void vampireGameproject::Health::setPointlife(int pointLife){
    Health::pointLife = pointLife;
}



/** Implementation of the getPointlifeDescription method.
*
* Implementation of the getPointlifeDescription method
* 
*
*
*/


std::string vampireGameproject::Health::getPointlifeDescription(void){
    return pointLifedescription;
}



/** Implementation of the getWeakness method.
*
* Implementation of the getWeakness method
* 
*
*
*/


std::string vampireGameproject::Health::getWeakness(void){
    return weakness;
}



/** Implementation of the setPointlifeDescription method.
*
* Implementation of the setPointlifeDescription method
* 
*
*
*/



void vampireGameproject::Health::setPointlifeDescription(void){
    pointLifedescription = textParser.parse_text();
}



