#include "classes.h"


/** Constructor of the class Gui.
*
* Modification of the constructor of Gui
* Initialisation of the testGui constructor 
* before the Gui constructor be initialised
*
* @param rulesGamereference: Reference of the RulesOfGame object
*/





vampireGameproject::Gui::Gui(){}





/** Destructor of the class Gui.
* Modification of the destructor of Gui */





vampireGameproject::Gui::~Gui(){}





/** Implementation of the setTableComboBox method.
*
* Implementation of the setTableComboBox method
* Method filling the ComboBoxes Clan, Nature and Health
* with Parsed Text
*
* @param index: number of the ComboBoxText in the table of ComboBoxesTexts
* @param vectorElements: vector containg the text to set in the ComboBoxText
*/





void vampireGameproject::Gui::setTableComboBox(int index, std::vector<std::string>& vectorElements){
    for(int iterator = 0; iterator < (int)vectorElements.size(); iterator++){
        tableComboBox[index].append(vectorElements.at(iterator));
    }
}





/** Implementation of the returnClanName method.
*
* Implementation of the returnClanName method
* Method returning the text active from the Clan 
* ComboBox Text */



std::string vampireGameproject::Gui::returnClanName(){
    return tableComboBox[0].get_active_text();
}




/** Implementation of the returnNature method.
*
* Implementation of the returnNature method
* Method returning the text active from the Nature 
* ComboBox Text */




std::string vampireGameproject::Gui::returnNature(){
    return tableComboBox[1].get_active_text();
}



