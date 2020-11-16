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
        rulesGame.setLimitPointsAttributes(5, 5, 5);
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
    
    // Then we, delete the active text in the Second ComboBox
    // And we reset the SpinCore of the Spin Button

    std::vector<MultiInput*> vectorMultiInput;
    vectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    vectorMultiInput[number]->unsetActiveText();
    vectorMultiInput[number]->resetSpinScore();

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




void vampireGameproject::Controllor::testInputsSecondComboBox(ButtonmultiInput& ButtonMultiInputReference, int number){
       
    // Initialising vectors of selected inputs

    ButtonMultiInputReference.setVectorSelectedInput();

    std::vector<std::string> vectorFirstComboBox = ButtonMultiInputReference.returnVectorSelectedInput("first");
    std::vector<std::string> vectorSecondComboBox = ButtonMultiInputReference.returnVectorSelectedInput("second");


    // Initialising a vector where are stored the parsed text corresponding to 
    // the items of the second combotext for the text entered in the first comboBox 

    std::vector<std::string> vectorAttributesCategorie = textParser.parse_AttributesCategorie(ButtonMultiInputReference.returnTextComboBox(number, "first"));
    
    // Initialising a vector to store all the MultiInputs

    std::vector<MultiInput*> vectorMultiInputs = ButtonMultiInputReference.returnVectorMultiInput();

    // Iteration of elements already entered by the user
    // If a first ComboBoxText iterated element entered 
    // by the user for a MultiInput is detected somewhere else,  
    // we look the iterated second item, if the iterated second item
    // corresponds with a second term present in the vector of selected 
    // second items, then, it means it's the same MultiInput 
    // If it's not the case, the second term present in the vector 
    // selected second item is deleted for this MultiInput whose the choice
    // doesn't correspond to this second term


    for(int iterator = 0; iterator < (int)vectorFirstComboBox.size(); iterator++){
        if (vectorMultiInputs[number]->returnTextComboBox("first") == vectorFirstComboBox.at(iterator) && 
            vectorMultiInputs[number]->returnTextComboBox("second") != vectorSecondComboBox.at(iterator)){
                vectorAttributesCategorie.erase(std::remove(vectorAttributesCategorie.begin(), 
                    vectorAttributesCategorie.end(), vectorSecondComboBox.at(iterator)),
                        vectorAttributesCategorie.end());
        }
    }

     ButtonMultiInputReference.setVectorComboBox(number, "second", vectorAttributesCategorie);


    
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
    testInputSpinButton(graphicalUserinterface.returnAttributesInput(), number);
    testInputSecondComboBoxChosenItems(graphicalUserinterface.returnAttributesInput(), number);
}




void vampireGameproject::Controllor::testInputFirstComboBoxForGui(int number){
    ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
    testInputsFirstComboBoxChangingItems(graphicalUserinterface.returnAttributesInput(), number);
    testInputSpinButton(graphicalUserinterface.returnAttributesInput(), number);
    testInputSecondComboBoxChosenItems(graphicalUserinterface.returnAttributesInput(), number);
}




/** Implementation of the testInputSecondComboBoxForGui method.
*
* Implementation of the testInputSecondComboBoxForGui method
* Method updating the dictionnary of selected inputs
* And from that, updating the items of the Second ComboBoxes
* for all the Concerned MultiInputs  
*
*/


void vampireGameproject::Controllor::testInputSecondComboBoxForGui(int number){
    ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
    testInputSecondComboBoxChosenItems(ButtonMultiInputReference, number);
}



void vampireGameproject::Controllor::testInputSpinButtonForGui(int number){
    ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
    testInputSpinButton(ButtonMultiInputReference, number);
    testFirstComboBoxDisponibility();
}


void vampireGameproject::Controllor::testInputPlusButtonForGui(){
    setMultiInput();
    testFirstComboBoxDisponibility();
}

void vampireGameproject::Controllor::testInputMinusButtonForGui(){
    deleteMultiInput();
    testInputSpinButtonWhenRemoved();
}


void vampireGameproject::Controllor::testInputSpinButtonWhenRemoved(){
    ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();

    // Updating the Dictionnary of Spin Score

    ButtonMultiInputReference.setDicoScoreFirstComboBox();
    
    // Setting a variable to use the VectorMultiInput
    
    std::vector<MultiInput*> vectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    
    // For all the MultiInputs, if the MultiInput has the same First ComboBox item
    // Than the MultiInput where the spin score has been updated. Then, we update 
    // the spin score limit, this one is computed such as : 
    // newSpinScore = oldSpinScore + ruledSpinScoreItem - ActualSpinScoreItem 

    
    for(int iterator = 0; iterator < (int)vectorMultiInput.size(); iterator++){
        
            int newSpinButtonLimit = vectorMultiInput[iterator]->returnSpinScore() + 
                (rulesGame.returnLimitPointsAttributes()[vectorMultiInput[iterator]->returnTextComboBox("first")] - 
                    ButtonMultiInputReference.returnDicoScoreFirstComboBox()[vectorMultiInput[iterator]->returnTextComboBox("first")]); 
              
            int spinScore = vectorMultiInput[iterator]->returnSpinScore();

            std::cout << spinScore << std::endl;
            std::cout << newSpinButtonLimit << std::endl;

            vectorMultiInput[iterator]->setLimitSpinButton(newSpinButtonLimit);
            vectorMultiInput[iterator]->returnSpinButton().set_value(spinScore);

    }


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
                testInputsSecondComboBox(ButtonMultiInputReference, iterator);
            }
        }
    }
}



/** Implementation of the testFirstComboBoxDisponibility method.
*
* Implementation of the testFirstComboBoxDisponibility method
* Method verifying in all the MultiInput if the authorized Spin  
* Score was been reached, if it's the case and if the actual 
* value of the First ComboBoxText is not a value where the 
* authorized Spin Score was reached, the element is deleted
* from the user proposed list 
*
*/


