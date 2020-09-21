#ifndef CLASS_PROJECT_VAMPIRE_HEADER
#define CLASS_PROJECT_VAMPIRE_HEADER

#include <list>
#include <string>

namespace project{
    class Concept{
        public:
            const std::string returnChoiceconcept;

        private:
            enum choiceConcept;

    };
    
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
            int age;
        
        public:
            void setterNature;
            string getNature;
            int getAge;

        
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

   // class Attributs{
   //     public:

   //     private:
   //         enum categories;
   //         std::list<pair<std::string,int>> attributes;
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