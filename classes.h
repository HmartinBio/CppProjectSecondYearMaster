//File: classes.h
//AuthorName: Hugo 
//AuthorSurname: MARTIN

#ifndef CLASS_PROJECT_VAMPIRE_HEADER
#define CLASS_PROJECT_VAMPIRE_HEADER

#include <list>
#include <string>
#include <map>
#include <bits/stdc++.h>

namespace vampireGameproject{

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

///////////////////////////////////////////////////////////////////////////////////////////

     class Attributes{
        public:
            Attributes();
            ~Attributes();
            std::map<std::string,int> getAttributes(char attributeTable);
            void setAttributes(char tableName, std::string attributeName, int value);

        private:
            std::map<std::string,int> physicalAttributes;
            std::map<std::string,int> socialAttributes;
            std::map<std::string,int> mentalAttributes;
    };

    class Abilities{
        public:
            Abilities();
            ~Abilities();
            std::map<std::string,int> getAbilities(char tableName);
            void setAbilities(char tableName,std::string abilitieName, int value);

        private:
            std::map<std::string,int> talents;
            std::map<std::string,int> skills;
            std::map<std::string,int> knowledges;
    };

    class Advantages{
        public:
            Advantages();
            ~Advantages();
            std::map<std::string, int> getAdvantages(char tableName);
            void setAdvantages(char tableName, std::string abilitieName, int value);

        private:
            std::map<std::string, int> backgrounds;
            std::map<std::string, int> virtues;
    };


///////////////////////////////////////////////////////////////////////////////////////////

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
            //std::map<char,int> socialMerits;
            //std::map<char,int> socialFlaws;
            //std::map<char,int> physicalMerits;
            //std::map<char,int> physicalFlaws;
            //std::map<char,int> mentalMerits;
            //std::map<char,int> mentalFlaws;
            //std::map<char,int> supernaturalMerits;
            //std::map<char,int> supernaturalFlaws;
    };


    class Health{
        public:
            Health();
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

    class CharacterTraits{
        public:
            CharacterTraits();
            ~CharacterTraits();
            std::string getHumanity(void);
            std::string getWillpower(void); 
            std::string getBloodpool(void);
            void setHumanity(int number); 
            void setWillpower(int number);
            void setBloodpool(int number); // Il faut tenir compte de la generation


        private:
            int humanity;
            int willPower;
            int bloodPool;
    };


////////////////////////////////////////////////////////////////////////////////////////////////
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

    
    class Daemenor {
        public:
            Daemenor();
            ~Daemenor();
            std::string getDaemenor(void);
            void setDaemenor(std::string daemenor);
            void setDescription(void); 

        private:
            std::string daemenor;
            std::string description;
            Parsetext& textParser;
    };

    
    class Nature {
        public:
            Nature(const Parsetext &textParser);
            ~Nature();
            std::string getNature(void);
            void setNature(std::string nature);
            void setDescription(void); 

        private:
            std::string nature;
            std::string description;
            Parsetext& textParser;

    };


    class Chronicle {
        public:
            Chronicle();
            ~Chronicle();
            std::string getChronicle(void);
            void setChronicle(std::string chronicle);
            void setDescription(void); 

        private:
            std::string chronicle;
            std::string description;
            Parsetext& textParse;
    };

    class Clan {
        public:
            Clan();
            ~Clan();
            std::string getClan(void);
            void setClan(std::string clan);
            void setVampirename(char name);
            std::string getVampirename(void);
            void setDescription(void); 

        private:
            std::string clan;
            std::string description;
            std::map<char,std::map<char, int>> disciplines;
            std::string vampireName;
            Parsetext& textParse;
    };

    class Generation {
        public:
            Generation();
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
            Parsetext& textParse;
    };


    class RulesofGame{
        public:
            RulesofGame();
            ~RulesofGame();

        private:
    };
         

/////////////////////////////////////////////////////////////////////////////////////////////////

    class Gui{
        public:
            Gui();
            ~Gui();
        private:
    };

/////////////////////////////////////////////////////////////////////////////////////////////////

// The second function parse_text aims to get the description of a skill, 
// a virtue, etc... proper to the character
// The function is not contained in each class but in the controller

    class Controllor{
        public:
            Controllor();
            ~Controllor();

        private:
            std::list<char> ListofInformationstoParse;
            Parsetext textParser;
    };
////////////////////////////////////////////////////////////////////////////////////////////////////

    class Parsetext{
        public:
            std::string parse_text(char categorie);
            std::string parse_text(char categorie, char table, char nameOfcomptence);
    };

}
#endif