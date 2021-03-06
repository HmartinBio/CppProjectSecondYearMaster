/**
 * @file Controllor.cpp
 *
 * @brief File containing source code of the Controllor class
 *
 *
 * @author Hugo MARTIN
 * Contact: hugo.martin.1@etu.univ-amu.fr
 *
 */



#include "classes.h"


/** Constructor of the class Controllor.
*
* Modification of the constructor of Controllor
* Initialising all the elements to build the 
* Graphical User Interface
*
*/

vampireGameproject::Controllor::Controllor():rulesGame(textParser), CharacterToCreate(textParser),
    createResultsFile(CharacterToCreate){
        

        /*Setting the title of the Window
        Resizing the Window and Initialising labels */


        graphicalUserinterface.set_title("Vampire Game Project");
        graphicalUserinterface.resize(400, 300);
        graphicalUserinterface.set_position(Gtk::WIN_POS_CENTER);
        graphicalUserinterface.initialiseTableLabel();
        graphicalUserinterface.setTableLabelAlign(0, "Name of the Vampire:");
        graphicalUserinterface.setTableLabelAlign(1, "Player name:");
        graphicalUserinterface.setTableLabelAlign(3, "Select a clan:");
        graphicalUserinterface.setTableLabelAlign(4, "Select a Nature:");
        graphicalUserinterface.setTableLabelAlign(5, "Select Attributes:");
        graphicalUserinterface.setTableLabelAlign(6, "Select Abilities:");
        graphicalUserinterface.setTableLabelAlign(7, "Select Disciplines:");
        graphicalUserinterface.setTableLabelAlign(8, "Select Backgrounds:");
        graphicalUserinterface.setTableLabelAlign(9, "Select Virtues:");
        graphicalUserinterface.setTableLabelAlign(10, "Select Merits and Flaws:");
        graphicalUserinterface.setTableLabelAlign(11, "Select Humanity Path:");
        graphicalUserinterface.setTableLabelAlign(12, "Select WillPower:");
        graphicalUserinterface.setTableLabelAlign(13, "Select Blood Pool:");
        graphicalUserinterface.setTableLabelAlign(14, "Select Health:");
        

        /*Placing labels on the Graphical User Interface*/


        graphicalUserinterface.setTableLabelOnGrid(0, 0, 0, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(1, 0, 1, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(3, 0, 2, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(4, 0, 3, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(5, 0, 10, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(6, 0, 16, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(7, 0, 24, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(8, 0, 31, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(9, 0, 40, 1, 1);        
        graphicalUserinterface.setTableLabelOnGrid(10, 0, 49, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(11, 0, 59, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(12, 0, 60, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(13, 0, 61, 1, 1);
        graphicalUserinterface.setTableLabelOnGrid(14, 0, 62, 1, 1);
        

        /*Initialising the Entry Widget
        Initialising ComboBoxText which are not
        a part of MultiInput objects*/


        graphicalUserinterface.initialiseEntryName();
        graphicalUserinterface.initialiseTableComboBox();


        /*Initialising list of clans and list of 
        Nature*/


        rulesGame.setVectorClans();
        rulesGame.setVectorNature();


        /*Initialising ComboBoxText not linked to MultiInput Object
        with vector containing the associated text to display 
        in the ComboBoxText items*/


        graphicalUserinterface.setTableComboBox(0, rulesGame.returnVectorClans());
        graphicalUserinterface.setTableComboBox(1, rulesGame.returnVectorNature());


        /*Placing ComboBoxTexts not linked to MultiInput Object
        on the Graphical User Interface */


        graphicalUserinterface.setTableComboBoxOnGrid(0, 3);
        graphicalUserinterface.setTableComboBoxOnGrid(1, 4);
        graphicalUserinterface.setTableComboBoxOnGrid(2, 14);


        /*Setting the limit points to all the elements
        in all the categories in the game to limit the user 
        to choose items in the game with a some limit points
        for all the elements */


        rulesGame.setLimitPointsAttributes(5, 5, 5, 13, 
            9, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 
                3, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 
                    5, 5, 5, 5, 5, 5, 5, 5, 7, 7, 7, 
                        5, 3, 3, 3, 3, 3, 3);



        /*Initialising the NickNameLabel and all the 
        ButtonMultiInput and ButtonMultiInputOneComboBox
        objects
        Initialising SpinButton, Health ComboBoxText and submit button*/


        initializeNicknameLabel();
        initializeButtonMultiInput("attributes");
        initializeButtonMultiInput("abilities");
        initializeButtonMultiInput("disciplines");
        initializeButtonMultiInputOneComboBox("backgrounds");
        initializeButtonMultiInputOneComboBox("virtues");
        initializeButtonMultiInput("MeritsFlaws");
        initializeSpinButton("humanityPath");
        initializeSpinButton("willPower");
        initializeSpinButton("bloodPool");
        initializeHealthComboBox();
        initializeFinalButton();
        
        /*Displaying all the elements on the interface*/
        
        graphicalUserinterface.showAll();

}



/** Destructor of the class Controllor.
*
* Modification of the destructor of Controllor class*/


vampireGameproject::Controllor::~Controllor(){}






/** Implementation of the testInputsFirstComboBoxChangingItems method.
*
* Implementation of the testInputsFirstComboBoxChangingItems method
* Method unsetting the text of the Second Combo BoxText, if the
* item of the first comboBox is changed. If it's changed, so, 
* the text of the second comboBox is clear and the spin score is clear too 
* This method works with the MultiInputs composed of two comboBoxesText.
*
* @param ButtonMultiInputReference: Reference of the ButtonMultiInput object to retrieve 
    the MultiInput vector and clear the spin Button score and the text of the Second 
    Combo Box of the selected MultiInput present in the MultiInput Vector
* @param number: number of the MultiInput to select in the MultiInput Vector
*/






void vampireGameproject::Controllor::testInputsFirstComboBoxChangingItems(ButtonmultiInput& ButtonMultiInputReference, int number){
    
    std::vector<MultiInput*> vectorMultiInput;
    vectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    
    if (vectorMultiInput[number]->returnTextComboBox("first") != ""){

        /*If the first ComboBoxText is empty, we append an element to avoid 
        conflicts with the use of the gtkmm function when we clean all the 
        elements in the FirstComboBoxText*/

        vectorMultiInput[number]->returnComboBox("second").append("test");
        vectorMultiInput[number]->returnComboBox("second").remove_all();
    }

    vectorMultiInput[number]->unsetActiveText();
    vectorMultiInput[number]->resetSpinScore();

}



/** Implementation of the testInputsFirstComboBoxChangingItemsOneComboBox method.
*
* Implementation of the testInputsFirstComboBoxChangingItemsOneComboBox method
* Method resetting the spin score associated to the selected MultiInputOneComboBox.
* This method works for the MultiInputOneComboBox composed of only one ComboBoxText  
*
* @param ButtonmultiInputOneComboBoxReference: Reference of the ButtonMultiInputOneComboBox object 
    to retrieve the MultiInputOneComboBox vector to clear the spin Button score and the text of the 
    Combo BoxText of the selected MultiInputOneComboBox in the vector
* @param number: number of the MultiInputOneComboBox to select in the MultiInputOneComboBox vector
*/


 void vampireGameproject::Controllor::testInputsFirstComboBoxChangeItemsOneComboBox(ButtonmultiInputOneComboBox& ButtonmultiInputOneComboBoxReference, int number){
    std::vector<MultiInputOneComboBox*> vectorMultiInputOneComboBox;
    
    vectorMultiInputOneComboBox = ButtonmultiInputOneComboBoxReference.returnVectorMultiInput();
    vectorMultiInputOneComboBox[number]->resetSpinScore();
 } 





/** Implementation of the testInputsSecondComboBox method.
*
* Implementation of the testInputsSecondComboBox method
* Method setting the text in the secondComboBoxText, if the 
* user already chose an item in the FirstComboBoxText, 
* When the user chose an item in the secondcomboBox, 
* this item can't be used by the others secondComboBox
*
* @param ButtonMultiInputReference: Reference of the ButtonMultiInput object
* @param number: number of the MultiInput to select in the vector
* @param categorieMultiInput: type of ButtonMultiInput alllowing to select the ButtonMutiInputobject to test SecondComboBoxText*/





void vampireGameproject::Controllor::testInputsSecondComboBox(ButtonmultiInput& ButtonMultiInputReference, int number, std::string categorieMultiInput){
       
    /*Initialising vectors of selected inputs*/

    ButtonMultiInputReference.setVectorSelectedInput();

    std::vector<std::string> vectorFirstComboBox = ButtonMultiInputReference.returnVectorSelectedInput("first");
    std::vector<std::string> vectorSecondComboBox = ButtonMultiInputReference.returnVectorSelectedInput("second");


    /*Initialising a vector where are saved the parsed text corresponding to 
    the items of the second combotext for the text entered in the first comboBox*/ 

    if (categorieMultiInput == "attributes"){

        std::vector<std::string> vectorAttributesCategorie = textParser.parseAttributesCategorie(ButtonMultiInputReference.returnTextComboBox(number, "first"));
    
        /*Initialising a vector to save all the MultiInputs objects*/

        std::vector<MultiInput*> vectorMultiInputs = ButtonMultiInputReference.returnVectorMultiInput();

        /*Iteration of elements already entered by the user
        If a first ComboBoxText iterated element entered 
        by the user for a MultiInput object is detected somewhere else,  
        we look the iterated second item, if the iterated second item
        corresponds with a second term present in the vector of selected 
        second items, then, it means it's the same MultiInput object
        If it's not the case, the second term present in the vector 
        selected second item is deleted for this MultiInput object whose the choice
        doesn't correspond to this second term*/


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

        std::vector<std::string> vectorAbilitiesCategorie = textParser.parseAbilitiesCategorie(ButtonMultiInputReference.returnTextComboBox(number, "first"));
    
        /*Initialising a vector to store all the MultiInputs*/

        std::vector<MultiInput*> vectorMultiInputs = ButtonMultiInputReference.returnVectorMultiInput();

        /*Iteration of elements already entered by the user
        If a first ComboBoxText iterated element entered 
        by the user for a MultiInput is detected somewhere else,  
        we look the iterated second item, if the iterated second item
        corresponds with a second term present in the vector of selected 
        second items, then, it means it's the same MultiInput 
        If it's not the case, the second term present in the vector 
        selected second item is deleted for this MultiInput whose the choice
        doesn't correspond to this second term*/


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


    if (categorieMultiInput == "disciplines"){

        std::vector<std::string> vectorAttributesCategorie = textParser.parseClanDisciplinesCategorie(ButtonMultiInputReference.returnTextComboBox(number, "first"));
    
        /*Initialising a vector to store all the MultiInputs*/

        std::vector<MultiInput*> vectorMultiInputs = ButtonMultiInputReference.returnVectorMultiInput();

        /*Iteration of elements already entered by the user
        If a first ComboBoxText iterated element entered 
        by the user for a MultiInput is detected somewhere else,  
        we look the iterated second item, if the iterated second item
        corresponds with a second term present in the vector of selected 
        second items, then, it means it's the same MultiInput 
        If it's not the case, the second term present in the vector 
        selected second item is deleted for this MultiInput whose the choice
        doesn't correspond to this second term*/


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


    if (categorieMultiInput == "MeritsFlaws"){

        std::vector<std::string> vectorAttributesCategorie = textParser.parseMeritsFlawsCategorie(ButtonMultiInputReference.returnTextComboBox(number, "first"));
    
        /*Initialising a vector to store all the MultiInputs*/

        std::vector<MultiInput*> vectorMultiInputs = ButtonMultiInputReference.returnVectorMultiInput();

        /*Iteration of elements already entered by the user
        If a first ComboBoxText iterated element entered 
        by the user for a MultiInput is detected somewhere else,  
        we look the iterated second item, if the iterated second item
        corresponds with a second term present in the vector of selected 
        second items, then, it means it's the same MultiInput 
        If it's not the case, the second term present in the vector 
        selected second item is deleted for this MultiInput whose the choice
        doesn't correspond to this second term*/


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

}






/** Implementation of the testClanButton method.
*
* Implementation of the testClanButton method
* Method updating the text in the First ComboBoxText associated 
* to the ButtonMultiInput object linked to disciplines when the user
* chooses a clan. If the user chooses another clan and fields exist 
* in MultiInput ComboBoxes associated to disciplines of the old clan, 
* then, these one are destroyed*/





void vampireGameproject::Controllor::testClanButton(){

    /*Initialising ButtonMultiInput reference and vectorMultiInput*/

    ButtonmultiInput& ButtonmultiInputReferenceDisciplines = graphicalUserinterface.returnDisciplinesInput();
    std::vector<MultiInput*> vectorMultiInputDisciplines = ButtonmultiInputReferenceDisciplines.returnVectorMultiInput();

    /*if the number of MultiInput in the vector is superior to one*/

    if ((int)vectorMultiInputDisciplines.size() > 1){

        /*Creation of a counter indicating the number of MultiInput present in the vector*/

        int sizeOfTheVectorMultiInputs = (int)vectorMultiInputDisciplines.size();

        /*while this numer is superior to 0, the last MultiInput
        of the vector is destroyed*/

        while(sizeOfTheVectorMultiInputs > 1){
            deleteMultiInput("disciplines");
            sizeOfTheVectorMultiInputs -= 1;
        }
    }

    /*When only one MultiInput is present, we reset the spin score and the
    First ComboBox and the Second ComboBox, then we update the FirstComboBox
    with the new name of chosen clan. Then, the nickname of the Clan is updated. */

    vectorMultiInputDisciplines[0]->resetSpinScore();
    vectorMultiInputDisciplines[0]->unsetActiveText();
    
    vectorMultiInputDisciplines[0]->returnComboBox("first").remove_all();

    vectorMultiInputDisciplines[0]->returnComboBox("second").append("test");

    vectorMultiInputDisciplines[0]->returnComboBox("second").remove_all();

    testFirstComboBoxDisponibility("disciplines");

    updateNicknameLabel();  
}





/** Implementation of the testInputsFirstComboBoxForGui method.
*
* Implementation of the testInputsFirstComboBoxForGui method
* Method reseting the second ComboBoxText and the spin score
* and the Spin Button is tested such as we select a score available
* for the First ComboBoxText item. Then, the SecondComboBoxText is updated
* to make appear Second ComboBoxText items corresponding to the selected First 
* ComboBoxText item
* 
* @param number: number of the MultiInput to select in the MultiInput Vector
* @param categorieMultiInput: type of ButtonMultiInput alllowing to select the ButtonMutiInputobject 
* to test SpinScore and Second ComboBoxText when it's available
*/





void vampireGameproject::Controllor::testInputFirstComboBoxForGui(int number, std::string categorieMultiInput){
    if (categorieMultiInput == "attributes"){
        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
        testInputsFirstComboBoxChangingItems(ButtonMultiInputReference, number);
        testInputSpinButton(ButtonMultiInputReference, number);
        testInputsSecondComboBox(ButtonMultiInputReference, number, categorieMultiInput);
    
    }

    if (categorieMultiInput == "abilities"){
        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAbilitiesInput();
        testInputsFirstComboBoxChangingItems(ButtonMultiInputReference, number);
        testInputSpinButton(ButtonMultiInputReference, number);
        testInputsSecondComboBox(ButtonMultiInputReference, number, categorieMultiInput);
    }

    if (categorieMultiInput == "disciplines"){
        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnDisciplinesInput();
        testInputsFirstComboBoxChangingItems(ButtonMultiInputReference, number);
        testInputSpinButton(ButtonMultiInputReference, number);
        testInputsSecondComboBox(ButtonMultiInputReference, number, categorieMultiInput);

    }
    
    if (categorieMultiInput == "backgrounds"){
        ButtonmultiInputOneComboBox& ButtonmultiInputOneComboBoxReference = graphicalUserinterface.returnBackgroundsInput();
        testInputsFirstComboBoxChangeItemsOneComboBox(ButtonmultiInputOneComboBoxReference, number);
        testInputSpinButtonOneComboBox(ButtonmultiInputOneComboBoxReference, number);
    }

    if (categorieMultiInput == "virtues"){
        ButtonmultiInputOneComboBox& ButtonmultiInputOneComboBoxReference = graphicalUserinterface.returnVirtuesInput();
        testInputsFirstComboBoxChangeItemsOneComboBox(ButtonmultiInputOneComboBoxReference, number);
        testInputSpinButtonOneComboBox(ButtonmultiInputOneComboBoxReference, number);
    }

    if (categorieMultiInput == "MeritsFlaws"){
        ButtonmultiInput& ButtonmultiInputReference = graphicalUserinterface.returnMeritsFlawsInput();
        testInputsFirstComboBoxChangingItems(ButtonmultiInputReference, number);
        testInputSpinButton(ButtonmultiInputReference, number);
        testInputsSecondComboBox(ButtonmultiInputReference, number, categorieMultiInput);
    }
    
}





/** Implementation of the testInputSecondComboBoxForGui method.
*
* Implementation of the testInputSecondComboBoxForGui method
* Method updating the vectors of selected inputs
* And from that, updating the items of the Second ComboBoxes
* for all the Concerned MultiInputs. This methods works for   
* MultiInputs composed of two ComboBoxesText
*
* @param number: number of the MultiInput to select in the MultiInput Vector
* @param categorieMultiInput: type of ButtonMultiInput alllowing to select the ButtonMutiInputobject to test Second ComboBox
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

    if (categorieMultiInput == "disciplines"){
        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnDisciplinesInput();
        testInputSecondComboBoxChosenItems(ButtonMultiInputReference, number, categorieMultiInput);
    }

    if (categorieMultiInput == "MeritsFlaws"){
        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnMeritsFlawsInput();
        testInputSecondComboBoxChosenItems(ButtonMultiInputReference, number, categorieMultiInput);
    }
    
}





/** Implementation of the testInputSpinButtonForGui method.
*
* Implementation of the testInputSpinButtonForGui method
* Method updating the spinScore and verifying the disponibility
* of the First ComboBox Item 
*
* @param number: number of the MultiInput to select in the MultiInput Vector
* @param categorieMultiInput: MultiInput categorie to select
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
* @param categorieMultiInput: type of ButtonMultiInput alllowing to select the ButtonMutiInputobject to test First ComboBoxText
*/





void vampireGameproject::Controllor::testInputPlusButtonForGui(std::string categorieMultiInput){
    setMultiInput(categorieMultiInput);
    testFirstComboBoxDisponibility(categorieMultiInput);
}



/** Implementation of the testInputMinusButtonForGui method.
*
* Implementation of the testInputMinusButtonForGui method
* Method deleting the last MultiInput and testing 
* the Spin Score avaibility items disponibility and the  
* First ComboBox items disponibility
* 
* @param categorieMultiInput: type of ButtonMultiInput alllowing to select the ButtonMutiInputobject to test First ComboBoxText and Spin Button
*/





void vampireGameproject::Controllor::testInputMinusButtonForGui(std::string categorieMultiInput){
    deleteMultiInput(categorieMultiInput);
    
    if (categorieMultiInput != "backgrounds" && categorieMultiInput != "virtues"){
        testInputSpinButtonWhenRemoved(categorieMultiInput);
    }

    testFirstComboBoxDisponibility(categorieMultiInput);
}





/** Implementation of the testInputSpinButtonWhenRemoved method.
*
* Implementation of the testInputSpinButtonWhenRemoved method
* Method updating the Spin Score when a MultiInput is deleted
* The Spin Score for all the others MultiInput is actualised 
* in real time when an item is deleted
*
* @param categorieMultiInput: type of ButtonMultiInput alllowing to select the ButtonMutiInputobject to test Spin Button
*/





void vampireGameproject::Controllor::testInputSpinButtonWhenRemoved(std::string categorieMultiInput){
    
    if (categorieMultiInput == "attributes"){

        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
    
        /*Updating the Dictionnary of Spin Score*/

        ButtonMultiInputReference.setDicoScoreFirstComboBox();
    
        /*Setting a variable to use the VectorMultiInput*/
    
        std::vector<MultiInput*> vectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    
        /*For all the MultiInputs, if the MultiInput has the same First ComboBox item
        Than the MultiInput where the spin score has been updated. Then, we update 
        the spin score limit, this one is computed such as : 
        newSpinScore = oldSpinScore + ruledSpinScoreItem - ActualSpinScoreItem*/

    
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
    
        /*Updating the Dictionnary of Spin Score*/

        ButtonMultiInputReference.setDicoScoreFirstComboBox();
    
        /*Setting a variable to use the VectorMultiInput*/
    
        std::vector<MultiInput*> vectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    
        /*For all the MultiInputs, if the MultiInput has the same First ComboBox item
        Than the MultiInput where the spin score has been updated. Then, we update 
        the spin score limit, this one is computed such as : 
        newSpinScore = oldSpinScore + ruledSpinScoreItem - ActualSpinScoreItem*/ 

    
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
* This methods works with MultiInput having two ComboBoxText
*
* @param ButtonMultiInputReference: Reference of the ButtonMultiInput object
* @param number: number of the MultiInput in the MultiInput Vector
* @param categorieMultiInput: type of ButtonMultiInput alllowing to select the ButtonMutiInputobject to test second ComboBox
*/





void vampireGameproject::Controllor::testInputSecondComboBoxChosenItems(ButtonmultiInput& ButtonMultiInputReference, int number, std::string categorieMultiInput){
    
    /*Declaration of the vectorMultinput*/

    std::vector<MultiInput*> vectorMultiInput;

    /*Initialising the vectorMultiInput*/

    vectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();

    /*For all the elements of the vectorMultiInput, if the element 
    is not the chosen MultiInput and if the item of the first 
    Combo Box is the same than the chosen MultiInput
    Then, we update the choices for the second ComboBox*/

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
* from the user proposed list in the others First Combo Box
*
* @param categorieMultiInput: type of ButtonMultiInput alllowing to select the ButtonMutiInputobject to test first ComboBox
*/





void vampireGameproject::Controllor::testFirstComboBoxDisponibility(std::string categorieMultiInput){
    
    if (categorieMultiInput == "attributes"){

        /*Initialising ButtonMultiInput Reference and VectorMultiInput */

        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
    
        std::vector<MultiInput*> vectorMultiInput;
        vectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    
        /*Setting the DicoScore for all the items of the FirstComboBox*/

        ButtonMultiInputReference.setDicoScoreFirstComboBox();
    
        std::map<std::string, int> dicoScoreFirstComboBox = ButtonMultiInputReference.returnDicoScoreFirstComboBox();
    
        std::map<std::string, int> dicoScoreFirstComboBoxRules = rulesGame.returnLimitPointsAttributes();
        std::vector<std::string> vectorFirstComboBoxOutsider;

        std::map<std::string, int>::iterator iterator;

        /*For all the elements in the dico Score, if the Spin Score max 
        was reached, then we register the element in a new vector*/ 


        for (iterator = dicoScoreFirstComboBox.begin(); iterator != dicoScoreFirstComboBox.end(); iterator++){
           
            if (iterator->first != ""){

                if (dicoScoreFirstComboBoxRules.at(iterator->first) == iterator->second){
                    vectorFirstComboBoxOutsider.push_back(iterator->first);
                }
            }


        }   

        /*For all the MultiInputs, we create the vector of First ComboBox Items,
        Then, we iterate all the terms whose the score is equal to the limit 
        If the term is the active term of the First ComboBox of the iterated MultiInput
        We don't delete the value in the list of the items proposed to the user
        If it's not the case, the value is not proposed to the user anymore*/



        std::vector<std::string> vectorFirstComboBoxChoices = textParser.parseAttributes();
        
        for(int i = 0; i < (int)vectorFirstComboBoxOutsider.size(); i++){
            std::cout << vectorFirstComboBoxOutsider.at(i) << std::endl;
        }


        for(int newIterator = 0; newIterator < (int)vectorMultiInput.size(); newIterator++){
            
            std::vector<std::string> vectorFirstComboBoxChoicesCopy = vectorFirstComboBoxChoices;
            if (!vectorFirstComboBoxOutsider.empty()){

                for(int iterator2 = 0; iterator2 < (int)vectorFirstComboBoxOutsider.size(); iterator2++){

                    if (vectorMultiInput[newIterator]->returnTextComboBox("first") != vectorFirstComboBoxOutsider.at(iterator2)){
                        vectorFirstComboBoxChoicesCopy.erase(std::remove(vectorFirstComboBoxChoicesCopy.begin(), 
                            vectorFirstComboBoxChoicesCopy.end(), vectorFirstComboBoxOutsider.at(iterator2)), 
                                vectorFirstComboBoxChoicesCopy.end());
                    }
                }
            
                
            }
            
            /*Saving the old value because the ComboBox items vector replacement 
            deletes spinScore and textActive in FirstComboBox and SecondComboBox.
            After the replacement, the old values are set.*/

            int spinScore = vectorMultiInput[newIterator]->returnSpinScore();
            std::string textSetactiveFirstComboBox = vectorMultiInput[newIterator]->returnTextComboBox("first");
            std::string textSetactiveSecondComboBox = vectorMultiInput[newIterator]->returnTextComboBox("second");
            vectorMultiInput[newIterator]->returnComboBox("first").remove_all();
            vectorMultiInput[newIterator]->setVectorComboBox(vectorFirstComboBoxChoicesCopy, "first");
            vectorMultiInput[newIterator]->returnComboBox("first").set_active_text(textSetactiveFirstComboBox);
            vectorMultiInput[newIterator]->returnComboBox("second").set_active_text(textSetactiveSecondComboBox);
            vectorMultiInput[newIterator]->returnSpinButton().set_value(spinScore);
        
        }


    }





    if (categorieMultiInput == "abilities"){
         
        /*Initialising ButtonMultiInput Reference and VectorMultiInput */
         
        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAbilitiesInput();
    
        std::vector<MultiInput*> vectorMultiInput;
        vectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    
        /*Setting the DicoScore for all the items of the FirstComboBox*/

        ButtonMultiInputReference.setDicoScoreFirstComboBox();
    
        std::map<std::string, int> dicoScoreFirstComboBox = ButtonMultiInputReference.returnDicoScoreFirstComboBox();
    
        std::map<std::string, int> dicoScoreFirstComboBoxRules = rulesGame.returnLimitPointsAttributes();
        std::vector<std::string> vectorFirstComboBoxOutsider;

        std::map<std::string, int>::iterator iterator;

        /*For all the elements in the dico Score, if the Spin Score max 
        was reached, then we register the element in a new vector*/ 


        for (iterator = dicoScoreFirstComboBox.begin(); iterator != dicoScoreFirstComboBox.end(); iterator++){
           
            if (iterator->first != ""){

                if (dicoScoreFirstComboBoxRules.at(iterator->first) == iterator->second){
                    vectorFirstComboBoxOutsider.push_back(iterator->first);
                }
            }


        }   

        /*For all the MultiInputs, we create the vector of First ComboBox Items,
        Then, we iterate all the terms whose the score is equal to the limit 
        If the term is the active term of the First ComboBox of the iterated MultiInput
        We don't delete the value in the list of the items proposed to the user
        If it's not the case, the value is not proposed to the user anymore*/


        std::vector<std::string> vectorFirstComboBoxChoices = textParser.parseAbilities();
        

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
            
            /*Saving the old value because the ComboBox items vector replacement 
            deletes spinScore and textActive in FirstComboBox and SecondComboBox.
            After the replacement, the old values are set.*/

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







    if (categorieMultiInput == "disciplines"){

        /*Initialising ButtonMultiInput Reference and VectorMultiInput */

        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnDisciplinesInput();
    
        std::vector<MultiInput*> vectorMultiInput;
        vectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();

        /*Setting the DicoScore for all the items of the FirstComboBox*/

        ButtonMultiInputReference.setDicoScoreFirstComboBox();
    
        std::map<std::string, int> dicoScoreFirstComboBox = ButtonMultiInputReference.returnDicoScoreFirstComboBox();
    
        std::map<std::string, int> dicoScoreFirstComboBoxRules = rulesGame.returnLimitPointsAttributes();
        std::vector<std::string> vectorFirstComboBoxOutsider;

        std::map<std::string, int>::iterator iterator;

        /*For all the elements in the dico Score, if the Spin Score max 
        was reached, then we register the element in a new vector*/ 


        for (iterator = dicoScoreFirstComboBox.begin(); iterator != dicoScoreFirstComboBox.end(); iterator++){
           
            if (iterator->first != ""){

                if (dicoScoreFirstComboBoxRules.at(iterator->first) == iterator->second){
                    vectorFirstComboBoxOutsider.push_back(iterator->first);
                }
            }


        }   

        /*For all the MultiInputs, we create the vector of First ComboBox Items,
        Then, we iterate all the terms whose the score is equal to the limit 
        If the term is the active term of the First ComboBox of the iterated MultiInput
        We don't delete the value in the list of the items proposed to the user
        If it's not the case, the value is not proposed to the user anymore*/


        std::string clanName = graphicalUserinterface.returnClanName();

        std::vector<std::string> vectorFirstComboBoxChoices = textParser.parseClanDisciplines(clanName);
        

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
            

            /*Saving the old value because the ComboBox items vector replacement 
            deletes spinScore and textActive in FirstComboBox and SecondComboBox.
            After the replacement, the old values are set.*/

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






    if (categorieMultiInput == "backgrounds"){

        /*Initialising ButtonMultiInput Reference and VectorMultiInput */

        ButtonmultiInputOneComboBox& ButtonMultiInputReferenceOneComboBox = graphicalUserinterface.returnBackgroundsInput();
    
        std::vector<MultiInputOneComboBox*> vectorMultiInputOneComboBox;
        vectorMultiInputOneComboBox = ButtonMultiInputReferenceOneComboBox.returnVectorMultiInput();
    
        /*Setting the DicoScore for all the items of the FirstComboBox*/

        ButtonMultiInputReferenceOneComboBox.setDicoScoreFirstComboBox();
    
        std::map<std::string, int> dicoScoreFirstComboBox = ButtonMultiInputReferenceOneComboBox.returnDicoScoreComboBox();
    
   
        std::map<std::string, int> dicoScoreFirstComboBoxRules = rulesGame.returnLimitPointsAttributes();
        std::vector<std::string> vectorFirstComboBoxOutsider;

        std::map<std::string, int>::iterator iterator;

        /* For all the elements in the dico Score, if the Spin Score max 
        was reached, then we register the element in a new vector*/ 


        for (iterator = dicoScoreFirstComboBox.begin(); iterator != dicoScoreFirstComboBox.end(); iterator++){
           
            if (iterator->first != ""){

                vectorFirstComboBoxOutsider.push_back(iterator->first);
            }
            


        }   

        /*For all the MultiInputs, we create the vector of First ComboBox Items,
        Then, we iterate all the terms whose the score is equal to the limit 
        If the term is the active term of the First ComboBox of the iterated MultiInput
        We don't delete the value in the list of the items proposed to the user
        If it's not the case, the value is not proposed to the user anymore*/


        

        std::vector<std::string> vectorFirstComboBoxChoices = textParser.parseBackgrounds();
        

        for(int iterator = 0; iterator < (int)vectorMultiInputOneComboBox.size(); iterator++){
            
            std::vector<std::string> vectorFirstComboBoxChoicesCopy = vectorFirstComboBoxChoices;

            if (!vectorFirstComboBoxOutsider.empty()){

                for(int iterator2 = 0; iterator2 < (int)vectorFirstComboBoxOutsider.size(); iterator2++){

                    if (vectorMultiInputOneComboBox[iterator]->returnTextComboBox() != vectorFirstComboBoxOutsider.at(iterator2)){
                        vectorFirstComboBoxChoicesCopy.erase(std::remove(vectorFirstComboBoxChoicesCopy.begin(), 
                            vectorFirstComboBoxChoicesCopy.end(), vectorFirstComboBoxOutsider.at(iterator2)), 
                                vectorFirstComboBoxChoicesCopy.end());
                    }
                }
            
            }
            
            /*Saving the old value because the ComboBox items vector replacement 
            deletes spinScore and textActive in FirstComboBox and SecondComboBox.
            After the replacement, the old values are set.*/

            int spinScore = vectorMultiInputOneComboBox[iterator]->returnSpinScore();
            std::string textSetactiveFirstComboBox = vectorMultiInputOneComboBox[iterator]->returnTextComboBox();
            vectorMultiInputOneComboBox[iterator]->returnComboBox().remove_all();
            vectorMultiInputOneComboBox[iterator]->setVectorComboBox(vectorFirstComboBoxChoicesCopy);
            vectorMultiInputOneComboBox[iterator]->returnComboBox().set_active_text(textSetactiveFirstComboBox);
            vectorMultiInputOneComboBox[iterator]->returnSpinButton().set_value(spinScore);
        }    
    
    }






    if (categorieMultiInput == "virtues"){
        
        /*Initialising ButtonMultiInput Reference and VectorMultiInput */

        ButtonmultiInputOneComboBox& ButtonMultiInputReferenceOneComboBox = graphicalUserinterface.returnVirtuesInput();
    
        std::vector<MultiInputOneComboBox*> vectorMultiInputOneComboBox;
        vectorMultiInputOneComboBox = ButtonMultiInputReferenceOneComboBox.returnVectorMultiInput();
    
        /*Setting the DicoScore for all the items of the FirstComboBox*/

        ButtonMultiInputReferenceOneComboBox.setDicoScoreFirstComboBox();
    
        std::map<std::string, int> dicoScoreFirstComboBox = ButtonMultiInputReferenceOneComboBox.returnDicoScoreComboBox();
    
   
        std::map<std::string, int> dicoScoreFirstComboBoxRules = rulesGame.returnLimitPointsAttributes();
        std::vector<std::string> vectorFirstComboBoxOutsider;

        std::map<std::string, int>::iterator iterator;

        /* For all the elements in the dico Score, if the Spin Score max 
        was reached, then we register the element in a new vector*/ 


        for (iterator = dicoScoreFirstComboBox.begin(); iterator != dicoScoreFirstComboBox.end(); iterator++){
           
            if (iterator->first != ""){

                vectorFirstComboBoxOutsider.push_back(iterator->first);
            }
            


        }   

        /* For all the MultiInputs, we create the vector of First ComboBox Items,
        Then, we iterate all the terms whose the score is equal to the limit 
        If the term is the active term of the First ComboBox of the iterated MultiInput
        We don't delete the value in the list of the items proposed to the user
        If it's not the case, the value is not proposed to the user anymore*/


        std::vector<std::string> vectorFirstComboBoxChoices = textParser.parseViritues();
        

        for(int iterator = 0; iterator < (int)vectorMultiInputOneComboBox.size(); iterator++){
            
            std::vector<std::string> vectorFirstComboBoxChoicesCopy = vectorFirstComboBoxChoices;

            if (!vectorFirstComboBoxOutsider.empty()){

                for(int iterator2 = 0; iterator2 < (int)vectorFirstComboBoxOutsider.size(); iterator2++){

                    if (vectorMultiInputOneComboBox[iterator]->returnTextComboBox() != vectorFirstComboBoxOutsider.at(iterator2)){
                        vectorFirstComboBoxChoicesCopy.erase(std::remove(vectorFirstComboBoxChoicesCopy.begin(), 
                            vectorFirstComboBoxChoicesCopy.end(), vectorFirstComboBoxOutsider.at(iterator2)), 
                                vectorFirstComboBoxChoicesCopy.end());
                    }
                }
            
            }
            
            /*Saving the old value because the ComboBox items vector replacement 
            deletes spinScore and textActive in FirstComboBox and SecondComboBox.
            After the replacement, the old values are set.*/

            int spinScore = vectorMultiInputOneComboBox[iterator]->returnSpinScore();
            std::string textSetactiveFirstComboBox = vectorMultiInputOneComboBox[iterator]->returnTextComboBox();
            vectorMultiInputOneComboBox[iterator]->returnComboBox().remove_all();
            vectorMultiInputOneComboBox[iterator]->setVectorComboBox(vectorFirstComboBoxChoicesCopy);
            vectorMultiInputOneComboBox[iterator]->returnComboBox().set_active_text(textSetactiveFirstComboBox);
            vectorMultiInputOneComboBox[iterator]->returnSpinButton().set_value(spinScore);
        }    
    
    }






    if (categorieMultiInput == "MeritsFlaws"){

        /*Initialising ButtonMultiInput Reference and VectorMultiInput */

        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnMeritsFlawsInput();
    
        std::vector<MultiInput*> vectorMultiInput;
        vectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    
        /*Setting the DicoScore for all the items of the FirstComboBox*/

        ButtonMultiInputReference.setDicoScoreFirstComboBox();
    
        std::map<std::string, int> dicoScoreFirstComboBox = ButtonMultiInputReference.returnDicoScoreFirstComboBox();
    

        std::map<std::string, int> dicoScoreFirstComboBoxRules = rulesGame.returnLimitPointsAttributes();
        std::vector<std::string> vectorFirstComboBoxOutsider;

        std::map<std::string, int>::iterator iterator;

        /* For all the elements in the dico Score, if the Spin Score max 
        was reached, then we register the element in a new vector*/ 


        for (iterator = dicoScoreFirstComboBox.begin(); iterator != dicoScoreFirstComboBox.end(); iterator++){
           
            if (iterator->first != ""){

                if (dicoScoreFirstComboBoxRules.at(iterator->first) == iterator->second){
                    vectorFirstComboBoxOutsider.push_back(iterator->first);
                }
            }


        }   

        /* For all the MultiInputs, we create the vector of First ComboBox Items,
        Then, we iterate all the terms whose the score is equal to the limit 
        If the term is the active term of the First ComboBox of the iterated MultiInput
        We don't delete the value in the list of the items proposed to the user
        If it's not the case, the value is not proposed to the user anymore*/



        std::vector<std::string> vectorFirstComboBoxChoices = textParser.parseMeritsFlaws();
        

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
            
             /*Saving the old value because the ComboBox items vector replacement 
            deletes spinScore and textActive in FirstComboBox and SecondComboBox.
            After the replacement, the old values are set.*/

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
* @param ButtonMultiInputReference: Reference of the ButtonMultiInput object
* @param number: number of the MultiInput to select in the MultiInput Vector
*/





void vampireGameproject::Controllor::testInputSpinButton(ButtonmultiInput& ButtonMultiInputReference, int number){
    
    /*Updating the Dictionnary of Spin Score*/

    ButtonMultiInputReference.setDicoScoreFirstComboBox();
    
    /*Setting a variable to use the VectorMultiInput*/
    
    std::vector<MultiInput*> vectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    
    /*For all the MultiInputs, if the MultiInput has the same First ComboBox item
    Than the MultiInput where the spin score has been updated. Then, we update 
    the spin score limit, this one is computed such as : 
    newSpinScore = oldSpinScore + ruledSpinScoreItem - ActualSpinScoreItem*/ 


    for(int iterator = 0; iterator < (int)vectorMultiInput.size(); iterator++){
        if(vectorMultiInput[iterator]->returnTextComboBox("first") == vectorMultiInput[number]->returnTextComboBox("first")){
        
            int newSpinButtonLimit = vectorMultiInput[iterator]->returnSpinScore() + 
                (rulesGame.returnLimitPointsAttributes()[vectorMultiInput[iterator]->returnTextComboBox("first")] - 
                    ButtonMultiInputReference.returnDicoScoreFirstComboBox()[vectorMultiInput[iterator]->returnTextComboBox("first")]); 

            int spinScore = vectorMultiInput[iterator]->returnSpinScore();

            vectorMultiInput[iterator]->setLimitSpinButton(newSpinButtonLimit);
            vectorMultiInput[iterator]->returnSpinButton().set_value(spinScore);
        }
    }
}





/** Implementation of the testInputSpinButtonOneComboBox method.
*
* Implementation of the testInputSpinButtonOneComboBox method
* Method updating the Spin Score Limit for all the MultiInputOneComboBox 
* when a SpinScore for a MultiInputOneComboBox is updated. 
*  
* @param ButtonMultiInputOneComboBoxReference: Reference of the ButtonMultiInputOneComboBox object
* @param number: number of the MultiInput to select in the MultiInput Vector
*/





void vampireGameproject::Controllor::testInputSpinButtonOneComboBox(ButtonmultiInputOneComboBox& ButtonMultiInputOneComboBoxReference, int number){
    
    /*Updating the Dictionnary of Spin Score*/

    ButtonMultiInputOneComboBoxReference.setDicoScoreFirstComboBox();
    
    /*Creating the vectorMultiInputOneComboBox variable*/

    std::vector<MultiInputOneComboBox*> vectorMultiInputOneComboBox = ButtonMultiInputOneComboBoxReference.returnVectorMultiInput();

    /*Updating the spin score limit, this one is computed such as: 
    newSpinScore = oldSpinScore + ruledSpinScoreItem - ActualSpinScoreItem*/ 

    int newSpinButtonLimit = vectorMultiInputOneComboBox[number]->returnSpinScore() +
        (rulesGame.returnLimitPointsAttributes()[vectorMultiInputOneComboBox[number]->returnTextComboBox()] - 
            ButtonMultiInputOneComboBoxReference.returnDicoScoreComboBox()[vectorMultiInputOneComboBox[number]->returnTextComboBox()]);

    int spinScore = vectorMultiInputOneComboBox[number]->returnSpinScore();

    vectorMultiInputOneComboBox[number]->setLimitSpinButton(newSpinButtonLimit);
    vectorMultiInputOneComboBox[number]->returnSpinButton().set_value(spinScore); 
}





/** Implementation of the setMultiInput method.
*
* Implementation of the setMultiInput method
* Method creating a new MultiInput and linking 
* the different buttons with Controllor class methods
*
* @param categorieMultiInput: type of ButtonMultiInput alllowing to select the ButtonMutiInputobject
*/





void vampireGameproject::Controllor::setMultiInput(std::string categorieMultiInput){
    
    if (categorieMultiInput == "attributes"){

        /*Initialising ButtonMultiInputReference and VectorMultiInput */

        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAttributesInput();
    
        /*Setting a new MultiInput*/

        ButtonMultiInputReference.setMultiInput();
        std::vector<MultiInput*> VectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
     
        /*Creating numberVector to count the number of MultiInput in the
        Vector*/

        int numberVector = VectorMultiInput.size() - 1;

        /*Returning the ComboBoxes of the last MultiInput in the vector*/

        Gtk::ComboBoxText& firstComboBox = VectorMultiInput[numberVector]->returnComboBox("first");
        Gtk::ComboBoxText& secondComboBox = VectorMultiInput[numberVector]->returnComboBox("second");
   
        /*Linking functions to ComboBoxes of the last MultiInput*/

        firstComboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputFirstComboBoxForGui), 
            numberVector, categorieMultiInput));

        secondComboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, 
            &vampireGameproject::Controllor::testInputSecondComboBoxForGui), 
                numberVector, categorieMultiInput));


        /*Displaying the last MultiInput on the interface*/

        graphicalUserinterface.setMultiInputOnGrid(ButtonMultiInputReference, numberVector);
    }





    if (categorieMultiInput == "abilities"){

        /*Initialising ButtonMultiInputReference and VectorMultiInput */

        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnAbilitiesInput();

        /*Setting a new MultiInput*/    

        ButtonMultiInputReference.setMultiInput();
        std::vector<MultiInput*> VectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    
        /*Creating numberVector to count the number of MultiInput in the
        Vector*/
    
        int numberVector = VectorMultiInput.size() - 1;

        /*Returning the ComboBoxes of the last MultiInput in the vector*/

        Gtk::ComboBoxText& firstComboBox = VectorMultiInput[numberVector]->returnComboBox("first");
        Gtk::ComboBoxText& secondComboBox = VectorMultiInput[numberVector]->returnComboBox("second");
   
        /*Linking functions to ComboBoxes of the last MultiInput*/

        firstComboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputFirstComboBoxForGui), 
            numberVector, categorieMultiInput));

        secondComboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, 
            &vampireGameproject::Controllor::testInputSecondComboBoxForGui), 
                numberVector, categorieMultiInput));

        /*Displaying the last MultiInput on the interface*/

        graphicalUserinterface.setMultiInputOnGrid(ButtonMultiInputReference, numberVector);
    }




    if (categorieMultiInput == "disciplines"){

        /*Initialising ButtonMultiInputReference and VectorMultiInput */

        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnDisciplinesInput();
    
        /*Setting a new MultiInput*/    

        ButtonMultiInputReference.setMultiInput();
        std::vector<MultiInput*> VectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    
        /*Creating numberVector to count the number of MultiInput in the
        Vector*/
    
        int numberVector = VectorMultiInput.size() - 1;

        /*Returning the ComboBoxes of the last MultiInput in the vector*/

        Gtk::ComboBoxText& firstComboBox = VectorMultiInput[numberVector]->returnComboBox("first");
        Gtk::ComboBoxText& secondComboBox = VectorMultiInput[numberVector]->returnComboBox("second");
   
        /*Linking functions to ComboBoxes of the last MultiInput*/

        firstComboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputFirstComboBoxForGui), 
            numberVector, categorieMultiInput));

        secondComboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, 
            &vampireGameproject::Controllor::testInputSecondComboBoxForGui), 
                numberVector, categorieMultiInput));

        /*Displaying the last MultiInput on the interface*/

        graphicalUserinterface.setMultiInputOnGrid(ButtonMultiInputReference, numberVector);
    }
    




    if (categorieMultiInput == "backgrounds"){

        /*Initialising ButtonMultiInputReference and VectorMultiInput */

        ButtonmultiInputOneComboBox& ButtonmultiInputReferenceOneComboBox = graphicalUserinterface.returnBackgroundsInput();
        
        /*Setting a new MultiInput*/ 
        
        ButtonmultiInputReferenceOneComboBox.setMultiInput();
        std::vector<MultiInputOneComboBox*> VectorMultiInputOneComboBox = ButtonmultiInputReferenceOneComboBox.returnVectorMultiInput();

        /*Creating numberVector to count the number of MultiInput in the
        Vector*/

        int numberVector = VectorMultiInputOneComboBox.size() - 1;

        /*Returning the ComboBox of the last MultiInput in the vector*/

        Gtk::ComboBoxText& comboBox = VectorMultiInputOneComboBox[numberVector]->returnComboBox();
        
        /*Linking function to ComboBox of the last MultiInput*/

        comboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputFirstComboBoxForGui), 
            numberVector, categorieMultiInput));
        
        /*Displaying the last MultiInput on the interface*/

        graphicalUserinterface.setMultiInputOneComboBoxOnGrid(ButtonmultiInputReferenceOneComboBox, numberVector);
    }


    if (categorieMultiInput == "virtues"){

        /*Initialising ButtonMultiInputReference and VectorMultiInput */

        ButtonmultiInputOneComboBox& ButtonmultiInputReferenceOneComboBox = graphicalUserinterface.returnVirtuesInput();
        
        /*Setting a new MultiInput*/ 
        
        ButtonmultiInputReferenceOneComboBox.setMultiInput();
        std::vector<MultiInputOneComboBox*> VectorMultiInputOneComboBox = ButtonmultiInputReferenceOneComboBox.returnVectorMultiInput();

        /*Creating numberVector to count the number of MultiInput in the
        Vector*/

        int numberVector = VectorMultiInputOneComboBox.size() - 1;

        /*Returning the ComboBox of the last MultiInput in the vector*/

        Gtk::ComboBoxText& comboBox = VectorMultiInputOneComboBox[numberVector]->returnComboBox();

        /*Linking function to ComboBox of the last MultiInput*/

        comboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputFirstComboBoxForGui), 
            numberVector, categorieMultiInput));
        
        /*Displaying the last MultiInput on the interface*/

        graphicalUserinterface.setMultiInputOneComboBoxOnGrid(ButtonmultiInputReferenceOneComboBox, numberVector);
    }


    if (categorieMultiInput == "MeritsFlaws"){

        /*Initialising ButtonMultiInputReference and VectorMultiInput */

        ButtonmultiInput& ButtonMultiInputReference = graphicalUserinterface.returnMeritsFlawsInput();
    
        /*Setting a new MultiInput*/ 

        ButtonMultiInputReference.setMultiInput();
        std::vector<MultiInput*> VectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    
        /*Creating numberVector to count the number of MultiInput in the
        Vector*/
    
        int numberVector = VectorMultiInput.size() - 1;

        /*Returning the ComboBoxes of the last MultiInput in the vector*/

        Gtk::ComboBoxText& firstComboBox = VectorMultiInput[numberVector]->returnComboBox("first");
        Gtk::ComboBoxText& secondComboBox = VectorMultiInput[numberVector]->returnComboBox("second");
   
        /*Linking functions to ComboBoxes of the last MultiInput*/

        firstComboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputFirstComboBoxForGui), 
            numberVector, categorieMultiInput));

        secondComboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, 
            &vampireGameproject::Controllor::testInputSecondComboBoxForGui), 
                numberVector, categorieMultiInput));


        /*Displaying the last MultiInput on the interface*/

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
* @param ButtonMultiInputReference: Reference of the ButtonMultiInput object
* @param categorieMultiInput: type of ButtonMultiInput alllowing to select the ButtonMutiInputobject
*/





