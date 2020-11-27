#include "classes.h"


/** Constructor of the class ButtonmultiInputOneComboBox.
*
* Modification of the constructor of ButtonmultiInputOneComboBox*/

vampireGameproject::ButtonmultiInputOneComboBox::ButtonmultiInputOneComboBox(){}



/** Destructor of the class ButtonmultiInputOneComboBox.
*
* Modification of the destructor of ButtonmultiInputOneComboBox*/



vampireGameproject::ButtonmultiInputOneComboBox::~ButtonmultiInputOneComboBox(){
    for(int iterator = 0; iterator < (int)vectorMultiInputs.size(); iterator++){
        MultiInputOneComboBox* referenceMultiInput = vectorMultiInputs[iterator];
        vectorMultiInputs.erase(vectorMultiInputs.begin() + iterator);
        delete referenceMultiInput;
    }
}


/** Implementation of the returnButton method.
*
* Implementation of the returnButton method
* Method returning the button reference
* 
* @param sign sign of the button to return 
* 
*/


Gtk::Button& vampireGameproject::ButtonmultiInputOneComboBox::returnButton(std::string sign){
    if (sign == "plus"){
        return plusButton;
    }

    else{
        return minusButton;
    }
}



/** Implementation of the returnComboBox method.
*
* Implementation of the returnComboBox method
* Method returning the Combobox Reference
* 
* @param position position of the ComboBox to return 
*
*/


////

//Gtk::ComboBoxText& vampireGameproject::ButtonmultiInput::returnComboBox(std::string position){
//    if (position == "first"){
       // return firstComboBox;
//    }

//    else{
//        return secondComboBox;
//    }
//}



/** Implementation of the returnSpinButton method.
*
* Implementation of the returnSpinButton method
* Method returning the SpinButton of the MultiInputOneComboBox
* 
* @param tableName name of the table to return 
*
*/



//Gtk::SpinButton& vampireGameproject::ButtonmultiInput::returnSpinButton(){
//    return spinButton;
//} 


////


/** Implementation of the setLabelMultiComboBox method.
*
* Implementation of the setLabelMultiComboBox method
* Method setting labels to buttons of the ButtonMultiInputOneComboBox object*/



void vampireGameproject::ButtonmultiInputOneComboBox::setLabelMultiComboBox(){
    plusButton.add_label("+");
    minusButton.add_label("-");
}



/** Implementation of the returnVectorMultiInput method.
*
* Implementation of the returnVectorMultiInput method
* Method returning the vector of MultiInputOneComboBox*/




std::vector<vampireGameproject::MultiInputOneComboBox*>& vampireGameproject::ButtonmultiInputOneComboBox::returnVectorMultiInput(){
    return vectorMultiInputs;
}





/** Implementation of the setDicoScoreFirstComboBox method.
*
* Implementation of the setDicoScoreFirstComboBox method
* Method setting the score by item of the Combo Box*/



void vampireGameproject::ButtonmultiInputOneComboBox::setDicoScoreFirstComboBox(){
    /* Initialisation of a dictionnary to compute the SpinScore by item
    of the ComboBox*/

    std::map<std::string, int> mapCounter;

    /*Iterating on the set of MultiInputOneComboBox, for each MultiInputOneComboBox
    If the ComboBox item is not in the dictionnary, 
    then it's added with the Spin Score. And if the MultiInputOneComboBox 
    item of the ComboBox is in the dictionnary, then the 
    Spin Score is incremented*/ 

   

    if (vectorMultiInputs.size() != 0){

        for(int iterator = 0; iterator < (int)vectorMultiInputs.size(); iterator++){

                if (mapCounter.find(vectorMultiInputs[iterator]->returnTextComboBox()) == mapCounter.end()){
                    mapCounter.insert(std::pair<std::string, int>(vectorMultiInputs[iterator]->returnTextComboBox(), 
                        vectorMultiInputs[iterator]->returnSpinScore()));
                }

                else{
                    mapCounter[vectorMultiInputs[iterator]->returnTextComboBox()] = 
                        mapCounter[vectorMultiInputs[iterator]->returnTextComboBox()] + 
                            vectorMultiInputs[iterator]->returnSpinScore();

                }
                  
        }



        DicoScoreComboBox = mapCounter;
    }

    else{
        DicoScoreComboBox = mapCounter;
    }
}



/** Implementation of the setVectorSelectedInput method.
*
* Implementation of the setVectorSelectedInput method
* Method setting the choices of MultiInputOneComboBox in a map*/





void vampireGameproject::ButtonmultiInputOneComboBox::setVectorSelectedInput(){

    /* Cleaning the vectors containing the selected items 
    of the First and the Second ComboBox*/

    vectorComboBoxSelectedInputs.clear();
    

    /* Iterating on the vector containing MultiInputsOneComboBox
    For each MultiInputsOneComboBox, if the text in the Second ComboBox
    doesn't exist again in the Dictionnary, then, it's 
    added in the Dictionnary else it's ignored*/


    for(int iterator = 0; iterator < (int)vectorMultiInputs.size(); iterator++){

        vectorComboBoxSelectedInputs.push_back(vectorMultiInputs[iterator]->returnTextComboBox());
    }
}



