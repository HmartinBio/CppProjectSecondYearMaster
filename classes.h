/**
 * @file classes.h
 *
 * @brief Header file containing the class prototypes of the Game project
 *
 * @ingroup PackageName
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Hugo MARTIN
 * Contact: hugo.martin.1@etu.univ-amu.fr
 *
 */


#ifndef CLASS_PROJECT_VAMPIRE_HEADER
#define CLASS_PROJECT_VAMPIRE_HEADER

#include <string>
#include <map>
#include <bits/stdc++.h> // imported to make multidimensional map
#include <vector>
#include "pystring.h"
#include <fstream>
#include <regex>
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/grid.h>
#include <gtkmm/label.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/application.h>
#include <gtkmm/button.h>
#include <gtkmm/misc.h>
#include <gtkmm.h>
#include <glibmm/ustring.h>

namespace vampireGameproject{



/**
 * Implementation of the Class Parsetext
 *
 * Parsetext class is designed to retrieve some informations in a text file 
 * The others class have a reference of the Parsetext class to avoid to 
 * copy a same function in several classes
 * 
 *
 */


    class Parsetext{
        public:
            Parsetext();
            ~Parsetext();
            std::string parse_text(std::string categorie);
            std::string parse_text(std::string categorie, std::string caracteristics);
            std::string parse_text(std::string categorie, std::string table, std::string nameOfcomptence);
            std::vector<std::string> parse_listClans(void);
            std::vector<std::string> parse_listNature(void);
            std::string parse_NicknameClan(std::string clanName);
            std::vector<std::string> parse_ClanDisciplines(std::string clanName);
            std::vector<std::string> parse_Attributes();
            std::vector<std::string> parse_AttributesCategorie(std::string categorie);
            std::vector<std::string> parse_Abilities();
            std::vector<std::string> parse_AbilitiesCategorie(std::string categorieToGet);
            std::vector<std::string> parse_Backgrounds();
            std::vector<std::string> parse_ClanDisciplinesCategorie(std::string categorie);
            std::vector<std::string> parse_Viritues();
            std::vector<std::string> parse_MeritsFlaws();
            std::vector<std::string> parse_MeritsFlawsCategorie(std::string categorie);
            std::vector<std::string> parse_Health();
    };



/**
 * Implementation of the Class Attributes
 *
 * Attributes class is designed such as all the attributes of a character 
 * are contained in this class
 *  
 * 
 *
 */


     class Attributes{
        public:
            Attributes(Parsetext& textParser);
            ~Attributes();
            std::map<std::string,int> getAttributes(std::string attributeTable);
            void setAttributes(std::string tableName, std::string attributeName, int value);
            std::string getDescriptionattributes(std::string table, std::string attributeName);

        private:
            std::map<std::string,int> physicalAttributes;
            std::map<std::string,int> socialAttributes;
            std::map<std::string,int> mentalAttributes;
            Parsetext& textParser;
    };



/**
 * Implementation of the Class Abilities
 *
 * Abilities class is designed such as all the abilities of a character 
 * are contained in this class.
 *  
 * 
 *
 */


    class Abilities{
        public:
            Abilities(Parsetext& textParser);
            ~Abilities();
            std::map<std::string,int> getAbilities(std::string tableName);
            void setAbilities(std::string tableName,std::string abilitieName, int value);
            std::string getDescriptionabilities(std::string table, std::string attributeName);

        private:
            std::map<std::string,int> talents;
            std::map<std::string,int> skills;
            std::map<std::string,int> knowledges;
            Parsetext& textParser;
    };


/**
 * Implementation of the Class Advantages
 *
 * Advantages class is designed such as all the abilities of a character 
 * are contained in this class
 *  
 * 
 *
 */


    class Advantages{
        public:
            Advantages(Parsetext& textParser);
            ~Advantages();
            std::map<std::string, int> getAdvantages(std::string tableName);
            void setAdvantages(std::string tableName, std::string abilitieName, int value);
            std::string getDescriptionadvantages(std::string table, std::string attributeName);

