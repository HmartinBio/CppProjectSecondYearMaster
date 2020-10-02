---
title: Vampire Game Project
author: Hugo MARTIN
date: 26/09/2020
---

## Contents

---

[Overview](#overview)\
[Requirements](#requirements)\
[Launching the app](#launching-the-app)\
[Code Presentation](#code-presentation)\
[Improvements](#improvements)

---
<br>

## Overview

---

The aim of this project is to build an interface where the user could
enter informations\
concerning a character. Once the character is created, the information concerning the character\
are written on a character sheet.


---
<br>

## Requirements

---

The application has been conceived for **Linux** systems.\
On your **Linux** computer, you need to have **g++** installed.\
**gtkmm-3.0** is required to compile the application.


---
<br>

## Launching the app

---

To launch the application, you need to move on the folder containing the app with the **command-line**.\
Once you are in the folder, you need to execute the **make** command such as:\

```console
make
```

Once the compilation is finished, you can execute the application with the command:\

```console
./vampireGameproject
```

---
<br>


## Code Presentation

---

We designed the code execution around the Controllor class. The Controllor class contains the Graphical User Interface and the others class responsible of others functionnalities of the program (textParsing, test, modification of the character sheet). At the beginning of the programm, it's the Controllor class which is launched.

```cpp
class Controllor{
        public:
            Controllor();
            ~Controllor();

        private:
            Parsetext textParser;
            Gui graphicalUserinterface;
    };
```


The Parsetext class contains all the functions to parse the text from the game to retrieve all the character features.



```cpp

    class Parsetext{
        public:
            Parsetext();
            ~Parsetext();
            std::string parse_text(std::string categorie);
            std::string parse_text(std::string categorie, std::string table, std::string nameOfcomptence);
    };
```

The Character class contains all the elements of a character (Attributes, Abilities, Advantages, etc...).

When a new Character is created, the reference of the Parsetext object contained in the Controllor is given at all the objects contained in the Character class. 

The constructor of the Character class is not executed yet. It allows to the objects contained in the class to parse text and return definition of some features of the character.


```cpp

class Character{
        private:
            std::string playerName;
            Chronicle characterChronicle;
            Attributes characterAttributes;
            Abilities characterAbilities;
            Advantages characterAdvantages;
            Meritsflaws characterMeritsflaws;
            Nature characterNature;
            Health characterHealth;
            CharacterTraits characterTraits;
            Generation characterGeneration;
            Daemenor characterDaemenor;
            Clan characterClan;
            
        public:
            std::string getPlayername(void);
            void setPlayername(std::string name);
            Character(Parsetext& textParser);
            ~Character();
    };

```

RulesofGame class is designed such as all the tests 
to verify inputted informations on the graphical user
interface are contained in this class. 

It allows to the interface to restrain some user choices for these one be in adequacy with the rules of the game. 

For example, each Clan has its own disciplines, so, when the user chooses the clan, this one can only chooses a discipline among the disciplines attributed to the Clan. 

```cpp

    class RulesofGame{
        public:
            RulesofGame(Gui& classReference);
            ~RulesofGame();

        private:
            Gui& referenceOutterclass;
    };
```
Gui class is designed such as all the elements composing  the graphical user interface are contained in this class. 

```cpp

    class Gui{
        public:
            Gui();
            ~Gui();
        private:
            RulesofGame testGui;
    };
```


Picturemodifying class is designed to modify the picture to include 
all the information about a character. 

Once the graphical user interface received all the informations about a character,\
Picturemodifying modifies the picture to generate a picture with all the informations about a character


```cpp
    class Picturemodifying{
        public:
            Picturemodifying();
            ~Picturemodifying();

        private:
    };
```

---
<br>

## Improvements

---



---