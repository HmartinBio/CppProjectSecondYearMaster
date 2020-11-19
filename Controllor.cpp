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
        graphicalUserinterface.setTableLabelAlign(4, "Select Abilities:");
        graphicalUserinterface.setTableLabelOnGrid(0, 0, 0, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(1, 0, 1, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(2, 2, 0, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(3, 0, 2, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(4, 0, 9, 1, 1);
        graphicalUserinterface.initialiseTableComboBox();
        rulesGame.setVectorClans();
        rulesGame.setVectorNature();
        graphicalUserinterface.setTableComboBox(0, rulesGame.returnVectorClans());
        graphicalUserinterface.setTableComboBox(1, rulesGame.returnVectorNature());
        graphicalUserinterface.setTableComboBoxOnGrid(0, 0);
        graphicalUserinterface.setTableComboBoxOnGrid(1, 1);
        rulesGame.setLimitPointsAttributes(5, 5, 5, 13, 9, 5);
        initializeButtonMultiInput("attributes");
        initializeButtonMultiInput("abilities");
        
        std::vector<std::string> abilities = textParser.parse_Abilities();
        
        for(int i = 0; i < (int)abilities.size(); i++){
            std::string chaine = abilities.at(i);
            std::cout << chaine << std::endl;
            std::cout << chaine.size() << std::endl;
        }

        graphicalUserinterface.showAll();

        //std::vector<std::string> abilities = textParser.parse_AbilitiesCategorie("Talents");
        //for(int i = 0; i < (int)abilities.size(); i++){
        //    std::cout << abilities.at(i) << std::endl;
        //}
                

        
        //graphicalUserinterface.returnAttributesInput();
        //graphicalUserinterface.setMultiComboBoxAttributes(1, 3, 1, 1);
        //graphicalUserinterface.setLabelMultiComboBoxAttributes();
        //rulesGame.setLimitSpinButtonAttributes(3);
       
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
    
    std::vector<MultiInput*> vectorMultiInput;
    vectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    
    if (vectorMultiInput[number]->returnTextComboBox("first") != ""){
        vectorMultiInput[number]->returnComboBox("second").append("test");
        vectorMultiInput[number]->returnComboBox("second").remove_all();
    }

    vectorMultiInput[number]->unsetActiveText();
    vectorMultiInput[number]->resetSpinScore();

}




/** Implementation of the testInputsSecondComboBox method.
*
* Implementation of the testInputsFirstComboBox method
* Method setting the text in the secondComboBox, if the 
* user already chose an item in the FirstComboBox, 
* When the user chose an item in the second comboBox, 
* this item can't be used by the others secondComboBox
*
* @param ButtonMultiInputReference Reference of the MultiInput button
*
*/




void vampireGameproject::Controllor::testInputsSecondComboBox(ButtonmultiInput& ButtonMultiInputReference, int number, std::string categorieMultiInput){
       
    // Initialising vectors of selected inputs

    ButtonMultiInputReference.setVectorSelectedInput();

    std::vector<std::string> vectorFirstComboBox = ButtonMultiInputReference.returnVectorSelectedInput("first");
    std::vector<std::string> vectorSecondComboBox = ButtonMultiInputReference.returnVectorSelectedInput("second");


    // Initialising a vector where are stored the parsed text corresponding to 
    // the items of the second combotext for the text entered in the first comboBox 

    if (categorieMultiInput == "attributes"){

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

        if (vectorMultiInputs[number]->returnTextComboBox("first") != ""){
            ButtonMultiInputReference.setVectorComboBox(number, "second", vectorAttributesCategorie);
        }
    }



    if (categorieMultiInput == "abilities"){

        std::vector<std::string> vectorAbilitiesCategorie = textParser.parse_AbilitiesCategorie(ButtonMultiInputReference.returnTextComboBox(number, "first"));
    
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
                    vectorAbilitiesCategorie.erase(std::remove(vectorAbilitiesCategorie.begin(), 
                        vectorAbilitiesCategorie.end(), vectorSecondComboBox.at(iterator)),
                            vectorAbilitiesCategorie.end());
            }
        }

        if (vectorMultiInputs[number]->returnTextComboBox("first") != ""){
            ButtonMultiInputReference.setVectorComboBox(number, "second", vectorAbilitiesCategorie);
        }
    }



}





//void vampireGameproject::Controllor::testAttributesInputsFirstComboBox(int number){
//    testInputsFirstComboBoxChangingItems(graphicalUserinterface.returnAttributesInput(), number);
//    testInputSpinButton(graphicalUserinterface.returnAttributesInput(), number);
//    testInputSecondComboBox(graphicalUserinterface.returnAttributesInput(), number);

//}




/** Implementation of the testInputsFirstComboBoxForGui method.
*
* Implementation of the testInputsFirstComboBoxForGui method
* Method applicating the testInputsFirstComboBoxForGui, when the  
* first ComboBoxText changes, the second comboboxtext and the spin score
* are reset and the Spin Button is tested such as we select a score available
* for the First ComboBoxText item. Then, the SecondComboBoxText is updated
* to make appear Second ComboBoxText items corresponding to the right First 
* ComboBoxText item 
*
*/





void vampireGameproject::Controllor::testInputFirstComboBoxForGui(int number, std::string categorieMultiInput){
    if (categorieMultiInput == "attributes"){
        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
        testInputsFirstComboBoxChangingItems(graphicalUserinterface.returnAttributesInput(), number);
        testInputSpinButton(graphicalUserinterface.returnAttributesInput(), number);
        testInputsSecondComboBox(graphicalUserinterface.returnAttributesInput(), number, categorieMultiInput);
    
    }

    if (categorieMultiInput == "abilities"){
        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAbilitiesInput();
        testInputsFirstComboBoxChangingItems(graphicalUserinterface.returnAbilitiesInput(), number);
        testInputSpinButton(graphicalUserinterface.returnAbilitiesInput(), number);
        testInputsSecondComboBox(graphicalUserinterface.returnAbilitiesInput(), number, categorieMultiInput);
    }
    
    
}




/** Implementation of the testInputSecondComboBoxForGui method.
*
* Implementation of the testInputSecondComboBoxForGui method
* Method updating the dictionnary of selected inputs
* And from that, updating the items of the Second ComboBoxes
* for all the Concerned MultiInputs  
*
*/


void vampireGameproject::Controllor::testInputSecondComboBoxForGui(int number, std::string categorieMultiInput){
    if (categorieMultiInput == "attributes"){
        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
        testInputSecondComboBoxChosenItems(ButtonMultiInputReference, number, categorieMultiInput);
    }

    if (categorieMultiInput == "abilities"){
        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAbilitiesInput();
        testInputSecondComboBoxChosenItems(ButtonMultiInputReference, number, categorieMultiInput);
    }

    
}



/** Implementation of the testInputSpinButtonForGui method.
*
* Implementation of the testInputSpinButtonForGui method
* Method updating the spinScore and verifying the disponibility
* of the First ComboBox Item 
*
*/


void vampireGameproject::Controllor::testInputSpinButtonForGui(int number, std::string categorieMultiInput){
    if (categorieMultiInput == "attributes"){
        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
        testInputSpinButton(ButtonMultiInputReference, number);
    }

    if (categorieMultiInput == "abilities"){
        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAbilitiesInput();
        testInputSpinButton(ButtonMultiInputReference, number);
    }

    testFirstComboBoxDisponibility(categorieMultiInput);
}

/** Implementation of the testInputPlusButtonForGui method.
*
* Implementation of the testInputPlusButtonForGui method
* Method setting a new MultiInput and testing the First ComboBoxText
* items disponibility
*
*/

void vampireGameproject::Controllor::testInputPlusButtonForGui(std::string categorieMultiInput){
    setMultiInput(categorieMultiInput);
    testFirstComboBoxDisponibility(categorieMultiInput);
}



/** Implementation of the testInputMinusButtonForGui method.
*
* Implementation of the testInputMinusButtonForGui method
* Method deleting the last MultiInput and testing 
* the Spin Score avaibility items disponibility 
* 
*/



void vampireGameproject::Controllor::testInputMinusButtonForGui(std::string categorieMultiInput){
    deleteMultiInput(categorieMultiInput);
    testInputSpinButtonWhenRemoved(categorieMultiInput);
    testFirstComboBoxDisponibility(categorieMultiInput);
}



/** Implementation of the testInputSpinButtonWhenRemove method.
*
* Implementation of the testInputSpinButtonWhenRemove method
* Method updating the Spin Score when a MultiInput is deleted
* The Spin Score for all the others MultiInput is actualised 
* in real time when an item is deleted 
*/


void vampireGameproject::Controllor::testInputSpinButtonWhenRemoved(std::string categorieMultiInput){
    
    if (categorieMultiInput == "attributes"){

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

                vectorMultiInput[iterator]->setLimitSpinButton(newSpinButtonLimit);
                vectorMultiInput[iterator]->returnSpinButton().set_value(spinScore);

        }

    }

    if (categorieMultiInput == "abilities"){
         ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAbilitiesInput();
    

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

                vectorMultiInput[iterator]->setLimitSpinButton(newSpinButtonLimit);
                vectorMultiInput[iterator]->returnSpinButton().set_value(spinScore);

        }
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


void vampireGameproject::Controllor::testInputSecondComboBoxChosenItems(ButtonmultiInput& ButtonMultiInputReference, int number, std::string categorieMultiInput){
    
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
                testInputsSecondComboBox(ButtonMultiInputReference, iterator, categorieMultiInput);
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


void vampireGameproject::Controllor::testFirstComboBoxDisponibility(std::string categorieMultiInput){
    
    if (categorieMultiInput == "attributes"){
        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
    

    
        std::vector<MultiInput*> vectorMultiInput;
        vectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    
        ButtonMultiInputReference.setDicoScoreFirstComboBox();
    
        std::map<std::string, int> dicoScoreFirstComboBox = ButtonMultiInputReference.returnDicoScoreFirstComboBox();
    
        std::cout << "depassement du setDicoScoreFirstComboBox" << std::endl;
    
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


        }   

        // For all the MultiInputs, we create the vector of First ComboBox Items,
        // Then, we iterate all the terms whose the score is equal to the limit 
        // If the term is the active term of the First ComboBox of the iterated MultiInput
        // We don't delete the value in the list of the items proposed to the user
        // If it's not the case, the value is not proposed to the user anymore



        std::vector<std::string> vectorFirstComboBoxChoices = textParser.parse_Attributes();
        
        std::cout << "testBoucleAvant" << std::endl;

        for(int iterator = 0; iterator < (int)vectorMultiInput.size(); iterator++){
            
            std::vector<std::string> vectorFirstComboBoxChoicesCopy = vectorFirstComboBoxChoices;
            if (!vectorFirstComboBoxOutsider.empty()){
                std::cout << "coucou" << std::endl;

                for(int iterator2 = 0; iterator2 < (int)vectorFirstComboBoxOutsider.size(); iterator2++){

                    if (vectorMultiInput[iterator]->returnTextComboBox("first") != vectorFirstComboBoxOutsider.at(iterator2)){
                        vectorFirstComboBoxChoicesCopy.erase(std::remove(vectorFirstComboBoxChoicesCopy.begin(), 
                            vectorFirstComboBoxChoicesCopy.end(), vectorFirstComboBoxOutsider.at(iterator2)), 
                                vectorFirstComboBoxChoicesCopy.end());
                    }
                }
            
                
            }
            
            std::cout << "testBoucleApres" << std::endl;

            int spinScore = vectorMultiInput[iterator]->returnSpinScore();
            std::string textSetactiveFirstComboBox = vectorMultiInput[iterator]->returnTextComboBox("first");
            std::string textSetactiveSecondComboBox = vectorMultiInput[iterator]->returnTextComboBox("second");
            vectorMultiInput[iterator]->returnComboBox("first").remove_all();
            vectorMultiInput[iterator]->setVectorComboBox(vectorFirstComboBoxChoicesCopy, "first");
            vectorMultiInput[iterator]->returnComboBox("first").set_active_text(textSetactiveFirstComboBox);
            vectorMultiInput[iterator]->returnComboBox("second").set_active_text(textSetactiveSecondComboBox);
            vectorMultiInput[iterator]->returnSpinButton().set_value(spinScore);
        
        }

        std::cout << "depassement du dicoScoreFirstComboBoxRules" << std::endl;        
    }



    if (categorieMultiInput == "abilities"){
         ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAbilitiesInput();
    

    
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


        }   

        // For all the MultiInputs, we create the vector of First ComboBox Items,
        // Then, we iterate all the terms whose the score is equal to the limit 
        // If the term is the active term of the First ComboBox of the iterated MultiInput
        // We don't delete the value in the list of the items proposed to the user
        // If it's not the case, the value is not proposed to the user anymore


        

        std::vector<std::string> vectorFirstComboBoxChoices = textParser.parse_Abilities();
        

        for(int iterator = 0; iterator < (int)vectorMultiInput.size(); iterator++){
            
            std::vector<std::string> vectorFirstComboBoxChoicesCopy = vectorFirstComboBoxChoices;

            if (!vectorFirstComboBoxOutsider.empty()){

                for(int iterator2 = 0; iterator2 < (int)vectorFirstComboBoxOutsider.size(); iterator2++){

                    if (vectorMultiInput[iterator]->returnTextComboBox("first") != vectorFirstComboBoxOutsider.at(iterator2)){
                        vectorFirstComboBoxChoicesCopy.erase(std::remove(vectorFirstComboBoxChoicesCopy.begin(), 
                            vectorFirstComboBoxChoicesCopy.end(), vectorFirstComboBoxOutsider.at(iterator2)), 
                                vectorFirstComboBoxChoicesCopy.end());
                    }
                }
            
            }
            
            int spinScore = vectorMultiInput[iterator]->returnSpinScore();
            std::string textSetactiveFirstComboBox = vectorMultiInput[iterator]->returnTextComboBox("first");
            std::string textSetactiveSecondComboBox = vectorMultiInput[iterator]->returnTextComboBox("second");
            vectorMultiInput[iterator]->returnComboBox("first").remove_all();
            vectorMultiInput[iterator]->setVectorComboBox(vectorFirstComboBoxChoicesCopy, "first");
            vectorMultiInput[iterator]->returnComboBox("first").set_active_text(textSetactiveFirstComboBox);
            vectorMultiInput[iterator]->returnComboBox("second").set_active_text(textSetactiveSecondComboBox);
            vectorMultiInput[iterator]->returnSpinButton().set_value(spinScore);
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



/** Implementation of the setMultiInput method.
*
* Implementation of the setMultiInput method
* Method creating a new MultiInput and linking 
* the different buttons with Controllor class methods
*
*/



void vampireGameproject::Controllor::setMultiInput(std::string categorieMultiInput){
    
    if (categorieMultiInput == "attributes"){

        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
    

        ButtonMultiInputReference.setMultiInput();
        std::vector<MultiInput*> VectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    
        //ButtonMultiInputReference.setVectorComboBox(VectorMultiInput.size() - 1, "first", textParser.parse_Attributes());
        //testAttributesInputsFirstComboBox(); 
    
        int numberVector = VectorMultiInput.size() - 1;

        Gtk::ComboBoxText& firstComboBox = VectorMultiInput[numberVector]->returnComboBox("first");
        Gtk::ComboBoxText& secondComboBox = VectorMultiInput[numberVector]->returnComboBox("second");
   
        firstComboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputFirstComboBoxForGui), 
            numberVector, categorieMultiInput));

        secondComboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, 
            &vampireGameproject::Controllor::testInputSecondComboBoxForGui), 
                numberVector, categorieMultiInput));

   

        graphicalUserinterface.setMultiInputOnGrid(ButtonMultiInputReference, numberVector);
    }

    if (categorieMultiInput == "abilities"){
        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAbilitiesInput();
    

        ButtonMultiInputReference.setMultiInput();
        std::vector<MultiInput*> VectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    
        //ButtonMultiInputReference.setVectorComboBox(VectorMultiInput.size() - 1, "first", textParser.parse_Attributes());
        //testAttributesInputsFirstComboBox(); 
    
        int numberVector = VectorMultiInput.size() - 1;

        Gtk::ComboBoxText& firstComboBox = VectorMultiInput[numberVector]->returnComboBox("first");
        Gtk::ComboBoxText& secondComboBox = VectorMultiInput[numberVector]->returnComboBox("second");
   
        firstComboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputFirstComboBoxForGui), 
            numberVector, categorieMultiInput));

        secondComboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, 
            &vampireGameproject::Controllor::testInputSecondComboBoxForGui), 
                numberVector, categorieMultiInput));

   

        graphicalUserinterface.setMultiInputOnGrid(ButtonMultiInputReference, numberVector);
    }

}




