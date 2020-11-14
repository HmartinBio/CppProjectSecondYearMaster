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
        initializeButtonMultiInput();
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


// Don't forget to verify for the first comboBox 
// If we changed of items, if it's the case, so, 
// we need to clean the spin score et and the 
// active text of the second ComboBox




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






/** Implementation of the testInputsFirstComboBoxChangingItems method.
*
* Implementation of the testInputsFirstComboBoxChangingItems method
* Method unsetting the text of the Second Combo Box, if the
* item of the first comboBox is changed. If it's changed, so, 
* the text of the second comboBox is clear and the spin score is clear too 
*
*
*
*/


// Il ne faudra pas oublier de rétablir le spin score de tous les autres
// Pour cela utiliser la méthode propre au spin score 
// !!!!!! A faire





void vampireGameproject::Controllor::testInputsFirstComboBoxChangingItems(ButtonmultiInput& ButtonMultiInputReference, int number){
    
    // if the text of the second Combobox is not null whereas we changed the item
    // of the first ComboBox

    if (ButtonMultiInputReference.returnTextComboBox(number, "second") != ""){
        std::map<std::string, std::string> dicoSelectedInputs = ButtonMultiInputReference.returnDicoSelectedInput(); 
        
        // If the item in the first comboBox is not associated to the 
        // item in the Second ComboBox

        if (dicoSelectedInputs[ButtonMultiInputReference.returnTextComboBox(number, "second")] != ButtonMultiInputReference.returnTextComboBox(number, "first")){
            ButtonMultiInputReference.deleteItemDicoSelectedInput(ButtonMultiInputReference.returnTextComboBox(number, "second"));
            
            // Then we, delete the active text in the Second ComboBox
            // And we reset the SpinCore of the Spin Button

            std::vector<MultiInput*> vectorMultiInput;
            vectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
            vectorMultiInput[number]->unsetActiveText();
            vectorMultiInput[number]->resetSpinScore();

            // Method to update the spin score of all MultiInput
        }
    }
}



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
    testInputsFirstComboBoxChangingItems(graphicalUserinterface.returnAttributesInput(), number);
    testInputsFirstComboBoxSpinButton(graphicalUserinterface.returnAttributesInput(), number);
    testInputsFirstComboBox(graphicalUserinterface.returnAttributesInput(), number);
}


/** Implementation of the testInputSecondComboBox method.
*
* Implementation of the testInputSecondComboBox method
* Method updating the dictionnary of selected inputs
* And from that, updating the items of the Second ComboBoxes
* for all the Concerned MultiInputs  
*
*/


void vampireGameproject::Controllor::testInputSecondComboBox(int number){
    ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
    ButtonMultiInputReference.setDicoSelectedInput();
    testInputSecondComboBoxChosenItems(ButtonMultiInputReference, number);

}



/** Implementation of the testInputSecondComboBoxChosenItems method.
*
* Implementation of the testInputSecondComboBoxChosenItems method
* Method detecting if in all the Second ComboBox of all MultiInput 
* we dectect the last MultiInput modified, if it's not the case,
* we look if the item of the First Combo Box is the same 
* of the item we choose for our Combo Box. If it's the case, 
* we delete the chosen item for all the concerned MultiInput  
*
*/


void vampireGameproject::Controllor::testInputSecondComboBoxChosenItems(ButtonmultiInput& ButtonMultiInputReference, int number){
    
    // Declaration of the vectorMultinput

    std::vector<MultiInput*> vectorMultiInput;

    // Initialising the vectorMultiInput

    vectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();

    // For all the elements of the vectorMultiInput, if the element 
    // is not the chosen MultiInput and if the item of the first 
    // Combo Box is the same than the chosen MultiInput
    // Then, we update the choices for the second ComboBox

    for(int iterator = 0; iterator < (int)vectorMultiInput.size(); iterator++){
        if (vectorMultiInput[iterator] != vectorMultiInput[number]){
            if (vectorMultiInput[iterator]->returnTextComboBox("first") == vectorMultiInput[number]->returnTextComboBox("first")){
                testInputsFirstComboBox(ButtonMultiInputReference, iterator);
            }
        }
    }
}





