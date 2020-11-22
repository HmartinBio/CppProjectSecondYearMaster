#include "classes.h"


/** Constructor of the class Parsetext.
*
* Modification of the constructor of Parsetext */

vampireGameproject::Parsetext::Parsetext(){}



/** Destructor of the class Parsetext.
*
* Modification of the destructor of Parsetext */


vampireGameproject::Parsetext::~Parsetext(){}





/** Implementation of the parse_text method.
*
* Implementation of the parse_text method
* Method returning a parsed text corresponding to  
* the description of the searched element 
* 
* @param categorie: categorie name to parse on the file */

/*Allows to parse all the text of a categorie (Abilities, Attributes,...)*/





std::string vampireGameproject::Parsetext::parse_text(std::string categorie){
    std::string lineOftext;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);

    /*while we don't find the searched categorie
    beginning by "####" we take the next line*/
    
    while(pystring::startswith(lineOftext, "####") != true && 
        pystring::find(lineOftext, categorie) == -1){
            std::getline(infile, lineOftext);
    }

    /*we create a string to save a part of 
    the text we want*/ 
    
    std::string partOftext;
    partOftext = categorie + "\n\n";
    std::getline(infile, lineOftext);
    partOftext += lineOftext;
    partOftext += "\n";
    
    /*while we don't reach the end of the paragraph
    we save text the in the string*/

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

/*Allows to parse Clans*/