/** Implementation of the initializeButtonMultiInputReference method.
*
* Implementation of the initializeButtonMultiInputReference method
* Method setting the plus and minus button of the ButtonMultiInput 
* Implementing the first MultiInput in the vector
* Linking buttons of the First MultiInput to Controllor class methods
*
*/



void vampireGameproject::Controllor::initializeButtonMultiInputReference(ButtonmultiInput& ButtonMultiInputReference, std::string categorieMultiInput){
    if (categorieMultiInput == "attributes"){
        ButtonMultiInputReference.setCoordinates(4, 2);
    }

    if (categorieMultiInput == "abilities"){
        ButtonMultiInputReference.setCoordinates(4, 9);
    }


    ButtonMultiInputReference.initialize();
    Gtk::Button& buttonPlus = ButtonMultiInputReference.returnButton("plus");
    Gtk::Button& buttonMinus = ButtonMultiInputReference.returnButton("minus");
    

    buttonPlus.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputPlusButtonForGui), 
        categorieMultiInput));
    
    buttonMinus.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputMinusButtonForGui), 
        categorieMultiInput));
    

    if (categorieMultiInput == "attributes"){
        ButtonMultiInputReference.setVectorComboBox(0, "first", textParser.parse_Attributes());
    }

    if (categorieMultiInput == "abilities"){
         ButtonMultiInputReference.setVectorComboBox(0, "first", textParser.parse_Abilities());
    }
    
    
    std::vector<MultiInput*> VectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    int numberVector = VectorMultiInput.size() - 1;
    Gtk::ComboBoxText& firstComboBox = VectorMultiInput[numberVector]->returnComboBox("first");
    Gtk::ComboBoxText& secondComboBox = VectorMultiInput[numberVector]->returnComboBox("second");
    firstComboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputFirstComboBoxForGui), 
        numberVector, categorieMultiInput));
    secondComboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, 
        &vampireGameproject::Controllor::testInputSecondComboBoxForGui), 
            numberVector, categorieMultiInput));
    
    //ButtonMultiInputReference.setVectorComboBox(0, "second");
    
    if (categorieMultiInput == "attributes"){
        graphicalUserinterface.setButtonMultiInputAttributes();
    }
    
    if (categorieMultiInput == "abilities"){
        graphicalUserinterface.setButtonMultiInputAbilities();
    }

    graphicalUserinterface.setMultiInputOnGrid(ButtonMultiInputReference, 0);


}



