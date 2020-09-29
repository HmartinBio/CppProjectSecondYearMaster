#include "classes.h"



/** Constructor of the class Abilities.
*
* Modification of the constructor of Abilities
*
*
*
*/



vampireGameproject::Abilities::Abilities(){
    /*
    talents.insert(std::pair<std::string,int>("Alertness", 0));
    talents.insert(std::pair<std::string,int>("Athletics", 0));
    talents.insert(std::pair<std::string,int>("Awareness", 0));
    talents.insert(std::pair<std::string,int>("Brawl", 0));
    talents.insert(std::pair<std::string, int>("Empathy", 0));
    talents.insert(std::pair<std::string,int>("Expression", 0));
    talents.insert(std::pair<std::string,int>("Intimidation", 0));
    talents.insert(std::pair<std::string,int>("Leadership", 0));
    talents.insert(std::pair<std::string,int>("Streetwise", 0));
    talents.insert(std::pair<std::string,int>("Subterfuge", 0));
    talents.insert(std::pair<std::string,int>("Alertness", 0));
    skills.insert(std::pair<std::string,int>("Animal Ken", 0));
    skills.insert(std::pair<std::string,int>("Crafts", 0));
    skills.insert(std::pair<std::string,int>("Drive", 0));
    skills.insert(std::pair<std::string,int>("Etiquette", 0));
    skills.insert(std::pair<std::string,int>("Firearms", 0));
    skills.insert(std::pair<std::string,int>("Larceny", 0));
    skills.insert(std::pair<std::string,int>("Melee", 0));
    skills.insert(std::pair<std::string,int>("Performance", 0));
    skills.insert(std::pair<std::string,int>("Stealth", 0));
    skills.insert(std::pair<std::string,int>("Survival", 0));
    skills.insert(std::pair<std::string,int>("Professional Skill", 0));
    knowledges.insert(std::pair<std::string,int>("Academics", 0));
    knowledges.insert(std::pair<std::string,int>("Computer", 0));
    knowledges.insert(std::pair<std::string,int>("Finance", 0));
    knowledges.insert(std::pair<std::string,int>("Investigation", 0));
    knowledges.insert(std::pair<std::string,int>("Law", 0));
    knowledges.insert(std::pair<std::string,int>("Medicine", 0));
    knowledges.insert(std::pair<std::string,int>("Occult", 0));
    knowledges.insert(std::pair<std::string,int>("Politics", 0));
    knowledges.insert(std::pair<std::string,int>("Science", 0));
    knowledges.insert(std::pair<std::string,int>("Technology", 0));
    knowledges.insert(std::pair<std::string,int>("Expert Knowledge", 0));
    */
}


/** Implementation of the getAbilities method.
*
* Implementation of the getAbilities method
* 
* @param attributeTable name of the table to return 
*
*/


std::map<std::string, int> vampireGameproject::Abilities::getAbilities(std::string tableName){
    if(tableName == "talents"){
        return talents;
    }

    else if(tableName == "skills"){
        return talents;
    }
    
    else if(tableName == "knowledges"){
        return knowledges;
    }
}


/** Implementation of the setAbilities method.
*
* Implementation of the setAbilities method
* 
* @param tableName name of the table to add an attribute 
* @param abilitieName name of the abilitie to add
* @param value value of the abilitie to add
*/


void vampireGameproject::Abilities::setAbilities(std::string tableName, std::string abilitieName, int value){
    if(tableName == "talents"){
        talents.insert(std::pair<std::string,int>(abilitieName, value));
    }

    else if(tableName == "skills"){
        skills.insert(std::pair<std::string,int>(abilitieName, value));
    }

    else if(tableName == "knowledges"){
        knowledges.insert(std::pair<std::string,int>(abilitieName, value));
    }

}