std::string vampireGameproject::Parsetext::parse_text(std::string categorie, std::string caracteristics){
    std::string lineOftext;
    std::string partOftext;
    std::ifstream infile("VampireV5.txt");
    std::string lineTofind;
    std::getline(infile, lineOftext);
    
    /*while we don't find the searched categorie
    beginning by "####" we take the next line*/

    while(pystring::startswith(lineOftext, "####") != true && 
        pystring::find(lineOftext, categorie) == -1){
            std::getline(infile, lineOftext);
    }

    lineTofind = "--" + caracteristics;

    /*while we don't find the caracteristics 
    we take the next line of the file*/ 

    while(pystring::startswith(lineOftext, lineTofind) != true){
        std::getline(infile, lineOftext);
    }

    /*we create a string to save a part of 
    the text we want*/ 

    partOftext = caracteristics + "\n\n";
    std::getline(infile, lineOftext);
    partOftext += lineOftext;
    partOftext += "\n";

    /*while we don't reach the end of the paragraph
    we save text the in the string*/    

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

/*allows to parse disciplines and merits_flaws*/





std::string vampireGameproject::Parsetext::parse_text(std::string categorie, std::string table, std::string nameOfcomptence){
    
    std::string lineOftext;
    std::string partOftext;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);

    /*while we don't find the searched categorie
    beginning by "####" we take the next line*/
    
    while(pystring::startswith(lineOftext, "####") != true && 
        pystring::find(lineOftext, categorie) == -1){
            std::getline(infile, lineOftext);
    }


    if(table == "Merits_flaws"){

        /*while we don't find the searched table
        beginning by "##" we take the next line*/

        while(pystring::startswith(lineOftext, "##") != true && 
            pystring::find(lineOftext, pystring::capitalize(table)) == -1){
                std::getline(infile, lineOftext);
            }
        
        /*while we don't find the searched nameofCompetence
        beginning by "--" we take the next line*/

        while(pystring::startswith(lineOftext, "--") != true && 
            pystring::find(lineOftext, nameOfcomptence) == -1){
                std::getline(infile, lineOftext);
            }
        
        /* we create a string to save a part of 
        the text we want*/

        partOftext = nameOfcomptence + "\n\n";
        std::getline(infile, lineOftext);
        partOftext += lineOftext;
        partOftext += "\n";

        /*while we don't reach the end of the paragraph
        we save text the in the string*/ 

        while(pystring::startswith(lineOftext, "--") != true){
            std::getline(infile, lineOftext);
            partOftext += lineOftext;
            partOftext += "\n";
        
        }
        
        infile.close();
        return partOftext;
    }

   else if(table == "Disciplines"){
        
        /*while we don't find the searched table
        beginning by "--" we take the next line*/

        while((pystring::startswith(lineOftext, "--") != true) && 
            (pystring::find(lineOftext, pystring::capitalize(table)) == -1)){
                std::getline(infile, lineOftext);
        }
        
        /*We create two strings to search in the line 
        of text*/

        std::string stringTofind1 = ":" + nameOfcomptence;
        std::string stringTofind2 = ": " + nameOfcomptence;

        /*while we don't find the searched nameofCompetence
        beginning by "\t [0-9]:" we take the next line*/

        while((((pystring::startswith(lineOftext, "\t") != true) &&
            (pystring::find(lineOftext, stringTofind1) != -1)) || 
            (pystring::find(lineOftext, stringTofind2) != -1))   
            ){
                std::getline(infile, lineOftext);
        }

        /*we create a string to save a part of 
        the text we want*/

        partOftext = nameOfcomptence + "\n\n";
        std::getline(infile, lineOftext);
        partOftext += lineOftext;
        partOftext += "\n";

        /*we create a bool to test if we are on the next paragraph*/

        bool testLine = std::regex_search(lineOftext, std::regex("^\t[0-9]:"));

        /*while we don't reach the next paragraph
        we save in a string the text we want*/

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

}





/** Implementation of the parse_listClans method.
*
* Implementation of the parse_listClans method
* Method returning the list of Clans */

/*Allows to parse all the text of a categorie (Abilities, Attributes,...)*/





std::vector<std::string> vampireGameproject::Parsetext::parse_listClans(){
    std::string lineOftext;
    std::vector<std::string> vectorClans;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);

    /* while we don't find the searched line
    beginning by "####" containing "Clans", 
    we take the next line*/

    while(pystring::startswith(lineOftext, "####") != true || 
        pystring::find(lineOftext, "Clans") == -1){
            std::getline(infile, lineOftext);
        }

    std::getline(infile, lineOftext);

    /* while reading line which one don't start by "##"
    and if a line begins by "--"" then, we save this line 
    in a vector*/
    
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





/** Implementation of the parse_listNature method.
*
* Implementation of the parse_listNature method
* Method returning the list of Nature */





std::vector<std::string> vampireGameproject::Parsetext::parse_listNature(){
    std::string lineOftext;
    std::vector<std::string> vectorNature;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);

    /* while we don't find the searched line
    beginning by "####" containing "Nature", 
    we take the next line*/

    while(pystring::startswith(lineOftext, "####") != true || 
        pystring::find(lineOftext, "Nature") == -1){
            std::getline(infile, lineOftext);
        }

    std::getline(infile, lineOftext);
    
    /* while the line doesn't start by "##", we get the line, if the 
    line begins by "--", we save it in a vector*/

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
* @param clanName: name of the Clan*/





std::string vampireGameproject::Parsetext::parse_NicknameClan(std::string clanName){
    std::string lineOftext;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);

    /* while we don't find the searched line
    beginning by "##" containing "Clans", 
    we take the next line*/

    while(pystring::startswith(lineOftext, "##") != true || 
        pystring::find(lineOftext, "Clans") == -1){
            std::getline(infile, lineOftext);
        }
    
    /*while the line doesn't starts with "--", if we don't find the
    the name of the clan in the line,we read the next line*/

    while(pystring::startswith(lineOftext, "--") != true || 
        pystring::find(lineOftext, clanName) == - 1){
            std::getline(infile, lineOftext);
        }
    
    /*while we don't read the line with the Nickname of the clan, 
    we read the next line*/
    
    while(pystring::find(lineOftext, "Nickname:") == - 1){
        std::getline(infile, lineOftext);
    }

    std::vector<std::string> vectorSplitter; 

    pystring::split(lineOftext, vectorSplitter, ":");

    infile.close();

    return vectorSplitter.at(1);

}





/** Implementation of the parse_ClanDisciplines method.
*
* Implementation of the parse_ClanDisciplines method
* Method returning a vector corresponding to  
* Disciplines associated to a clan 
* 
* @param clanName: name of the Clan */





