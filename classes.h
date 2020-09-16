#ifndef CLASSES_HEADER
#define CLASSES_HEADER

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
            std::string returnChoice; 

        private:
            enum choiceNature;
    }

    class Demeanor{
        public:
            std::string returnChoice;
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

    class Personnage{
        public:

        private:
    }
}
#endif