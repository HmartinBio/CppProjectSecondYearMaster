#include "classes.h"

vampireGameproject::Abilities::Abilities(){
    talents.insert(std::pair<char,int>("Alertness", 0));
    talents.insert(std::pair<char,int>("Athletics", 0));
    talents.insert(std::pair<char,int>("Awareness", 0));
    talents.insert(std::pair<char,int>("Brawl", 0));
    talents.insert(std::pair<char,int>("Empathy", 0));
    talents.insert(std::pair<char,int>("Expression", 0));
    talents.insert(std::pair<char,int>("Intimidation", 0));
    talents.insert(std::pair<char,int>("Leadership", 0));
    talents.insert(std::pair<char,int>("Streetwise", 0));
    talents.insert(std::pair<char,int>("Subterfuge", 0));
    talents.insert(std::pair<char,int>("Alertness", 0));
    skills.insert(std::pair<char,int>("Animal Ken", 0));
    skills.insert(std::pair<char,int>("Crafts", 0));
    skills.insert(std::pair<char,int>("Drive", 0));
    skills.insert(std::pair<char,int>("Etiquette", 0));
    skills.insert(std::pair<char,int>("Firearms", 0));
    skills.insert(std::pair<char,int>("Larceny", 0));
    skills.insert(std::pair<char,int>("Melee", 0));
    skills.insert(std::pair<char,int>("Performance", 0));
    skills.insert(std::pair<char,int>("Stealth", 0));
    skills.insert(std::pair<char,int>("Survival", 0));
    skills.insert(std::pair<char,int>("Professional Skill", 0));
    knowledges.insert(std::pair<char,int>("Academics", 0));
    knowledges.insert(std::pair<char,int>("Computer", 0));
    knowledges.insert(std::pair<char,int>("Finance", 0));
    knowledges.insert(std::pair<char,int>("Investigation", 0));
    knowledges.insert(std::pair<char,int>("Law", 0));
    knowledges.insert(std::pair<char,int>("Medicine", 0));
    knowledges.insert(std::pair<char,int>("Occult", 0));
    knowledges.insert(std::pair<char,int>("Politics", 0));
    knowledges.insert(std::pair<char,int>("Science", 0));
    knowledges.insert(std::pair<char,int>("Technology", 0));
    knowledges.insert(std::pair<char,int>("Expert Knowledge", 0));
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