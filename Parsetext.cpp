#include "classes.h"


/** Constructor of the class Parsetext.
*
* Modification of the constructor of Parsetext
*
*
*
*/

vampireGameproject::Parsetext::Parsetext(){}



/** Destructor of the class Parsetext.
*
* Modification of the destructor of Parsetext
*
*
*
*/


vampireGameproject::Parsetext::~Parsetext(){}



/** Implementation of the parse_text method.
*
* Implementation of the parse_text method
* Method returning a parsed text corresponding to  
* the description of the searched element 
* 
* @param categorie categorie name to parse on the file
* 
*/

// Allows to parse all the text of a categorie (Abilities, Attributes,...)

std::string vampireGameproject::Parsetext::parse_text(std::string categorie){
    std::string lineOftext;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);

    // while we don't find the searched categorie
    // beginning by "####" we take the next line
    
    while(pystring::startswith(lineOftext, "####") != true && 
        pystring::find(lineOftext, categorie) == -1){
            std::getline(infile, lineOftext);
    }

    // we create a string to save a part of 
    // the text we want 
    
    std::string partOftext;
    partOftext = categorie + "\n\n";
    std::getline(infile, lineOftext);
    partOftext += lineOftext;
    partOftext += "\n";
    
    // while we don't reach the end of the paragraph
    // we save text the in the string

    while(pystring::startswith(lineOftext, "#") != true){
        std::getline(infile, lineOftext);
        partOftext += lineOftext;
        partOftext += "\n";
    }

    infile.close();
    return partOftext;
}

/**
 # @overload std::string parse_text(std::string categorie, std::string caracteristics)
 */

// Allows to parse Clans

std::string vampireGameproject::Parsetext::parse_text(std::string categorie, std::string caracteristics){
    std::string lineOftext;
    std::string partOftext;
    std::ifstream infile("VampireV5.txt");
    std::string lineTofind;
    // Reading the first line of the file
    std::getline(infile, lineOftext);
    
    // while we don't find the searched categorie
    // beginning by "####" we take the next line

    while(pystring::startswith(lineOftext, "####") != true && 
        pystring::find(lineOftext, categorie) == -1){
            std::getline(infile, lineOftext);
    }

    lineTofind = "--" + caracteristics;

    // while we don't find the caracteristics 
    // we take the next line of the file 

    while(pystring::startswith(lineOftext, lineTofind) != true){
        std::getline(infile, lineOftext);
    }

    // we create a string to save a part of 
    // the text we want 

    partOftext = caracteristics + "\n\n";
    std::getline(infile, lineOftext);
    partOftext += lineOftext;
    partOftext += "\n";

    // while we don't reach the end of the paragraph
    // we save text the in the string    

    while(pystring::startswith(lineOftext, "--") != true){
        std::getline(infile, lineOftext);
        partOftext += lineOftext;
        partOftext += "\n";
    }

    infile.close();
    return partOftext;
}


/**
 # @overload std::string parse_text(std::string categorie, std::string table, std::string nameOfcomptence)
 */

// allows to parse disciplines and merits_flaws

