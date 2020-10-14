#include "classes.h"

using namespace std;

int main(int argc, char* argv[]){
    auto app = Gtk::Application::create(argc, argv);
    vampireGameproject::Controllor appControlor;
    app->run(appControlor.graphicalUserinterface.window) ;
    //cout << "test" << endl;
    return 0;
}

