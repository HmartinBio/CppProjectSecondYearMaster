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
            char playerName;
            
        public:
            char getPlayername(void);
            Character();
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
            std::map<std::string,int> getAbilities(char tableName);
            void setAbilities(char tableName,char abilitieName, int value);

        private:
            std::map<std::string,int> talents;
            std::map<std::string,int> skills;
            std::map<std::string,int> knowledges;
    };

    class Advantages{
        public:
            Advantages();
            std::map<std::string, int> getAdvantages(char tableName);
            void setAdvantages(char tableName,char advantageName, int value);

        private:
            std::map<std::string, int> backgrounds;
            std::map<std::string, int> virtues;
    };


///////////////////////////////////////////////////////////////////////////////////////////

    class Meritsflows{
        public: 
            Meritsflows();
            std::map<std::string,int> getMerits(char type);
            std::map<std::string,int> getFlaws(char type);
            void setMerits(char table, char meritsName, int number);
            void setFlaws(char table, char flawsName, int number);

        private:
            std::map<std::string, std::map<std::string, int>> Merits;
            std::map<std::string, std::map<std::string, int>> Flaws; 
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
            int getPointlife(void);
            std::list<char> getWeakness(void);
            void setPointlife(int pointLife);
            void setWeakness(char weakness);
            void setPointlifeDescription(std::string description);
            std::string getPointlifeDescription(void);

        private:
            int pointLife;
            std::list<char> weakness;
            std::string pointLifedescription;
    };

    class CharacterTraits{
        public:
            CharacterTraits();
            std::string getHumanity(void);
            std::string getWillpower(void); 
            std::string getBloodpool(void);
            void setHumanity(); 
            void setWillpower();
            void setBloodpool();


        private:
            int humanity;
            int willPower;
            int bloodPool;
    };


////////////////////////////////////////////////////////////////////////////////////////////////

    class setCharacterFields{
        public:
            setCharacterFields();
            void setCategorie(std::string categorie, std::string& variable);
            std::string getCategorie(void);
            void setDescription(std::string description);
            std::string getDescription(void);
    };


    class Clan : public setCharacterFields{
        public:
            Clan();
            std::string getClan(void);
            std::string setClan(void);
            void setVampirename(char name);
            char getVampirename(void);

        private:
            std::string clan;
            std::string description;
            std::map<char,std::map<char, int>> disciplines;
            char vampireName;
    };

    class Daemenor : public setCharacterFields{
        public:
            Daemenor();
            std::string getDaemenor(void);
            std::string setDaemenor(void); 

        private:
            std::string demeanor;
            std::string description;
    };

    class Generation : public setCharacterFields{
        public:
            Generation();
            std::string getGeneration(void);
            std::string setGeneration(void); 
            int getAge(void);
            void setAge(int age);

        private:
            std::string generation;
            std::string description;
            int age;

    };



    class Nature : public setCharacterFields{
        public:
            Nature();
            std::string getNature(void);
            void setNature(std::string nature);

        private:
            std::string nature;
            std::string description;
    };


    class Chronicle : public setCharacterFields{
        public:
            Chronicle();
            std::string getChronicle(void);
            void setChronicle(std::string chronicle);

        private:
            std::string chronicle;
            std::string description;
    };

    class RulesofGame{
        public:

        private:
    };
         

/////////////////////////////////////////////////////////////////////////////////////////////////

    class Gui{};

/////////////////////////////////////////////////////////////////////////////////////////////////

// The second function parse_text aims to get the description of a skill, 
// a virtue, etc... proper to the character
// The function is not contained in each class but in the controller

    class Controllor{
        public:
            Controllor();
            std::string parse_text(char categorie);
            std::string parse_text(char categorie, char table, char nameOfcomptence);

        private:
            std::list<char> ListofInformationstoParse;
    };
////////////////////////////////////////////////////////////////////////////////////////////////////

}
#endif