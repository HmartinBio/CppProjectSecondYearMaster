#include "classes.h"


/** Constructor of the class Picturemodifying.
*
* Modification of the constructor of Picturemodifying
*
*
*
*/

vampireGameproject::Picturemodifying::Picturemodifying(Character& ReferenceCharacter): CharacterReference(ReferenceCharacter){}


/** Destructor of the class Picturemodifying.
*
* Modification of the destructor of Picturemodifying
*
*
*
*/

vampireGameproject::Picturemodifying::~Picturemodifying(){}



void vampireGameproject::Picturemodifying::writeResultsAttributes(std::ofstream& fileToWrite){
    fileToWrite << "<--------------------------------------------Attributes---------------------------------------->" << std::endl;
    fileToWrite << "Physical\tSocial\t\t\tMental" << std::endl;
    
    std::map<std::string, int> physicalAttributes = CharacterReference.getAttributes("Physical");
    std::map<std::string, int> socialAttributes = CharacterReference.getAttributes("Social");
    std::map<std::string, int> mentalAttributes = CharacterReference.getAttributes("Mental");
    

    std::string tableAttributes[] = {"Strength", "Charisma", 
        "Perception", "Dexterity", "Manipulation", 
            "Intelligence", "Stamina", "Appearance", "Wits"};

    int tableAttributesSize = 9;

    std::map<std::string, int>::iterator iteratorMap;


    for(int iterator = 0; iterator < tableAttributesSize; iterator++){
        if (iterator % 3 == 0){
            iteratorMap = physicalAttributes.find(tableAttributes[iterator]);

            if(iteratorMap != physicalAttributes.end()){
                fileToWrite << tableAttributes[iterator] << ":" << iteratorMap->second << "\t";
            }
            else{
                fileToWrite << tableAttributes[iterator] << ": 0" << "\t";
            }
        }

        if ((iterator - 1) % 3 == 0){
            iteratorMap = socialAttributes.find(tableAttributes[iterator]);

            if (iteratorMap != socialAttributes.end()){
                fileToWrite << tableAttributes[iterator] << ":" << iteratorMap->second << "\t";
            }
            else{
                fileToWrite << tableAttributes[iterator] << ": 0" << "\t";
            }
        }

        if((iterator - 2) % 3 == 0){
            iteratorMap = mentalAttributes.find(tableAttributes[iterator]);

            if(iteratorMap != mentalAttributes.end()){
                fileToWrite << "\t" << tableAttributes[iterator] << ":" << iteratorMap->second << "\n";
            }
            else{
                fileToWrite << "\t" << tableAttributes[iterator] << ": 0" << "\n";
            }
        }

    }

}


void vampireGameproject::Picturemodifying::writeResultsAbilities(std::ofstream& fileToWrite){
    fileToWrite << "\n";
    fileToWrite << "<------------------------------------------Abilities------------------------------------------->" << std::endl;
    fileToWrite << "Talents\tSkills\t\tKnowledges" << std::endl;

    std::string tableAbilities[] = {"Alertness", "Animal Ken", 
        "Academics", "Athletics", "Crafts", "Computer", "Awareness", 
            "Drive", "Finance", "Brawl", "Etiquette", "Investigation", 
                "Empathy", "Firearms", "Law", "Expression", "Larceny", 
                    "Medicine", "Intimidation", "Melee", "Occult", 
                        "Leadership", "Performance", "Politics", 
                            "Streetwise", "Stealth", "Science", 
                                "Subterfuge", "Survival", "Technology"};


    int tableAbilitiesSize = 30;

    std::map<std::string, int> talentsAbilities = CharacterReference.getAbilties("talents");
    std::map<std::string, int> skillsAbilities = CharacterReference.getAbilties("skills");
    std::map<std::string, int> knowledgesAbilities = CharacterReference.getAbilties("knowledges");

    std::map<std::string, int>::iterator iteratorMap;





    for(int iterator = 0; iterator < tableAbilitiesSize; iterator++){
        if (iterator % 3 == 0){
            iteratorMap = talentsAbilities.find(tableAbilities[iterator]);

            if(iteratorMap != talentsAbilities.end()){
                fileToWrite << tableAbilities[iterator] << ":" << iteratorMap->second << "\t";
            }
            else{
                fileToWrite << tableAbilities[iterator] << ": 0" << "\t";
            }
        }

        if ((iterator - 1) % 3 == 0){
            iteratorMap = skillsAbilities.find(tableAbilities[iterator]);

            if (iteratorMap != skillsAbilities.end()){
                fileToWrite << tableAbilities[iterator] << ":" << iteratorMap->second << "\t";
            }
            else{
                fileToWrite << tableAbilities[iterator] << ": 0" << "\t";
            }
        }

        if((iterator - 2) % 3 == 0){
            iteratorMap = knowledgesAbilities.find(tableAbilities[iterator]);

            if(iteratorMap != knowledgesAbilities.end()){
                fileToWrite << tableAbilities[iterator] << ":" << iteratorMap->second << "\n";
            }
            else{
                fileToWrite << tableAbilities[iterator] << ": 0" << "\n";
            }
        }
    }

}


