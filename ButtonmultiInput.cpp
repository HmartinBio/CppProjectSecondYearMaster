#include "classes.h"

vampireGameproject::ButtonmultiInput::ButtonmultiInput(){}

vampireGameproject::ButtonmultiInput::~ButtonmultiInput(){}

Gtk::Button& vampireGameproject::ButtonmultiInput::returnButton(std::string sign){
    if (sign == "plus"){
        return plusButton;
    }

    else{
        return minusButton;
    }
}

Gtk::ComboBoxText& vampireGameproject::ButtonmultiInput::returnComboBox(std::string position){
    if (position == "first"){
        return firstComboBox;
    }

    else{
        return secondComboBox;
    }
}

Gtk::SpinButton& vampireGameproject::ButtonmultiInput::returnSpinButton(){
    return spinButton;
} 