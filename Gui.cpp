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
        Gui::set_title("Vampire Game Project");
        Gui::resize(400, 300);
        Gui::set_position(Gtk::WIN_POS_CENTER);
        
        for(int iterator = 0; iterator <= 3; iterator++){
            tableLabel[iterator] = Gtk::Label();
        }

        tableLabel[0].set_text("Select a clan:");
        tableLabel[0].set_xalign(0.0);
        tableLabel[1].set_text("Select a Nature:");
        tableLabel[1].set_xalign(0.0);
        tableLabel[2].set_text("    Name of the Vampire:");
        tableLabel[3].set_text("Select Attributes:");
        tableLabel[3].set_xalign(0.0);
        mainGrid.attach(tableLabel[0], 0, 0, 1, 1);
        mainGrid.attach(tableLabel[1], 0, 1, 1, 1);
        mainGrid.attach(tableLabel[2], 2, 0, 1, 1);
        mainGrid.attach(tableLabel[3], 0, 2, 1, 1);
        mainGrid.insert_row(1);
        tableComboBox[0] = Gtk::ComboBoxText();
        tableComboBox[1] = Gtk::ComboBoxText();
        tableComboBox[0].append("Assamite");
        tableComboBox[0].append("Brujah");
        tableComboBox[1].append("Stealer");
        //mainGrid.attach(tableComboBox[0], 1, 0, 1, 1);
        mainGrid.attach_next_to(tableComboBox[0], tableLabel[0], Gtk::POS_RIGHT, 1, 1);
        mainGrid.attach_next_to(tableComboBox[1], tableLabel[3], Gtk::POS_RIGHT, 1, 1);
        //mainGrid.attach(tableComboBox[1], 1, 1, 1, 1);
        //mainGrid.set_row_homogeneous(true);
        //mainGrid.set_column_homogeneous(true);
        mainGrid.show_all();
        Gui::add(mainGrid);
        Gui::show_all_children();
    }



/** Destructor of the class Gui.
*
* Modification of the destructor of Gui
*
*
*
*/

vampireGameproject::Gui::~Gui(){}