        private:
            std::map<std::string, int> backgrounds;
            std::map<std::string, int> virtues;
            Parsetext& textParser;
    };



/**
 * Implementation of the Class Meritsflaws
 *
 * Meritsflaws class is designed such as all the Merits and Flaws of a character 
 * are contained in this class
 *  
 * 
 *
 */


    class Meritsflaws{
        public: 
            Meritsflaws(Parsetext& textParser);
            ~Meritsflaws();
            std::map<std::string,int> getMeritsFlaws(std::string type);
            void setMeritsFlaws(std::string table, std::string meritsFlawName, int number);
            std::string getDescription(std::string table, std::string attributeName);

        private:
            std::map<std::string, std::map<std::string, int>> meritsFlaws;
            Parsetext& textParser;
    };



/**
 * Implementation of the Class Health
 *
 * Health class is designed such as weakness and point of life 
 * of the character are contained in this class
 *  
 * 
 *
 */


    class Health{
        public:
            Health(Parsetext& textParser);
            ~Health();
            std::string getPointlife(void);
            std::vector<std::string> getWeakness(void);
            void setPointlife(std::string pointLife);
            void setWeakness(std::string weakness);
            void setPointlifeDescription(void);
            std::string getPointlifeDescription(void);

        private:
            std::string pointLife;
            std::vector<std::string> weakness;
            std::string pointLifedescription;
            Parsetext& textParser;
    };


/**
 * Implementation of the Class CharacterTraits
 *
 * CharacterTraits class is designed such as Humanity/Path, Bloodpool
 * and Willpower fields of a character are contained in this class
 *  
 * 
 *
 */


    class CharacterTraits{
        public:
            CharacterTraits(Parsetext& textParser);
            ~CharacterTraits();
            std::string getHumanity(void);
            std::string getWillpower(void); 
            float getBloodpool(void);
            void setHumanity(int number); 
            void setWillpower(int number);
            void setBloodpool(float number); // Il faut tenir compte de la generation


        private:
            int humanity;
            int willPower;
            float bloodPool;
            Parsetext& textParser;
    };





/**
 * Implementation of the Class Daemenor
 *
 * Daemenor class is designed such as the Daemenor informations of a character 
 * are contained in this class
 *  
 * 
 *
 */



    class Daemenor {
        public:
            Daemenor(Parsetext& textParser);
            ~Daemenor();
            std::string getDaemenor(void);
            void setDaemenor(std::string daemenor);
            void setDescription(void);
            std::string getDescription(void);

        private:
            std::string daemenor;
            std::string description;
            Parsetext& textParser;
    };


/**
 * Implementation of the Class Nature
 *
 * Nature class is designed such as all the Nature informations of a character 
 * are contained in this class
 *  
 * 
 *
 */

 
    class Nature {
        public:
            Nature(Parsetext& textParser);
            ~Nature();
            std::string getNature(void);
            void setNature(std::string nature);
            void setDescription(void);
            std::string getDescription(void); 

        private:
            std::string nature;
            std::string description;
            Parsetext& textParser;

    };


/**
 * Implementation of the Class Chronicle
 *
 * Chronicle class is designed such as the information 
 * dealing with the set of stories followed by a character 
 * are contained in this class
 * 
 *
 */



    class Chronicle {
        public:
            Chronicle(Parsetext& textParser);
            ~Chronicle();
            std::string getChronicle(void);
            void setChronicle(std::string chronicle);
            void setDescription(void);
            std::string getDescription(void); 

        private:
            std::string chronicle;
            std::string description;
            Parsetext& textParser;
    };


union MultiDimensionnalDataStructure{
    MultiDimensionnalDataStructure(std::string categorieToEnter);
    MultiDimensionnalDataStructure(int categorieValue);
    ~MultiDimensionnalDataStructure();
    std::string categorie;
    int value;
};






/**
 * Implementation of the Class Clan
 *
 * Clan class is designed such as all informations 
 * concerning or linked to the clan of a character 
 * are contained in this class 
 * 
 *
 */



