#include "classes.h"


/** Constructor of the class ButtonmultiInput.
*
* Modification of the constructor of ButtonmultiInput
* 
*
*
*/

vampireGameproject::ButtonmultiInputOneComboBox::ButtonmultiInputOneComboBox(){}



/** Destructor of the class ButtonmultiInput.
*
* Modification of the destructor of ButtonmultiInput
*
*
*
*/



vampireGameproject::ButtonmultiInputOneComboBox::~ButtonmultiInputOneComboBox(){}


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
* Method returning the SpinButton
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
* Method setting labels to buttons
*  
*
*/



void vampireGameproject::ButtonmultiInputOneComboBox::setLabelMultiComboBox(){
    plusButton.add_label("+");
    minusButton.add_label("-");
}



/** Implementation of the returnVectorMultiInput method.
*
* Implementation of the returnVectorMultiInput method
* Method returning the vector of MultiInput
* 
*
*/




std::vector<vampireGameproject::MultiInputOneComboBox*>& vampireGameproject::ButtonmultiInputOneComboBox::returnVectorMultiInput(){
    return vectorMultiInputs;
}





/** Implementation of the setDicoScoreFirstComboBox method.
*
* Implementation of the setDicoScoreFirstComboBox method
* Method setting the score by item of the First Combo Box
*  
*
*/



void vampireGameproject::ButtonmultiInputOneComboBox::setDicoScoreFirstComboBox(){
    // Initialisation of a dictionnary to compute the SpinScore by item
    // of the first ComboBox

    std::map<std::string, int> mapCounter;

    // Iterating on the set of MultiInput, for each MultiInput
    // If the first ComboBox item is not in the dictionnary, 
    // then it's added with the Spin Score. And if the MultiInput 
    // item of the First ComboBox is in the dictionnary, then the 
    // Spin Score is incremented 

   

    if (vectorMultiInputs.size() != 0){

        for(int iterator = 0; iterator < (int)vectorMultiInputs.size(); iterator++){

                if (mapCounter.find(vectorMultiInputs[iterator]->returnTextComboBox()) == mapCounter.end()){
                    mapCounter.insert(std::pair<std::string, int>(vectorMultiInputs[iterator]->returnTextComboBox(), 
                        vectorMultiInputs[iterator]->returnSpinScore()));
                        std::cout << "creation de points" << std::endl;
                        std::cout << vectorMultiInputs[iterator]->returnTextComboBox() << std::endl;
                        std::cout << mapCounter[vectorMultiInputs[iterator]->returnTextComboBox()] << std::endl;
                        std::cout << "fin de creation de points" << std::endl;
                }

                else{
                    std::cout << "ajout de points" << std::endl;
                    mapCounter[vectorMultiInputs[iterator]->returnTextComboBox()] = 
                        mapCounter[vectorMultiInputs[iterator]->returnTextComboBox()] + 
                            vectorMultiInputs[iterator]->returnSpinScore();
                    std::cout << vectorMultiInputs[iterator]->returnTextComboBox() << std::endl;
                    std::cout << mapCounter[vectorMultiInputs[iterator]->returnTextComboBox()] << std::endl;
                    std::cout << "fin d'ajout de points" << std::endl;

                }
                  
        }

        std::cout << "affichage du dictionnaire" << std::endl;
        for ( const auto &myPair : mapCounter ) {
            std::cout << myPair.first <<  std::endl;
            std::cout << myPair.second << std::endl;
        }



        DicoScoreComboBox = mapCounter;
    }

    else{
        DicoScoreComboBox = mapCounter;
    }
}



/** Implementation of the setDicoSelectedInput method.
*
* Implementation of the setDicoSelectedInput method
* Method setting the choices of MultiInput in a map
* 
*
*/





