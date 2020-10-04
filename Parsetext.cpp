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


std::string vampireGameproject::Parsetext::parse_text(std::string categorie){
    std::string lineOftext = "";
    std::string partOftext;
    std::ifstream infile("VampireV5.txt");
    std::string lineTofind = "#### " + categorie;
    
    while(lineOftext != lineTofind){
        std::getline(infile, lineOftext);
    }

    partOftext = categorie + "\n\n";
    std::getline(infile, lineOftext);
    partOftext += lineOftext;
    partOftext += "\n";
    
    while(pystring::startswith(lineOftext, "#") != true){
        std::getline(infile, lineOftext);
        partOftext += lineOftext;
        partOftext += "\n";
    
    infile.close();
    }
}

/**
 # @overload std::string parse_text(std::string categorie, std::string caracteristics)
 */

std::string vampireGameproject::Parsetext::parse_text(std::string categorie, std::string caracteristics){
    std::string lineOftext = "";
    std::string partOftext;
    std::ifstream infile("VampireV5.txt");
    std::string lineTofind = "#### " + categorie;
    
    while(lineOftext != lineTofind){
        std::getline(infile, lineOftext);
    }

    std::string lineTofind = "--" + caracteristics;

    while(lineOftext != lineTofind){
        std::getline(infile, lineOftext);
    }

    partOftext = caracteristics + "\n\n";
    std::getline(infile, lineOftext);
    partOftext += lineOftext;
    partOftext += "\n";
    
    while(pystring::startswith(lineOftext, "--") != true){
        std::getline(infile, lineOftext);
        partOftext += lineOftext;
        partOftext += "\n";
    
    infile.close();
    }
}


/**
 # @overload std::string parse_text(std::string categorie, std::string table, std::string nameOfcomptence)
 */


std::string vampireGameproject::Parsetext::parse_text(std::string categorie, std::string table, std::string nameOfcomptence){
    
    
    std::string lineOftext = "";
    std::string partOftext;
    std::ifstream infile("VampireV5.txt");
    std::string lineTofind = "#### " + categorie;
    
    while(lineOftext != lineTofind){
        std::getline(infile, lineOftext);
    }

    if(table == "Merits_flaws"){
        std::string lineTofind = "##" + table;
    }

    else if(table == "Disciplines"){
        std::string lineTofind = "--" + table;
    }

    

    while(lineOftext != lineTofind){
        std::getline(infile, lineOftext);
    }

    partOftext = caracteristics + "\n\n";
    std::getline(infile, lineOftext);
    partOftext += lineOftext;
    partOftext += "\n";
    
    while(pystring::startswith(lineOftext, "--") != true){
        std::getline(infile, lineOftext);
        partOftext += lineOftext;
        partOftext += "\n";
    
    infile.close();
    }
}