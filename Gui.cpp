#include "classes.h"


/** Constructor of the class Gui.
*
* Modification of the constructor of Gui
* Initialisation of the testGui constructor 
* before the Gui constructor be initialised
*
*/

vampireGameproject::Gui::Gui(RulesofGame& rulesGamereference): 
    testGui(rulesGamereference){}



/** Destructor of the class Gui.
* Modification of the destructor of Gui
*
*
*
*/

vampireGameproject::Gui::~Gui(){}




/** Implementation of the setTableComboBox method.
*
* Implementation of the setTableComboBox method
* Method filling the ComboBoxes Clan and Nature
* with Parsed Text
*
*
*/



void vampireGameproject::Gui::setTableComboBox(int index, std::vector<std::string>& vectorElements){
    for(int iterator = 0; iterator < (int)vectorElements.size(); iterator++){
        tableComboBox[index].append(vectorElements.at(iterator));
    }
}



std::string vampireGameproject::Gui::returnClanName(){
    return tableComboBox[0].get_active_text();
}


/** Implementation of the initialiseTableLabel method.
*
* Implementation of the initialiseTableLabel method
* Method setting the Label for Clan, Name of the Vampire, 
* Attributes and Nature
*
*
*/



void vampireGameproject::Gui::initialiseTableLabel(){
    for(int iterator = 0; iterator <= 3; iterator++){
            tableLabel[iterator] = Gtk::Label();
        }
}



/** Implementation of the initialiseTableLabel method.
*
* Implementation of the initialiseTableLabel method
* Method creating the ComboBox Nature and Clan
*
*
*/



void vampireGameproject::Gui::initialiseTableComboBox(){
    tableComboBox[0] = Gtk::ComboBoxText();
    tableComboBox[1] = Gtk::ComboBoxText();
}



/** Implementation of the setTableLabelAlign method.
*
* Implementation of the setTableLabelAlign method
* Method creating the ComboBox Nature and Clan
*
*
*/



void vampireGameproject::Gui::setTableLabelAlign(int index, std::string label){
    tableLabel[index].set_text(label);
    tableLabel[index].set_xalign(0.0);
}




/** Implementation of the setTableLabel method.
*
* Implementation of the setTableLabel method
* Method assigning text to a precised label
*
*
*/




void vampireGameproject::Gui::setTableLabel(int index, std::string label){
    tableLabel[index].set_text(label);
}


/** Implementation of the setTableLabelOnGrid method.
*
* Implementation of the setTableLabelOnGrid method
* Method displaying labels on the GUI
*
*
*/




void vampireGameproject::Gui::setTableLabelOnGrid(int index, int xcoordinates, int ycoordinates, int width, int height){
    mainGrid.attach(tableLabel[index], xcoordinates, ycoordinates, width, height);
}



/** Implementation of the setTableComboBoxOnGrid method.
*
* Implementation of the setTableComboBoxOnGrid method
* Method displaying ComboBoxes on the GUI
*
*
*/



void vampireGameproject::Gui::setTableComboBoxOnGrid(int index, int indexLabel){
    mainGrid.attach_next_to(tableComboBox[index], tableLabel[indexLabel], Gtk::POS_RIGHT, 1, 1);
}



Gtk::ComboBoxText& vampireGameproject::Gui::returnComboBoxClan(){
    return tableComboBox[0];
}




/** Implementation of the setMultiComboBox method.
*
* Implementation of the setTableComboBoxOnGrid method
* Method displaying ComboBoxes on the GUI
*
*   !!!!!!!!!!!!!Method to delete!!!!!!!!!!!!!!!!!!
*/





void vampireGameproject::Gui::setMultiComboBox(Gtk::Button& buttonPlus, Gtk::Button& buttonMinus,
                Gtk::ComboBoxText& ComboFirst, Gtk::ComboBoxText& ComboSecond,
                Gtk::SpinButton& buttonSpin, int xcoordinates, int ycoordinates, 
                int width, int height){

        mainGrid.attach(buttonMinus, xcoordinates, ycoordinates, width, height);
        mainGrid.attach_next_to(buttonPlus, buttonMinus, Gtk::POS_RIGHT, 1, 1);
        mainGrid.attach_next_to(ComboFirst, buttonMinus, Gtk::POS_RIGHT, 1, 1);
        mainGrid.attach_next_to(ComboSecond, ComboFirst, Gtk::POS_RIGHT, 1, 1);
        mainGrid.attach_next_to(buttonSpin, ComboSecond, Gtk::POS_RIGHT, 1, 1);
}




/** Implementation of the setButtonMultiInputAttributes method.
*
* Implementation of the setButtonMultiInputAttributes method
* Method displaying Plus and Minus button of ButtonMultiInput
* And Displaying their labels on the buttons
*
*/



