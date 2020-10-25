#include "classes.h"


/** Constructor of the class Controllor.
*
* Modification of the constructor of Controllor
* 
*
*
*/

vampireGameproject::Controllor::Controllor(): graphicalUserinterface(rulesGame),
    rulesGame(textParser, graphicalUserinterface){
        graphicalUserinterface.set_title("Vampire Game Project");
        graphicalUserinterface.resize(400, 300);
        graphicalUserinterface.set_position(Gtk::WIN_POS_CENTER);
        graphicalUserinterface.initialiseTableLabel();
        graphicalUserinterface.setTableLabelAlign(0, "Select a clan:");
        graphicalUserinterface.setTableLabelAlign(1, "Select a Nature:");
        graphicalUserinterface.setTableLabel(2, "    Name of the Vampire:");
        graphicalUserinterface.setTableLabelAlign(3, "Select Attributes:");
        graphicalUserinterface.setTableLabelOnGrid(0, 0, 0, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(1, 0, 1, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(2, 2, 0, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(3, 0, 2, 1, 1);
        graphicalUserinterface.initialiseTableComboBox();
        rulesGame.setVectorClans();
        rulesGame.setVectorNature();
        graphicalUserinterface.setTableComboBox(0, rulesGame.returnVectorClans());
        graphicalUserinterface.setTableComboBox(1, rulesGame.returnVectorNature());
        graphicalUserinterface.setTableComboBoxOnGrid(0, 0);
        graphicalUserinterface.setTableComboBoxOnGrid(1, 1);
        //graphicalUserinterface.setMultiComboBoxAttributes(1, 3, 1, 1);
        //graphicalUserinterface.setLabelMultiComboBoxAttributes();
        //rulesGame.setLimitSpinButtonAttributes(3);
        graphicalUserinterface.showAll();
}



/** Destructor of the class Controllor.
*
* Modification of the destructor of Controllor
*
*
*
*/


vampireGameproject::Controllor::~Controllor(){}






/** Implementation of the testInputsFirstComboBoxSpinButton method.
*
* Implementation of the testInputsFirstComboBoxSpinButton method
* Method setting the limit of the Spin Button, if the 
* user already chose an items, then this one doesn't appear
* when we chooose the item in the first ComboBox
*
* @param ButtonMultiInputReference Reference of the MultiInput button
*
*/





void vampireGameproject::Controllor::testInputsFirstComboBoxSpinButton(ButtonmultiInput& ButtonMultiInputReference, int number){
    
    // Updating the Dictionnary containing the Point numbers 
    // by items of the First Combo Box
    
    ButtonMultiInputReference.setDicoScoreFirstComboBox();

    // Building temporary maps to store Limits of Points Attributes
    // By the Items of the First Combo Box and to store the Spin Button
    // Scoree by Items of the First Combo Box 

    std::map<std::string, int> DictionnaryScoreFirstComboBox;
    std::map<std::string, int> DictionnaryLimitPointsAttributes;

    // Setting maps

    DictionnaryScoreFirstComboBox = ButtonMultiInputReference.returnDicoScoreFirstComboBox();
    DictionnaryLimitPointsAttributes = rulesGame.returnLimitPointsAttributes();

    // Building a map to store MultiInput in the aim to modify the spin limit
    // for the MultiInput selected

    std::vector<MultiInput*> vectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();

    // Modifing the Spin Limit of the MultiInput selected according to the 
    // rules of Game

    vectorMultiInput[number]->setLimitSpinButton(DictionnaryLimitPointsAttributes[vectorMultiInput[number]->returnTextComboBox("first")] - 
        DictionnaryScoreFirstComboBox[vectorMultiInput[number]->returnTextComboBox("first")]);


}







/** Implementation of the testInputsFirstComboBox method.
*
* Implementation of the testInputsFirstComboBox method
* Method setting the text in the secondComboBox, if the 
* user already chose an items, then this one doesn't appear
* when we chooose the item in the first ComboBox
*
* @param ButtonMultiInputReference Reference of the MultiInput button
*
*/









void vampireGameproject::Controllor::testInputsFirstComboBox(ButtonmultiInput& ButtonMultiInputReference, int number){
    
    // Building a map to store the selected items for the second Combo Box

    std::map<std::string, std::string> mapSelectedInput;
    
    // Initialising the map

    ButtonMultiInputReference.setDicoSelectedInput();
    mapSelectedInput = ButtonMultiInputReference.returnDicoSelectedInput(); 
    
    // Initialising a counter to count the occurences in the text parsed with 
    // the already choices in the comboBoxes
    
    int counter = 0;
    
    // Initialising a vector where are stored the parsed text corresponding to 
    // the items of the second combotext for the text entered in the first comboBox 

    std::vector<std::string> vectorAttributesCategorie = textParser.parse_AttributesCategorie(ButtonMultiInputReference.returnTextComboBox(number, "first"));
    
    // Initialising a vector to store attributes positions found 
    // in the other choices of the user 

    std::vector<int> vectorAttributesPosition;

    // Iteration of elements already entered by the user
    // If a element entered by the user is detected in the 
    // vector containing the text parsed for the second 
    // ComboBox, then the index of the vector element is 
    // stored in a vector

    for(std::map<std::string,std::string>::iterator itertatorDictionnary = mapSelectedInput.begin(); itertatorDictionnary != mapSelectedInput.end(); ++itertatorDictionnary){
        std::string key =  itertatorDictionnary->first;
        std::vector<std::string>::iterator iteratorVector = std::find(vectorAttributesCategorie.begin(), 
            vectorAttributesCategorie.end(), key);    
        
        if (iteratorVector != vectorAttributesCategorie.end()){
            counter += 1;
            int index = std::distance(vectorAttributesCategorie.begin(), iteratorVector);
            vectorAttributesPosition.push_back(index);
        }        
    }

    // If the number of found elements in the dictionnary of 
    // already entered elements by the user is equal to 0
    // Then all the vector is given at the comboBox.
    // Else, we retire the elements already selected 

    if (counter == 0){
        ButtonMultiInputReference.setVectorComboBox(number, "second",
                vectorAttributesCategorie);
    }

    else{
        for(int iterator = 0; iterator < (int)vectorAttributesPosition.size(); iterator++){
            vectorAttributesCategorie.erase(vectorAttributesCategorie.begin() + ((int)vectorAttributesPosition.at(iterator) - 1));
        }

        ButtonMultiInputReference.setVectorComboBox(number, "second", vectorAttributesCategorie);
    }
    
}




/** Implementation of the testAttributesInputsFirstComboBox method.
*
* Implementation of the testAttributesInputFirstComboBox method
* Method applicating the testInputsFirstComboBox and the 
* testInputsFirstComboBoxSpinButton on the ButtonMultiInputs 
* Attributes
*
*/






void vampireGameproject::Controllor::testAttributesInputsFirstComboBox(int number){
    testInputsFirstComboBoxSpinButton(graphicalUserinterface.returnAttributesInput(), number);
    testInputsFirstComboBox(graphicalUserinterface.returnAttributesInput(), number);
}







/** Implementation of the initializeButtonMultiInput method.
*
* Implementation of the initializeButtonMultiInput method
* Method setting the first MultiInput in the vector
*
*/



void vampireGameproject::Controllor::initializeButtonMultiInputReference(ButtonmultiInput& ButtonMultiInputReference){
    ButtonMultiInputReference.setVectorComboBox(0, "first", textParser.parse_Attributes());
}









void vampireGameproject::Controllor::initializeButtonMultiInput(){
    initializeButtonMultiInputReference(graphicalUserinterface.returnAttributesInput());
}