void vampireGameproject::ButtonmultiInputOneComboBox::setVectorSelectedInput(){

    // Cleaning the vectors containing the selected items 
    // of the First and the Second ComboBox

    vectorComboBoxSelectedInputs.clear();
    

    // Iterating on the vector containing MultiInputs
    // For each MultiInputs, if the text in the Second ComboBox
    // doesn't exist again in the Dictionnary, then, it's 
    // added in the Dictionnary else it's ignored

    for(int iterator = 0; iterator < (int)vectorMultiInputs.size(); iterator++){

        vectorComboBoxSelectedInputs.push_back(vectorMultiInputs[iterator]->returnTextComboBox());
    }
}



/** Implementation of the setMultiInput method.
*
* Implementation of the setMultiInput method
* Method setting a new MultiInput 
*  
*
*/




void vampireGameproject::ButtonmultiInputOneComboBox::setMultiInput(){
    vectorMultiInputs.push_back(new MultiInputOneComboBox);


}



/** Implementation of the deleteMultiInput method.
*
* Implementation of the deleteMultiInput method
* Method deleting the last MultiInput of the vector
* 
*
*/




void vampireGameproject::ButtonmultiInputOneComboBox::deleteMultiInput(){
    MultiInputOneComboBox* lastElement = vectorMultiInputs.back();
    vectorMultiInputs.pop_back();
    delete lastElement;
}



/** Implementation of the setCoordinates method.
*
* Implementation of the setCoordinates method
* Method setting the coordinates of the ButtonMultiInput
* 
* @param coordinateX absciss coordinate 
* @param coordinateY image coordinate
*
*/



void vampireGameproject::ButtonmultiInputOneComboBox::setCoordinates(int coordinateX, int coordinateY){
    xcoordinates = coordinateX;
    ycoordinates = coordinateY;
}



/** Implementation of the returnDicoScoreFirstComboBox method.
*
* Implementation of the returnDicoScoreFirstComboBox method
* Method returning the point number for each First Combo Box items
* 
*
*/


std::map<std::string, int> vampireGameproject::ButtonmultiInputOneComboBox::returnDicoScoreComboBox(){
    return DicoScoreComboBox;
}


/** Implementation of the returnDicoSelectedInputs method.
*
* Implementation of the returnDicoSelectedInputs method
* Method returning a map with all the selected items
* 
*
*/



std::vector<std::string> vampireGameproject::ButtonmultiInputOneComboBox::returnVectorSelectedInput(){    
    return vectorComboBoxSelectedInputs;
}


/** Implementation of the initialize method.
*
* Implementation of the initialize method
* Method initializing the ButtonMultiInput
* 
*
*/


void vampireGameproject::ButtonmultiInputOneComboBox::initialize(){
    setMultiInput();
}



/** Implementation of the setVectorComboBox method.
*
* Implementation of the setVectorComboBox method
* Method initializing the choosen ComboBox with a chosen vector
* 
*
*/


void vampireGameproject::ButtonmultiInputOneComboBox::setVectorComboBox(int index, std::vector<std::string> vectorReference){
    vectorMultiInputs[index]->setVectorComboBox(vectorReference);
}



/** Implementation of the returnTextComboBox method.
*
* Implementation of the returnTextComboBox method
* Method returning the text from the chosen ComboBox
* 
*
*/



std::string vampireGameproject::ButtonmultiInputOneComboBox::returnTextComboBox(int number){
   return vectorMultiInputs[number]->returnTextComboBox();
}




/** Implementation of the returnXCoordinate method.
*
* Implementation of the returnXCoordinate method
* Method returning the x coordinate
* 
*
*/



int vampireGameproject::ButtonmultiInputOneComboBox::returnXCoordinate(){
    return xcoordinates;
}


/** Implementation of the returnYCoordinate method.
*
* Implementation of the returnYCoordinate method
* Method returning the y coordinate
* 
*
*/



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

 void vampireGameproject::ButtonmultiInputOneComboBox::deleteItemDicoSelectedInput(std::string item){
     DicoSelectedInputs.erase(item);
 }

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