void vampireGameproject::Gui::setButtonMultiInputAttributes(){
     
    mainGrid.attach_next_to(attributesInput.returnButton("minus"), 
        tableLabel[3], Gtk::POS_RIGHT, 1, 1);

     //mainGrid.attach(attributesInput.returnButton("minus"), 
     //       attributesInput.returnXCoordinate(), 
     //       attributesInput.returnYCoordinate(), 1, 1);
     

    mainGrid.attach_next_to(attributesInput.returnButton("plus"), 
        attributesInput.returnButton("minus"), Gtk::POS_RIGHT, 1, 1);
    
    setLabelMultiComboBoxAttributes();
}



void vampireGameproject::Gui::setButtonMultiInputAbilities(){

    mainGrid.attach_next_to(abilitiesInput.returnButton("minus"), 
        tableLabel[4], Gtk::POS_RIGHT, 1, 1);
    
    mainGrid.attach_next_to(abilitiesInput.returnButton("plus"), 
            abilitiesInput.returnButton("minus"), Gtk::POS_RIGHT, 1, 1);

    setLabelMultiComboBoxAbilities();

}

void vampireGameproject::Gui::setButtonMultiInputBackgrounds(){

    mainGrid.attach_next_to(backgroundsInput.returnButton("minus"), 
        tableLabel[6], Gtk::POS_RIGHT, 1, 1);
    
    mainGrid.attach_next_to(backgroundsInput.returnButton("plus"), 
        backgroundsInput.returnButton("minus"), Gtk::POS_RIGHT, 1, 1);
    
    setLabelMultiComboBoxBackgrounds();
}

void vampireGameproject::Gui::setButtonMultiInputVirtues(){
     mainGrid.attach_next_to(virtuesInput.returnButton("minus"), 
        tableLabel[7], Gtk::POS_RIGHT, 1, 1);
    
    mainGrid.attach_next_to(virtuesInput.returnButton("plus"), 
        virtuesInput.returnButton("minus"), Gtk::POS_RIGHT, 1, 1);
    
    setLabelMultiComboBoxVirtues();

}

void vampireGameproject::Gui::setButtonMultiInputDisciplines(){
    mainGrid.attach_next_to(disciplinesInput.returnButton("minus"), 
        tableLabel[5], Gtk::POS_RIGHT, 1, 1);
    
    mainGrid.attach_next_to(disciplinesInput.returnButton("plus"), 
        disciplinesInput.returnButton("minus"), Gtk::POS_RIGHT, 1, 1);

    setLabelMultiComboBoxDisciplines();

}

void vampireGameproject::Gui::setButtonMultiInputMeritsFlaws(){
     mainGrid.attach_next_to(meritsFlawsInput.returnButton("minus"), 
        tableLabel[8], Gtk::POS_RIGHT, 1, 1);
    
    mainGrid.attach_next_to(meritsFlawsInput.returnButton("plus"), 
        meritsFlawsInput.returnButton("minus"), Gtk::POS_RIGHT, 1, 1);

    setLabelMultiComboBoxMeritsFlaws();
}

void vampireGameproject::Gui::setSpinButtonHumanityPath(){
    mainGrid.attach_next_to(HumanityPathScore, tableLabel[9], Gtk::POS_RIGHT, 1, 1);  
}

void vampireGameproject::Gui::setSpinButtonWillPower(){
    mainGrid.attach_next_to(WillPowerScore, tableLabel[10], Gtk::POS_RIGHT, 1, 1);
}

void vampireGameproject::Gui::setSpinButtonBloodPool(){
    mainGrid.attach_next_to(BloodPoolScore, tableLabel[11], Gtk::POS_RIGHT, 1, 1);
}

void vampireGameproject::Gui::setValidationButton(){
    validationButton.set_label("Save");
    mainGrid.attach(validationButton, 0, 53, 1, 1);

}

Gtk::SpinButton& vampireGameproject::Gui::returnHumanityPathSpinButton(){
    return HumanityPathScore;
}

Gtk::SpinButton& vampireGameproject::Gui::returnWillPowerSpinButton(){
    return WillPowerScore;
}

Gtk::SpinButton& vampireGameproject::Gui::returnBloodPoolSpinButton(){
    return BloodPoolScore;
}

Gtk::Button& vampireGameproject::Gui::returnValidationButton(){
    return validationButton;
}


/** Implementation of the setLabelMultiComboBoxAttributes method.
*
* Implementation of the setLabelMultiComboBoxAttributes method
* Method displaying Plus and Minus on the buttons
*
*
*/




void vampireGameproject::Gui::setLabelMultiComboBoxAttributes(){
    attributesInput.setLabelMultiComboBox();
}


void vampireGameproject::Gui::setLabelMultiComboBoxAbilities(){
    abilitiesInput.setLabelMultiComboBox();
}

void vampireGameproject::Gui::setLabelMultiComboBoxBackgrounds(){
    backgroundsInput.setLabelMultiComboBox();
}

void vampireGameproject::Gui::setLabelMultiComboBoxVirtues(){
    virtuesInput.setLabelMultiComboBox();
}

