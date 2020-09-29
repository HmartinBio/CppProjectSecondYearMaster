#include "classes.h"

vampireGameproject::CharacterTraits::CharacterTraits(){}
vampireGameproject::CharacterTraits::~CharacterTraits(){}

void vampireGameproject::CharacterTraits::setHumanity(int number){
    humanity = number;
}

void vampireGameproject::CharacterTraits::setWillpower(int number){
    willPower = number;
}

void vampireGameproject::CharacterTraits::setBloodpool(int number){
    bloodPool = number;
}

std::string vampireGameproject::CharacterTraits::getHumanity(void){
    switch(humanity){
        case 0 : return "Monstruous";
            break;
        case 1: return "Horrific";
            break;
        case 2: return "Bestial";
            break;
        case 3: return "Cold";
            break;
        case 4: return "Unfeeling" ;
            break;
        case 5: return "Distant"; 
            break;
        case 6: return "Removed";
            break;
        case 7: return "Normal";
            break;
        case 8: return "Caring";
            break;
        case 9: return "Compassionate";
            break;
        case 10: return "Saintly";
            break;
        default:
            break;
    }
}

std::string vampireGameproject::CharacterTraits::getWillpower(void){
    switch(willPower){
    case 1: return "Spineless"; 
        break;
    case 2: return "Weak";
        break;
    case 3: return "Unassertive";
        break;
    case 4: return "Diffident";
        break;
    case 5: return "Certain";
        break;
    case 6: return "Confident";
        break;
    case 7: return "Determined";
        break;
    case 8: return "Controlled";
        break;
    case 9: return "Iron-willed";
        break;
    case 10: return "Unshakable";
        break;
    default:
        break;
    }
} 

int vampireGameproject::CharacterTraits::getBloodpool(void){
    return bloodPool;
}

