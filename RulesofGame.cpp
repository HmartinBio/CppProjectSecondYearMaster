#include "classes.h"


/** Constructor of the class RulesofGame.
*
* Modification of the constructor of RulesofGame
* Initialisation of a Gui reference 
* before the Nature constructor be initialised
*
* @param classReference reference of the Gui class containing RulesofGame class
*/

vampireGameproject::RulesofGame::RulesofGame(Parsetext& parserReference, Gui& classReference): parser(parserReference), referenceOutterclass(classReference){}


/** Destructor of the class RulesofGame.
*
* Modification of the destructor of RulesofGame
*
*
*
*/


vampireGameproject::RulesofGame::~RulesofGame(){}

void vampireGameproject::RulesofGame::setVectorClans(){
    vectorClans = parser.parse_listClans();
}

void vampireGameproject::RulesofGame::setVectorNature(){
    vectorNature = parser.parse_listNature();
}

std::vector<std::string>& vampireGameproject::RulesofGame::returnVectorClans(){
    return vectorClans;
}

std::vector<std::string>& vampireGameproject::RulesofGame::returnVectorNature(){
    return vectorNature;
}

//void vampireGameproject::RulesofGame::setLimitSpinButton(vampireGameproject::ButtonmultiInput& buttonMultiInputReference, int limit){
//    buttonMultiInputReference.setLimitSpinButton(limit);
//}

//void vampireGameproject::RulesofGame::setLimitSpinButtonAttributes(int limit){
//    setLimitSpinButton(referenceOutterclass.returnAttributesInput(), limit);
//}

void vampireGameproject::RulesofGame::setVectorMultiInput(std::vector<std::string>& vectorInput){}



void vampireGameproject::RulesofGame::setLimitPointsAttributes(int PhysicalPoints, int SocialPoints, int MentalPoints, int TalentsPoints,
    int SkillsPoints, int KnowledgesPoints){
    limitPointsAttributes.insert(std::pair<std::string, int>("Physical", PhysicalPoints));
    limitPointsAttributes.insert(std::pair<std::string, int>("Social", SocialPoints));
    limitPointsAttributes.insert(std::pair<std::string, int>("Mental", MentalPoints));
    limitPointsAttributes.insert(std::pair<std::string, int>("Talents", TalentsPoints));
    limitPointsAttributes.insert(std::pair<std::string, int>("Skills", SkillsPoints));
    limitPointsAttributes.insert(std::pair<std::string, int>("Knowledges", KnowledgesPoints));
}

std::map<std::string, int> vampireGameproject::RulesofGame::returnLimitPointsAttributes(){
    return limitPointsAttributes;
}