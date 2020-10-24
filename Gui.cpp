#include "classes.h"


/** Constructor of the class Gui.
*
* Modification of the constructor of Gui
* Initialisation of the testGui constructor 
* before the Gui constructor be initialised
*
*/

vampireGameproject::Gui::Gui(RulesofGame& rulesGamereference): 
    testGui(rulesGamereference){
        //Gui::set_title("Vampire Game Project");
        //Gui::resize(400, 300);
        //Gui::set_position(Gtk::WIN_POS_CENTER);
        
        //for(int iterator = 0; iterator <= 3; iterator++){
        //    tableLabel[iterator] = Gtk::Label();
        //}

        //tableLabel[0].set_text("Select a clan:");
        //tableLabel[0].set_xalign(0.0);
        //tableLabel[1].set_text("Select a Nature:");
        //tableLabel[1].set_xalign(0.0);
        //tableLabel[2].set_text("    Name of the Vampire:");
        //tableLabel[3].set_text("Select Attributes:");
        //tableLabel[3].set_xalign(0.0);
        //mainGrid.attach(tableLabel[0], 0, 0, 1, 1);
        //mainGrid.attach(tableLabel[1], 0, 1, 1, 1);
        //mainGrid.attach(tableLabel[2], 2, 0, 1, 1);
        //mainGrid.attach(tableLabel[3], 0, 2, 1, 1);
        //mainGrid.insert_row(1);
        //tableComboBox[0] = Gtk::ComboBoxText();
        //tableComboBox[1] = Gtk::ComboBoxText();
        
        ////std::vector<std::string> vectorClans = testGui.returnVectorClans();

        ////for(int iterator = 0; iterator < (int)vectorClans.size(); iterator++){
        ////    tableComboBox[0].append(vectorClans.at(iterator));
        ////}
        
        //tableComboBox[0].append("Assamite");
        //tableComboBox[0].append("Brujah");
        //tableComboBox[1].append("Stealer");
        ////mainGrid.attach(tableComboBox[0], 1, 0, 1, 1);
        //mainGrid.attach_next_to(tableComboBox[0], tableLabel[0], Gtk::POS_RIGHT, 1, 1);
        //mainGrid.attach_next_to(tableComboBox[1], tableLabel[3], Gtk::POS_RIGHT, 1, 1);
        ////mainGrid.attach(tableComboBox[1], 1, 1, 1, 1);
        ////mainGrid.set_row_homogeneous(true);
        ////mainGrid.set_column_homogeneous(true);
        //mainGrid.show_all();
        //Gui::add(mainGrid);
        //Gui::show_all_children();
    }



/** Destructor of the class Gui.
* Modification of the destructor of Gui
*
*
*
*/

vampireGameproject::Gui::~Gui(){}




void vampireGameproject::Gui::setTableComboBox(int index, std::vector<std::string>& vectorElements){
    for(int iterator = 0; iterator < (int)vectorElements.size(); iterator++){
        tableComboBox[index].append(vectorElements.at(iterator));
    }
}




void vampireGameproject::Gui::initialiseTableLabel(){
    for(int iterator = 0; iterator <= 3; iterator++){
            tableLabel[iterator] = Gtk::Label();
        }
}



void vampireGameproject::Gui::initialiseTableComboBox(){
    tableComboBox[0] = Gtk::ComboBoxText();
    tableComboBox[1] = Gtk::ComboBoxText();
}




void vampireGameproject::Gui::setTableLabelAlign(int index, std::string label){
    tableLabel[index].set_text(label);
    tableLabel[index].set_xalign(0.0);
}



void vampireGameproject::Gui::setTableLabel(int index, std::string label){
    tableLabel[index].set_text(label);
}





void vampireGameproject::Gui::setTableLabelOnGrid(int index, int xcoordinates, int ycoordinates, int width, int height){
    mainGrid.attach(tableLabel[index], xcoordinates, ycoordinates, width, height);
}






void vampireGameproject::Gui::setTableComboBoxOnGrid(int index, int indexLabel){
    mainGrid.attach_next_to(tableComboBox[index], tableLabel[indexLabel], Gtk::POS_RIGHT, 1, 1);
}





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





void vampireGameproject::Gui::setMultiComboBoxAttributes(int xcoordinates, int ycoordinates, int width, int height){
    setMultiComboBox(attributesInput.returnButton("plus"), attributesInput.returnButton("minus"),
    attributesInput.returnComboBox("first"), attributesInput.returnComboBox("second"), 
    attributesInput.returnSpinButton(), xcoordinates, ycoordinates, width, height);
}






void vampireGameproject::Gui::setLabelMultiComboBoxAttributes(){
    attributesInput.setLabelMultiComboBox();
}

vampireGameproject::ButtonmultiInput& vampireGameproject::Gui::returnAttributesInput(){
    return attributesInput;
}


void vampireGameproject::Gui::showAll(){
    mainGrid.show_all();
    Gui::add(mainGrid);
    Gui::show_all_children();
}