void vampireGameproject::Picturemodifying::writeResultsAdvantages(std::ofstream& fileToWrite){
    fileToWrite << "\n";
    fileToWrite << "<-------------------------------------------Advantages----------------------------------------->" << std::endl;
    
    std::vector<MultiDimensionnalDataStructure*> DisciplinesVector = CharacterReference.returnDisciplines();
    std::map<std::string, int> backgroundMap = CharacterReference.getBackground();
    std::map<std::string, int> virtuesMap = CharacterReference.getVirtues();

    std::cout << "Firstdictionnary" << std::endl;

    std::map<std::string, int> DisciplinesDictionnary;

    for(int iterator = 0; iterator < (int)DisciplinesVector.size(); iterator++){

        if (iterator % 3 == 0){
            if (DisciplinesDictionnary.find(DisciplinesVector[iterator]->categorie) == DisciplinesDictionnary.end()){
                DisciplinesDictionnary.insert(std::pair<std::string, int>(DisciplinesVector[iterator]->categorie, DisciplinesVector[iterator + 2]->value));
            }

            else{
                DisciplinesDictionnary[DisciplinesVector[iterator]->categorie] += DisciplinesVector[iterator + 2]->value;
            }

        }
    }

    


    fileToWrite << "Disciplines" << std::endl;

    std::map<std::string, int>::iterator mapIterator;

    for(mapIterator = DisciplinesDictionnary.begin(); mapIterator != DisciplinesDictionnary.end(); mapIterator++){
        fileToWrite << mapIterator->first << ":" << mapIterator->second << "\n";
    }

    fileToWrite << "\n";
    fileToWrite << "Backgrounds" << std::endl;

    for(mapIterator = backgroundMap.begin(); mapIterator != backgroundMap.end(); mapIterator++){
        fileToWrite << mapIterator->first << ":" << mapIterator->second << "\n";
    }

    fileToWrite << "\n";
    fileToWrite << "Virtues" << std::endl;

    for(mapIterator = virtuesMap.begin(); mapIterator != virtuesMap.end(); mapIterator++){
        fileToWrite << mapIterator->first << ":" << mapIterator->second << "\n";
    }

    fileToWrite << "<---------------------------------------------------------------------------------------------->" << std::endl;
}


void vampireGameproject::Picturemodifying::writeResultsHumanityPathToHealth(std::ofstream& fileToWrite){
    fileToWrite << "\t<-------Humanity/Path------>\t<-------Health--------->" << std::endl;
    
    std::string HumanityPath = CharacterReference.getHumanity();
    std::string Willpower = CharacterReference.getWillpower();
    float bloodPool = CharacterReference.getBloodpool();
    std::string health = CharacterReference.getHealth();

    fileToWrite << "\t\t" << HumanityPath << "\t\t\t" << health << std::endl;
    fileToWrite << "\t<-------Willpower---------->" << std::endl;
    fileToWrite << "\t\t" << Willpower << std::endl;
    fileToWrite << "\t" << "<-------Blood pool--------->" << std::endl;
    fileToWrite << "\t\t" << bloodPool << "\t\t\t" << "<--------Weakness------->" << std::endl;
    fileToWrite << "\n";
    fileToWrite << "\t\t\t\t\t<-------Experience------>\n" << std::endl;
}