    class Clan {
        public:
            Clan(Parsetext& textParser);
            ~Clan();
            std::string getClan(void);
            void setClan(std::string clan);
            void setVampirename(std::string vampireNickName);
            std::string getVampirename(void);
            void setDescription(void); 
            std::string getDescription(void);
            //void setDisciplines(std::map<std::string,std::map<std::string, int>> disciplines);
            void setDisciplines(std::vector<MultiDimensionnalDataStructure*> disciplines);
            //std::map<std::string,std::map<std::string, int>> getDisciplines(void);
            std::vector<MultiDimensionnalDataStructure*> getDisciplines();

        private:
            std::string clan;
            std::string description;
            //std::map<std::string,std::map<std::string, int>> disciplines;
            std::vector<MultiDimensionnalDataStructure*> disciplines;
            std::string vampireName;
            Parsetext& textParser;
    };


/**
 * Implementation of the Class Generation
 *
 * Generation class is designed such as all the informations 
 * related to the generation of a character are contained in this class
 *  
 * 
 *
 */



    class Generation {
        public:
            Generation(Parsetext& textParser);
            ~Generation();
            std::string getGeneration(void);
            void setGeneration(std::string generation); 
            int getAge(void);
            void setAge(int age);
            void setDescription(void);
            std::string getDescription(void);

        private:
            std::string generation;
            std::string description;
            int age;
            Parsetext& textParser;
    };


    class MultiInput{
        public:
            MultiInput();
            virtual ~MultiInput();
            Gtk::ComboBoxText& returnComboBox(std::string position);
            Gtk::SpinButton& returnSpinButton();
            void setLimitSpinButton(int limit);
            void AddText(std::string vectorPosition, std::string stringToAdd, int index);
            void DeleteText(std::string vectorPosition, int index);
            int returnSpinScore();
            std::string returnTextComboBox(std::string index);
            void setVectorComboBox(std::vector<std::string>& vectorText, std::string index);
            void setComboBoxFunction(std::string index);
            void unsetActiveText();
            void resetSpinScore();

        private:
            Gtk::ComboBoxText firstComboBox;
            Gtk::ComboBoxText secondComboBox;
            Gtk::SpinButton spinButton;
    };


    class Controllor;

    class ButtonmultiInput{
            public:
                ButtonmultiInput();
                virtual ~ButtonmultiInput();
                Gtk::Button& returnButton(std::string sign);
                //
                //Gtk::ComboBoxText& returnComboBox(std::string position);
                //Gtk::SpinButton& returnSpinButton();
                //
                void setLabelMultiComboBox();
                std::vector<MultiInput*>& returnVectorMultiInput();
                void setVectorSelectedInput();
                void setDicoScoreFirstComboBox();
                void setMultiInput();
                void deleteMultiInput();
                void setCoordinates(int coordinateX, int coordinateY);
                std::map<std::string, int> returnDicoScoreFirstComboBox();
                std::vector<std::string> returnVectorSelectedInput(std::string index);
                void setLimitMultiInput();
                void setComboBoxFunction(std::string index);
                void setFunctionForComboBox(std::string index, std::vector<std::string> (&functionToSet)());
                void setVectorComboBox(int index, std::string position, std::vector<std::string> vectorReference);
                void initialize();
                void setNumberMultiInput(int number);
                std::string returnTextComboBox(int number, std::string index);
                void deleteItemDicoSelectedInput(std::string item);
                int returnXCoordinate();
                int returnYCoordinate();
                void setCounter();
                void increaseNumberMultiInput();
                void deacreaseNumberMultiInput();
                int returnNumberMultiInput();