std::string vampireGameproject::Parsetext::parse_text(std::string categorie, std::string table, std::string nameOfcomptence){
    
    std::string lineOftext;
    std::string partOftext;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);

    // while we don't find the searched categorie
    // beginning by "####" we take the next line

    
    while(pystring::startswith(lineOftext, "####") != true && 
        pystring::find(lineOftext, categorie) == -1){
            std::getline(infile, lineOftext);
    }


    if(table == "Merits_flaws"){

        // while we don't find the searched table
        // beginning by "##" we take the next line

        while(pystring::startswith(lineOftext, "##") != true && 
            pystring::find(lineOftext, pystring::capitalize(table)) == -1){
                std::getline(infile, lineOftext);
            }
        
        // while we don't find the searched nameofCompetence
        // beginning by "--" we take the next line

        while(pystring::startswith(lineOftext, "--") != true && 
            pystring::find(lineOftext, nameOfcomptence) == -1){
                std::getline(infile, lineOftext);
            }
        
        // we create a string to save a part of 
        // the text we want

        partOftext = nameOfcomptence + "\n\n";
        std::getline(infile, lineOftext);
        partOftext += lineOftext;
        partOftext += "\n";

        // while we don't reach the end of the paragraph
        // we save text the in the string 

        while(pystring::startswith(lineOftext, "--") != true){
            std::getline(infile, lineOftext);
            partOftext += lineOftext;
            partOftext += "\n";
        
        }
        
        infile.close();
        return partOftext;
    }

   else if(table == "Disciplines"){
        
        // while we don't find the searched table
        // beginning by "--" we take the next line

        while((pystring::startswith(lineOftext, "--") != true) && 
            (pystring::find(lineOftext, pystring::capitalize(table)) == -1)){
                std::getline(infile, lineOftext);
        }
        
        // We create two strings to search in the line 
        // of text

        std::string stringTofind1 = ":" + nameOfcomptence;
        std::string stringTofind2 = ": " + nameOfcomptence;

        // while we don't find the searched nameofCompetence
        // beginning by "\t [0-9]:" we take the next line

        while((((pystring::startswith(lineOftext, "\t") != true) &&
            (pystring::find(lineOftext, stringTofind1) != -1)) || 
            (pystring::find(lineOftext, stringTofind2) != -1))   
            ){
                std::getline(infile, lineOftext);
        }

        // we create a string to save a part of 
        // the text we want

        partOftext = nameOfcomptence + "\n\n";
        std::getline(infile, lineOftext);
        partOftext += lineOftext;
        partOftext += "\n";

        // we create a bool to test if we are on the next paragraph

        bool testLine = std::regex_search(lineOftext, std::regex("^\t[0-9]:"));

        // while we don't reach the next paragraph
        // we save in a string the text we want

        while(testLine == false){
            std::getline(infile, lineOftext);
            partOftext += lineOftext;
            partOftext += "\n";
            testLine = std::regex_search(lineOftext,
                std::regex("^\t[0-9]:"));
        }

        infile.close();
        return partOftext;
   }

   else{
       std::cout << "ERROR, the table name is uncorrect" << std::endl;
       return "ERROR";
   }

  //  }

}


/** Implementation of the parse_listClans method.
*
* Implementation of the parse_listClans method
* Method returning the list of Clans  
* 
* 
* 
*/

// Allows to parse all the text of a categorie (Abilities, Attributes,...)

std::vector<std::string> vampireGameproject::Parsetext::parse_listClans(){
    std::string lineOftext;
    std::vector<std::string> vectorClans;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);

    // while we don't find the searched table
    // beginning by "##" we take the next line

    while(pystring::startswith(lineOftext, "####") != true || 
        pystring::find(lineOftext, "Clans") == -1){
            std::getline(infile, lineOftext);
        }

    std::getline(infile, lineOftext);
    
    while(pystring::startswith(lineOftext, "##") != true){
        std::getline(infile, lineOftext);

        if (pystring::startswith(lineOftext, "--") == true){
            lineOftext = lineOftext.substr(2, lineOftext.size());
            vectorClans.push_back(lineOftext);

        }

    }

    infile.close();

    return vectorClans;
}

std::vector<std::string> vampireGameproject::Parsetext::parse_listNature(){
    std::string lineOftext;
    std::vector<std::string> vectorNature;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);

    // while we don't find the searched table
    // beginning by "##" we take the next line

    while(pystring::startswith(lineOftext, "####") != true || 
        pystring::find(lineOftext, "Nature") == -1){
            std::getline(infile, lineOftext);
        }

    std::getline(infile, lineOftext);
    
    while(pystring::startswith(lineOftext, "##") != true){
        std::getline(infile, lineOftext);

        if (pystring::startswith(lineOftext, "--") == true){
            lineOftext = lineOftext.substr(2, lineOftext.size());
            vectorNature.push_back(lineOftext);

        }

    }

    infile.close();

    return vectorNature;
}