void vampireGameproject::Picturemodifying::writeResultsMeritsFlaws(std::ofstream& fileToWrite){
    fileToWrite << "<---------------------------------------Merits & Flaws----------------------------------------->" << std::endl;
    fileToWrite << "Merit&Flaws\tType\t\tCost" << std::endl;
    std::map<std::string, int> physicalMeritsFlaws = CharacterReference.returnMeritsFlaws("Physical");
    std::map<std::string, int> mentalMeritsFlaws = CharacterReference.returnMeritsFlaws("Mental");
    std::map<std::string, int> socialMeritsFlaws = CharacterReference.returnMeritsFlaws("Social");
    std::map<std::string, int> supernaturalMeritsFlaws = CharacterReference.returnMeritsFlaws("Supernatural");

    std::map<std::string, int>::iterator iteratorMap;

    if (!physicalMeritsFlaws.empty()){
        for(iteratorMap = physicalMeritsFlaws.begin(); iteratorMap!= physicalMeritsFlaws.end(); iteratorMap++){
            fileToWrite << "Physical" << "\t\t" << iteratorMap->first <<  "\t\t" << iteratorMap->second << std::endl;
        }
    }

    if (!mentalMeritsFlaws.empty()){
        for(iteratorMap = mentalMeritsFlaws.begin(); iteratorMap!= mentalMeritsFlaws.end(); iteratorMap++){
            fileToWrite << "Mental" << "\t\t" << iteratorMap->first <<  "\t\t" << iteratorMap->second << std::endl;
        }
    }

    if (!socialMeritsFlaws.empty()){
        for(iteratorMap = socialMeritsFlaws.begin(); iteratorMap!= socialMeritsFlaws.end(); iteratorMap++){
            fileToWrite << "Social" << "\t\t" << iteratorMap->first <<  "\t\t" << iteratorMap->second << std::endl;
        }
    }

    if (!supernaturalMeritsFlaws.empty()){
        for(iteratorMap = supernaturalMeritsFlaws.begin(); iteratorMap!= supernaturalMeritsFlaws.end(); iteratorMap++){
            fileToWrite << "Supernatural" << "\t\t" << iteratorMap->first <<  "\t\t" << iteratorMap->second << std::endl;
        }
    }
}