void vampireGameproject::Controllor::initializeButtonMultiInputReference(ButtonmultiInput& ButtonMultiInputReference, std::string categorieMultiInput){
    
    /*Setting coordinates of the ButtonMultiInput object*/
    
    if (categorieMultiInput == "attributes"){
        ButtonMultiInputReference.setCoordinates(4, 10);
    }

    if (categorieMultiInput == "abilities"){
        ButtonMultiInputReference.setCoordinates(4, 16);
    }

    if (categorieMultiInput == "disciplines"){
        ButtonMultiInputReference.setCoordinates(4, 24);
    }

    if (categorieMultiInput == "MeritsFlaws"){
        ButtonMultiInputReference.setCoordinates(4, 49);
    }

    /*Initialising the ButtonMultiInput*/

    ButtonMultiInputReference.initialize();

    /*Returning the reference of the plus and minus buttons from
    the ButtonmultiInput object*/

    Gtk::Button& buttonPlus = ButtonMultiInputReference.returnButton("plus");
    Gtk::Button& buttonMinus = ButtonMultiInputReference.returnButton("minus");
    
    /*Linking buttons to functions*/

    buttonPlus.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputPlusButtonForGui), 
        categorieMultiInput));
    
    buttonMinus.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputMinusButtonForGui), 
        categorieMultiInput));
    
    /*Filling the vector of the first ComboBox from the first MultiInput*/

    if (categorieMultiInput == "attributes"){
        ButtonMultiInputReference.setVectorComboBox(0, "first", textParser.parseAttributes());
    }

    if (categorieMultiInput == "abilities"){
         ButtonMultiInputReference.setVectorComboBox(0, "first", textParser.parseAbilities());
    }
    if (categorieMultiInput == "MeritsFlaws"){
        ButtonMultiInputReference.setVectorComboBox(0, "first", textParser.parseMeritsFlaws());
    }
    
    /*Returning the VectorMultiInput from the ButtonMultiInput object*/

    std::vector<MultiInput*> VectorMultiInput = ButtonMultiInputReference.returnVectorMultiInput();
    
    /*Creating number vector counting the number of MultiInput in the
    MultiInput vector*/

    int numberVector = VectorMultiInput.size() - 1;
    
    /*Returning references of ComboBoxes of the first MultiInput*/

    Gtk::ComboBoxText& firstComboBox = VectorMultiInput[numberVector]->returnComboBox("first");
    Gtk::ComboBoxText& secondComboBox = VectorMultiInput[numberVector]->returnComboBox("second");
    
    /*Linking ComboBoxes to functions*/
    
    firstComboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputFirstComboBoxForGui), 
        numberVector, categorieMultiInput));
    secondComboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, 
        &vampireGameproject::Controllor::testInputSecondComboBoxForGui), 
            numberVector, categorieMultiInput));
    
    /*Displaying the buttons on the interface*/
    
    if (categorieMultiInput == "attributes"){
        graphicalUserinterface.setButtonMultiInputAttributes();
    }
    
    if (categorieMultiInput == "abilities"){
        graphicalUserinterface.setButtonMultiInputAbilities();
    }

    if (categorieMultiInput == "disciplines"){
        graphicalUserinterface.setButtonMultiInputDisciplines();
    }

    if (categorieMultiInput == "MeritsFlaws"){
        graphicalUserinterface.setButtonMultiInputMeritsFlaws();
    }

    /*Displaying the MultiInput on the interface*/

    graphicalUserinterface.setMultiInputOnGrid(ButtonMultiInputReference, 0);


}