/** Implementation of the parse_NicknameClan method.
*
* Implementation of the parse_NicknameClan method
* Method returning a nickname corresponding to  
* a Vampire Clan 
* 
* @param clanName name of the Clan
* 
*/

// Allows to parse the Nickname of a Clan



std::string vampireGameproject::Parsetext::parse_NicknameClan(std::string clanName){
    std::string lineOftext;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);

    // while we don't find the searched table
    // beginning by "##" we take the next line

    while(pystring::startswith(lineOftext, "##") != true || 
        pystring::find(lineOftext, "Clans") == -1){
            std::getline(infile, lineOftext);
        }
    
    while(pystring::startswith(lineOftext, "--") != true || 
        pystring::find(lineOftext, clanName) == - 1){
            std::getline(infile, lineOftext);
        }
    
    
    while(pystring::find(lineOftext, "Nickname:") == - 1){
        std::getline(infile, lineOftext);
    }

    std::vector<std::string> vectorSplitter; 

    pystring::split(lineOftext, vectorSplitter, ":");

    infile.close();

    return vectorSplitter.at(1);

}


/** Implementation of the parse_NicknameClan method.
*
* Implementation of the parse_NicknameClan method
* Method returning a nickname corresponding to  
* a Vampire Clan 
* 
* @param clanName name of the Clan
* 
*/

// Allows to parse the Nickname of a Clan




std::vector<std::string> vampireGameproject::Parsetext::parse_ClanDisciplines(std::string clanName){
    std::string lineOftext;
    std::vector<std::string> vectorClansDisciplines;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);

    // while we don't find the searched table
    // beginning by "##" we take the next line

    while(pystring::startswith(lineOftext, "##") != true || 
        pystring::find(lineOftext, "Clans") == -1){
            std::getline(infile, lineOftext);
        }

    while(pystring::startswith(lineOftext, "--") != true || 
        pystring::find(lineOftext, clanName) == - 1){
            std::getline(infile, lineOftext);
        }

     while(pystring::find(lineOftext, "Clan Disciplines:") == - 1){
        std::getline(infile, lineOftext);
    }

    std::vector<std::string> vectorSplitter; 

    pystring::split(lineOftext, vectorSplitter, ":");

    pystring::split(vectorSplitter.at(1), vectorClansDisciplines, ",");

    infile.close();

    return vectorClansDisciplines;    
}


    //while(lineOftext != lineTofind){
    //    std::getline(infile, lineOftext);
    //}

    //if(table == "Merits_flaws"){
    //    std::string lineTofind = "##" + table;
    //}

    //else if(table == "Disciplines"){
    //    std::string lineTofind = "--" + table;
    //}

    //while(lineOftext != lineTofind){
    //    std::getline(infile, lineOftext);
    //}

   /*  if(table == "Merits_flaws"){
        while(pystring::startswith(lineOftext, "##") != true && 
            pystring::find(lineOftext, pystring::capitalize()  
            
            while(pystring::find(lineOftext, "####") == - 1 && 
        pystring::find(lineOftext, categorie) == -1){
            std::getline(infile, lineOftext);
    }) )
        std::string lineTofind = "##" + table;
    }

    else if(table == "Disciplines"){
        std::string lineTofind = "--" + table;
    }

    partOftext = nameOfcomptence + "\n\n";
    std::getline(infile, lineOftext);
    partOftext += lineOftext;
    partOftext += "\n";
    
    while(pystring::startswith(lineOftext, "--") != true){
        std::getline(infile, lineOftext);
        partOftext += lineOftext;
        partOftext += "\n";
    
    infile.close();
    }
} */