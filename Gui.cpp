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


void vampireGameproject::Gui::deleteMultiInputOnGrid(ButtonmultiInput& ButtonMultiInputReference, int number){
    mainGrid.remove(ButtonMultiInputReference.returnVectorMultiInput()[number]->returnComboBox("first"));
    mainGrid.remove(ButtonMultiInputReference.returnVectorMultiInput()[number]->returnComboBox("second"));
    mainGrid.remove(ButtonMultiInputReference.returnVectorMultiInput()[number]->returnSpinButton());
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