/** Implementation of the initializeButtonMultiInputReferenceOneComboBox method.
*
* Implementation of the initializeButtonMultiInputReferenceOneComboBox method
* Method setting the plus and minus button of the ButtonMultiInputOneComboBox 
* Implementing the first MultiInputOneComboBox in the vector
* Linking button of the First MultiInputOneComboBox to Controllor class methods
*
* @param ButtonMultiInputOneComboBoxReference: Reference of the ButtonMultiInputOneComboBox object
* @param categorieMultiInput: type of ButtonMultiInputOneComboBox alllowing to select the ButtonMutiInputOneComboBox object
*/




void vampireGameproject::Controllor::initializeButtonMultiInputReferenceOneComboBox(ButtonmultiInputOneComboBox& ButtonMultiInputOneComboBoxReference, 
                std::string categorieMultiInputOneComboBox){

                    /*Setting coordinates of the ButtonMultiInput object*/

                    if (categorieMultiInputOneComboBox == "backgrounds"){
                        ButtonMultiInputOneComboBoxReference.setCoordinates(4,31);
                    }

                    if (categorieMultiInputOneComboBox == "virtues"){
                        ButtonMultiInputOneComboBoxReference.setCoordinates(4, 40);
                    }

                    /*Initialising the ButtonMultiInputOneComboBox*/

                    ButtonMultiInputOneComboBoxReference.initialize();


                    /*Returning the reference of the plus and minus buttons from
                    the ButtonmultiInput object*/


                    Gtk::Button& buttonPlus = ButtonMultiInputOneComboBoxReference.returnButton("plus");
                    Gtk::Button& buttonMinus = ButtonMultiInputOneComboBoxReference.returnButton("minus");                    

                    /*Linking buttons to functions*/

                    buttonPlus.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputPlusButtonForGui), 
                        categorieMultiInputOneComboBox));
    
                    buttonMinus.signal_clicked().connect(sigc::bind<std::string>(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputMinusButtonForGui), 
                        categorieMultiInputOneComboBox));

                    /*Filling the vector of the first ComboBox from the first MultiInputOneComboBox*/

                    if (categorieMultiInputOneComboBox == "backgrounds"){
                        ButtonMultiInputOneComboBoxReference.setVectorComboBox(0, textParser.parseBackgrounds());
                    }

                    if (categorieMultiInputOneComboBox == "virtues"){
                        ButtonMultiInputOneComboBoxReference.setVectorComboBox(0, textParser.parseViritues());
                    }

                    /*Returning the VectorMultiInput from the ButtonMultiInput object*/

                    std::vector<MultiInputOneComboBox*> VectorMultiInputOneComboBox = ButtonMultiInputOneComboBoxReference.returnVectorMultiInput();
                    
                    /*Creating number vector counting the number of MultiInput in the
                    MultiInput vector*/
                    
                    int numberVector = VectorMultiInputOneComboBox.size() - 1;
                    
                    /*Returning reference of ComboBoxe of the first MultiInput*/
                    
                    Gtk::ComboBoxText& comboBox = VectorMultiInputOneComboBox[numberVector]->returnComboBox();

                    /*Linking ComboBox to function*/

                    comboBox.signal_changed().connect(sigc::bind<int, std::string>(sigc::mem_fun(*this, &vampireGameproject::Controllor::testInputFirstComboBoxForGui), 
                    numberVector, categorieMultiInputOneComboBox));

                    /*Displaying the buttons on the interface*/

                    if (categorieMultiInputOneComboBox == "backgrounds"){
                        graphicalUserinterface.setButtonMultiInputBackgrounds();
                    }

                    if (categorieMultiInputOneComboBox == "virtues"){
                        graphicalUserinterface.setButtonMultiInputVirtues();
                    }

                    /*Displaying the MultiInputOneComboBox on the interface*/

                    graphicalUserinterface.setMultiInputOneComboBoxOnGrid(ButtonMultiInputOneComboBoxReference, 0);

                }





