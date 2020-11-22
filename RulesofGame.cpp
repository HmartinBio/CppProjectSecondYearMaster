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
    int SkillsPoints, int KnowledgesPoints, int AnimalismPoints, int AuspexPoints, int CelerityPoints, int ChimerstryPoints, 
        int DementationPoints, int DominatePoints, int FortitudePoints, int NecromancyPoints, int ObfuscatePoints, int ObtenebrationPoints, 
            int PotencePoints, int PresencePoints, int ProteanPoints, int QuietusPoints, int SerpentisPoints, int ThaumaturgyPoints, 
            int VicissitudePoints, int AlliesPoints, int AlternateIdentityPoints, int BlackHandMembershipPoints, int ContactsPoints, 
                int DomainPoints, int FamePoints, int GenerationPoints, int HerdPoints, int InfluencePoints, int MentorPoints, 
                    int ResourcesPoints, int RetainersPoints, int RitualsPoints, int StatusPoints, int ConsciencePoints, 
                        int SelfControlPoints, int CouragePoints, int SupernaturalPoints){
                        limitPointsAttributes.insert(std::pair<std::string, int>("Physical", PhysicalPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Social", SocialPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Mental", MentalPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Talents", TalentsPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Skills", SkillsPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Knowledges", KnowledgesPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Animalism", AnimalismPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Auspex", AuspexPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Celerity", CelerityPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Chimerstry", ChimerstryPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Dementation", DementationPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Dominate", DominatePoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Fortitude", FortitudePoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Necromancy", NecromancyPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Obfuscate", ObfuscatePoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Obtenebration", ObtenebrationPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Potence", PotencePoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Presence", PresencePoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Protean", ProteanPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Quietus", QuietusPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Serpentis", SerpentisPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Thaumaturgy", ThaumaturgyPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Vicissitude", VicissitudePoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Allies", AlliesPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Alternate Identity", AlternateIdentityPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Black Hand Membership", BlackHandMembershipPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Contacts", ContactsPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Domain", DomainPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Fame", FamePoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Generation", GenerationPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Herd", HerdPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Influence", InfluencePoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Mentor", MentorPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Resources", ResourcesPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Retainers", RetainersPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Rituals", RitualsPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Status", StatusPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Conscience", ConsciencePoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Self-Control", SelfControlPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Courage", CouragePoints));
                         limitPointsAttributes.insert(std::pair<std::string, int>("Supernatural", SupernaturalPoints));
}

std::map<std::string, int> vampireGameproject::RulesofGame::returnLimitPointsAttributes(){
    return limitPointsAttributes;
}