void vampireGameproject::Controllor::testFirstComboBoxDisponibility(){
    ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
    std::vector<MultiInput*> vectorMultiInput;
    vectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    ButtonMultiInputReference.setDicoScoreFirstComboBox();
    std::map<std::string, int> dicoScoreFirstComboBox = ButtonMultiInputReference.returnDicoScoreFirstComboBox();
    

   
    
    std::map<std::string, int> dicoScoreFirstComboBoxRules = rulesGame.returnLimitPointsAttributes();
    std::vector<std::string> vectorFirstComboBoxOutsider;

    std::map<std::string, int>::iterator iterator;

    // For all the elements in the dico Score, if the Spin Score max 
    // was reached, then we register the element in a new vector 


    for (iterator = dicoScoreFirstComboBox.begin(); iterator != dicoScoreFirstComboBox.end(); iterator++){
           
        if (iterator->first != ""){

            if (dicoScoreFirstComboBoxRules.at(iterator->first) == iterator->second){
                vectorFirstComboBoxOutsider.push_back(iterator->first);
            }
        }


        // For all the MultiInputs, we create the vector of First ComboBox Items,
        // Then, we iterate all the terms whose the score is equal to the limit 
        // If the term is the active term of the First ComboBox of the iterated MultiInput
        // We don't delete the value in the list of the items proposed to the user
        // If it's not the case, the value is not proposed to the user anymore

        for(int iterator = 0; iterator < (int)vectorMultiInput.size(); iterator++){
            
            std::vector<std::string> vectorFirstComboBoxChoices = textParser.parse_Attributes();

            if (vectorMultiInput[iterator]->returnTextComboBox("first") != ""){

                for(int iterator2 = 0; iterator2 < (int)vectorFirstComboBoxOutsider.size(); iterator2++){
                    if (vectorMultiInput[iterator]->returnTextComboBox("first") != vectorFirstComboBoxOutsider.at(iterator2)){
                        vectorFirstComboBoxChoices.erase(std::remove(vectorFirstComboBoxChoices.begin(), 
                            vectorFirstComboBoxChoices.end(), vectorFirstComboBoxOutsider.at(iterator2)), 
                                vectorFirstComboBoxChoices.end());
                    }
                }
            }

            int spinScore = vectorMultiInput[iterator]->returnSpinScore();
            std::string textSetactive = vectorMultiInput[iterator]->returnTextComboBox("first");
            vectorMultiInput[iterator]->returnComboBox("first").remove_all();
            vectorMultiInput[iterator]->setVectorComboBox(vectorFirstComboBoxChoices, "first");
            vectorMultiInput[iterator]->returnComboBox("first").set_active_text(textSetactive);
            vectorMultiInput[iterator]->returnSpinButton().set_value(spinScore);
        }
    }

    //else{
    //    std::cout << "test" << std::endl;
    //    std::vector<std::string> vectorFirstComboBoxChoices = textParser.parse_Attributes();
    //    vectorMultiInput[vectorMultiInput.size()]->setVectorComboBox(vectorFirstComboBoxChoices, "first");
    //}
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
        
            //std::cout << rulesGame.returnLimitPointsAttributes()["Mental"] << std::endl;
            //std::cout << rulesGame.returnLimitPointsAttributes()[vectorMultiInput[iterator]->returnTextComboBox("first")] << std::endl;

            int newSpinButtonLimit = vectorMultiInput[iterator]->returnSpinScore() + 
                (rulesGame.returnLimitPointsAttributes()[vectorMultiInput[iterator]->returnTextComboBox("first")] - 
                    ButtonMultiInputReference.returnDicoScoreFirstComboBox()[vectorMultiInput[iterator]->returnTextComboBox("first")]); 

            int spinScore = vectorMultiInput[iterator]->returnSpinScore();

            vectorMultiInput[iterator]->setLimitSpinButton(newSpinButtonLimit);
            vectorMultiInput[iterator]->returnSpinButton().set_value(spinScore);
        }
    }
}


void vampireGameproject::Controllor::setMultiInput(){
    ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
    ButtonMultiInputReference.setMultiInput();
    std::vector<MultiInput*> VectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    
    //ButtonMultiInputReference.setVectorComboBox(VectorMultiInput.size() - 1, "first", textParser.parse_Attributes());
    //testAttributesInputsFirstComboBox(); 
    
    int numberVector = VectorMultiInput.size() - 1;

    Gtk::ComboBoxText& firstComboBox = VectorMultiInput[numberVector]->returnComboBox("first");
    
    firstComboBox.signal_changed().connect(sigc::bind<int>(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputFirstComboBoxForGui), 
        VectorMultiInput.size() - 1));


    graphicalUserinterface.setMultiInputOnGrid(ButtonMultiInputReference, numberVector);
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
    buttonPlus.signal_clicked().connect(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputPlusButtonForGui));
    buttonMinus.signal_clicked().connect(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputMinusButtonForGui));
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
    
    if (VectorMultiInput.size() != 1){

        graphicalUserinterface.deleteMultiInputOnGrid(ButtonMultiInputReference, VectorMultiInput.size() - 1);
        ButtonMultiInputReference.deleteMultiInput();
    }
}



void vampireGameproject::Controllor::setVectorSecondComboBox(std::string ComboBoxFirstValue){
    ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
    std::vector<std::string> vectorSecondBoxElements = textParser.parse_AttributesCategorie(ComboBoxFirstValue);
    std::vector<MultiInput*> VectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    ButtonMultiInputReference.setVectorComboBox(VectorMultiInput.size() - 1, "second", vectorSecondBoxElements);

}