/** Implementation of the initializeButtonMultiInput method.
*
* Implementation of the initializeButtonMultiInput method
* Method setting the first MultiInput in the vector
* And setting the first MultiInput, plus and minus button
* of the ButtonMultiInput 
*
* @param categorieMultiInput: type of ButtonMultiInputOneComboBox alllowing to select the ButtonMutiInputOneComboBox object
*/


void vampireGameproject::Controllor::initializeButtonMultiInput(std::string categorieMultiInput){
    if (categorieMultiInput == "attributes"){
        initializeButtonMultiInputReference(graphicalUserinterface.returnAttributesInput(), categorieMultiInput);
    }

     if (categorieMultiInput == "abilities"){
        initializeButtonMultiInputReference(graphicalUserinterface.returnAbilitiesInput(), categorieMultiInput);
    }

    if (categorieMultiInput == "disciplines"){
        Gtk::ComboBoxText& comboBoxClan = graphicalUserinterface.returnComboBoxClan();
        comboBoxClan.signal_changed().connect(sigc::mem_fun(*this, &vampireGameproject::Controllor::testClanButton));
        initializeButtonMultiInputReference(graphicalUserinterface.returnDisciplinesInput(), categorieMultiInput);
    }

    if (categorieMultiInput == "MeritsFlaws"){
        initializeButtonMultiInputReference(graphicalUserinterface.returnMeritsFlawsInput(), categorieMultiInput);
    }
}




