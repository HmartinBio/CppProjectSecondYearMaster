#include "classes.h"

/** Constructor of the class Character.
*
* Modification of the Constructor of Character
* for this one gives the Parsetext reference to 
* the other class members contained in Character 
*
* @param textParse: reference of Parsetext
*/


vampireGameproject::Character::Character(Parsetext& textParser)
    : characterChronicle(textParser), characterAttributes(textParser),
    characterAbilities(textParser), characterAdvantages(textParser),
    characterMeritsflaws(textParser), characterNature(textParser),
    characterHealth(textParser), characterTraits(textParser),
    characterGeneration(textParser), characterDaemenor(textParser), 
    characterClan(textParser){}



/** Destructor of the class Character.
*
* Modification of the Destructor of Character  
*
*/


vampireGameproject::Character::~Character(){}



/** Implementation of the getPlayername method.
*
* Implementation of the getPlayername method
* Method returning the player name 
*  
*
*/



std::string vampireGameproject::Character::getPlayername(void){
    return playerName;
}



/** Implementation of the setPlayername method.
*
* Implementation of the setPlayername method
* Method modifing the attribute playerName of the class
*
* @param name: string to assign to playerName
*/


void vampireGameproject::Character::setPlayername(std::string name){
    playerName = name;
}





/** Implementation of the setAttributes method.
*
* Implementation of the setAttributes method
* Method setting the attributes in the Character object
*
* @param firstComboBoxItem: string extracted from the FirstComboBoxText on the interface
* @param secondComboBoxItem: string extracted from the SecondComboBoxText on the interface
* @param SpinScore: Spin Score extracted from the interface
*/


void vampireGameproject::Character::setAttributes(std::string firstComboBoxItem, 
                std::string secondComboBoxItem, int SpinScore){
                    characterAttributes.setAttributes(firstComboBoxItem, 
                        secondComboBoxItem, SpinScore);
                }




/** Implementation of the getAttributes method.
*
* Implementation of the getAttributes method
* Method getting the attributes in the Character object
*
* @param firstComboBoxItem: type of Attributes to retrieve
*/


std::map<std::string, int> vampireGameproject::Character::getAttributes(std::string firstComboBoxItem){
    return characterAttributes.getAttributes(firstComboBoxItem);
}





/** Implementation of the setAbilities method.
*
* Implementation of the setAbilities method
* Method setting the abilities in the Character object
*
* @param firstComboBoxItem: string extracted from the FirstComboBoxText on the interface
* @param secondComboBoxItem: string extracted from the SecondComboBoxText on the interface 
* @param SpinScore: Spin Score extracted from the interface
*/





void vampireGameproject::Character::setAbilities(std::string firstComboBoxItem, 
                std::string secondComboBoxItem, int SpinScore){
                    characterAbilities.setAbilities(firstComboBoxItem, secondComboBoxItem, SpinScore);
                }





/** Implementation of the getAbilities method.
*
* Implementation of the getAbilities method
* Method getting the abilities from the Character object
*
* @param firstComboBoxItem: type of Abilities to retrieve
*/





std::map<std::string, int> vampireGameproject::Character::getAbilties(std::string FirstComboBoxItem){
    return characterAbilities.getAbilities(FirstComboBoxItem);
}




/** Implementation of the setMeritsFlaws method.
*
* Implementation of the setMeritsFlaws method
* Method setting the Merits and Flaws in the Character object
*
* @param firstComboBoxItem: string extracted from the FirstComboBoxText on the interface
* @param secondComboBoxItem: string extracted from the SecondComboBoxText on the interface 
* @param SpinScore: Spin Score extracted from the interface
*/



void vampireGameproject::Character::setMeritsflaws(std::string firstComboBoxItem, 
                std::string secondComboBoxItem, int SpinScore){
                    characterMeritsflaws.setMeritsFlaws(firstComboBoxItem, secondComboBoxItem, SpinScore);

}