std::vector<std::string> vampireGameproject::Parsetext::parse_ClanDisciplines(std::string clanName){
    std::string lineOftext;
    std::vector<std::string> vectorClansDisciplines;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);

    /* while we don't find the searched line
    beginning by "##" containing "Clans", 
    we take the next line*/

    while(pystring::startswith(lineOftext, "##") != true || 
        pystring::find(lineOftext, "Clans") == -1){
            std::getline(infile, lineOftext);
        }

    /* while the line doesn't begin by "--" and we don't find the clan
    name in the line, we read the next line*/

    while(pystring::startswith(lineOftext, "--") != true || 
        pystring::find(lineOftext, clanName) == - 1){
            std::getline(infile, lineOftext);
        }

    /*while we don't find the disciplines associated to the Clan
    we read the next line*/

    while(pystring::find(lineOftext, "Clan Disciplines:") == - 1){
        std::getline(infile, lineOftext);
    }

    std::vector<std::string> vectorSplitter; 

    pystring::split(lineOftext, vectorSplitter, ":");

    pystring::split(vectorSplitter.at(1), vectorClansDisciplines, ",");

    infile.close();

    /*For all the elements of the vector containing disciplines associated
    to the clan, if a discipline is spelled with spaces, we delete these spaces*/

    for(int i = 0; i < (int)vectorClansDisciplines.size(); i++){
        std::string lineToAdd = vectorClansDisciplines.at(i);
        if (pystring::startswith(lineToAdd, " ") == true){
            lineToAdd = lineToAdd.substr(1, lineToAdd.size());
            vectorClansDisciplines[i] = lineToAdd;
        }
    }

    return vectorClansDisciplines;    
}





/** Implementation of the parse_ClanDisciplinesCategorie method.
*
* Implementation of the parse_ClanDisciplinesCategorie method
* Method returning a vector corresponding to  
*  sub-Disciplines associated to a clan 
* 
* @param categorie: name of the discipline to retrieve sub-disciplines*/





std::vector<std::string> vampireGameproject::Parsetext::parse_ClanDisciplinesCategorie(std::string categorie){
    std::string lineOftext;
    std::vector<std::string> vectorClansDisciplines;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);

    /* while we don't find the searched line
    beginning by "####" containing "Disciplines", 
    we take the next line*/

    while(pystring::startswith(lineOftext, "####") != true || 
        pystring::find(lineOftext, "Disciplines") == -1){
            std::getline(infile, lineOftext);
        }

    /*while the line doesn't start with "--" and we don't find the name
    of the discipline in the line, we get the next line*/

    while(pystring::startswith(lineOftext, "--") != true || 
        pystring::find(lineOftext, categorie) == - 1){
            std::getline(infile, lineOftext);
        }
    
    std::getline(infile, lineOftext);
    std::string secondLineOfText;
    std::vector<std::string> vectorCategorieDisciplines;

    /*while the line doens't start with "--" or the line doesn't
    start with "#", we get the next line*/

    while(pystring::startswith(lineOftext, "--") != true && 
        pystring::startswith(lineOftext, "#") != true){
        
        std::getline(infile, secondLineOfText);

        /* if the second line of the text begins by "\t*", 
        we split the line by ":", we extract the part of the 
        line containing sub-disciplines, if the string containing
        list of sub-disciplines begins by a space, then, we delete it
        from the string*/

        if (pystring::startswith(secondLineOfText, "\t*") == true && 
            pystring::startswith(secondLineOfText, "\t**") == false){
            
            std::vector<std::string> vectorToSplitText;
            pystring::split(lineOftext, vectorToSplitText, ":");

            std::string lineToAdd;
            lineToAdd = vectorToSplitText.at(1);

            if (pystring::startswith(lineToAdd, " ") == true){
                lineToAdd = lineToAdd.substr(1, lineToAdd.size());
            }

            vectorCategorieDisciplines.push_back(lineToAdd);
            lineOftext = secondLineOfText;
        }

        else{
            lineOftext = secondLineOfText;
        }

    }

    return vectorCategorieDisciplines;

}





