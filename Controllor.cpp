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
        graphicalUserinterface.setMultiComboBoxAttributes(1, 3, 1, 1);
        graphicalUserinterface.setLabelMultiComboBoxAttributes();
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