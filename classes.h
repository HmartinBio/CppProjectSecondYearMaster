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

#include <list>
#include <string>
#include <map>
#include <bits/stdc++.h> // imported to make multidimensional map


namespace vampireGameproject{

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
            
        public:
            std::string getPlayername(void);
            void setPlayername(std::string name);
            Character(Parsetext& textParser);
            ~Character();
            Chronicle characterChronicle;
            Attributes characterAttributes;
            Abilities characterAbilities;
            Advantages characterAdvantages;
            Meritsflows characterMeritsflows;
            Nature characterNature;
            Health characterHealth;
            CharacterTraits characterTraits;
            Generation characterGeneration;
            Daemenor characterDaemenor;
            Clan characterClan;
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
            Attributes();
            ~Attributes();
            std::map<std::string,int> getAttributes(std::string attributeTable);
            void setAttributes(std::string tableName, std::string attributeName, int value);

        private:
            std::map<std::string,int> physicalAttributes;
            std::map<std::string,int> socialAttributes;
            std::map<std::string,int> mentalAttributes;
    };



/**
 * Implementation of the Class Abilities
 *
 * Attributes class is designed such as all the attributes of a character 
 * are contained in this class.
 *  
 * 
 *
 */



    class Abilities{
        public:
            Abilities();
            ~Abilities();
            std::map<std::string,int> getAbilities(std::string tableName);
            void setAbilities(std::string tableName,std::string abilitieName, int value);

        private:
            std::map<std::string,int> talents;
            std::map<std::string,int> skills;
            std::map<std::string,int> knowledges;
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
            Advantages();
            ~Advantages();
            std::map<std::string, int> getAdvantages(std::string tableName);
            void setAdvantages(std::string tableName, std::string abilitieName, int value);

        private:
            std::map<std::string, int> backgrounds;
            std::map<std::string, int> virtues;
    };



/**
 * Implementation of the Class Meritsflows
 *
 * Meritsflows class is designed such as all the Merits and Flows of a character 
 * are contained in this class
 *  
 * 
 *
 */


    class Meritsflows{
        public: 
            Meritsflows();
            ~Meritsflows();
            std::map<std::string,int> getMerits(std::string type);
            std::map<std::string,int> getFlaws(std::string type);
            void setMerits(std::string table, std::string meritsName, int number);
            void setFlaws(std::string table, std::string flawsName, int number);

        private:
            std::map<std::string, std::map<std::string, int>> merits;
            std::map<std::string, std::map<std::string, int>> flaws;
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
            std::string getWeakness(void);
            void setPointlife(int pointLife);
            void setWeakness(char weakness);
            void setPointlifeDescription(void);
            std::string getPointlifeDescription(void);

        private:
            int pointLife;
            std::string weakness;
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
            CharacterTraits();
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
    };


/* 
    class setCharacterFields{
        public:
            setCharacterFields();
            void setCategorie(std::string categorie, std::string& variable);
            std::string getCategorie(void);
            void setDescription(std::string description);
            std::string getDescription(void);
    };
 */


/**
 * Implementation of the Class Daemenor
 *
 * Daemenor class is designed such as the Daemenor information of a character 
 * is contained in this class
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

        private:
            std::string daemenor;
            std::string description;
            Parsetext& textParser;
    };


/**
 * Implementation of the Class Nature
 *
 * Nature class is designed such as all the Nature information of a character 
 * is contained in this class
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
 * is contained in this class
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

        private:
            std::string clan;
            std::string description;
            std::map<char,std::map<char, int>> disciplines;
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

        private:
            std::string generation;
            std::string description;
            int age;
            Parsetext& textParser;
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
            RulesofGame();
            ~RulesofGame();

        private:
            Gui& graphicalInterface;
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




    class Gui{
        public:
            Gui();
            ~Gui();
        private:
            RulesofGame& testGui;
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

        private:
            std::list<std::string> ListofInformationstoParse;
            Parsetext textParser;
    };


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
            std::string parse_text(char categorie);
            std::string parse_text(char categorie, char table, char nameOfcomptence);
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
            Picturemodifying();
            ~Picturemodifying();

        private:
    };

}

#endif