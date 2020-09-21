#ifndef CLASS_PROJECT_VAMPIRE_HEADER
#define CLASS_PROJECT_VAMPIRE_HEADER

#include <list>
#include <string>
#include <map>

namespace project{

    class Clan{
        public:
            const std::string returnChoiceclans;
            const std::list<std::string> returnChoicepowers;

        private:
            enum existingClans;
            enum powers;
           

    };

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