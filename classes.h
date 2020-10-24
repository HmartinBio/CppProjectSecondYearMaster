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
            std::map<std::string,int> getMerits(std::string type);
            std::map<std::string,int> getFlaws(std::string type);
            void setMerits(std::string table, std::string meritsName, int number);
            void setFlaws(std::string table, std::string flawsName, int number);
            std::string getDescription(std::string table, std::string attributeName);

        private:
            std::map<std::string, std::map<std::string, int>> merits;
            std::map<std::string, std::map<std::string, int>> flaws;
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
            int getPointlife(void);
            std::vector<std::string> getWeakness(void);
            void setPointlife(int pointLife);
            void setWeakness(std::string weakness);
            void setPointlifeDescription(void);
            std::string getPointlifeDescription(void);

        private:
            int pointLife;
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
            int getBloodpool(void);
            void setHumanity(int number); 
            void setWillpower(int number);
            void setBloodpool(int number); // Il faut tenir compte de la generation


        private:
            int humanity;
            int willPower;
            int bloodPool;
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
            void setVampirename(void);
            std::string getVampirename(void);
            void setDescription(void); 
            std::string getDescription(void);
            void setDisciplines(std::map<std::string,std::map<std::string, int>> disciplines);
            std::map<std::string,std::map<std::string, int>> getDisciplines(void);

        private:
            std::string clan;
            std::string description;
            std::map<std::string,std::map<std::string, int>> disciplines;
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
            //virtual ~MultiInput();
            Gtk::ComboBoxText& returnComboBox(std::string position);
            Gtk::SpinButton& returnSpinButton();
            void setLimitSpinButton(int limit);
            void AddText(std::string vectorPosition, std::string stringToAdd, int index);
            void DeleteText(std::string vectorPosition, int index);
            int returnSpinScore();
            std::string returnTextComboBox(std::string index);
    
        private:
            Gtk::ComboBoxText firstComboBox;
            Gtk::ComboBoxText secondComboBox;
            Gtk::SpinButton spinButton;
    };



    class ButtonmultiInput{
            public:
                ButtonmultiInput();
                virtual ~ButtonmultiInput();
                Gtk::Button& returnButton(std::string sign);
                Gtk::ComboBoxText& returnComboBox(std::string position);
                Gtk::SpinButton& returnSpinButton();
                void setLabelMultiComboBox();
                std::vector<MultiInput*> returnVectorMultiInput();
                void setDicoSelectedInput();
                void setVectorComboBox(std::vector<std::string>& vectorText, std::string index);
                void setDicoScoreFirstComboBox();
                void setMultiInput();
                void deleteMultiInput();
                void setCoordinates(int coordinateX, int coordinateY);
                std::map<std::string, int> returnDicoScoreFirstComboBox();
                std::map<std::string, std::string> returnDicoSelectedInput();
                int xcoordinates;
                int ycoordinates; 


            private:
                Gtk::Button plusButton; 
                Gtk::Button minusButton;
                Gtk::ComboBoxText firstComboBox;
                Gtk::ComboBoxText secondComboBox;
                Gtk::SpinButton spinButton;
                std::vector<MultiInput*> vectorMultiInputs;
                std::map<std::string, std::string> DicoSelectedInputs;
                std::vector<std::string> vectorFirstComboBox;
                std::vector<std::string> vectorSecondComboBox;
                std::map<std::string, int> DicoScoreFirstComboBox;
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
            ButtonmultiInput& returnAttributesInput();
            void showAll();

        private:
            Gtk::Grid mainGrid; 
            RulesofGame& testGui;
            Gtk::Label tableLabel[4];
            Gtk::ComboBoxText tableComboBox[2];
            ButtonmultiInput attributesInput;


            
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
            void setLimitSpinButton(vampireGameproject::ButtonmultiInput& buttonMultiInputReference, 
                int limit);
            void setLimitSpinButtonAttributes(int limit);
            Parsetext& parser;
            void setVectorMultiInput(std::vector<std::string>& vectorInput);

        private:
            Gui& referenceOutterclass;
            std::vector<std::string> vectorClans;
            std::vector<std::string> vectorNature;
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

        private:
            Parsetext textParser;
            RulesofGame rulesGame;
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
            
    };




    class Picturemodifying{
        public:
            Picturemodifying();
            ~Picturemodifying();

        private:
    };

}

#endif