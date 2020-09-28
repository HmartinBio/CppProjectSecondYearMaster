#include "classes.h"

vampireGameproject::Advantages::Advantages(){
    virtues.insert(std::pair<std::string, int>("Conscience", 0));
    virtues.insert(std::pair<std::string, int>("Self-control", 0));
    virtues.insert(std::pair<std::string, int>("Courage", 0));

    /* backgrounds.insert(std::pair<char, int>("Allies", 0));
    backgrounds.insert(std::pair<char, int>("Alternate identity", 0));
    backgrounds.insert(std::pair<char, int>("Black Hand Membership", 0));
    backgrounds.insert(std::pair<char, int>("Contacts", 0));
    backgrounds.insert(std::pair<char, int>("Domain", 0));
    backgrounds.insert(std::pair<char, int>("Fame", 0));
    backgrounds.insert(std::pair<char, int>("Generation", 0));
    backgrounds.insert(std::pair<char, int>("Herd", 0));
    backgrounds.insert(std::pair<char, int>("Influence", 0));
    backgrounds.insert(std::pair<char, int>("Mentor", 0));
    backgrounds.insert(std::pair<char, int>("Resources", 0));
    backgrounds.insert(std::pair<char, int>("Retainers", 0));
    backgrounds.insert(std::pair<char, int>("Rituals", 0));
    backgrounds.insert(std::pair<char, int>("Status", 0));
     */
}

vampireGameproject::Advantages::~Advantages(){}

std::map<std::string, int> vampireGameproject::Advantages::getAdvantages(char tableName){
    switch(tableName){
        case 'backgrounds': return backgrounds;
            break;
        case 'virtues': return virtues;
            break;
        default:
            break;
    }
}

 void vampireGameproject::Advantages::setAdvantages(char tableName, std::string abilitieName, int value){
     switch(tableName){
         case 'backgrounds': backgrounds[abilitieName] += value;
            break;
        case 'virtues': virtues[abilitieName] += value;
            break;
        default:
            break;
     }
 }

 