#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "Classes/MainMenu.h"
#include "Classes/Card.h"
#include "Classes/CardHandler.h"


int main() {
    CardHandler Handler{};
    MainMenu Menu{};
    Menu.printMenu();

    while (true) {
        std::cout << "Enter a number: ";
        int userChoice = Menu.checkInput();
        int cardNr{};
        bool exists{};
        bool access{};

        switch (userChoice) {
            case 1: {
                std::cout << "CURRENTLY LAMP IS: Green" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(3));
                break;
            }
            case 2:
                Handler.listAllCards();
                break;
            case 3:
                std::cout << std::endl;
                std::cout << "Enter card id: ";
                cardNr = Menu.checkInput();
                exists = Handler.cardExists(cardNr);

                if (exists){
                    std::cout << "Card number " << cardNr << " already exists." << std::endl;
                    std::cout << "Do you want to grant access?" << std::endl;
                    access = Handler.getUserInput();
                    Handler.grantAccess(cardNr, access);
                }
                else{
                    std::cout << "Do you want to grant access?" << std::endl;
                    access = Handler.getUserInput();
                    Handler.createCard(cardNr, access);
                }
                break;
            case 4:
                std::cout << std::endl;
                std::cout << "Enter card id to be removed: ";
                cardNr = Menu.checkInput();
                exists = Handler.cardExists(cardNr);
                if (exists){
                    Handler.deleteCard(cardNr);
                }
                else{
                    std::cout << "Card id does not exist." << std::endl;
                }
                break;
            case 5:
                std::cout << "Exiting.." << std::endl;
                return 0;
            case 6:
                std::cout << std::endl;
                std::cout << "CURRENTLY LAMP IS: Off" << std::endl;
                std::cout << "Enter a card id to test:";
                cardNr = Menu.checkInput();
                exists = Handler.cardExists(cardNr);
                if (exists){
                    if (Handler.checkAccess(cardNr)){
                        std::cout << "CURRENTLY LAMP IS: GREEN" << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(3));
                    }
                    else{
                        std::cout << "CURRENTLY LAMP IS: RED" << std::endl;
                    }
                }
                else{
                    std::cout << "Card id does not exist." << std::endl;
                }
                break;
            default:
                std::cout << "Invalid input." << std::endl;
                break;
        }
        Menu.printMenu();
    }
}