/** Implementation of the setMultiInput method.
*
* Implementation of the setMultiInput method
* Method setting a new MultiInputOneComboBox */




void vampireGameproject::ButtonmultiInputOneComboBox::setMultiInput(){
    vectorMultiInputs.push_back(new MultiInputOneComboBox);


}



/** Implementation of the deleteMultiInput method.
*
* Implementation of the deleteMultiInput method
* Method deleting the last MultiInputOneComboBox of the vector*/




void vampireGameproject::ButtonmultiInputOneComboBox::deleteMultiInput(){
    MultiInputOneComboBox* lastElement = vectorMultiInputs.back();
    vectorMultiInputs.pop_back();
    delete lastElement;
}



/** Implementation of the setCoordinates method.
*
* Implementation of the setCoordinates method
* Method setting the coordinates of the ButtonMultiInputOneComboBox
* 
* @param coordinateX absciss coordinate 
* @param coordinateY image coordinate
*
*/



void vampireGameproject::ButtonmultiInputOneComboBox::setCoordinates(int coordinateX, int coordinateY){
    xcoordinates = coordinateX;
    ycoordinates = coordinateY;
}



/** Implementation of the returnDicoScoreComboBox method.
*
* Implementation of the returnDicoScoreComboBox method
* Method returning the point number for each Combo Box items*/


std::map<std::string, int> vampireGameproject::ButtonmultiInputOneComboBox::returnDicoScoreComboBox(){
    return DicoScoreComboBox;
}


/** Implementation of the returnVectorSelectedInput method.
*
* Implementation of the returnVectorSelectedInput method
* Method returning a vector with all the selected items */



std::vector<std::string> vampireGameproject::ButtonmultiInputOneComboBox::returnVectorSelectedInput(){    
    return vectorComboBoxSelectedInputs;
}


/** Implementation of the initialize method.
*
* Implementation of the initialize method
* Method initializing the ButtonMultiInputOneComboBox */


void vampireGameproject::ButtonmultiInputOneComboBox::initialize(){
    setMultiInput();
}



/** Implementation of the setVectorComboBox method.
*
* Implementation of the setVectorComboBox method
* Method initializing the choosen ComboBox with a chosen vector
* 
* @param index: index of the MultiInputOneComboBox to select in the vector 
* @param vectorReference: vector containing strings to set in the ComboBoxText
*/


void vampireGameproject::ButtonmultiInputOneComboBox::setVectorComboBox(int index, std::vector<std::string> vectorReference){
    vectorMultiInputs[index]->setVectorComboBox(vectorReference);
}



/** Implementation of the returnTextComboBox method.
*
* Implementation of the returnTextComboBox method
* Method returning the text from the ComboBox
* 
* @param number: number of the MultiInput to select in the vector
*/



std::string vampireGameproject::ButtonmultiInputOneComboBox::returnTextComboBox(int number){
   return vectorMultiInputs[number]->returnTextComboBox();
}




/** Implementation of the returnXCoordinate method.
*
* Implementation of the returnXCoordinate method
* Method returning the x coordinate of the 
* ButtonMultiInputOneComboBox */



int vampireGameproject::ButtonmultiInputOneComboBox::returnXCoordinate(){
    return xcoordinates;
}


/** Implementation of the returnYCoordinate method.
*
* Implementation of the returnYCoordinate method
* Method returning the y coordinate of the 
* ButtonMultiInputOneComboBox */



int vampireGameproject::ButtonmultiInputOneComboBox::returnYCoordinate(){
    return ycoordinates;
}








// Il faudrait passer les fonctions du Controlleur au buttonMultiInput
// Le contrôleur regarderait si les points sont atteints où pas et 
// supprimerait pour les autres MultiInput le texte choisis
// Le contrôleur transmettrait une fonction où il regarde si il y a eu des choix ou pas encore 
// Si il y en a pas eu c'est open bar sinon pour les MultiInput où le texte n'est 
// pas encore actif, on restreint le spin button et le choix des combobox




/** Implementation of the deleteItemDicoSelectedInput method.
*
* Implementation of the deleteItemDicoSelectedInput method
* Method deleting the chosen item of the DictionnarySelectedInputs
*
*/
/* 
 void vampireGameproject::ButtonmultiInputOneComboBox::deleteItemDicoSelectedInput(std::string item){
     DicoSelectedInputs.erase(item);
 } */

 /* void vampireGameproject::ButtonmultiInput::setCounter(){
     numberMultiInput = 1;
 }

void vampireGameproject::ButtonmultiInput::increaseNumberMultiInput(){
    numberMultiInput += 1;
}

void vampireGameproject::ButtonmultiInput::deacreaseNumberMultiInput(){
    numberMultiInput -= 1;
}

int vampireGameproject::ButtonmultiInput::returnNumberMultiInput(){
    return numberMultiInput;
} */