            private:
                Gtk::Button plusButton;
                Gtk::Button minusButton;
                Gtk::ComboBoxText firstComboBox;
                Gtk::ComboBoxText secondComboBox;
                Gtk::SpinButton spinButton;
                std::vector<MultiInput*> vectorMultiInputs;
                std::map<std::string, std::string> DicoSelectedInputs;
                std::vector<std::string> vectorFirstComboBoxSelectedInputs;
                std::vector<std::string> vectorSecondComboBoxSelectedInputs;
                int SecondComboBoxItemsNumber;
                int xcoordinates;
                int ycoordinates;
                std::map<std::string, int> DicoScoreFirstComboBox;
                std::vector<std::string> (*functionForComboBoxOne)();
                std::vector<std::string> (*functionForSecondComboBox)(std::string categorie);
                void (*functionForSpinButton)();
                //Controllor* ControllorAddress;
                int numberMultiInput;
                std::string dataToParse;
    };




class MultiInputOneComboBox{
        public:
            MultiInputOneComboBox();
            virtual ~MultiInputOneComboBox();
            Gtk::ComboBoxText& returnComboBox();
            Gtk::SpinButton& returnSpinButton();
            void setLimitSpinButton(int limit);
            //void AddText(std::string vectorPosition, std::string stringToAdd, int index);
            //void DeleteText(std::string vectorPosition, int index);
            int returnSpinScore();
            std::string returnTextComboBox();
            void setVectorComboBox(std::vector<std::string>& vectorText);
            void setComboBoxFunction(std::string index);
            void unsetActiveText();
            void resetSpinScore();

        private:
            Gtk::ComboBoxText ComboBox;
            Gtk::SpinButton spinButton;
    };












class ButtonmultiInputOneComboBox{
            public:
                ButtonmultiInputOneComboBox();
                virtual ~ButtonmultiInputOneComboBox();
                Gtk::Button& returnButton(std::string sign);
                //
                //Gtk::ComboBoxText& returnComboBox(std::string position);
                //Gtk::SpinButton& returnSpinButton();
                //
                void setLabelMultiComboBox();
                std::vector<MultiInputOneComboBox*>& returnVectorMultiInput();
                void setVectorSelectedInput();
                void setDicoScoreFirstComboBox();
                void setMultiInput();
                void deleteMultiInput();
                void setCoordinates(int coordinateX, int coordinateY);
                std::map<std::string, int> returnDicoScoreComboBox();
                std::vector<std::string> returnVectorSelectedInput();
                void setLimitMultiInput();
                void setComboBoxFunction(std::string index);
                void setFunctionForComboBox(std::string index, std::vector<std::string> (&functionToSet)());
                void setVectorComboBox(int index, std::vector<std::string> vectorReference);
                void initialize();
                void setNumberMultiInput(int number);
                std::string returnTextComboBox(int number);
                void deleteItemDicoSelectedInput(std::string item);
                int returnXCoordinate();
                int returnYCoordinate();
                void setCounter();
                void increaseNumberMultiInput();
                void deacreaseNumberMultiInput();
                int returnNumberMultiInput();

            private:
                Gtk::Button plusButton;
                Gtk::Button minusButton;
                Gtk::ComboBoxText firstComboBox;
                Gtk::ComboBoxText secondComboBox;
                Gtk::SpinButton spinButton;
                std::vector<MultiInputOneComboBox*> vectorMultiInputs;
                std::map<std::string, std::string> DicoSelectedInputs;
                std::vector<std::string> vectorComboBoxSelectedInputs;
                int SecondComboBoxItemsNumber;
                int xcoordinates;
                int ycoordinates;
                std::map<std::string, int> DicoScoreComboBox;
                std::vector<std::string> (*functionForComboBoxOne)();
                std::vector<std::string> (*functionForSecondComboBox)(std::string categorie);
                void (*functionForSpinButton)();
                //Controllor* ControllorAddress;
                int numberMultiInput;
                std::string dataToParse;
    };








/**
 * Implementation of the Class Gui
 *
 * Gui class is designed such as all the elements composing  
 * the graphical user interface are contained in this class
 *  
 * 
 *
 */
    class RulesofGame; 

    class Gui : public Gtk::Window{
        public:
            Gui(RulesofGame& rulesGamereference);
            virtual ~Gui();
            void setTableComboBox(int index, std::vector<std::string>& vectorElements);
            void initialiseTableLabel();
            void initialiseTableComboBox();
            void setTableLabelAlign(int index, std::string label);
            void setTableLabel(int index, std::string label);
            void setTableLabelOnGrid(int index, int xcoordinates, int ycoordinates, int width, int height);
            void setTableComboBoxOnGrid(int index, int indexLabel);
            void setMultiComboBox(Gtk::Button& buttonPlus, Gtk::Button& buttonMinus,
                Gtk::ComboBoxText& ComboFirst, Gtk::ComboBoxText& ComboSecond,
                Gtk::SpinButton& buttonSpin, int xcoordinates, int ycoordinates, int width, int height);
            