/** Implementation of the initializeButtonMultiInputOneComboBox method.
*
* Implementation of the initializeButtonMultiInputOneComboBox method
* Method setting the first MultiInputOneComboBox in the vector
* And setting the first MultiInputOneComboBox, plus and minus button
* of the ButtonMultiInputOneComboBox 
*
* @param categorieMultiInput: type of ButtonMultiInputOneComboBox alllowing to select the ButtonMutiInputOneComboBox object
*/




void vampireGameproject::Controllor::initializeButtonMultiInputOneComboBox(std::string categorieMultiInput){
    if (categorieMultiInput == "backgrounds"){
        initializeButtonMultiInputReferenceOneComboBox(graphicalUserinterface.returnBackgroundsInput(), 
            categorieMultiInput);
    }

    if (categorieMultiInput == "virtues"){
        initializeButtonMultiInputReferenceOneComboBox(graphicalUserinterface.returnVirtuesInput(),
            categorieMultiInput);
    }
}





/** Implementation of the deleteMultiInput method.
*
* Implementation of the deleteMultiInput method
* Method deleting the last MultiInput
*
* @param categorieMultiInput: type of ButtonMultiInput alllowing to select the ButtonMutiInput object
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

    if (categorieMultiInput == "disciplines"){
        ButtonmultiInput& ButtonmultiInputReference = graphicalUserinterface.returnDisciplinesInput();

        std::vector<MultiInput*> VectorMultiInput = ButtonmultiInputReference.returnVectorMultiInput(); 


        if (VectorMultiInput.size() != 1){

            graphicalUserinterface.deleteMultiInputOnGrid(ButtonmultiInputReference, VectorMultiInput.size() - 1);
            ButtonmultiInputReference.deleteMultiInput();
        }

    }

    if (categorieMultiInput == "backgrounds"){
        ButtonmultiInputOneComboBox& ButtonmultiInputOneComboBoxReference = graphicalUserinterface.returnBackgroundsInput();
        std::vector<MultiInputOneComboBox*> VectorMultiInput = ButtonmultiInputOneComboBoxReference.returnVectorMultiInput();


        if (VectorMultiInput.size() != 1){
            graphicalUserinterface.deleteMultiInputOneComboBoxOnGrid(ButtonmultiInputOneComboBoxReference, VectorMultiInput.size() - 1);
            ButtonmultiInputOneComboBoxReference.deleteMultiInput();
        }
    }

    if (categorieMultiInput == "virtues"){
        ButtonmultiInputOneComboBox& ButtonmultiInputOneComboBoxReference = graphicalUserinterface.returnVirtuesInput();
        std::vector<MultiInputOneComboBox*> VectorMultiInput = ButtonmultiInputOneComboBoxReference.returnVectorMultiInput();


        if (VectorMultiInput.size() != 1){
            graphicalUserinterface.deleteMultiInputOneComboBoxOnGrid(ButtonmultiInputOneComboBoxReference, VectorMultiInput.size() - 1);
            ButtonmultiInputOneComboBoxReference.deleteMultiInput();
        }        
    }

    if (categorieMultiInput == "MeritsFlaws"){
        ButtonmultiInput& ButtonmultiInputReference = graphicalUserinterface.returnMeritsFlawsInput();

        std::vector<MultiInput*> VectorMultiInput = ButtonmultiInputReference.returnVectorMultiInput();


        if (VectorMultiInput.size() != 1){
            graphicalUserinterface.deleteMultiInputOnGrid(ButtonmultiInputReference, VectorMultiInput.size() - 1);
            ButtonmultiInputReference.deleteMultiInput();
        }
    }
}





/** Implementation of the initializeSpinButton method.
*
* Implementation of the initializeSpinButton method
* Method setting the limit for fields composed only of SpinButtons 
*
* @param categorieSpinButton: type of SpinButton alllowing to select the SpinButton object
*/





