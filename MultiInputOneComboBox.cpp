#include "classes.h"


/** Constructor of the class MultiInput.
*
* Modification of the constructor of MultiInput
* 
*
*
*/


vampireGameproject::MultiInputOneComboBox::MultiInputOneComboBox(){}




/** Destructor of the class MultiInput.
*
* Modification of the destructor of MultiInput
*
*
*
*/



vampireGameproject::MultiInputOneComboBox::~MultiInputOneComboBox(){}




/** Implementation of the returnSpinButton method.
*
* Implementation of the returnSpinButton method
* Method returning the reference of the SpinButton
*  
*
*/



Gtk::SpinButton& vampireGameproject::MultiInputOneComboBox::returnSpinButton(){
    return spinButton;
}




/** Implementation of the returnComboBox method.
*
* Implementation of the returnComboBox method
* Method returning the reference of the chosen ComboBox
*  
*
*/




Gtk::ComboBoxText& vampireGameproject::MultiInputOneComboBox::returnComboBox(){
    return ComboBox;
}



/** Implementation of the setLimitSpinButton method.
*
* Implementation of the setLimitSpinButton method
* Method setting the limit of the SpinButton
*  
*
*/



void vampireGameproject::MultiInputOneComboBox::setLimitSpinButton(int limit){
    spinButton.set_range(0, limit);
    spinButton.set_increments(1,1);
}



/** Implementation of the returnSpinScore method.
*
* Implementation of the returnSpinScore method
* Method returning the Spin Score
*  
*
*/




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






/** Implementation of the AddText method.
*
* Implementation of the AddText method
* Method adding an item to a specific position
* in the ComboBox 
*
*/




/* void vampireGameproject::MultiInputO::AddText(std::string vectorPosition, std::string stringToAdd, int index){
    if (vectorPosition == "first"){
        ComboBox.insert(index, stringToAdd);
    }

    else{
        ComboBox.insert(index, stringToAdd);
    }
} */




/** Implementation of the DeleteText method.
*
* Implementation of the DeleteText method
* Method deleting an item to a specific position
* of a ComboBox
*
*/





/* 
void vampireGameproject::MultiInput::DeleteText(std::string vectorPosition, int index){
    if (vectorPosition == "first"){
        firstComboBox.remove_text(index);
    }

    else{
        secondComboBox.remove_text(index);
    }
}

 */





/** Implementation of the setVectorComboBox method.
*
* Implementation of the setVectorComboBox method
* Method setting the vector containing the ComboBox items
* 
* @param vectorText vector containing the items
* @param index position of the Combobox to set 
*
*/




void vampireGameproject::MultiInputOneComboBox::setVectorComboBox(std::vector<std::string>& vectorText){

    for(int iterator = 0; iterator < (int)vectorText.size(); iterator++){
        ComboBox.append(vectorText.at(iterator));
    }
 

}


/** Implementation of the unsetActiveText method.
*
* Implementation of the unsetActiveText method
* Method unsetting the active text of the Second 
* ComboBox Text
* 
* 
*
*/


void vampireGameproject::MultiInputOneComboBox::unsetActiveText(){
    ComboBox.set_active_text("");
}


/** Implementation of the resetSpinScore method.
*
* Implementation of the resetSpinScore method
* Method reseting the spin Score of a MultiInput Spin Button
* 
* 
*
*/


void vampireGameproject::MultiInputOneComboBox::resetSpinScore(){
    spinButton.set_value(0);
    spinButton.set_increments(0, 0);
}