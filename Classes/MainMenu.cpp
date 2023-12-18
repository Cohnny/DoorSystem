#include "MainMenu.h"
#include <iostream>
#include <limits>


void MainMenu::printMenu() {
    std::cout << std::endl;
    std::cout << "Admin menu" << std::endl
         << "1. Remote open door" << std::endl
         << "2. List all cards in system" << std::endl
         << "3. Add/remove access" << std::endl
         << "4. Remove card" << std::endl
         << "5. Exit" << std::endl
         << "6. Test card" << std::endl;
}

int MainMenu::checkInput() {
    while (!(std::cin >> choice))
    {
        std::cout << "Invalid input." << std::endl;
        std::cout << "Enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return choice;
}