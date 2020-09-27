#include "classes.h"

vampireGameproject::Abilities::Abilities(){
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
}

std::map<char,int> vampireGameproject::Abilities::getAbilities(char tableName){
    switch (tableName){
        case 'talents': return talents;
            break;
        case 'skills': return skills;
            break;
        case 'knowledges': return knowledges;
            break; 
        default:
            break;
    }
}

void vampireGameproject::Abilities::setAbilities(char tableName,char abilitieName, int value){
    switch(tableName){
        case 'talents': talents[abilitieName] += value;
            break;
        case 'skills': skills[abilitieName] += value;
            break;
        case 'knowledges': knowledges[abilitieName] += value;
            break;
        default:
            break;
    }
}