void vampireGameproject::Controllor::initializeSpinButton(std::string categorieSpinButton){
    if (categorieSpinButton == "humanityPath"){
        graphicalUserinterface.setSpinButtonHumanityPath();
        Gtk::SpinButton& spinScoreHumanity = graphicalUserinterface.returnHumanityPathSpinButton();
        spinScoreHumanity.set_range(0, 10);
        spinScoreHumanity.set_increments(1, 1);
    }

    if (categorieSpinButton == "willPower"){
        graphicalUserinterface.setSpinButtonWillPower();
        Gtk::SpinButton& spinScoreWillPower = graphicalUserinterface.returnWillPowerSpinButton();
        spinScoreWillPower.set_range(1, 10);
        spinScoreWillPower.set_increments(1, 1);
    }

    if (categorieSpinButton == "bloodPool"){
        graphicalUserinterface.setSpinButtonBloodPool();
        Gtk::SpinButton& spinScoreBloodPool = graphicalUserinterface.returnBloodPoolSpinButton();
        spinScoreBloodPool.set_range(0, 20);
        spinScoreBloodPool.set_digits(2);
        spinScoreBloodPool.set_increments(0.25, 0.25);
    }
}





/** Implementation of the initializeFinalButton method.
*
* Implementation of the initializeFinalButton method
* Method setting the button to submit user choices*/




