#include "classes.h"


/** Constructor of the class MultiInput.
*
* Modification of the constructor of MultiInput
* 
*
*
*/


vampireGameproject::MultiInput::MultiInput(){}




/** Destructor of the class MultiInput.
*
* Modification of the destructor of MultiInput
*
*
*
*/



vampireGameproject::MultiInput::~MultiInput(){}




/** Implementation of the returnSpinButton method.
*
* Implementation of the returnSpinButton method
* Method returning the reference of the SpinButton
*  
*
*/



Gtk::SpinButton& vampireGameproject::MultiInput::returnSpinButton(){
    return spinButton;
}




/** Implementation of the returnComboBox method.
*
* Implementation of the returnComboBox method
* Method returning the reference of the chosen ComboBox
*  
*
*/




Gtk::ComboBoxText& vampireGameproject::MultiInput::returnComboBox(std::string position){
    if (position == "first"){
        return firstComboBox;
    }

    else{
        return secondComboBox;
    }
}



/** Implementation of the setLimitSpinButton method.
*
* Implementation of the setLimitSpinButton method
* Method setting the limit of the SpinButton
*  
*
*/



void vampireGameproject::MultiInput::setLimitSpinButton(int limit){
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




int vampireGameproject::MultiInput::returnSpinScore(){
    return spinButton.get_value();
}





/** Implementation of the returnTextComboBox method.
*
* Implementation of the returnTextComboBox method
* Method returning the Text from ComboBox
* If nothing is set for the Combobox, then an empty string 
* is returned
*/




std::string vampireGameproject::MultiInput::returnTextComboBox(std::string index){
    if (index == "first"){

        if (firstComboBox.get_active_text() != ""){
            return firstComboBox.get_active_text();
            
        }

        return "";
       

        
    }

    else{

        if (secondComboBox.get_active_text() != ""){
            return secondComboBox.get_active_text();
                
        }

        return "";
        
        
            
    }
}






/** Implementation of the setVectorComboBox method.
*
* Implementation of the setVectorComboBox method
* Method setting the vector containing the ComboBox items
* 
* @param vectorText vector containing the items
* @param index position of the Combobox to set 
*
*/




void vampireGameproject::MultiInput::setVectorComboBox(std::vector<std::string>& vectorText, 
    std::string index){

    if (index == "first"){
        for(int iterator = 0; iterator < (int)vectorText.size(); iterator++){
            firstComboBox.append(vectorText.at(iterator));
        }
    }

    else{
        for(int iterator = 0; iterator < (int)vectorText.size(); iterator++){
            secondComboBox.append(vectorText.at(iterator));
        }
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


void vampireGameproject::MultiInput::unsetActiveText(){
    secondComboBox.set_active_text("");
}


/** Implementation of the resetSpinScore method.
*
* Implementation of the resetSpinScore method
* Method reseting the spin Score of a MultiInput Spin Button
* 
* 
*
*/


void vampireGameproject::MultiInput::resetSpinScore(){
    spinButton.set_value(0);
    spinButton.set_increments(0, 0);
}