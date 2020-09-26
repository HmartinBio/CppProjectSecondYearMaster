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


     class Attributes{
        public:
            std::map<char,int> getAttributes(void);
            void setAttributes(char tableName,char attributeName, int value);

        private:
            std::map<char,int> physicalAttributes;
            std::map<char,int> socialAttributes;
            std::map<char,int> mentalAttributes;
    };

    class Abilities{
        public:
            std::map<char,int> getAbilities(void);
            void setAbilities(char tableName,char abilitieName, int value);

        private:
            std::map<char,int> talents;
            std::map<char,int> skills;
            std::map<char,int> knowledges;
    };

    class Advantages{
        public:
            std::map<char,int> getAdvantages(void);
            void setAdvantages(char tableName,char advantageName, int value);

        private:
            std::map<char,int> disciplines;
            std::map<char,int> backgrounds;
            std::map<char,int> virtues;
    };

    class Meritsflows{
        public: 
            std::map<char,int> getMerits(void);
            std::map<char,int> getFlaws(void);
            std::map<char,int> setMerits;
            std::map<char,int> setFlaws;

        private:
            std::map<char,int> Merits;
            std::map<char,int> Flaws;
    };


    class Health{
        public: 
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


    class setCharacterFields{
        public:
            void setCategorie(std::string categorie, std::string& variable);
            std::string getCategorie(void);
            void setDescription(std::string description, std::string classType);
            std::string getDescription(void);
    };


    class Clan : public setCharacterFields{
        public:
            std::string getClan(void);
            std::string setClan(void);
        private:
            std::string clan;
            std::string description;
    };

    class Daemenor : public setCharacterFields{
        public:
            std::string getDaemenor(void);
            std::string setDaemenor(void); 

        private:
            std::string demeanor;
            std::string description;
    };

    class Generation : public setCharacterFields{
        public:
            std::string getGeneration(void);
            std::string setGeneration(void); 

        private:
            std::string generation;
            std::string description;
    };



    class Nature : public setCharacterFields{
        public:
            std::string getNature(void);
            void setNature(std::string nature);

        private:
            std::string nature;
            std::string description;
    };


    class Chronicle : public setCharacterFields{
        public:
            std::string getChronicle(void);
            void setChronicle(std::string chronicle);

        private:
            std::string chronicle;
            std::string description;
    };
         

    class Gui{};



    class Controllor{
        public:
            std::string parse_text(char categorie);

        private:
            std::list<char> ListofInformationstoParse;
    };

    


   // class Nature{
   //     public:
   //         const std::string returnChoicenature; 

   //     private:
   //         enum choiceNature;
   // }

    //class Demeanor{
    //    public:
    //        const std::string returnChoicedemeanor;
    //    private:
    //        enum choiceDemeanor;
   // }

   

    //class Abilities{
    //    public:

     //   private:
     //       enum abilityCategories;
    //}

    //class Avantages{
    //    public:

    //    private:
    //}

    //class Controlor{
    //    public:

    //    private:
    //}

    //class Merits_flows{
    //    public:

    //    private:
    //}

    
}
#endif