void vampireGameproject::Controllor::initializeFinalButton(){
    graphicalUserinterface.setValidationButton();
    Gtk::Button& submitButton = graphicalUserinterface.returnValidationButton();
    submitButton.signal_clicked().connect(sigc::mem_fun(*this, &vampireGameproject::Controllor::submitUserChoices));

}





/** Implementation of the updateNicknameLabel method.
*
* Implementation of the updateNicknameLabel method
* Method updating the label of Vampire Nickname*/





void vampireGameproject::Controllor::updateNicknameLabel(){
    std::string actualClanName = graphicalUserinterface.returnClanName();
    std::string nicknameClan = textParser.parseNicknameClan(actualClanName);
    graphicalUserinterface.setTextNicknameLabel(nicknameClan);
}





/** Implementation of the initializeNicknameLabel method.
*
* Implementation of the initializeNicknameLabel method
* Method initialising the Nickname Label in the interface*/





void vampireGameproject::Controllor::initializeNicknameLabel(){
    graphicalUserinterface.setNicknameLabel();
}





/** Implementation of the initializeHealthComboBox method.
*
* Implementation of the initializeHealthComboBox method
* Method initialising the Health ComboBox*/





void vampireGameproject::Controllor::initializeHealthComboBox(){
    std::vector<std::string> vectorHealth = textParser.parseHealth();
    graphicalUserinterface.setTableComboBox(2, vectorHealth);
}



