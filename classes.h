#ifndef CLASS_PROJECT_VAMPIRE_HEADER
#define CLASS_PROJECT_VAMPIRE_HEADER

#include <list>
#include <string>
#include <map>

namespace vampireGameproject{

    class Character{
        private:
            string nature;
            string playerName;
            string chronicle;
            int age;
            string demeanor;
            string clan;
            string generation;
        
        public:
            void setterNature;
            string getNature;
            string getPlayername;
            string getChronicle;
            int getAge;
            string getDemeanor;
            string getClan;
            string getGeneration;
        
    };


     class Attributes{
        public:
            map<char,int> getAttributes;
            void setAttributes;

        private:
            map<char,int> physicalAttributes;
            map<char,int> socialAttributes;
            map<char,int> mentalAttributes;
    };

    class Abilities{
        public:
            map<char,int> getAbilities;
            void setAbilities;

        private:
            map<char,int> Talents;
            map<char,int> Skills;
            map<char,int> Knowledges;
    };

    class Advantages{
        public:
            map<char,int> getAdvantages;
            void setAdvantages;


        private:
            map<char,int> Disciplines;
            map<char,int> Backgrounds;
            map<char,int> Virtues;
    };

    class Meritsflows{
        public: 

        private:
            map<char,int> Merits;
            map<char,int> Flaws;
    };


    class Health{
        public: 
            int getPointlife;
            list<char> getWeakness;

        private:
            int pointLife;
            list<char> weakness;

    };

    class CharacterTraits{
        public:
            string getHumanity;
            string getWillpower; 
            string getBloodpool;


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