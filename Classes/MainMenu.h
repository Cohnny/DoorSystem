#ifndef MAINMENU_H
#define MAINMENU_H

#include <string>

class MainMenu {
public:
    void printMenu(); 
    int checkInput();

private:
    int choice;
};


#endif // MAINMENU_H