/** Implementation of the saveAttributesInCharacter method.
*
* Implementation of the saveAttributesInCharacter method
* Method allowing to retrieve the Attributes choices of 
* the user on the interface and to save it in CharacterToCreate*/



void vampireGameproject::Controllor::saveAttributesInCharacter(){
    ButtonmultiInput& ButtonmultiInputreference = graphicalUserinterface.returnAttributesInput();
    std::vector<MultiInput*> vectorMultiInputReference = ButtonmultiInputreference.returnVectorMultiInput();

    for(int iterator = 0; iterator < (int)vectorMultiInputReference.size(); iterator++){
       
       if (vectorMultiInputReference[iterator]->returnTextComboBox("first") != "" && 
            vectorMultiInputReference[iterator]->returnTextComboBox("second") != ""){

                CharacterToCreate.setAttributes(vectorMultiInputReference[iterator]->returnTextComboBox("first"), 
                    vectorMultiInputReference[iterator]->returnTextComboBox("second"), 
                        vectorMultiInputReference[iterator]->returnSpinScore());  
        }
    }
}




/** Implementation of the saveAttributesInCharacter method.
*
* Implementation of the saveAttributesInCharacter method
* Method allowing to retrieve the Attributes choices of 
* the user on the interface and to save it in CharacterToCreate*/



void vampireGameproject::Controllor::saveAbilitiesInCharacter(){
    ButtonmultiInput& ButtonmultiInputreference = graphicalUserinterface.returnAbilitiesInput();
    std::vector<MultiInput*> vectorMultiInputReference = ButtonmultiInputreference.returnVectorMultiInput();

    for(int iterator = 0; iterator < (int)vectorMultiInputReference.size(); iterator++){
        
        if (vectorMultiInputReference[iterator]->returnTextComboBox("first") != "" && 
            vectorMultiInputReference[iterator]->returnTextComboBox("second") != ""){
        
                CharacterToCreate.setAbilities(vectorMultiInputReference[iterator]->returnTextComboBox("first"), 
                    vectorMultiInputReference[iterator]->returnTextComboBox("second"), 
                        vectorMultiInputReference[iterator]->returnSpinScore());    
        }
    }
}




/** Implementation of the saveDisciplinesInCharacter method.
*
* Implementation of the saveDisciplinesInCharacter method
* Method allowing to retrieve the Disciplines choices of 
* the user on the interface and to save it in CharacterToCreate*/




void vampireGameproject::Controllor::saveDisciplinesInCharacter(){
    ButtonmultiInput& ButtonmultiInputreference = graphicalUserinterface.returnDisciplinesInput();
    std::vector<MultiInput*> vectorMultiInputReference = ButtonmultiInputreference.returnVectorMultiInput();

    std::vector<MultiDimensionnalDataStructure*> disciplinesVector;

    for(int iterator = 0; iterator < (int)vectorMultiInputReference.size(); iterator++){


        if (vectorMultiInputReference[iterator]->returnTextComboBox("first") != "" && 
            vectorMultiInputReference[iterator]->returnTextComboBox("second") != ""){
                
                disciplinesVector.push_back(new MultiDimensionnalDataStructure(vectorMultiInputReference[iterator]->returnTextComboBox("first")));
                disciplinesVector.push_back(new MultiDimensionnalDataStructure(vectorMultiInputReference[iterator]->returnTextComboBox("second")));
                disciplinesVector.push_back(new MultiDimensionnalDataStructure(vectorMultiInputReference[iterator]->returnSpinScore()));

        }
    }

    CharacterToCreate.setDisciplines(disciplinesVector);  
}



/** Implementation of the saveBackgroundsInCharacter method.
*
* Implementation of the saveBackgroundsInCharacter method
* Method allowing to retrieve the Backgrounds choices of 
* the user on the interface and to save it in CharacterToCreate*/



void vampireGameproject::Controllor::saveBackgroundsInCharacter(){
    ButtonmultiInputOneComboBox& ButtonmultiInputreferenceOneComboBox = graphicalUserinterface.returnBackgroundsInput();
    std::vector<MultiInputOneComboBox*> vectorMultiInputReference = ButtonmultiInputreferenceOneComboBox.returnVectorMultiInput();

    for(int iterator = 0; iterator < (int)vectorMultiInputReference.size(); iterator++){
        
        if (vectorMultiInputReference[iterator]->returnTextComboBox() != ""){
        
            CharacterToCreate.setBackground(vectorMultiInputReference[iterator]->returnTextComboBox(),
                vectorMultiInputReference[iterator]->returnSpinScore());
        }
    }
}




/** Implementation of the saveVirtuesInCharacter method.
*
* Implementation of the saveVirtuesInCharacter method
* Method allowing to retrieve the Virtues choices of 
* the user on the interface and to save it in CharacterToCreate*/



void vampireGameproject::Controllor::saveVirtuesInCharacter(){
    ButtonmultiInputOneComboBox& ButtonmultiInputreferenceOneComboBox = graphicalUserinterface.returnVirtuesInput();
    std::vector<MultiInputOneComboBox*> vectorMultiInputReference = ButtonmultiInputreferenceOneComboBox.returnVectorMultiInput();


    for(int iterator = 0; iterator < (int)vectorMultiInputReference.size(); iterator++){
        
        if (vectorMultiInputReference[iterator]->returnTextComboBox() != ""){
        
            CharacterToCreate.setVirtues(vectorMultiInputReference[iterator]->returnTextComboBox(),
                vectorMultiInputReference[iterator]->returnSpinScore());
        }
    }

}



/** Implementation of the saveMeritsFlawsCharacter method.
*
* Implementation of the saveMeritsFlawsCharacter method
* Method allowing to retrieve the MeritsFlaws choices of 
* the user on the interface and to save it in CharacterToCreate*/



void vampireGameproject::Controllor::saveMeritsFlawsCharacter(){
    ButtonmultiInput& ButtonmultiInputreference = graphicalUserinterface.returnMeritsFlawsInput();
    std::vector<MultiInput*> vectorMultiInputReference = ButtonmultiInputreference.returnVectorMultiInput();

    for(int iterator = 0; iterator < (int)vectorMultiInputReference.size(); iterator++){
       
       if (vectorMultiInputReference[iterator]->returnTextComboBox("first") != "" && 
            vectorMultiInputReference[iterator]->returnTextComboBox("second") != ""){
       
            CharacterToCreate.setMeritsflaws(vectorMultiInputReference[iterator]->returnTextComboBox("first"),
                vectorMultiInputReference[iterator]->returnTextComboBox("second"), 
                    vectorMultiInputReference[iterator]->returnSpinScore());
        }
    }
}




/** Implementation of the saveUserChoices method.
*
* Implementation of the saveUserChoices method
* Method allowing to retrieve the all the choices of 
* the user on the interface and to save it in CharacterToCreate */



void vampireGameproject::Controllor::saveUserChoices(){
    
    CharacterToCreate.setVampireNickName(graphicalUserinterface.returnLabelVampireNickName().get_text());
    CharacterToCreate.setClan(graphicalUserinterface.returnClanName());
    CharacterToCreate.setNature(graphicalUserinterface.returnNature());
   
    saveAttributesInCharacter();
    saveAbilitiesInCharacter();
    saveDisciplinesInCharacter();
    saveBackgroundsInCharacter();
    saveVirtuesInCharacter();
    saveMeritsFlawsCharacter();

    CharacterToCreate.setHumanity(graphicalUserinterface.returnHumanityPathSpinButton().get_value());
    CharacterToCreate.setWillpower(graphicalUserinterface.returnWillPowerSpinButton().get_value());
    CharacterToCreate.setBloodpool(graphicalUserinterface.returnBloodPoolSpinButton().get_value());
    CharacterToCreate.setHealth(graphicalUserinterface.returnHealth());
    CharacterToCreate.setGeneration(graphicalUserinterface.returnBloodPoolSpinButton().get_value());
    CharacterToCreate.setPlayername(graphicalUserinterface.returnPlayerName());
}






/** Implementation of the submitUserChoices method.
*
* Implementation of the submitUserChoices method
* Method allowing to propose to the user to save 
* the file to create in a selected folder. 
* After that, all the choices of 
* the user on the interface are save in CharacterToCreate
* Then, the output file containing all the user choices is created*/



void vampireGameproject::Controllor::submitUserChoices(){
   std::string filename = graphicalUserinterface.setFileChooser();
   
   if (filename != ""){
       saveUserChoices();
       createResultsFile.writeResultsFile(filename);
   }

   std::vector<MultiDimensionnalDataStructure*> disciplinesVector;
   
   /*Deleting all the address contained in the disciplinesVector*/

   for(int iterator = 0; iterator < (int)disciplinesVector.size(); iterator++){
       MultiDimensionnalDataStructure* MultiDimensionnalDataStructureReference = disciplinesVector[iterator];
       disciplinesVector.erase(disciplinesVector.begin() + iterator);
       delete MultiDimensionnalDataStructureReference;
    }

}