/** Implementation of the returnMeritsFlaws method.
*
* Implementation of the returnMeritsFlaws method
* Method getting the Merits and Flaws from the Character object
*
* @param firstComboBoxItem: type of Merits and Flaws to retrieve
*/




std::map<std::string, int> vampireGameproject::Character::returnMeritsFlaws(std::string FirstComboBoxItem){
    return characterMeritsflaws.getMeritsFlaws(FirstComboBoxItem);
}





/** Implementation of the setNature method.
*
* Implementation of the setNature method
* Method setting the Nature in the Character object
*
* @param ComboBoxItem: string extracted from the ComboBox on the interface
*/



void vampireGameproject::Character::setNature(std::string ComboBoxItem){
    characterNature.setNature(ComboBoxItem);
}




/** Implementation of the getNature method.
*
* Implementation of the getNature method
* Method getting the Nature from the Character object */




std::string vampireGameproject::Character::getNature(){
    return characterNature.getNature();
}




/** Implementation of the setHealth method.
*
* Implementation of the setHealth method
* Method setting the Health in the Character object
*
* @param ComboBoxItem: string extracted from the ComboBoxText on the interface
*/



void vampireGameproject::Character::setHealth(std::string ComboBoxItem){
    characterHealth.setPointlife(ComboBoxItem);
}




/** Implementation of the getHealth method.
*
* Implementation of the getHealth method
* Method getting the Health from the Character object */




std::string vampireGameproject::Character::getHealth(){
    return characterHealth.getPointlife();
}




/** Implementation of the setGeneration method.
*
* Implementation of the setGeneration method
* Method setting the Generation in the Character object
*
* @param SpinScoreButton: SpinScore extracted from the Spin Button on the interface
*/




void vampireGameproject::Character::setGeneration(float SpinScoreButton){
    if (SpinScoreButton == 0.25){
        characterGeneration.setGeneration("Bat/Rat");
    }

    if (SpinScoreButton == 0.5){
        characterGeneration.setGeneration("Bird");
    }

    if (SpinScoreButton > 0.5 && SpinScoreButton < 1){
        characterGeneration.setGeneration("Plasma Bag");
    }

    if (SpinScoreButton >= 1 && SpinScoreButton < 2){
        characterGeneration.setGeneration("Cat");
    }

    if (SpinScoreButton >= 2 && SpinScoreButton < 5){
        characterGeneration.setGeneration("Dog");
    }

    if (SpinScoreButton >=5 && SpinScoreButton < 10){
        characterGeneration.setGeneration("Child");
    }

    if (SpinScoreButton == 10){
        characterGeneration.setGeneration("Average Human");
    }

    if (SpinScoreButton > 10 && SpinScoreButton < 20){
        characterGeneration.setGeneration("Vampire");
    }

    if (SpinScoreButton == 20){
        characterGeneration.setGeneration("Werewolf");
    }
}




/** Implementation of the getGeneration method.
*
* Implementation of the getGeneration method
* Method getting the Generation from the Character object */





std::string vampireGameproject::Character::getGeneration(){
    return characterGeneration.getGeneration();
}




/** Implementation of the setClan method.
*
* Implementation of the setClan method
* Method setting the Clan in the Character object
*
* @param ComboBoxItem: string extracted from the ComboBoxText on the interface
*/





void vampireGameproject::Character::setClan(std::string ComboBoxItem){
    characterClan.setClan(ComboBoxItem);
}




/** Implementation of the getClan method.
*
* Implementation of the getClan method
* Method getting the Clan from the Character object */




std::string vampireGameproject::Character::getClan(){
    return characterClan.getClan();
}





/** Implementation of the setBackground method.
*
* Implementation of the setBackground method
* Method setting the Background in the Character object
*
* @param ComboBoxItem: string extracted from the ComboBoxText on the interface
* @param SpinScore: SpinScore extracted from the Spin Button on the interface
*/