/** Implementation of the parse_Attributes method.
*
* Implementation of the parse_Attributes method
* Method returning a vector containing the attributes*/





std::vector<std::string> vampireGameproject::Parsetext::parse_Attributes(){
    std::string lineOftext;
    std::vector<std::string> vectorAttributes;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);

    /* while we don't find the searched line
    beginning by "####" containing "Attributes", 
    we take the next line*/

    while(pystring::startswith(lineOftext, "####") != true ||
        pystring::find(lineOftext, "Attributes") == -1){
            std::getline(infile, lineOftext);
    }

    std::getline(infile, lineOftext);    

    /*while the line doesn't contain "####", we read the next line*/

    while(pystring::find(lineOftext, "#####") == -1){
        std::getline(infile, lineOftext);

        /*if the line doesn't contain "####"*/

        if (pystring::find(lineOftext, "#####") == -1){

            /*if the line begins by "##", and if the line contains spaces, 
            we delete it and we save the line in a vecttor, else, we save the
            line in the vector*/

            if (pystring::startswith(lineOftext, "##")){
                

                if (lineOftext.substr(lineOftext.size() - 1, lineOftext.size() - 1) == " "){
                    vectorAttributes.push_back(lineOftext.substr(3, (lineOftext.size() - 4)));
                }

                else{
                    vectorAttributes.push_back(lineOftext.substr(3, lineOftext.size()));
                }
                
            }   
        }
    }

    infile.close();
    return vectorAttributes;
}





/** Implementation of the parse_AttributesCategorie method.
*
* Implementation of the parse_AttributesCategorie method
* Method returning a vector containing the sub-attributes
* associated to an attribute 
*
* @param categorie: name of the attribute to retrieve sub-attributes
*/





std::vector<std::string> vampireGameproject::Parsetext::parse_AttributesCategorie(std::string categorie){
    std::string lineOftext;
    std::vector<std::string> vectorAttributes;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);

    /* while we don't find the searched line
    beginning by "####" containing "Attributes", 
    we take the next line*/

    while(pystring::startswith(lineOftext, "####") != true || 
        pystring::find(lineOftext, "Attributes") == -1){
            std::getline(infile, lineOftext);
    }

    std::getline(infile, lineOftext);

    /*while the line doesn't begin by "##" and doesn't contain the 
    searchd attribute, we get the next line*/

    while(pystring::startswith(lineOftext, "##") != true || 
        pystring::find(lineOftext,categorie) == -1){
            std::getline(infile, lineOftext);
        }

    std::getline(infile, lineOftext);

    /*while the line doesn't start with "##", we read the next line*/

    while(pystring::startswith(lineOftext, "##") != true){
        std::getline(infile, lineOftext);
        
        /*if the line begins by "--", we save the line in a vector*/

        if (pystring::startswith(lineOftext, "--") == true){
            vectorAttributes.push_back(lineOftext.substr(2, lineOftext.size()));
        }
    }

    infile.close();
    return vectorAttributes;
}





/** Implementation of the parse_Abilities method.
*
* Implementation of the parse_Abilities method
* Method returning a vector containing the abilities*/