void vampireGameproject::Picturemodifying::writeResultsOthersCaracteristics(std::ofstream& fileToWrite){
    fileToWrite << "<-----------------------------------------Other Traits----------------------------------------->" << std::endl;
    fileToWrite << "\n\n";
    fileToWrite << "<--------Rituals-----------------------------------------------------------------Paths--------->" << std::endl;
    fileToWrite << "Name\tLevel\t" << std::endl;
    fileToWrite << "\n\n\n\n";
    fileToWrite << "<------------Experiance-------------------------------------------------Derangements----------->" << std::endl;
    fileToWrite << "Total:" << std::endl;
    fileToWrite << "Total Spent:" << std::endl;
    fileToWrite << "Spent On:" << std::endl;
    fileToWrite << "\n\n\n";
    fileToWrite << "<-----------------------------------------Combat----------------------------------------------->" << std::endl;
    fileToWrite << "____________________________________________________________________________________" << std::endl;
    fileToWrite << "Weapon/Attack\tDiff.\tDamage\tRane\tRate\tClip\tConceal\tArmor" << std::endl;
    fileToWrite << "____________________________________________________________________________________" << std::endl;
    fileToWrite << "____________________________________________________________________________________\tClass:" << std::endl;
    fileToWrite << "____________________________________________________________________________________\tRating:" << std::endl;
    fileToWrite << "____________________________________________________________________________________\tPenality:" << std::endl;
    fileToWrite << "____________________________________________________________________________________\tDescription:" << std::endl;
    
    for(int iterator = 0; iterator < 3; iterator++){
        fileToWrite << "____________________________________________________________________________________" << std::endl;
    }
    
    fileToWrite << "<------------------------------------Expanded Backgrounds-------------------------------------->" << std::endl;
    fileToWrite << "\tAllies\t\t\t\t\t\t\tMentor" << std::endl;
    fileToWrite << "\n\n" << std::endl;
    fileToWrite << "\tContacts\t\t\t\t\t\tResources" << std::endl;
    fileToWrite << "\n\n" << std::endl;
    fileToWrite << "\tFame\t\t\t\t\t\t\tRetainers" << std::endl;
    fileToWrite << "\n\n" << std::endl;
    fileToWrite << "\tHerd\t\t\t\t\t\t\tStatus" << std::endl;
    fileToWrite << "\n\n" << std::endl;
    fileToWrite << "\tInfluence\t\t\t\t\t\tOther()" << std::endl;
    fileToWrite << "\n\n" << std::endl;
    fileToWrite << "<---------------------------------------Possessions-------------------------------------------->" << std::endl;
    fileToWrite << "\tGear(Carried)\t\t\t\tEquipment(Owned)" << std::endl;
    fileToWrite << "\n\n" << std::endl;
    fileToWrite << "\tFeeding Grounds\t\t\tVehicles" << std::endl;
    fileToWrite << "<-----------------------------------Blood Bonds/Vinculi---------------------------------------->" << std::endl;
    fileToWrite << "Bound To\tRating\t\tBound To\tRating" << std::endl;
    fileToWrite << "\n\n" << std::endl;
    fileToWrite << "<-------------------------------------------Havens--------------------------------------------->" << std::endl;
    fileToWrite << "Location\tDescription" << std::endl;
    fileToWrite << "\n\n" << std::endl;
    fileToWrite << "<--------------------------------------------History------------------------------------------->" << std::endl;
    fileToWrite << "\t\t\t\t\t\tPrelude" << std::endl;
    fileToWrite << "\n\n";
    fileToWrite << "\t\t\t\t\t\tGoals" << std::endl;
    fileToWrite << "\n\n";
    fileToWrite << "<------------------------------------------Description----------------------------------------->" << std::endl;
    fileToWrite << "Age:" << std::endl;
    fileToWrite << "Apparent Age:" << std::endl;
    fileToWrite << "Date of Birth:" << std::endl;
    fileToWrite << "R.I.P:" << std::endl;
    fileToWrite << "Hair:" << std::endl;
    fileToWrite << "Eyes:" << std::endl;
    fileToWrite << "Race:" << std::endl;
    fileToWrite << "Nationality:" << std::endl;
    fileToWrite << "Height:" << std::endl;
    fileToWrite << "Weight:" << std::endl;
    fileToWrite << "Sex:" << std::endl;
    fileToWrite << "<-------------------------------------------Visuals-------------------------------------------->" << std::endl;
    fileToWrite << "\tCoterie Chat\t\t\t\t\t\t\tCharacterSketch" << std::endl;



}


void vampireGameproject::Picturemodifying::writeResultsFile(std::string filename){
    std::ofstream outfile(filename);
    outfile << "\t\t\t20th Anniversary Edition" << std::endl;
    outfile << "\t\t\tVAMPIRE" << std::endl;
    outfile << "\t\t\tThe Masquerade\n" << std::endl;
    outfile << "Name:" << CharacterReference.returnVampireNickName() << "\tNature:";
    outfile << CharacterReference.getNature() << "\tClan:" << CharacterReference.getClan() << std::endl;
    outfile << "Player:" << CharacterReference.getPlayername() << "\t\tDemeanor:" << CharacterReference.getNature();
    outfile << "\t\tGeneration:" << CharacterReference.getGeneration() << std::endl;
    outfile << "Chronicle:" << "\t\t" << "Concept:" << "\t\t" << "Sire:" << std::endl;
    outfile << "\n";
    writeResultsAttributes(outfile);
    writeResultsAbilities(outfile);
    std::cout << "test" << std::endl;
    writeResultsAdvantages(outfile);
    writeResultsHumanityPathToHealth(outfile);
    writeResultsMeritsFlaws(outfile);
    writeResultsOthersCaracteristics(outfile);
    outfile.close();
}