            void setMultiComboBoxAttributes(int xcoordinates, int ycoordinates, int width, int height);
            void setLabelMultiComboBoxAttributes();
            void setLabelMultiComboBoxAbilities();
            void setLabelMultiComboBoxDisciplines();
            void setLabelMultiComboBoxMeritsFlaws();
            ButtonmultiInput& returnAttributesInput();
            ButtonmultiInput& returnAbilitiesInput();
            ButtonmultiInput& returnDisciplinesInput();
            ButtonmultiInput& returnMeritsFlawsInput();
            void setMultiInputOnGrid(ButtonmultiInput& ButtonMultiInputReference, int number);
            void deleteMultiInputOnGrid(ButtonmultiInput& ButtonMultiInputReference, int number);
            void setButtonMultiInputAttributes();
            void setButtonMultiInputAbilities();
            void setButtonMultiInputDisciplines();
            void setButtonMultiInputMeritsFlaws();
            void showAll();
            ButtonmultiInputOneComboBox& returnBackgroundsInput();
            ButtonmultiInputOneComboBox& returnVirtuesInput();
            void setMultiInputOneComboBoxOnGrid(ButtonmultiInputOneComboBox& ButtonmultiInputOneComboBoxReference, int number);
            void deleteMultiInputOneComboBoxOnGrid(ButtonmultiInputOneComboBox& ButtonmultiInputOneComboBoxReference, int number);
            void setButtonMultiInputBackgrounds();
            void setButtonMultiInputVirtues();
            void setLabelMultiComboBoxBackgrounds();
            void setLabelMultiComboBoxVirtues();
            std::string returnClanName();
            Gtk::ComboBoxText& returnComboBoxClan();
            void setSpinButtonHumanityPath();
            void setSpinButtonWillPower();
            void setSpinButtonBloodPool();
            void setValidationButton();
            Gtk::SpinButton& returnHumanityPathSpinButton(); 
            Gtk::SpinButton& returnWillPowerSpinButton();
            Gtk::SpinButton& returnBloodPoolSpinButton();
            Gtk::Button& returnValidationButton();
            Gtk::Label& returnLabelVampireNickName();
            void setNicknameLabel();
            void setTextNicknameLabel(std::string textToAdd);
            std::string setFileChooser();
            std::string returnNature();
            std::string returnHealth();
            void initialiseEntryName();
            std::string returnPlayerName();       

        private:
            Gtk::Grid mainGrid; 
            RulesofGame& testGui;
            Gtk::Label tableLabel[15];
            Gtk::ComboBoxText tableComboBox[3];
            ButtonmultiInput attributesInput;
            ButtonmultiInput abilitiesInput;
            ButtonmultiInput disciplinesInput;
            ButtonmultiInput meritsFlawsInput;
            ButtonmultiInputOneComboBox backgroundsInput;
            ButtonmultiInputOneComboBox virtuesInput;
            Gtk::SpinButton HumanityPathScore;
            Gtk::SpinButton WillPowerScore;
            Gtk::SpinButton BloodPoolScore;
            Gtk::Button validationButton;
            Gtk::Entry NameEntry;      
            
    };



/**
 * Implementation of the Class RulesofGame
 *
 * RulesofGame class is designed such as all the tests 
 * to verify inputted informations on the graphical user
 * interface are contained in this class
 * 
 *
 */