void vampireGameproject::Gui::setLabelMultiComboBoxDisciplines(){
    disciplinesInput.setLabelMultiComboBox();
}

void vampireGameproject::Gui::setLabelMultiComboBoxMeritsFlaws(){
    meritsFlawsInput.setLabelMultiComboBox();
}


/** Implementation of the returnAttributesInput method.
*
* Implementation of the returnAttributesInput method
* Method returning a reference of ButtonMultiInput
*
*
*/


vampireGameproject::ButtonmultiInput& vampireGameproject::Gui::returnAttributesInput(){
    return attributesInput;
}

vampireGameproject::ButtonmultiInput& vampireGameproject::Gui::returnAbilitiesInput(){
    return abilitiesInput;
}


 vampireGameproject::ButtonmultiInput& vampireGameproject::Gui::returnDisciplinesInput(){
     return disciplinesInput;
 }

vampireGameproject::ButtonmultiInput& vampireGameproject::Gui::returnMeritsFlawsInput(){
    return meritsFlawsInput;
}

vampireGameproject::ButtonmultiInputOneComboBox& vampireGameproject::Gui::returnBackgroundsInput(){
    return backgroundsInput;
}

vampireGameproject::ButtonmultiInputOneComboBox& vampireGameproject::Gui::returnVirtuesInput(){
    return virtuesInput;
}


/** Implementation of the setMultiInputOnGrid method.
*
* Implementation of the setMultiInputOnGrid method
* Method displaying new MultiInput on the GUI
*
*
*/



void vampireGameproject::Gui::setMultiInputOnGrid(ButtonmultiInput& ButtonMultiInputReference, int number){
    mainGrid.attach(ButtonMultiInputReference.returnVectorMultiInput()[number]->returnComboBox("first"), ButtonMultiInputReference.returnXCoordinate(), ButtonMultiInputReference.returnYCoordinate() + number, 1, 1);
    mainGrid.attach_next_to(ButtonMultiInputReference.returnVectorMultiInput()[number]->returnComboBox("second"), ButtonMultiInputReference.returnVectorMultiInput()[number]->returnComboBox("first"), Gtk::POS_RIGHT, 1, 1);
    mainGrid.attach_next_to(ButtonMultiInputReference.returnVectorMultiInput()[number]->returnSpinButton(), ButtonMultiInputReference.returnVectorMultiInput()[number]->returnComboBox("second"), Gtk::POS_RIGHT, 1, 1);
    mainGrid.show_all();
}

void vampireGameproject::Gui::setMultiInputOneComboBoxOnGrid(ButtonmultiInputOneComboBox& ButtonmultiInputOneComboBoxReference, int number){
     mainGrid.attach(ButtonmultiInputOneComboBoxReference.returnVectorMultiInput()[number]->returnComboBox(), ButtonmultiInputOneComboBoxReference.returnXCoordinate(), ButtonmultiInputOneComboBoxReference.returnYCoordinate() + number, 1, 1);
     mainGrid.attach_next_to(ButtonmultiInputOneComboBoxReference.returnVectorMultiInput()[number]->returnSpinButton(), ButtonmultiInputOneComboBoxReference.returnVectorMultiInput()[number]->returnComboBox(), Gtk::POS_RIGHT, 1, 1);
     mainGrid.show_all();
 }

void vampireGameproject::Gui::deleteMultiInputOnGrid(ButtonmultiInput& ButtonMultiInputReference, int number){
    mainGrid.remove(ButtonMultiInputReference.returnVectorMultiInput()[number]->returnComboBox("first"));
    mainGrid.remove(ButtonMultiInputReference.returnVectorMultiInput()[number]->returnComboBox("second"));
    mainGrid.remove(ButtonMultiInputReference.returnVectorMultiInput()[number]->returnSpinButton());
}

 void vampireGameproject::Gui::deleteMultiInputOneComboBoxOnGrid(ButtonmultiInputOneComboBox& ButtonmultiInputOneComboBoxReference, int number){
     mainGrid.remove(ButtonmultiInputOneComboBoxReference.returnVectorMultiInput()[number]->returnComboBox());
     mainGrid.remove(ButtonmultiInputOneComboBoxReference.returnVectorMultiInput()[number]->returnSpinButton());
 }
 
Gtk::Label& vampireGameproject::Gui::returnLabelVampireNickName(){
    return tableLabel[13];
}

void vampireGameproject::Gui::setNicknameLabel(){
    mainGrid.attach_next_to(tableLabel[13], tableLabel[2], Gtk::POS_RIGHT, 1, 1);
}

void vampireGameproject::Gui::setTextNicknameLabel(std::string textToAdd){
    tableLabel[13].set_text(textToAdd);
}

/** Implementation of the showAll method.
*
* Implementation of the showAll method
* Method initiating the display of all the elements 
* on the GUI
*
*
*/



void vampireGameproject::Gui::showAll(){
    mainGrid.show_all();
    Gui::add(mainGrid);
    Gui::show_all_children();
}

