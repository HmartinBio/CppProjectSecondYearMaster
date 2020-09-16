#ifndef CLASS_PROJECT_VAMPIRE_HEADER
#define CLASS_PROJECT_VAMPIRE_HEADER

#include <list>
#include <string>

namespace project{
    class Clan{
        public:
            std::string returnChoiceclans;
            std::list<std::string> returnChoicepowers;

        private:
            enum existingClans;
            enum powers;
    }

    class Nature{
        public:
            std::string returnChoicenature; 

        private:
            enum choiceNature;
    }

    class Demeanor{
        public:
            std::string returnChoicedemeanor;
        private:
            enum choiceDemeanor;
    }

    class Attributs{
        public:

        private:
            enum categories;
            std::list<pair<std::string,int>> attributes;
    }

    class Abilities{
        public:

        private:
            enum abilityCategories;
    }

    class Avantages{
        public:

        private:
    }

    class Controlor{
        public:

        private:
    }

    class Merits_flows{
        public:

        private:
    }

    class Character{
        public:

        private:
    }
}
#endif