    class RulesofGame{
        public:
            RulesofGame(Parsetext& parserReference, Gui& classReference);
            ~RulesofGame();
            std::vector<std::string>& returnVectorClans();
            std::vector<std::string>& returnVectorNature();
            void setVectorClans();
            void setVectorNature();
            //void setLimitSpinButton(vampireGameproject::ButtonmultiInput& buttonMultiInputReference, 
            //    int limit);
            //void setLimitSpinButtonAttributes(int limit);
            Parsetext& parser;
            void setVectorMultiInput(std::vector<std::string>& vectorInput);
            void setLimitPointsAttributes(int PhysicalPoints, int SocialPoints, int MentalPoints, int TalentsPoints,
                int SkillsPoints, int KnowledgesPoints, int AnimalismPoints, int AuspexPoints, int CelerityPoints, 
                    int ChimerstryPoints, int DementationPoints, int DominatePoints, int FortitudePoints, int NecromancyPoints, 
                        int ObfuscatePoints, int ObtenebrationPoints, int PotencePoints, int PresencePoints, int ProteanPoints, 
                            int QuietusPoints, int SerpentisPoints, int ThaumaturgyPoints, 
                                int VicissitudePoints, int AlliesPoints, int AlternateIdentityPoints, int BlackHandMembershipPoints, 
                                    int ContactsPoints, int DomainPoints, int FamePoints, int GenerationPoints, int HerdPoints, 
                                        int InfluencePoints, int MentorPoints, int ResourcesPoints, int RetainersPoints, 
                                            int RitualsPoints, int StatusPoints, int ConsciencePoints, 
                                                int SelfControlPoints, int CouragePoints, int SupernaturalPoints);

            std::map<std::string, int> returnLimitPointsAttributes();
            
        private:
            Gui& referenceOutterclass;
            std::vector<std::string> vectorClans;
            std::vector<std::string> vectorNature;
            std::map<std::string, int> dictionnaryLimitWidget;
            std::map<std::string, int> limitPointsAttributes;
            
    };
         












/**
* Implementation of the Class Character
*
* Character class is designed such as all the informations concerning a
* playable character are written in this class. Once this class is created
* all the informations contained in a Character object are extracted to 
* modify the character picture. Character object are created once the 
* Graphical user interface received all the informations to create a character
*/

    class Character{
        private:
            std::string playerName;
            Chronicle characterChronicle;
            Attributes characterAttributes;
            Abilities characterAbilities;
            Advantages characterAdvantages;
            Meritsflaws characterMeritsflaws;
            Nature characterNature;
            Health characterHealth;
            CharacterTraits characterTraits;
            Generation characterGeneration;
            Daemenor characterDaemenor;
            Clan characterClan;
            
        public:
            std::string getPlayername(void);
            void setPlayername(std::string name);
            Character(Parsetext& textParser);
            ~Character();
            void setAttributes(std::string firstComboBoxItem, 
                std::string secondComboBoxItem, int SpinScore);
            std::map<std::string,int> getAttributes(std::string firstComboBoxItem);
            void setAbilities(std::string firstComboBoxItem, 
                std::string secondComboBoxItem, int SpinScore);
            std::map<std::string, int> getAbilties(std::string FirstComboBoxItem);
            void setMeritsflaws(std::string firstComboBoxItem, 
                std::string secondComboBoxItem, int SpinScore);
            std::map<std::string, int> returnMeritsFlaws(std::string FirstComboBoxItem);
            void setNature(std::string ComboBoxItem);
            std::string getNature();
            void setHealth(std::string ComboBoxItem);
            std::string getHealth();
            void setGeneration(float SpinScoreButton);
            std::string getGeneration();
            void setClan(std::string ComboBoxItem);
            std::string getClan();
            void setBackground(std::string ComboBoxItem, int SpinScore);
            std::map<std::string, int> getBackground();
            void setVirtues(std::string ComboBoxItem, int spinScore);
            std::map<std::string, int> getVirtues();
            void setHumanity(int number);
            std::string getHumanity();
            void setWillpower(int number);
            std::string getWillpower();
            void setBloodpool(float number);
            float getBloodpool();
            //void setDisciplines(std::map<std::string,std::map<std::string, int>> disciplines);
            //std::map<std::string,std::map<std::string, int>> returnDisciplines();
            void setDisciplines(std::vector<MultiDimensionnalDataStructure*> disciplines);
            std::vector<MultiDimensionnalDataStructure*> returnDisciplines();
            
            void setVampireNickName(std::string Nickname);
            std::string returnVampireNickName();
    };




/**
 * Implementation of the Class Picturemodifying
 *
 * Picturemodifying class is designed to modify the picture to include  
 * all the information about a character. Once the graphical user interface
 * received all the informations about a character, Picturemodifying modifies 
 * the picture to generate a picture with all the informations about a character
 *
 */


