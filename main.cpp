#include "classes.h"

using namespace std;

// Ne pas oublier de faire l'héritage de la Window
// Ne pas oublier de regarder Weakness des clans car 
// certains clans ne peuvent avoir certains Attributs et Disciplines

int main(int argc, char* argv[]){
    auto app = Gtk::Application::create(argc, argv);
    vampireGameproject::Controllor appControlor;
    app->run(appControlor.graphicalUserinterface) ;
    //cout << "test" << endl;
    return 0;
}

