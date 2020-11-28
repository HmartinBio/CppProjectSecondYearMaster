#include "classes.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    
    /*Building an object for the gtkmm Gui*/

    auto app = Gtk::Application::create(argc, argv);
    
    /*Building the Controllor object where all the functionnalities
    of the application are present*/

    vampireGameproject::Controllor appControlor;
    
    /*Running the application*/

    app->run(appControlor.graphicalUserinterface) ;
    return 0;
}

