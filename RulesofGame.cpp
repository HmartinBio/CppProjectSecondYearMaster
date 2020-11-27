#include "classes.h"


/** Constructor of the class RulesofGame.
*
* Modification of the constructor of RulesofGame
* Initialisation of a Gui reference 
* before the Nature constructor be initialised
*
* @param parserReference: Reference of ParseText object 
* @param classReference: reference of the Gui class containing RulesofGame class
*/

vampireGameproject::RulesofGame::RulesofGame(Parsetext& parserReference, Gui& classReference): parser(parserReference), referenceOutterclass(classReference){}


/** Destructor of the class RulesofGame.
*
* Modification of the destructor of RulesofGame*/


vampireGameproject::RulesofGame::~RulesofGame(){}



/** Implementation of the setVectorClans method.
*
* Implementation of the setVectorClans method
* Method*/



void vampireGameproject::RulesofGame::setVectorClans(){
    vectorClans = parser.parse_listClans();
}



/** Implementation of the setVectorNature method.
*
* Implementation of the setVectorNature method
* Method*/


void vampireGameproject::RulesofGame::setVectorNature(){
    vectorNature = parser.parse_listNature();
}




/** Implementation of the returnVectorClans method.
*
* Implementation of the returnVectorClans method
* Method allowign to return vector of Clans*/



std::vector<std::string>& vampireGameproject::RulesofGame::returnVectorClans(){
    return vectorClans;
}




/** Implementation of the returnVectorNature method.
*
* Implementation of the returnVectorNature method
* Method allowign to return vector of Nature*/







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





/** Implementation of the setLimitiPointsAttributes method.
*
* Implementation of the setLimitPointsAttributes method
* Method allowing to set the limiti points of the Spin Box in the Gui
*
* @param PhysicalPoints: Limit of Physical Points 
* @param SocialPoints: Limit of Social Points 
* @param MentalPoints: Limit of Mental Points  
* @param TalentsPoints: Limit of Talents Points 
* @param SkillsPoints: Limit of Skills Points  
* @param KnowledgesPoints: Limit of Knowledges Points  
* @param AnimalismPoints: Limit of Animalism Points  
* @param  AuspexPoints: Limit of Auspex Points 
* @param CelerityPoints: Limit of Celerity Points 
* @param ChimerstryPoints: Limit of Chimertstry Points 
* @param DementationPoints: Limit of Dementation Points 
* @param DominatePoints: Limit of Dominate Points 
* @param FortitudePoints: Limit of Fortitude Points 
* @param NecromancyPoints: Limit of Necromancy Points 
* @param ObfuscatePoints: Limit of Obfuscate Points 
* @param ObtenebrationPoints: Limit of Obtenebration Points 
* @param PotencePoints: Limit of Potence Points 
* @param PresencePoints: Limit of Presence Points 
* @param ProteanPoints: Limit of Protean Points 
* @param QuietusPoints: Limit of Quietus Points 
* @param SerpentisPoints: Limit of Serpentis Points 
* @param ThaumaturgyPoints: Limit of Thaumaturgy Points 
* @param VicissitudePoints: Limit of Vicissitude Points 
* @param AlliesPoints: Limit of Allies Points 
* @param AlternateIdentityPoints: Limit of Alternate Identity Points 
* @param BlackHandMembershipPoints: Limit of Black Hand Membership Points 
* @param ContactsPoints: Limit of Contacts Points 
* @param DomainPoints: Limit of Domain Points 
* @param FamePoints: Limit of Fame Points 
* @param GenerationPoints: Limit of Generation Points 
* @param HerdPoints: Limit of Herd Points 
* @param InfluencePoints: Limit of Influence Points 
* @param MentorPoints: Limit of Mentor Points 
* @param ResourcesPoints: Limit of Resources Points 
* @param RetainersPoints: Limit of Retainers Points 
* @param RitualsPoints: Limit of Rituals Points 
* @param StatusPoints: Limit of Status Points 
* @param ConsciencePoints: Limit of Conscience Points 
* @param SelfControlPoints: Limit of Self-Control Points 
* @param CouragePoints: Limit of Courage Points 
* @param SupernaturalPoints: Limit of Supernatural Points 
*/






void vampireGameproject::RulesofGame::setLimitPointsAttributes(int PhysicalPoints, int SocialPoints, int MentalPoints, int TalentsPoints,
    int SkillsPoints, int KnowledgesPoints, int AnimalismPoints, int AuspexPoints, int CelerityPoints, int ChimerstryPoints, 
        int DementationPoints, int DominatePoints, int FortitudePoints, int NecromancyPoints, int ObfuscatePoints, int ObtenebrationPoints, 
            int PotencePoints, int PresencePoints, int ProteanPoints, int QuietusPoints, int SerpentisPoints, int ThaumaturgyPoints, 
            int VicissitudePoints, int AlliesPoints, int AlternateIdentityPoints, int BlackHandMembershipPoints, int ContactsPoints, 
                int DomainPoints, int FamePoints, int GenerationPoints, int HerdPoints, int InfluencePoints, int MentorPoints, 
                    int ResourcesPoints, int RetainersPoints, int RitualsPoints, int StatusPoints, int ConsciencePoints, 
                        int SelfControlPoints, int CouragePoints, int SupernaturalPoints, int DaimoinonPoints, int SanginusPoints, 
                            int MelpomineePoints, int FlightPoints, int TemporisPoints, int OghamPoints){
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
                        limitPointsAttributes.insert(std::pair<std::string, int>("Daimoinon", DaimoinonPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Sanginus", SanginusPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Melpominee", MelpomineePoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Flight", FlightPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Temporis", TemporisPoints));
                        limitPointsAttributes.insert(std::pair<std::string, int>("Ogham", OghamPoints));
}





/** Implementation of the returnLimitiPointsAttributes method.
*
* Implementation of the returnLimitPointsAttributes method
* Method returning the dictionnary containing the Points Limit
* for all the fields in the interface **/



std::map<std::string, int> vampireGameproject::RulesofGame::returnLimitPointsAttributes(){
    return limitPointsAttributes;
}