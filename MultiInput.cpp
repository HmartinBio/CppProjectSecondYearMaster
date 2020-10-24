#include "classes.h"

vampireGameproject::MultiInput::MultiInput(){};
//vampireGameproject::MultiInput::~MultiInput(){};

Gtk::SpinButton& vampireGameproject::MultiInput::returnSpinButton(){
    return spinButton;
}

Gtk::ComboBoxText& vampireGameproject::MultiInput::returnComboBox(std::string position){
    if (position == "first"){
        return firstComboBox;
    }

    else{
        return secondComboBox;
    }
}

void vampireGameproject::MultiInput::setLimitSpinButton(int limit){
    spinButton.set_range(0, limit);
    spinButton.set_increments(1,1);
}

int vampireGameproject::MultiInput::returnSpinScore(){
    return spinButton.get_value();
}

std::string vampireGameproject::MultiInput::returnTextComboBox(std::string index){
    if (index == "first"){
        return firstComboBox.get_active_text();
    }

    else{
        return secondComboBox.get_active_text();
    }
}

void vampireGameproject::MultiInput::AddText(std::string vectorPosition, std::string stringToAdd, int index){
    if (vectorPosition == "first"){
        firstComboBox.insert(index, stringToAdd);
    }

    else{
        secondComboBox.insert(index, stringToAdd);
    }
}

void vampireGameproject::MultiInput::DeleteText(std::string vectorPosition, int index){
    if (vectorPosition == "first"){
        firstComboBox.remove_text(index);
    }

    else{
        secondComboBox.remove_text(index);
    }
}