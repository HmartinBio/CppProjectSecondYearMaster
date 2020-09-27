//File: classes.h
//AuthorName: Hugo 
//AuthorSurname: MARTIN

#ifndef CLASS_PROJECT_VAMPIRE_HEADER
#define CLASS_PROJECT_VAMPIRE_HEADER

#include <list>
#include <string>
#include <map>

namespace vampireGameproject{

    class Character{
        private:
            char playerName;
            int age;
        
        public:
            void setAge(int age);
            char getPlayername(void);
            int getAge(void);
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
            std::map<char,int> getAttributes(char attributeTable);
            void setAttributes(char tableName,char attributeName, int value);

        private:
            std::map<char,int> physicalAttributes;
            std::map<char,int> socialAttributes;
            std::map<char,int> mentalAttributes;
    };

    class Abilities{
        public:
            Abilities();
            std::map<char,int> getAbilities(void);
            void setAbilities(char tableName,char abilitieName, int value);

        private:
            std::map<char,int> talents;
            std::map<char,int> skills;
            std::map<char,int> knowledges;
    };

    class Advantages{
        public:
            Advantages();
            std::map<char,int> getAdvantages(void);
            void setAdvantages(char tableName,char advantageName, int value);

        private:
            std::map<char,std::map<char, int>> disciplines;
            std::map<char,int> backgrounds;
            std::map<char,int> virtues;
    };


///////////////////////////////////////////////////////////////////////////////////////////

    class Meritsflows{
        public: 
            Meritsflows();
            std::map<char,int> getMerits(char type);
            std::map<char,int> getFlaws(char type);
            void setMerits(char table);
            void setFlaws(char table);

        private:
            std::map<char, std::map<char, int>> Merits;
            std::map<char, std::map<char, int>> Flaws; 
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

        private:
            int pointLife;
            std::list<char> weakness;

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
        private:
            std::string clan;
            std::string description;
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

        private:
            std::string generation;
            std::string description;
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