std::string vampireGameproject::Gui::returnHealth(){
    return tableComboBox[2].get_active_text();
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



/** Implementation of the initialiseTableComboBox method.
*
* Implementation of the initialiseTableComboBox method
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
* Method setting the text of labels contained in the 
* table of Labels and aligning this text to the interface
*
* @param index: number of Label in the table 
* @param label: text to set in the label
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
* @param index: number of the Label in the Label table
* @param xcoordinates: x coordinates to set the label in the gui
* @param ycoordinates: y coordinate to set the label in the gui
* @param width: width of the label in the gui
* @param height: height of the label in the gui
*/




void vampireGameproject::Gui::setTableLabelOnGrid(int index, int xcoordinates, int ycoordinates, int width, int height){
    mainGrid.attach(tableLabel[index], xcoordinates, ycoordinates, width, height);
}



/** Implementation of the setTableComboBoxOnGrid method.
*
* Implementation of the setTableComboBoxOnGrid method
* Method displaying ComboBoxes on the GUI
*
* @param index: number of the ComboBox in the ComboBox table
* @param indexLabel: number of the Label in the Label Table
*/



void vampireGameproject::Gui::setTableComboBoxOnGrid(int index, int indexLabel){
    mainGrid.attach_next_to(tableComboBox[index], tableLabel[indexLabel], Gtk::POS_RIGHT, 1, 1);
}





/** Implementation of the returnComboBoxClan method.
*
* Implementation of the returnComboBoxClan method
* Method returning ComboBoxText associated to the Clan*/



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
* And Displaying their labels on the buttons*/





void vampireGameproject::Gui::setButtonMultiInputAttributes(){
     
    mainGrid.attach_next_to(attributesInput.returnButton("minus"), 
        tableLabel[5], Gtk::POS_RIGHT, 1, 1);

    mainGrid.attach_next_to(attributesInput.returnButton("plus"), 
        attributesInput.returnButton("minus"), Gtk::POS_RIGHT, 1, 1);
    
    setLabelMultiComboBoxAttributes();
}





/** Implementation of the setButtonMultiInputAbilities method.
*
* Implementation of the setButtonMultiInputAbilities method
* Method displaying Plus and Minus button of ButtonMultiInput
* And Displaying their labels on the buttons
*
*/



void vampireGameproject::Gui::setButtonMultiInputAbilities(){

    mainGrid.attach_next_to(abilitiesInput.returnButton("minus"), 
        tableLabel[6], Gtk::POS_RIGHT, 1, 1);
    
    mainGrid.attach_next_to(abilitiesInput.returnButton("plus"), 
            abilitiesInput.returnButton("minus"), Gtk::POS_RIGHT, 1, 1);

    setLabelMultiComboBoxAbilities();
}





/** Implementation of the setButtonMultiInputBackgrounds method.
*
* Implementation of the setButtonMultiInputBackgrounds method
* Method displaying Plus and Minus button of ButtonMultiInput
* And Displaying their labels on the buttons
*
*/



void vampireGameproject::Gui::setButtonMultiInputBackgrounds(){

    mainGrid.attach_next_to(backgroundsInput.returnButton("minus"), 
        tableLabel[8], Gtk::POS_RIGHT, 1, 1);
    
    mainGrid.attach_next_to(backgroundsInput.returnButton("plus"), 
        backgroundsInput.returnButton("minus"), Gtk::POS_RIGHT, 1, 1);
    
    setLabelMultiComboBoxBackgrounds();
}





/** Implementation of the setButtonMultiInputVirtues method.
*
* Implementation of the setButtonMultiInputVirtues method
* Method displaying Plus and Minus button of ButtonMultiInput
* And Displaying their labels on the buttons
*
*/





void vampireGameproject::Gui::setButtonMultiInputVirtues(){
     mainGrid.attach_next_to(virtuesInput.returnButton("minus"), 
        tableLabel[9], Gtk::POS_RIGHT, 1, 1);
    
    mainGrid.attach_next_to(virtuesInput.returnButton("plus"), 
        virtuesInput.returnButton("minus"), Gtk::POS_RIGHT, 1, 1);
    
    setLabelMultiComboBoxVirtues();

}



/** Implementation of the setButtonMultiInputDisciplines method.
*
* Implementation of the setButtonMultiInputDisciplines method
* Method displaying Plus and Minus button of ButtonMultiInput
* And Displaying their labels on the buttons
*
*/


void vampireGameproject::Gui::setButtonMultiInputDisciplines(){
    mainGrid.attach_next_to(disciplinesInput.returnButton("minus"), 
        tableLabel[7], Gtk::POS_RIGHT, 1, 1);
    
    mainGrid.attach_next_to(disciplinesInput.returnButton("plus"), 
        disciplinesInput.returnButton("minus"), Gtk::POS_RIGHT, 1, 1);

    setLabelMultiComboBoxDisciplines();

}





/** Implementation of the setButtonMultiInputMeritsFlaws method.
*
* Implementation of the setButtonMultiInputMeritsFlaws method
* Method displaying Plus and Minus button of ButtonMultiInput
* And Displaying their labels on the buttons
*
*/



void vampireGameproject::Gui::setButtonMultiInputMeritsFlaws(){
     mainGrid.attach_next_to(meritsFlawsInput.returnButton("minus"), 
        tableLabel[10], Gtk::POS_RIGHT, 1, 1);
    
    mainGrid.attach_next_to(meritsFlawsInput.returnButton("plus"), 
        meritsFlawsInput.returnButton("minus"), Gtk::POS_RIGHT, 1, 1);

    setLabelMultiComboBoxMeritsFlaws();
}


/** Implementation of the setSpinButtonHumanityPath method.
*
* Implementation of the setSpinButtonHumanityPath method
* Method displaying the Spin button associated to Humanity Path
* next to the label in the gui*/


void vampireGameproject::Gui::setSpinButtonHumanityPath(){
    mainGrid.attach_next_to(HumanityPathScore, tableLabel[11], Gtk::POS_RIGHT, 1, 1);  
}





/** Implementation of the setSpinButtonWillPower method.
*
* Implementation of the setSpinButtonWillPower method
* Method displaying the Spin button associated to WillPower
* next to the label in the gui*/



void vampireGameproject::Gui::setSpinButtonWillPower(){
    mainGrid.attach_next_to(WillPowerScore, tableLabel[12], Gtk::POS_RIGHT, 1, 1);
}





/** Implementation of the setSpinButtonBloodPool method.
*
* Implementation of the setSpinButtonBloodPool method
* Method displaying the Spin button associated to Humanity Path
* next to the label in the gui*/



void vampireGameproject::Gui::setSpinButtonBloodPool(){
    mainGrid.attach_next_to(BloodPoolScore, tableLabel[13], Gtk::POS_RIGHT, 1, 1);
}





/** Implementation of the setValidationButton method.
*
* Implementation of the setValidationButton method
* Method displaying the button allowing to retrieve 
* informations entered by the user and to generate the 
* file containing the information*/


void vampireGameproject::Gui::setValidationButton(){
    validationButton.set_label("Save");
    mainGrid.attach(validationButton, 0, 54, 1, 1);

}


/** Implementation of the returnHumanityPathSpinButton method.
*
* Implementation of the returnHumanityPathSpinButton method
* Method allowing to return the Spinbutton associated to Humanity 
* Path*/



Gtk::SpinButton& vampireGameproject::Gui::returnHumanityPathSpinButton(){
    return HumanityPathScore;
}





/** Implementation of the returnWillPowerSpinButton method.
*
* Implementation of the returnWillPowerSpinButton method
* Method allowing to return the Spinbutton associated to Willpower*/



Gtk::SpinButton& vampireGameproject::Gui::returnWillPowerSpinButton(){
    return WillPowerScore;
}



/** Implementation of the returnBloodPoolSpinButton method.
*
* Implementation of the returnBloodPoolSpinButton method
* Method allowing to return the Spinbutton associated to Blood Pool*/



Gtk::SpinButton& vampireGameproject::Gui::returnBloodPoolSpinButton(){
    return BloodPoolScore;
}



/** Implementation of the returnValidationButton method.
*
* Implementation of the returnValidationButton method
* Method allowing to return the button allowing to 
* retrieve the informations from the user*/



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





/** Implementation of the setLabelMultiComboBoxAbilities method.
*
* Implementation of the setLabelMultiComboBoxAbilities method
* Method displaying Plus and Minus on the buttons
*
*
*/


void vampireGameproject::Gui::setLabelMultiComboBoxAbilities(){
    abilitiesInput.setLabelMultiComboBox();
}



/** Implementation of the setLabelMultiComboBoxBackgrounds method.
*
* Implementation of the setLabelMultiComboBoxBackgrounds method
* Method displaying Plus and Minus on the buttons
*
*
*/



void vampireGameproject::Gui::setLabelMultiComboBoxBackgrounds(){
    backgroundsInput.setLabelMultiComboBox();
}





/** Implementation of the setLabelMultiComboBoxVirtues method.
*
* Implementation of the setLabelMultiComboBoxVirtues method
* Method displaying Plus and Minus on the buttons
*
*
*/





void vampireGameproject::Gui::setLabelMultiComboBoxVirtues(){
    virtuesInput.setLabelMultiComboBox();
}




/** Implementation of the setLabelMultiComboBoxDisciplines method.
*
* Implementation of the setLabelMultiComboBoxDisciplines method
* Method displaying Plus and Minus on the buttons
*
*
*/




void vampireGameproject::Gui::setLabelMultiComboBoxDisciplines(){
    disciplinesInput.setLabelMultiComboBox();
}




/** Implementation of the setLabelMultiComboBoxMeritsFlaws method.
*
* Implementation of the setLabelMultiComboBoxMeritsFlaws method
* Method displaying Plus and Minus on the buttons
*
*
*/




void vampireGameproject::Gui::setLabelMultiComboBoxMeritsFlaws(){
    meritsFlawsInput.setLabelMultiComboBox();
}





/** Implementation of the returnAttributesInput method.
*
* Implementation of the returnAttributesInput method
* Method returning a reference of ButtonMultiInput associated 
* to Attributes */


vampireGameproject::ButtonmultiInput& vampireGameproject::Gui::returnAttributesInput(){
    return attributesInput;
}


/** Implementation of the returnAbilitiesInput method.
*
* Implementation of the returnAbilitiesInput method
* Method returning a reference of ButtonMultiInput associated 
* to Abilties */




vampireGameproject::ButtonmultiInput& vampireGameproject::Gui::returnAbilitiesInput(){
    return abilitiesInput;
}



/** Implementation of the returnDisciplinesInput method.
*
* Implementation of the returnDisciplinesInput method
* Method returning a reference of ButtonMultiInput associated 
* to Disciplines */





 vampireGameproject::ButtonmultiInput& vampireGameproject::Gui::returnDisciplinesInput(){
     return disciplinesInput;
 }



/** Implementation of the returnMeritsFlaws method.
*
* Implementation of the returnMeritsFlaws method
* Method returning a reference of ButtonMultiInput associated 
* to MeritsFlaws */



vampireGameproject::ButtonmultiInput& vampireGameproject::Gui::returnMeritsFlawsInput(){
    return meritsFlawsInput;
}



/** Implementation of the returnBackgroundsInput method.
*
* Implementation of the returnAttributesInput method
* Method returning a reference of ButtonMultiInputOneComboBox associated 
* to Backgrounds */





vampireGameproject::ButtonmultiInputOneComboBox& vampireGameproject::Gui::returnBackgroundsInput(){
    return backgroundsInput;
}



/** Implementation of the returnVirtuesInput method.
*
* Implementation of the returnVirtuesInput method
* Method returning a reference of ButtonMultiInput associated 
* to Virtues */





vampireGameproject::ButtonmultiInputOneComboBox& vampireGameproject::Gui::returnVirtuesInput(){
    return virtuesInput;
}





/** Implementation of the setMultiInputOnGrid method.
*
* Implementation of the setMultiInputOnGrid method
* Method displaying new MultiInput on the GUI
*
* @param ButtonMultiInputReference: Reference of the ButtonMultiInput object
* @param number: number of the MultiInput in the MultiInput vector
*/



void vampireGameproject::Gui::setMultiInputOnGrid(ButtonmultiInput& ButtonMultiInputReference, int number){
    mainGrid.attach(ButtonMultiInputReference.returnVectorMultiInput()[number]->returnComboBox("first"), ButtonMultiInputReference.returnXCoordinate(), ButtonMultiInputReference.returnYCoordinate() + number, 1, 1);
    mainGrid.attach_next_to(ButtonMultiInputReference.returnVectorMultiInput()[number]->returnComboBox("second"), ButtonMultiInputReference.returnVectorMultiInput()[number]->returnComboBox("first"), Gtk::POS_RIGHT, 1, 1);
    mainGrid.attach_next_to(ButtonMultiInputReference.returnVectorMultiInput()[number]->returnSpinButton(), ButtonMultiInputReference.returnVectorMultiInput()[number]->returnComboBox("second"), Gtk::POS_RIGHT, 1, 1);
    mainGrid.show_all();
}





/** Implementation of the setMultiInputOneComboBoxOnGrid method.
*
* Implementation of the setMultiInputOneComboBoxOnGrid method
* Method displaying new MultiInput on the GUI
*
* @param ButtonmultiInputOneComboBoxReference: Reference of the ButtonMultiInputOneComboBox object
* @param number: number of the MultiInputOneComboBox in the MultiInputOneComboBox vector
*/



void vampireGameproject::Gui::setMultiInputOneComboBoxOnGrid(ButtonmultiInputOneComboBox& ButtonmultiInputOneComboBoxReference, int number){
     mainGrid.attach(ButtonmultiInputOneComboBoxReference.returnVectorMultiInput()[number]->returnComboBox(), ButtonmultiInputOneComboBoxReference.returnXCoordinate(), ButtonmultiInputOneComboBoxReference.returnYCoordinate() + number, 1, 1);
     mainGrid.attach_next_to(ButtonmultiInputOneComboBoxReference.returnVectorMultiInput()[number]->returnSpinButton(), ButtonmultiInputOneComboBoxReference.returnVectorMultiInput()[number]->returnComboBox(), Gtk::POS_RIGHT, 1, 1);
     mainGrid.show_all();
 }





/** Implementation of the deleteMultiInputOnGrid method.
*
* Implementation of the deleteMultiInputOnGrid method
* Method deletng the last MultiInput from the Gui
*
* @param ButtonMultiInputReference: Reference of the ButtonMultiInput object
* @param number: number of the MultiInput in the MultiInput vector
*/




void vampireGameproject::Gui::deleteMultiInputOnGrid(ButtonmultiInput& ButtonMultiInputReference, int number){
    mainGrid.remove(ButtonMultiInputReference.returnVectorMultiInput()[number]->returnComboBox("first"));
    mainGrid.remove(ButtonMultiInputReference.returnVectorMultiInput()[number]->returnComboBox("second"));
    mainGrid.remove(ButtonMultiInputReference.returnVectorMultiInput()[number]->returnSpinButton());
}





/** Implementation of the deleteMultiInputOneComboBoxOnGrid method.
*
* Implementation of the deleteMultiInputOneComboBoxOnGrid method
* Method deletng the last MultiInputOneComboBox from the Gui
*
* @param ButtonmultiInputOneComboBoxReference: Reference of the ButtonMultiInputOneComboBox object
* @param number: number of the MultiInputOneComboBox in the MultiInputOneComboBox vector
*/




 void vampireGameproject::Gui::deleteMultiInputOneComboBoxOnGrid(ButtonmultiInputOneComboBox& ButtonmultiInputOneComboBoxReference, int number){
     mainGrid.remove(ButtonmultiInputOneComboBoxReference.returnVectorMultiInput()[number]->returnComboBox());
     mainGrid.remove(ButtonmultiInputOneComboBoxReference.returnVectorMultiInput()[number]->returnSpinButton());
 }




/** Implementation of the returnLabelVampireNickName method.
*
* Implementation of the returnLabelVampireNickName method
* Method returning the Label associated to the Vampire Nick Name*/




Gtk::Label& vampireGameproject::Gui::returnLabelVampireNickName(){
    return tableLabel[2];
}



/** Implementation of the setNickNameLabel method.
*
* Implementation of the setNickNameLabel method
* Method setting the Label associated to the Vampire Nick Name
* on the Gui*/




void vampireGameproject::Gui::setNicknameLabel(){
    mainGrid.attach_next_to(tableLabel[2], tableLabel[0], Gtk::POS_RIGHT, 1, 1);
}




/** Implementation of the setTextNicknameLabel method.
*
* Implementation of the setTextNicknameLabel method
* Method updating the Label text associated to the Vampire Nick Name
* on the Gui
*
* @param textToAdd: text to add to the Nickname Label
*/



void vampireGameproject::Gui::setTextNicknameLabel(std::string textToAdd){
    tableLabel[2].set_text(textToAdd);
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

std::string vampireGameproject::Gui::setFileChooser(){
    Gtk::FileChooserDialog* fileToSave = new Gtk::FileChooserDialog("Please choose a folder", 
        Gtk::FILE_CHOOSER_ACTION_SAVE);
    
    fileToSave->set_transient_for(*this);
    fileToSave->add_button("_Cancel", Gtk::ResponseType::RESPONSE_CANCEL);
    fileToSave->add_button("Select", Gtk::ResponseType::RESPONSE_OK);

    int result = fileToSave->run();
    std::string filenameToReturn;

    switch(result){
        case Gtk::ResponseType::RESPONSE_OK:
            filenameToReturn = fileToSave->get_filename();
            break;

        case Gtk::ResponseType::RESPONSE_CANCEL:
            filenameToReturn = "";
            break;
        
        default:
            filenameToReturn = "";
            break;
    
    }

    delete fileToSave;
    return filenameToReturn;
}

void vampireGameproject::Gui::initialiseEntryName(){
    mainGrid.attach_next_to(NameEntry, tableLabel[1], Gtk::POS_RIGHT, 1, 1);
}

std::string vampireGameproject::Gui::returnPlayerName(){
    return NameEntry.get_text();
}