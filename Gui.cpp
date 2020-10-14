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
        window.set_title("Vampire Game Project");
        window.resize(400, 300);
        window.set_position(Gtk::WIN_POS_CENTER);
        tableLabel[0] = Gtk::Label();
        tableLabel[0].set_text("Select a clan");
        mainGrid.attach(tableLabel[0], 0, 0, 1, 1);
        mainGrid.show_all();
        window.add(mainGrid);
        window.show_all_children();
    }



/** Destructor of the class Gui.
*
* Modification of the destructor of Gui
*
*
*
*/

vampireGameproject::Gui::~Gui(){}