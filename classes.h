#ifndef CLASS_PROJECT_VAMPIRE_HEADER
#define CLASS_PROJECT_VAMPIRE_HEADER

#include <list>
#include <string>
#include <map>

namespace vampireGameproject{

    class Character{
        private:
            std::string nature;
            char playerName;
            std::string chronicle;
            int age;
            std::string demeanor;
            std::string clan;
            std::string generation;
        
        public:
            void setNature(std::string nature);
            void setChronicle(std::string chronicle);
            void setDemeanor(std::string demeanor); 
            void setClan(std::string clan);
            void setGeneration(std::string generation);
            void setAge(int age);
            std::string getNature(void);
            char getPlayername(void);
            std::string getChronicle(void);
            int getAge(void);
            std::string getDemeanor(void);
            std::string getClan(void);
            std::string getGeneration(void);
            Attributes characterAttributes;
            Abilities characterAbilities;
            Advantages characterAdvantages;
            Meritsflows characterMeritsflows;
            Health characterHealth;
            CharacterTraits characterTraits;
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

    class Clan{
        public:

        private:
            std::string clan;
            std::string description;
    };

    class Daemenor{
        public: 

        private:
            std::string demeanor;
            std::string description;
    };

    class Generation{
        public:

        private:
            std::string generation;
    };


    class Parsing{
        public: 
            std::map<char,std::string> parse_text(char categorie);
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