/** Implementation of the initializeButtonMultiInput method.
*
* Implementation of the initializeButtonMultiInput method
* Method setting the first MultiInput in the vector
* And setting the first MultiInput, plus and minus button
* of the ButtonMultiInput 
*/


void vampireGameproject::Controllor::initializeButtonMultiInput(std::string categorieMultiInput){
    if (categorieMultiInput == "attributes"){
        initializeButtonMultiInputReference(graphicalUserinterface.returnAttributesInput(), categorieMultiInput);
    }

     if (categorieMultiInput == "abilities"){
        initializeButtonMultiInputReference(graphicalUserinterface.returnAbilitiesInput(), categorieMultiInput);
    }
}



/** Implementation of the deleteMultiInput method.
*
* Implementation of the deleteMultiInput method
* Method deleting the last MultiInput
* 
*/


void vampireGameproject::Controllor::deleteMultiInput(std::string categorieMultiInput){
    if (categorieMultiInput == "attributes"){
         ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
    
   
        std::vector<MultiInput*> VectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput(); 
    
        if (VectorMultiInput.size() != 1){

            graphicalUserinterface.deleteMultiInputOnGrid(ButtonMultiInputReference, VectorMultiInput.size() - 1);
            ButtonMultiInputReference.deleteMultiInput();
        }
    }

    if (categorieMultiInput == "abilities"){
        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAbilitiesInput();
    
   
        std::vector<MultiInput*> VectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput(); 
    
        if (VectorMultiInput.size() != 1){

            graphicalUserinterface.deleteMultiInputOnGrid(ButtonMultiInputReference, VectorMultiInput.size() - 1);
            ButtonMultiInputReference.deleteMultiInput();
        }
    }
}


/* 
void vampireGameproject::Controllor::setVectorSecondComboBox(std::string ComboBoxFirstValue){
    ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
    std::vector<std::string> vectorSecondBoxElements = textParser.parse_AttributesCategorie(ComboBoxFirstValue);
    std::vector<MultiInput*> VectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    ButtonMultiInputReference.setVectorComboBox(VectorMultiInput.size() - 1, "second", vectorSecondBoxElements);

}

void vampireGameproject::Controllor::setCounter(){
    ButtonmultiInput& ButtonMultiInputReference =  graphicalUserinterface.returnAttributesInput();
    ButtonMultiInputReference.setCounter();
} */