/** Implementation of the testInputSpinButton method.
*
* Implementation of the testInputSpinButton method
* Method updating the Spin Score Limit for all the MultiInput 
* when a SpinScore for a MultiInput is updated
*  
*
*/



void vampireGameproject::Controllor::testInputSpinButton(ButtonmultiInput& ButtonMultiInputReference, int number){
    
    // Updating the Dictionnary of Spin Score

    ButtonMultiInputReference.setDicoScoreFirstComboBox();
    
    // Setting a variable to use the VectorMultiInput
    
    std::vector<MultiInput*> vectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    
    // For all the MultiInputs, if the MultiInput has the same First ComboBox item
    // Than the MultiInput where the spin score has been updated. Then, we update 
    // the spin score limit, this one is computed such as : 
    // newSpinScore = oldSpinScore + ruledSpinScoreItem - ActualSpinScoreItem 

    for(int iterator = 0; iterator < (int)vectorMultiInput.size(); iterator++){
        if(vectorMultiInput[iterator]->returnTextComboBox("first") == vectorMultiInput[number]->returnTextComboBox("first")){
            
            int newSpinButtonLimit = vectorMultiInput[iterator]->returnSpinScore() + (rulesGame.returnLimitPointsAttributes()[vectorMultiInput[number]->returnTextComboBox("first")] 
                - ButtonMultiInputReference.returnDicoScoreFirstComboBox()[vectorMultiInput[number]->returnTextComboBox("first")]);
            vectorMultiInput[iterator]->setLimitSpinButton(newSpinButtonLimit);
        }
    }
}


void vampireGameproject::Controllor::setMultiInput(){
    ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
    ButtonMultiInputReference.setMultiInput();
    std::vector<MultiInput*> VectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    ButtonMultiInputReference.setVectorComboBox(VectorMultiInput.size() - 1, "first", textParser.parse_Attributes());
    //testAttributesInputsFirstComboBox(); 
    graphicalUserinterface.setMultiInputOnGrid(ButtonMultiInputReference, VectorMultiInput.size() - 1);
}







/** Implementation of the initializeButtonMultiInput method.
*
* Implementation of the initializeButtonMultiInput method
* Method setting the first MultiInput in the vector
*
*/



void vampireGameproject::Controllor::initializeButtonMultiInputReference(ButtonmultiInput& ButtonMultiInputReference){
    ButtonMultiInputReference.setCoordinates(4, 2);
    ButtonMultiInputReference.initialize();
    Gtk::Button& buttonPlus = ButtonMultiInputReference.returnButton("plus");
    Gtk::Button& buttonMinus = ButtonMultiInputReference.returnButton("minus");
    buttonPlus.signal_clicked().connect(sigc::mem_fun(*this, &vampireGameproject::Controllor::setMultiInput));
    buttonMinus.signal_clicked().connect(sigc::mem_fun(*this, &vampireGameproject::Controllor::deleteMultiInput));
    ButtonMultiInputReference.setVectorComboBox(0, "first", textParser.parse_Attributes());
    //ButtonMultiInputReference.setVectorComboBox(0, "second");
    graphicalUserinterface.setButtonMultiInputAttributes();
    graphicalUserinterface.setMultiInputOnGrid(ButtonMultiInputReference, 0);


}




void vampireGameproject::Controllor::initializeButtonMultiInput(){
    initializeButtonMultiInputReference(graphicalUserinterface.returnAttributesInput());
}


void vampireGameproject::Controllor::deleteMultiInput(){
    ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
    std::vector<MultiInput*> VectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput(); 
    graphicalUserinterface.deleteMultiInputOnGrid(ButtonMultiInputReference, VectorMultiInput.size() - 1);
    ButtonMultiInputReference.deleteMultiInput();
}