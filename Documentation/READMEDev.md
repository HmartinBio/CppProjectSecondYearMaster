---
title: Developper Guide
author: Hugo MARTIN
date: 26/09/2020
---

## Contents


[Overview](#overview)\
[Requirements](#requirements)\
[Installing the app](#launching-the-app)\
[Uninstalling the app](#uninstalling-the-app)\
[Code Presentation](#code-presentation)\
[Improvements](#improvements)\
[Doxygen Documentation](#doxygen-documentation)



<br>

## Overview


The aim of this project was to build an interface where the user could
enter informations\
concerning a character from a specific game. Once the character is created, the informations\
concerning the character are written on a character sheet.




<br>

## Requirements


The application has been conceived for **Linux** systems.\
On your **Linux** computer, you need to have **g++** compiler installed.\
**gtkmm-3.0** is required to compile the application.

To install **g++**, you can run the command: 

```bash
sudo apt install build-essential
```

And to install **gtkmm-3.0**, you can run the command: 

```bash
sudo apt-get install libgtkmm-3.0-dev 
```



<br>

## Installing the app


To install the application, you need to move on the folder containing the app with the **command-line**.\
Once you are in the folder, you need to execute the **make** command such as:

```bash
make
```


## Uninstalling the app

To uninstall the application, you need to move on the folder containing the app with the **command-line**.\
Once you are in the folder, execute this command:

```bash
make mrproper
```
This **command-line** deletes all the files created by the compiler, including the **executable** file.

To only delete the **intermediary** files created by the compiler but not the executable file, you can run the **command-line:**

```bash
make clean
```



<br>


## Code Presentation


We designed the code execution around the **Controllor** class following the **Model-View-Controllor** code organization. The **Controllor** class contains the **Graphical User Interface** and the others class objects responsible of others functionnalities of the program (**textParser**, **RulesofGame**, **Character**, **Picturemodifying**). At the beginning of the program, it's the **Controllor** class object constructor which is launched.


The **Controllor** class object initialise the **Graphical User Interface** and set the limits points to all the game fields.This one initialise a **Character** class object to save all the choices of the user. The choices of the user are retrieved from this class object to save it in a file by using **createResultsFile** object methods.


```cpp
class Controllor{
        public:
            Controllor();
            ~Controllor();
            Gui graphicalUserinterface;
            void testAttributesInputsFirstComboBox(int number);
            void testInputsSecondComboBox(ButtonmultiInput& ButtonMultiInputReference, int number, std::string categorieMultiInput);
            void testInputsFirstComboBoxSpinButton(ButtonmultiInput& ButtonMultiInputReference, int number);
            void testInputsFirstComboBoxChangingItems(ButtonmultiInput& ButtonMultiInputReference, int number);
            void initializeButtonMultiInputReference(ButtonmultiInput& ButtonMultiInputReference, 
                std::string categorieMultiInput);
            void initializeButtonMultiInput(std::string categorieMultiInput);
            void testInputSecondComboBoxForGui(int number, std::string categorieMultiInput);
            void testInputSecondComboBoxChosenItems(ButtonmultiInput& ButtonMultiInputReference, int number, std::string categorieMultiInput);
            void testInputSpinButton(ButtonmultiInput& ButtonMultiInputReference, int number);
            void setMultiInput(std::string categorieMultiInput);
            void deleteMultiInput(std::string categorieMultiInput);
            void setVectorSecondComboBox(std::string ComboBoxFirstValue);
            void testFirstComboBoxDisponibility(std::string categorieMultiInput);
            void testInputFirstComboBoxForGui(int number, std::string categorieMultiInput);
            void testInputSpinButtonForGui(int number, std::string categorieMultiInput);
            void testInputSpinButtonWhenRemoved(std::string categorieMultiInput);
            void testInputPlusButtonForGui(std::string categorieMultiInput);
            void testInputMinusButtonForGui(std::string categorieMultiInput);
            void initializeButtonMultiInputOneComboBox(std::string      categorieMultiInput);
            void initializeButtonMultiInputReferenceOneComboBox(ButtonmultiInputOneComboBox& ButtonMultiInputOneComboBoxReference, 
                std::string categorieMultiInputOneComboBox);
            void testInputsFirstComboBoxChangeItemsOneComboBox(ButtonmultiInputOneComboBox& ButtonmultiInputOneComboBoxReference, int number);
            void testInputSpinButtonOneComboBox(ButtonmultiInputOneComboBox& ButtonMultiInputOneComboBoxReference, int number);
            void testClanButton();
            void initializeSpinButton(std::string categorieSpinButton);
            void initializeFinalButton();
            void initializeNicknameLabel();
            void updateNicknameLabel();
            void initializeHealthComboBox();
            void submitUserChoices();
            void saveAttributesInCharacter();
            void saveAbilitiesInCharacter();
            void saveDisciplinesInCharacter();
            void saveBackgroundsInCharacter();
            void saveVirtuesInCharacter();
            void saveMeritsFlawsCharacter();
            void saveUserChoices();


        private:
            Parsetext textParser;
            RulesofGame rulesGame;
            Character CharacterToCreate;
            Picturemodifying createResultsFile;
    };
```


The **Parsetext** class contains all the functions to parse the text from the **VampireV5.txt** file to retrieve all the character features.



```cpp
      class Parsetext{
        public:
            Parsetext();
            ~Parsetext();
            std::string parseText(std::string categorie);
            std::string parseText(std::string categorie, std::string caracteristics);
            std::string parseText(std::string categorie, std::string table, std::string nameOfcomptence);
            std::vector<std::string> parselistClans(void);
            std::vector<std::string> parselistNature(void);
            std::string parseNicknameClan(std::string clanName);
            std::vector<std::string> parseClanDisciplines(std::string clanName);
            std::vector<std::string> parseAttributes();
            std::vector<std::string> parseAttributesCategorie(std::string categorie);
            std::vector<std::string> parseAbilities();
            std::vector<std::string> parseAbilitiesCategorie(std::string categorieToGet);
            std::vector<std::string> parseBackgrounds();
            std::vector<std::string> parseClanDisciplinesCategorie(std::string categorie);
            std::vector<std::string> parseViritues();
            std::vector<std::string> parseMeritsFlaws();
            std::vector<std::string> parseMeritsFlawsCategorie(std::string categorie);
            std::vector<std::string> parseHealth();
    };

```

The **Character** class contains all the elements of a character (**Attributes**, **Abilities**, **Advantages**, etc...).

When a new **Character** is created, the reference of the **Parsetext** object contained in the **Controllor** is given at all the objects contained in the **Character** class. 

It allows to the objects contained in the class to parse text and return definition of some features of the character.

**Character** also allows to set the elements contained in the class objects (**Attributes**, **Abilities**, **Advantages**, etc...) and to retrieve these informations.


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
        void setAttributes(std::string firstComboBoxItem, 
            std::string secondComboBoxItem, int SpinScore);
        std::map<std::string,int> getAttributes(std::string firstComboBoxItem);
        void setAbilities(std::string firstComboBoxItem, 
            std::string secondComboBoxItem, int SpinScore);
        std::map<std::string, int> getAbilties(std::string FirstComboBoxItem);
        void setMeritsflaws(std::string firstComboBoxItem, 
            std::string secondComboBoxItem, int SpinScore);
        std::map<std::string, int> returnMeritsFlaws(std::string FirstComboBoxItem);
        void setNature(std::string ComboBoxItem);
        std::string getNature();
        void setHealth(std::string ComboBoxItem);
        std::string getHealth();
        void setGeneration(float SpinScoreButton);
        std::string getGeneration();
        void setClan(std::string ComboBoxItem);
        std::string getClan();
        void setBackground(std::string ComboBoxItem, int SpinScore);
        std::map<std::string, int> getBackground();
        void setVirtues(std::string ComboBoxItem, int spinScore);
        std::map<std::string, int> getVirtues();
        void setHumanity(int number);
        std::string getHumanity();
        void setWillpower(int number);
        std::string getWillpower();
        void setBloodpool(float number);
        float getBloodpool();
        void setDisciplines(std::vector<MultiDimensionnalDataStructure*> disciplines);
        std::vector<MultiDimensionnalDataStructure*> returnDisciplines();
            
        void setVampireNickName(std::string Nickname);
        std::string returnVampireNickName();
    };

```

**RulesofGame** class is designed such as all informations related to the game are contained in this class. 

It allows to the interface to restrain some user choices for these one be in adequacy with the rules of the game.

**Controllor** class is charged with establishing the link between the **RulesofGame** class object with the **Gui** class object to restrain user choices on the interface.

For example, each **Clan** has its own disciplines, so, when the user chooses the clan, this one can only chooses a discipline among the disciplines attributed to the **Clan**. 

```cpp
    class RulesofGame{
        public:
            RulesofGame(Parsetext& parserReference);
            ~RulesofGame();
            std::vector<std::string>& returnVectorClans();
            std::vector<std::string>& returnVectorNature();
            void setVectorClans();
            void setVectorNature();
            Parsetext& parser;
            void setLimitPointsAttributes(int PhysicalPoints, int SocialPoints, int MentalPoints, int TalentsPoints,
                int SkillsPoints, int KnowledgesPoints, int AnimalismPoints, int AuspexPoints, int CelerityPoints, 
                    int ChimerstryPoints, int DementationPoints, int DominatePoints, int FortitudePoints, int NecromancyPoints, 
                        int ObfuscatePoints, int ObtenebrationPoints, int PotencePoints, int PresencePoints, int ProteanPoints, 
                            int QuietusPoints, int SerpentisPoints, int ThaumaturgyPoints, 
                                int VicissitudePoints, int AlliesPoints, int AlternateIdentityPoints, int BlackHandMembershipPoints, 
                                    int ContactsPoints, int DomainPoints, int FamePoints, int GenerationPoints, int HerdPoints, 
                                        int InfluencePoints, int MentorPoints, int ResourcesPoints, int RetainersPoints, 
                                            int RitualsPoints, int StatusPoints, int ConsciencePoints, 
                                                int SelfControlPoints, int CouragePoints, int SupernaturalPoints, 
                                                    int DaimoinonPoints, int Sanginus, int MelpomineePoints, int FlightPoints, 
                                                        int TemporisPoints, int OghamPoints);

            std::map<std::string, int> returnLimitPointsAttributes();
            
        private:
            std::vector<std::string> vectorClans;
            std::vector<std::string> vectorNature;
            std::map<std::string, int> limitPointsAttributes;
            
    };
```


**Gui** class is designed such as all the elements composing the **Graphical User Interface** are contained in this class. The **Gui** class object contains all the methods allowing to the **Controllor** class to activate the **Graphical User Interface** when the **Controllor** constructor is launched.


```cpp
class Gui : public Gtk::Window{
    public:
        Gui();
        virtual ~Gui();
        void setTableComboBox(int index, std::vector<std::string>& vectorElements);
        void initialiseTableLabel();
        void initialiseTableComboBox();
        void setTableLabelAlign(int index, std::string label);
        void setTableLabel(int index, std::string label);
        void setTableLabelOnGrid(int index, int xcoordinates, int ycoordinates, int width, int height);
        void setTableComboBoxOnGrid(int index, int indexLabel);
        void setMultiComboBoxAttributes(int xcoordinates, int ycoordinates, int width, int height);
        void setLabelMultiComboBoxAttributes();
        void setLabelMultiComboBoxAbilities();
        void setLabelMultiComboBoxDisciplines();
        void setLabelMultiComboBoxMeritsFlaws();
        ButtonmultiInput& returnAttributesInput();
        ButtonmultiInput& returnAbilitiesInput();
        ButtonmultiInput& returnDisciplinesInput();
        ButtonmultiInput& returnMeritsFlawsInput();
        void setMultiInputOnGrid(ButtonmultiInput& ButtonMultiInputReference, int number);
        void deleteMultiInputOnGrid(ButtonmultiInput& ButtonMultiInputReference, int number);
        void setButtonMultiInputAttributes();
        void setButtonMultiInputAbilities();
        void setButtonMultiInputDisciplines();
        void setButtonMultiInputMeritsFlaws();
        void showAll();
        ButtonmultiInputOneComboBox& returnBackgroundsInput();
        ButtonmultiInputOneComboBox& returnVirtuesInput();
        void setMultiInputOneComboBoxOnGrid(ButtonmultiInputOneComboBox& ButtonmultiInputOneComboBoxReference, int number);
        void deleteMultiInputOneComboBoxOnGrid(ButtonmultiInputOneComboBox& ButtonmultiInputOneComboBoxReference, int number);
        void setButtonMultiInputBackgrounds();
        void setButtonMultiInputVirtues();
        void setLabelMultiComboBoxBackgrounds();
        void setLabelMultiComboBoxVirtues();
        std::string returnClanName();
        Gtk::ComboBoxText& returnComboBoxClan();
        void setSpinButtonHumanityPath();
        void setSpinButtonWillPower();
        void setSpinButtonBloodPool();
        void setValidationButton();
        Gtk::SpinButton& returnHumanityPathSpinButton(); 
        Gtk::SpinButton& returnWillPowerSpinButton();
        Gtk::SpinButton& returnBloodPoolSpinButton();
        Gtk::Button& returnValidationButton();
        Gtk::Label& returnLabelVampireNickName();
        void setNicknameLabel();
        void setTextNicknameLabel(std::string textToAdd);
        std::string setFileChooser();
        std::string returnNature();
        std::string returnHealth();
        void initialiseEntryName();
        std::string returnPlayerName();       

    private:
        Gtk::Grid mainGrid; 
        Gtk::Label tableLabel[15];
        Gtk::ComboBoxText tableComboBox[3];
        ButtonmultiInput attributesInput;
        ButtonmultiInput abilitiesInput;
        ButtonmultiInput disciplinesInput;
        ButtonmultiInput meritsFlawsInput;
        ButtonmultiInputOneComboBox backgroundsInput;
        ButtonmultiInputOneComboBox virtuesInput;
        Gtk::SpinButton HumanityPathScore;
        Gtk::SpinButton WillPowerScore;
        Gtk::SpinButton BloodPoolScore;
        Gtk::Button validationButton;
        Gtk::Entry NameEntry;           
};
```


**Picturemodifying** class is designed to create a text file including 
all the informations about a character. 

Once the **Graphical User Interface** set all the informations about a character in the **Character** class object. **Picturemodifying** retrieve all the informations by a **Character** class object reference given by the **Controllor** class and creates the text file with all the informations about the character.


```cpp
    class Picturemodifying{
        public:
            Picturemodifying(Character& ReferenceCharacter);
            ~Picturemodifying();
            void writeResultsFile(std::string filename);
            void writeResultsAttributes(std::ofstream& fileToWrite);
            void writeResultsAbilities(std::ofstream& fileToWrite);
            void writeResultsAdvantages(std::ofstream& fileToWrite);
            void writeResultsHumanityPathToHealth(std::ofstream& fileToWrite);
            void writeResultsMeritsFlaws(std::ofstream& fileToWrite);
            void writeResultsOthersCaracteristics(std::ofstream& fileToWrite);

        private:
            Character& CharacterReference;
    };
```

### Custom Widgets built during the project

During the project, we designed four custom Widgets.
The first one is the **MultiInput**, this **Widget** allows to represent
two side by side **ComboBoxText** Widgets. These one are next to a **SpinButton** Widget. The selection of an item in the First **ComboBoxText** allows to fill the Second **ComboBoxText** and to activate the **SpinButton** Widget. **MultiInput** Widget is contained in the **ButtonmultiInput** Widget, this one allows to synchronize **ComboBoxText** with the **SpinButton**.


```cpp
class MultiInput{
    public:
        MultiInput();
        virtual ~MultiInput();
        Gtk::ComboBoxText& returnComboBox(std::string position);
        Gtk::SpinButton& returnSpinButton();
        void setLimitSpinButton(int limit);
        int returnSpinScore();
        std::string returnTextComboBox(std::string index);
        void setVectorComboBox(std::vector<std::string>& vectorText, std::string index);
        void setComboBoxFunction(std::string index);
        void unsetActiveText();
        void resetSpinScore();

    private:
        Gtk::ComboBoxText firstComboBox;
        Gtk::ComboBoxText secondComboBox;
        Gtk::SpinButton spinButton;
};

```

**ButtonmultiInput** Widget allows to create dynamically **MultiInput** Widgets, methods of the **ButtonmultiInput** class allows to append or delete **MultiInput** objects in a vector contained in the **ButtonmultiInput** class. The **ButtonmultiInput** Widget is also responsible to synchronize the data entered by the user with the **Controllor** class to make the Widget responsive. **ButtonmultiInput** Widget is composed of at least one **MultiInput** Widget, one Plus **Button** Widget and one minus Button **Widget** allowing to append or delete **MultiInput** Widgets.


```cpp
class ButtonmultiInput{
    public:
        ButtonmultiInput();
        virtual ~ButtonmultiInput();
        Gtk::Button& returnButton(std::string sign);
        void setLabelMultiComboBox();
        std::vector<MultiInput*>& returnVectorMultiInput();
        void setVectorSelectedInput();
        void setDicoScoreFirstComboBox();
        void setMultiInput();
        void deleteMultiInput();
        void setCoordinates(int coordinateX, int coordinateY);
        std::map<std::string, int> returnDicoScoreFirstComboBox();
        std::vector<std::string> returnVectorSelectedInput(std::string index);
        void setLimitMultiInput();
        void setVectorComboBox(int index, std::string position, std::vector<std::string> vectorReference);
        void initialize();
        std::string returnTextComboBox(int number, std::string index);
        int returnXCoordinate();
        int returnYCoordinate();

    private:
        Gtk::Button plusButton;
        Gtk::Button minusButton;
        Gtk::ComboBoxText firstComboBox;
        Gtk::ComboBoxText secondComboBox;
        std::vector<MultiInput*> vectorMultiInputs;
        std::vector<std::string> vectorFirstComboBoxSelectedInputs;
        std::vector<std::string> vectorSecondComboBoxSelectedInputs;
        int xcoordinates;
        int ycoordinates;
        std::map<std::string, int> DicoScoreFirstComboBox;
};

```

The previous Widgets were designed a second time with other class names(**MultiInputOneComboBox**, **ButtonmultiInputOneComboBox**). These are the same Widgets except that **MultiInputOneComboBox** Widget has only one **ComboBoxText** compared to **MultiInput** Widget.


```cpp
class MultiInputOneComboBox{
    public:
        MultiInputOneComboBox();
        virtual ~MultiInputOneComboBox();
        Gtk::ComboBoxText& returnComboBox();
        Gtk::SpinButton& returnSpinButton();
        void setLimitSpinButton(int limit);
        int returnSpinScore();
        std::string returnTextComboBox();
        void setVectorComboBox(std::vector<std::string>& vectorText);
        void unsetActiveText();
        void resetSpinScore();

    private:
        Gtk::ComboBoxText ComboBox;
        Gtk::SpinButton spinButton;
};

```



```cpp
    class ButtonmultiInputOneComboBox{
        public:
            ButtonmultiInputOneComboBox();
            virtual ~ButtonmultiInputOneComboBox();
            Gtk::Button& returnButton(std::string sign);
            void setLabelMultiComboBox();
            std::vector<MultiInputOneComboBox*>& returnVectorMultiInput();
            void setVectorSelectedInput();
            void setDicoScoreFirstComboBox();
            void setMultiInput();
            void deleteMultiInput();
            void setCoordinates(int coordinateX, int coordinateY);
            std::map<std::string, int> returnDicoScoreComboBox();
            std::vector<std::string> returnVectorSelectedInput();
            void setLimitMultiInput();
            void setVectorComboBox(int index, std::vector<std::string> vectorReference);
            void initialize();
            void setNumberMultiInput(int number);
            std::string returnTextComboBox(int number);
            int returnXCoordinate();
            int returnYCoordinate();

        private:
            Gtk::Button plusButton;
            Gtk::Button minusButton;
            Gtk::ComboBoxText firstComboBox;
            Gtk::ComboBoxText secondComboBox;
            std::vector<MultiInputOneComboBox*> vectorMultiInputs;
            std::vector<std::string> vectorComboBoxSelectedInputs;
            int xcoordinates;
            int ycoordinates;
            std::map<std::string, int> DicoScoreComboBox;
    };

```


### Meta Data Structure built during the project

During the project, we built a **union** in the aim to save **string** and **integer** in the vector containing **Disciplines** in the class **Clan**. This data structure allowed to avoid to make a double loop when we retrieve the **Disciplines** informations. 

**Union** are data structures allowing to save a variable in a type chosen according to the developper need.


```cpp
union MultiDimensionnalDataStructure{
        MultiDimensionnalDataStructure(std::string categorieToEnter);
        MultiDimensionnalDataStructure(int categorieValue);
        ~MultiDimensionnalDataStructure();
        std::string categorie;
        int value;
};
```

<br>

## Improvements

Some **bugs** persist in the application, these one are caused by **double loop** in the application code. To correct these troubles, some parts of the application code are to revise in the aim to use others
data structure allowing to avoid to make double loops.

Moreover, the limit points attributed to game fields in the class **RulesofGame** doesn't reflect the limit points in the true rules of game. For that, we need to create several dictionnary for each game fields in the aim each field must have its own dictionnary allowing to control the points sum for each game field.  

To finish, we could add more game fields for the output file be as representative as possible. And we could propose to the user to download a Picture Character Sheet by using the [OpenCV](https://docs.opencv.org/3.4/d6/d6e/group__imgproc__draw.html) library. 


## Doxygen Documentation

A Doxygen documentation is available [here](DoxygenDocumentation/html/annotated.html)