std::vector<std::string> vampireGameproject::Parsetext::parse_Abilities(){
    std::string lineOftext;
    std::vector<std::string> vectorAbilities;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);


    /* while we don't find the searched line
    beginning by "####" containing "Abilities", 
    we take the next line*/

    while(pystring::startswith(lineOftext, "####") != true || 
        pystring::find(lineOftext, "Abilities") == -1){
            std::getline(infile, lineOftext);
    }

    std::getline(infile, lineOftext);

    int counterAbilities = 0;


    while(counterAbilities < 3){
        std::getline(infile, lineOftext);

        /*if the line starts with "#" and we don't find "####" 
        in the line, we split the line by "##", if the number of
        elements from the splitted text has a size of two elements,
        we retrieve the second part of the splitted text containing abilities,
        if the splitted text contains more elements, then, we retrieve 
        the third part of the splitted text. In all the cases, the counter is 
        incremented*/

        if (pystring::startswith(lineOftext, "#") == true && 
            pystring::find(lineOftext, "#####") == - 1){

                std::vector<std::string> vectorToSplitText;
                pystring::split(lineOftext, vectorToSplitText, "##");

            
                if (vectorToSplitText.size() == 2){
                    std::string lineToRegister = vectorToSplitText.at(1);
                    lineToRegister = lineToRegister.substr(1, lineToRegister.size());
                    vectorAbilities.push_back(lineToRegister);
                }

                else{
                    std::string lineToRegister = vectorToSplitText.at(2);
                    lineToRegister = lineToRegister.substr(1, lineToRegister.size());
                    vectorAbilities.push_back(lineToRegister);
                }

                counterAbilities += 1;
            }
        

    }

    infile.close();
    return vectorAbilities;
}





/** Implementation of the parse_AbilitiesCategorie method.
*
* Implementation of the parse_AbilitiesCategorie method
* Method returning a vector containing the sub-abilities 
* from a selected abilitie
*
* @param categorieToGet: name of the Abilitie to retrieve sub-abilities
*/





std::vector<std::string> vampireGameproject::Parsetext::parse_AbilitiesCategorie(std::string categorieToGet){
    std::string lineOftext;
    std::vector<std::string> vectorAbilities;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);


    /* while we don't find the searched line
    beginning by "####" containing "Abilities", 
    we take the next line*/


    while(pystring::startswith(lineOftext, "####") != true || 
        pystring::find(lineOftext, "Abilities") == -1){
            std::getline(infile, lineOftext);
    }

    std::getline(infile, lineOftext);

    /*while the line doesn't starts with "##" and we don't find the
    searched Abilitie, we read the next line*/

    while(pystring::startswith(lineOftext, "##") != true || 
        pystring::find(lineOftext,categorieToGet) == -1){
            std::getline(infile, lineOftext);
        }

    std::getline(infile, lineOftext);

    /*while the line doesn't start with "##", we read the next line
    if the line begins by "--", we save the line in a vector*/

    while(pystring::startswith(lineOftext, "##") != true){
        std::getline(infile, lineOftext);
        
        if (pystring::startswith(lineOftext, "--") == true){
            vectorAbilities.push_back(lineOftext.substr(2, lineOftext.size()));
        }
    }

    infile.close();
    return vectorAbilities;

}





/** Implementation of the parse_Background method.
*
* Implementation of the parse_Background method
* Method creating the Background elements in a vector
* and returning it*/





std::vector<std::string> vampireGameproject::Parsetext::parse_Backgrounds(){
    std::vector<std::string> vectorBackgrounds;
    vectorBackgrounds.push_back("Allies");
    vectorBackgrounds.push_back("Alternate Identity");
    vectorBackgrounds.push_back("Black Hand Membership");
    vectorBackgrounds.push_back("Contacts");
    vectorBackgrounds.push_back("Domain");
    vectorBackgrounds.push_back("Fame");
    vectorBackgrounds.push_back("Generation");
    vectorBackgrounds.push_back("Herd");
    vectorBackgrounds.push_back("Influence");
    vectorBackgrounds.push_back("Mentor");
    vectorBackgrounds.push_back("Resources");
    vectorBackgrounds.push_back("Retainers");
    vectorBackgrounds.push_back("Rituals");
    vectorBackgrounds.push_back("Status");

    return vectorBackgrounds;

}





/** Implementation of the parse_Virtues method.
*
* Implementation of the parse_Virtues method
* Method returning a vector containing the Vertues*/





