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
            void setNature;
            void setChronicle;
            void setDemeanor; 
            void setClan;
            void setGeneration;
            std::string getNature;
            char getPlayername;
            std::string getChronicle;
            int getAge;
            std::string getDemeanor;
            std::string getClan;
            std::string getGeneration;
            Attributes characterAttributes;
            Abilities characterAbilities;
            Advantages characterAdvantages;
            Meritsflows characterMeritsflows;
            Health characterHealth;
            CharacterTraits characterTraits;
    };


     class Attributes{
        public:
            std::map<char,int> getAttributes;
            void setAttributes;

        private:
            std::map<char,int> physicalAttributes;
            std::map<char,int> socialAttributes;
            std::map<char,int> mentalAttributes;
    };

    class Abilities{
        public:
            std::map<char,int> getAbilities;
            void setAbilities;

        private:
            std::map<char,int> talents;
            std::map<char,int> skills;
            std::map<char,int> knowledges;
    };

    class Advantages{
        public:
            std::map<char,int> getAdvantages;
            void setAdvantages;

        private:
            std::map<char,int> disciplines;
            std::map<char,int> backgrounds;
            std::map<char,int> virtues;
    };

    class Meritsflows{
        public: 
            std::map<char,int> getMerits;
            std::map<char,int> getFlaws;

        private:
            std::map<char,int> Merits;
            std::map<char,int> Flaws;
    };


    class Health{
        public: 
            int getPointlife;
            std::list<char> getWeakness;
            void setPointlife;
            void setWeakness;

        private:
            int pointLife;
            std::list<char> weakness;

    };

    class CharacterTraits{
        public:
            std::string getHumanity;
            std::string getWillpower; 
            std::string getBloodpool;


        private:
            int humanity;
            int willPower;
            int bloodPool;
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