#include "classes.h"


/** Constructor of the class MultiInput.
*
* Modification of the constructor of MultiInput
* 
*
*
*/


vampireGameproject::MultiInput::MultiInput(){};




/** Destructor of the class MultiInput.
*
* Modification of the destructor of MultiInput
*
*
*
*/



vampireGameproject::MultiInput::~MultiInput(){};




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






/** Implementation of the AddText method.
*
* Implementation of the AddText method
* Method adding an item to a specific position
* in the ComboBox 
*
*/




void vampireGameproject::MultiInput::AddText(std::string vectorPosition, std::string stringToAdd, int index){
    if (vectorPosition == "first"){
        firstComboBox.insert(index, stringToAdd);
    }

    else{
        secondComboBox.insert(index, stringToAdd);
    }
}




/** Implementation of the DeleteText method.
*
* Implementation of the DeleteText method
* Method deleting an item to a specific position
* of a ComboBox
*
*/






void vampireGameproject::MultiInput::DeleteText(std::string vectorPosition, int index){
    if (vectorPosition == "first"){
        firstComboBox.remove_text(index);
    }

    else{
        secondComboBox.remove_text(index);
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