/**
 * @file MultiInputOneComboBox.cpp
 *
 * @brief File containing source code of the MultiInputOneComboBox class
 *
 *
 * @author Hugo MARTIN
 * Contact: hugo.martin.1@etu.univ-amu.fr
 *
 */



#include "classes.h"


/** Constructor of the class MultiInputOneComboBox.
*
* Modification of the constructor of MultiInputOneComboBox */


vampireGameproject::MultiInputOneComboBox::MultiInputOneComboBox(){}




/** Destructor of the class MultiInputOneComboBox.
*
* Modification of the destructor of MultiInputOneComboBox */



vampireGameproject::MultiInputOneComboBox::~MultiInputOneComboBox(){}




/** Implementation of the returnSpinButton method.
*
* Implementation of the returnSpinButton method
* Method returning the reference of the SpinButton */



Gtk::SpinButton& vampireGameproject::MultiInputOneComboBox::returnSpinButton(){
    return spinButton;
}




/** Implementation of the returnComboBox method.
*
* Implementation of the returnComboBox method
* Method returning the reference of the ComboBox */




Gtk::ComboBoxText& vampireGameproject::MultiInputOneComboBox::returnComboBox(){
    return ComboBox;
}



/** Implementation of the setLimitSpinButton method.
*
* Implementation of the setLimitSpinButton method
* Method setting the limit of the SpinButton
*  
* @param limit: limit of the SpinButton
*/



void vampireGameproject::MultiInputOneComboBox::setLimitSpinButton(int limit){
    spinButton.set_range(0, limit);
    spinButton.set_increments(1,1);
}



/** Implementation of the returnSpinScore method.
*
* Implementation of the returnSpinScore method
* Method returning the Spin Score from the Spin Button */




int vampireGameproject::MultiInputOneComboBox::returnSpinScore(){
    return spinButton.get_value();
}





/** Implementation of the returnTextComboBox method.
*
* Implementation of the returnTextComboBox method
* Method returning the Text from ComboBox
* If nothing is set for the Combobox, then an empty string 
* is returned
*/




std::string vampireGameproject::MultiInputOneComboBox::returnTextComboBox(){

    if (ComboBox.get_active_text() != ""){
        return ComboBox.get_active_text();
            
    }

    return "";

}





/** Implementation of the setVectorComboBox method.
*
* Implementation of the setVectorComboBox method
* Method setting the vector containing the ComboBox items
* 
* @param vectorText: vector containing the items
*/




void vampireGameproject::MultiInputOneComboBox::setVectorComboBox(std::vector<std::string>& vectorText){

    for(int iterator = 0; iterator < (int)vectorText.size(); iterator++){
        ComboBox.append(vectorText.at(iterator));
    }
 
}


/** Implementation of the unsetActiveText method.
*
* Implementation of the unsetActiveText method
* Method unsetting the active text of the ComboBox Text
* 
*
*/


void vampireGameproject::MultiInputOneComboBox::unsetActiveText(){
    ComboBox.set_active_text("");
}



/** Implementation of the resetSpinScore method.
*
* Implementation of the resetSpinScore method
* Method reseting the spin Score of a MultiInputOneComboBox Spin Button */


void vampireGameproject::MultiInputOneComboBox::resetSpinScore(){
    spinButton.set_value(0);
    spinButton.set_increments(0, 0);
}