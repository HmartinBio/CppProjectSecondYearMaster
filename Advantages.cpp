#include "classes.h"



/** Constructor of the class Advantages.
*
* Modification of the constructor of Advantages
*
*
*
*/


vampireGameproject::Advantages::Advantages(){
    /*
    virtues.insert(std::pair<std::string, int>("Conscience", 0));
    virtues.insert(std::pair<std::string, int>("Self-control", 0));
    virtues.insert(std::pair<std::string, int>("Courage", 0));

    */

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


/** Destructor of the class Advantages.
*
* Modification of the destructor of Advantages
*
*
*
*/



vampireGameproject::Advantages::~Advantages(){}


/** Implementation of the getAdvantages method.
*
* Implementation of the getAdvantages method
* Method returning the Advantages
* 
* @param tableName
*
*/




std::map<std::string, int> vampireGameproject::Advantages::getAdvantages(std::string tableName){
    if(tableName == "backgrounds"){
        return backgrounds;
    }

    else if(tableName == "virtues"){
        return virtues;
    }
}



/** Implementation of the setAdvantages method.
*
* Implementation of the setAdvantages method
* Method setting the advantages
* 
* @param tableName name of the table where setting the abilitie
* @param abilitieName name of the abilitie to set
* @param value value of the abilitie to set
*/


 void vampireGameproject::Advantages::setAdvantages(std::string tableName, std::string abilitieName, int value){
     if(tableName == "backgrounds"){
         backgrounds.insert(std::pair<std::string, int>(abilitieName, value));
     }

     else if(tableName == "virtues"){
         virtues.insert(std::pair<std::string, int>(abilitieName, value));

     }
 }

 