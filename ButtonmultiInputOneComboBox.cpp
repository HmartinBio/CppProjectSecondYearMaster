/**
 * @file ButtonmultiInputOneComboBox.cpp
 *
 * @brief File containing source code of the ButtonmultiInputOneComboBox class
 *
 *
 * @author Hugo MARTIN
 * Contact: hugo.martin.1@etu.univ-amu.fr
 *
 */




#include "classes.h"


/** Constructor of the class ButtonmultiInputOneComboBox.
*
* Modification of the constructor of ButtonmultiInputOneComboBox*/


vampireGameproject::ButtonmultiInputOneComboBox::ButtonmultiInputOneComboBox(){}



/** Destructor of the class ButtonmultiInputOneComboBox.
*
* Modification of the destructor of ButtonmultiInputOneComboBox
* Deleting all the MultiInput address contained in
* the vectorMultiInputs
*/



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
* @param sign: sign of the button to return 
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
* Method setting the score by item of the ComboBoxText*/





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
    of the ComboBox in each MultiInputOneComboBox object*/


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
* Method setting a new MultiInputOneComboBox object*/




void vampireGameproject::ButtonmultiInputOneComboBox::setMultiInput(){
    vectorMultiInputs.push_back(new MultiInputOneComboBox);


}



/** Implementation of the deleteMultiInput method.
*
* Implementation of the deleteMultiInput method
* Method deleting the last MultiInputOneComboBox from the vectorMultiInputs */




void vampireGameproject::ButtonmultiInputOneComboBox::deleteMultiInput(){
    MultiInputOneComboBox* lastElement = vectorMultiInputs.back();
    vectorMultiInputs.pop_back();
    delete lastElement;
}



/** Implementation of the setCoordinates method.
*
* Implementation of the setCoordinates method
* Method setting the coordinates of the ButtonMultiInputOneComboBox object
* 
* @param coordinateX: absciss coordinate 
* @param coordinateY: image coordinate
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
* Method initializing the ButtonMultiInputOneComboBox object */


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
* Method returning the x coordinate from the 
* ButtonMultiInputOneComboBox object */



int vampireGameproject::ButtonmultiInputOneComboBox::returnXCoordinate(){
    return xcoordinates;
}



/** Implementation of the returnYCoordinate method.
*
* Implementation of the returnYCoordinate method
* Method returning the y coordinate from the 
* ButtonMultiInputOneComboBox object */



int vampireGameproject::ButtonmultiInputOneComboBox::returnYCoordinate(){
    return ycoordinates;
}

