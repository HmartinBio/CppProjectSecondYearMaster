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


void vampireGameproject::ButtonmultiInput::setLabelMultiComboBox(){
    plusButton.add_label("+");
    minusButton.add_label("-");
}

std::vector<vampireGameproject::MultiInput*> vampireGameproject::ButtonmultiInput::returnVectorMultiInput(){
    return vectorMultiInputs;
}


void vampireGameproject::ButtonmultiInput::setVectorComboBox(std::vector<std::string>& vectorText, std::string index){
    if (index == "first"){
        vectorFirstComboBox = vectorText;
    }

    else{
        vectorSecondComboBox = vectorText;
    }

}


void vampireGameproject::ButtonmultiInput::setDicoScoreFirstComboBox(){
    std::map<std::string, int> mapCounter;

    for(int iterator = 0; iterator < (int)vectorMultiInputs.size(); iterator++){
            mapCounter.insert(std::pair<std::string, int>(vectorMultiInputs[iterator]->returnTextComboBox("first"), 
                vectorMultiInputs[iterator]->returnSpinScore()));        
    }

    std::map<std::string, int>::iterator it;
    
    for (it = mapCounter.begin(); it != mapCounter.end(); it++){
        if (DicoScoreFirstComboBox.find(it->first) == DicoScoreFirstComboBox.end()){
            DicoScoreFirstComboBox.insert(std::pair<std::string, int>(it->first, it->second));
        }

        else{
            DicoScoreFirstComboBox.at(it->first) = it->second;
        }

    }

}


void vampireGameproject::ButtonmultiInput::setDicoSelectedInput(){

    DicoSelectedInputs.clear();

    for(int iterator = 0; iterator < (int)vectorMultiInputs.size(); iterator++){
        DicoSelectedInputs.insert(std::pair<std::string, std::string>(vectorMultiInputs[iterator]->returnTextComboBox("second"), 
            vectorMultiInputs[iterator]->returnTextComboBox("first")));
    }
}
    
void vampireGameproject::ButtonmultiInput::setMultiInput(){
    vectorMultiInputs.push_back(new MultiInput);

}

void vampireGameproject::ButtonmultiInput::deleteMultiInput(){
    vectorMultiInputs.pop_back();
}

void vampireGameproject::ButtonmultiInput::setCoordinates(int coordinateX, int coordinateY){
    xcoordinates = coordinateX;
    ycoordinates = coordinateY;
}