void vampireGameproject::Character::setBackground(std::string ComboBoxItem, int SpinScore){
    characterAdvantages.setAdvantages("backgrounds", ComboBoxItem, SpinScore);
}




/** Implementation of the getBackground method.
*
* Implementation of the getBackground method
* Method getting the Background from the Character object */




std::map<std::string, int> vampireGameproject::Character::getBackground(){
    return characterAdvantages.getAdvantages("backgrounds");
}




/** Implementation of the setVirtues method.
*
* Implementation of the setVirtues method
* Method setting the Virtues in the Character object
*
* @param ComboBoxItem: string extracted from the ComboBoxText on the interface
* @param spinScore: SpinScore extracted from the Spin Button on the interface
*/





void vampireGameproject::Character::setVirtues(std::string ComboBoxItem, int spinScore){
    characterAdvantages.setAdvantages("virtues", ComboBoxItem, spinScore);
}




/** Implementation of the getVirtues method.
*
* Implementation of the getVirtues method
* Method getting the Virtues from the Character object */




std::map<std::string, int> vampireGameproject::Character::getVirtues(){
    return characterAdvantages.getAdvantages("virtues");
}




/** Implementation of the setHumanity method.
*
* Implementation of the setHumanity method
* Method setting the Humanity in the Character object
*
* @param number: Humanity/Path value to set
*/




void vampireGameproject::Character::setHumanity(int number){
    characterTraits.setHumanity(number);
}





/** Implementation of the getHumanity method.
*
* Implementation of the getHumanity method
* Method getting the Humanity/Path from the Character object */





std::string vampireGameproject::Character::getHumanity(){
    return characterTraits.getHumanity();
}



/** Implementation of the setWillpower method.
*
* Implementation of the setWillpower method
* Method setting the Willpower in the Character object
*
* @param number: Willpower value to set
*/



void vampireGameproject::Character::setWillpower(int number){
    characterTraits.setWillpower(number);
}




/** Implementation of the getWillpower method.
*
* Implementation of the getWillpower method
* Method getting the Willpower from the Character object */




std::string vampireGameproject::Character::getWillpower(){
    return characterTraits.getWillpower();
}




/** Implementation of the setBloodpool method.
*
* Implementation of the setBloodpool method
* Method setting the Bloodpool in the Character object
*
* @param number: Bloodpool value to set
*/



void vampireGameproject::Character::setBloodpool(float number){
    characterTraits.setBloodpool(number);
}



/** Implementation of the getBloodpool method.
*
* Implementation of the getBloodpool method
* Method getting the Bloodpool from the Character object */




float vampireGameproject::Character::getBloodpool(){
   return characterTraits.getBloodpool();
}



/** Implementation of the setDisciplines method.
*
* Implementation of the setDisciplines method
* Method setting the Disciplines in the Character object
*
* @param disciplines: vector containing disciplines objects to set
*/



void vampireGameproject::Character::setDisciplines(std::vector<MultiDimensionnalDataStructure*> disciplines){
    characterClan.setDisciplines(disciplines);
}





/** Implementation of the setVampireNickName method.
*
* Implementation of the setVampireNickName method
* Method setting the Vampire Nick Name in the Character object
*
* @param Nickname: string containing the NickName of the Vampire
*/




void vampireGameproject::Character::setVampireNickName(std::string Nickname){
    characterClan.setVampirename(Nickname);
}




/** Implementation of the returnVampireNickName method.
*
* Implementation of the returnVampireNickName method
* Method getting the NickName from the Character object */



std::string vampireGameproject::Character::returnVampireNickName(){
    return characterClan.getVampirename();
}




/** Implementation of the returnDisciplines method.
*
* Implementation of the returnDisciplines method
* Method getting the Disciplines from the Character object */




std::vector<vampireGameproject::MultiDimensionnalDataStructure*> vampireGameproject::Character::returnDisciplines(){
    return characterClan.getDisciplines();
}