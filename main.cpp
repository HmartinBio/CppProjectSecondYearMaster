#include "classes.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Ne pas oublier de faire l'héritage de la Window
// Ne pas oublier de regarder Weakness des clans car 
// certains clans ne peuvent avoir certains Attributs et Disciplines

int main(int argc, char* argv[]){
    auto app = Gtk::Application::create(argc, argv);
    vampireGameproject::Controllor appControlor;
    //vampireGameproject::Parsetext parser;
    //vector<string> vecteur = parser.parse_ClanDisciplines("Nosferatu");
    //for(int i = 0; i < (int)vecteur.size(); i++){
    //    cout << vecteur.at(i) << endl;
    //}
    app->run(appControlor.graphicalUserinterface) ;
    //cout << "test" << endl;
    return 0;
}