    class Picturemodifying{
        public:
            Picturemodifying(Character& ReferenceCharacter);
            ~Picturemodifying();
            void writeResultsFile(std::string filename);
            void writeResultsAttributes(std::ofstream& fileToWrite);
            void writeResultsAbilities(std::ofstream& fileToWrite);
            void writeResultsAdvantages(std::ofstream& fileToWrite);
            void writeResultsHumanityPathToHealth(std::ofstream& fileToWrite);
            void writeResultsMeritsFlaws(std::ofstream& fileToWrite);
            void writeResultsOthersCaracteristics(std::ofstream& fileToWrite);

        private:
            Character& CharacterReference;
    };
















// The second function parse_text aims to get the description of a skill, 
// a virtue, etc... proper to the character
// The function is not contained in each class but in the controller


/**
 * Implementation of the Class Controllor
 *
 * Controllor class is designed to control the coordination between the  
 * graphical user interface and the other functionalities of the program
 *  
 * 
 *
 */


    class Controllor{
        public:
            Controllor();
            ~Controllor();
            Gui graphicalUserinterface;
            void testAttributesInputsFirstComboBox(int number);
            void testInputsSecondComboBox(ButtonmultiInput& ButtonMultiInputReference, int number, std::string categorieMultiInput);
            void testInputsFirstComboBoxSpinButton(ButtonmultiInput& ButtonMultiInputReference, int number);
            void testInputsFirstComboBoxChangingItems(ButtonmultiInput& ButtonMultiInputReference, int number);
            void initializeButtonMultiInputReference(ButtonmultiInput& ButtonMultiInputReference, 
                std::string categorieMultiInput);
            void initializeButtonMultiInput(std::string categorieMultiInput);
            //void testInputsSecondComboBox(ButtonmultiInput& ButtonMultiInputReference);
            void AttributesInputsSecondComboBox();
            void testInputSecondComboBoxForGui(int number, std::string categorieMultiInput);
            void testInputSecondComboBoxChosenItems(ButtonmultiInput& ButtonMultiInputReference, int number, std::string categorieMultiInput);
            void testInputSpinButton(ButtonmultiInput& ButtonMultiInputReference, int number);
            void setMultiInput(std::string categorieMultiInput);
            void deleteMultiInput(std::string categorieMultiInput);
            void setVectorSecondComboBox(std::string ComboBoxFirstValue);
            void testFirstComboBoxDisponibility(std::string categorieMultiInput);
            void testInputFirstComboBoxForGui(int number, std::string categorieMultiInput);
            void testInputSpinButtonForGui(int number, std::string categorieMultiInput);
            void testInputSpinButtonWhenRemoved(std::string categorieMultiInput);
            void testInputPlusButtonForGui(std::string categorieMultiInput);
            void testInputMinusButtonForGui(std::string categorieMultiInput);
            void setCounter();
            void initializeButtonMultiInputOneComboBox(std::string categorieMultiInput);
            void initializeButtonMultiInputReferenceOneComboBox(ButtonmultiInputOneComboBox& ButtonMultiInputOneComboBoxReference, 
                std::string categorieMultiInputOneComboBox);
            void testInputsFirstComboBoxChangeItemsOneComboBox(ButtonmultiInputOneComboBox& ButtonmultiInputOneComboBoxReference, int number);
            void testInputSpinButtonOneComboBox(ButtonmultiInputOneComboBox& ButtonMultiInputOneComboBoxReference, int number);
            void testClanButton();
            void initializeSpinButton(std::string categorieSpinButton);
            void initializeFinalButton();
            void initializeNicknameLabel();
            void updateNicknameLabel();
            void initializeHealthComboBox();
            void submitUserChoices();
            void saveAttributesInCharacter();
            void saveAbilitiesInCharacter();
            void saveDisciplinesInCharacter();
            void saveBackgroundsInCharacter();
            void saveVirtuesInCharacter();
            void saveMeritsFlawsCharacter();
            void saveUserChoices();


        private:
            Parsetext textParser;
            RulesofGame rulesGame;
            Character CharacterToCreate;
            Picturemodifying createResultsFile;
    };
}

#endif