std::vector<std::string> vampireGameproject::Parsetext::parse_Viritues(){
    std::string lineOftext;
    std::vector<std::string> vectorVirtues;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);

    /* while we don't find the searched line
    beginning by "####" containing "Virtues", 
    we take the next line*/

    while(pystring::startswith(lineOftext, "####") != true || 
        pystring::find(lineOftext, "Virtues") == -1){
            std::getline(infile, lineOftext);
    }


    std::getline(infile, lineOftext);

    /* while the line doens't start with "##" or doens't contain
    "Willpower", we take the next line, if the line starts with "--",
    we extract the line and we save it in a vector*/

    while(pystring::startswith(lineOftext, "##") != true && 
        pystring::find(lineOftext, "Willpower") == -1){
            std::getline(infile, lineOftext);
        
            
            if (pystring::startswith(lineOftext, "--") == true &&
                pystring::find(lineOftext, "Willpower") == -1){
                vectorVirtues.push_back(lineOftext.substr(2, lineOftext.size()));
            }

        }

        infile.close();
        return vectorVirtues;
}





/** Implementation of the parse_MeritsFlaws method.
*
* Implementation of the parse_MeritsFlaws method
* Method returning a vector containing the MeritsFlaws*/





std::vector<std::string> vampireGameproject::Parsetext::parse_MeritsFlaws(){
    std::string lineOftext;
    std::vector<std::string> vectorMeritsFlaws;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);

    /* while we don't find the searched line
    beginning by "####" containing "Merits and flaws", 
    we take the next line*/

    while(pystring::startswith(lineOftext, "####") != true || 
        pystring::find(lineOftext, "Merits and flaws") == -1){
            std::getline(infile, lineOftext);
    
    }

    std::getline(infile, lineOftext);

    /*while we can read line, if the line starts with "##"
    we save the line in a vector*/

    while(std::getline(infile, lineOftext)){
        if (pystring::startswith(lineOftext, "##") == true){
            std::string lineToAdd = lineOftext.substr(3, lineOftext.size());
            lineToAdd =  pystring::capitalize(lineToAdd);
            vectorMeritsFlaws.push_back(lineToAdd);

        }
    }

    return vectorMeritsFlaws;

}





/** Implementation of the parse_MeritsFlawsCategorie method.
*
* Implementation of the parse_MeritsFlawsCategorie method
* Method returning a vector containing the sub-MeritsFlaws associated to 
* a MeritsFlaws
*
* @param categorie: Name of a MeritsFlaws to retrieve sub-MeritsFlaws*/




std::vector<std::string> vampireGameproject::Parsetext::parse_MeritsFlawsCategorie(std::string categorie){
    std::string lineOftext;
    std::vector<std::string> vectorMeritsFlaws;
    std::ifstream infile("VampireV5.txt");
    std::getline(infile, lineOftext);

    /* while we don't find the searched line
    beginning by "####" containing "Merits and flaws", 
    we take the next line*/

    while(pystring::startswith(lineOftext, "####") != true || 
        pystring::find(lineOftext, "Merits and flaws") == -1){
            std::getline(infile, lineOftext);
    }

    /*while the line doesn't start with "##" and doens't contain 
    the categorie with upper letters, we get the next line*/

    while(pystring::startswith(lineOftext, "##") != true || 
        pystring::find(lineOftext, pystring::upper(categorie)) == -1){
            std::getline(infile, lineOftext);
    }

    /*while the line doesn't start with "##", and the line doesn't contain
    the name of the MeritsFlaws in upper letters, or we can get the next line, 
    if the line starts with "--", we split the line by "(", and we extract the part of the
    line containg sub-MeritsFlaws and we save it in a vector*/

    while((pystring::startswith(lineOftext, "##") != true ||
        pystring::find(lineOftext, pystring::upper(categorie)) != -1) &&
            (std::getline(infile, lineOftext))){
                if (pystring::startswith(lineOftext, "--") == true){
                    std::vector<std::string> vectorTosplitText;
                    pystring::split(lineOftext, vectorTosplitText, "(");
                    std::string lineToAdd = vectorTosplitText.at(0);
                    lineToAdd = lineToAdd.substr(2, lineToAdd.size() - 1);
                    vectorMeritsFlaws.push_back(lineToAdd);
                }
            }

    return vectorMeritsFlaws;


}
