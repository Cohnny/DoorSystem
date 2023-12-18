#include "CardHandler.h"
#include "Card.h"
#include <iostream>
#include <limits>
#include <conio.h>
#include <algorithm>

CardHandler::CardHandler() {}

bool CardHandler::cardExists(int cardId) {
    for (const auto& card : cards) {
        if (card.getId() == cardId) {
            return true;
        }
    }
    return false;
}

bool CardHandler::checkAccess(int cardId)
{
    for (auto& card : cards){
        if (card.getId() == cardId){
            return card.getAccess();
        }
    }

    return false;
}

bool CardHandler::getUserInput() {
    while (true) {
        std::cout << "Enter 'yes' or 'no': ";
        std::string answer;
        std::cin >> answer;

        if (answer == "yes") {
            return true;
        } else if (answer == "no") {
            return false;
        } else {
            std::cout << "Invalid input. Please enter 'yes' or 'no'." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void CardHandler::grantAccess(int cardId, bool access){
    for (auto& card : cards){
        if (card.getId() == cardId){
            card.setAccess(access);
        }
    }
}

void CardHandler::createCard(int cardId, bool access) {
    Card newCard(cardId, access);
    cards.push_back(newCard);
    std::cout << "Card created: " << newCard.printTimestamp() << std::endl;
    std::cout << "Card id: " << newCard.getId() << std::endl;
    std::cout << "Card acces: " << (access ? "Granted" : "Denied") << std::endl;
}

void CardHandler::deleteCard(int cardId) {
    auto itr = std::find_if(begin(cards), end(cards), [cardId](const Card& card) {
        return card.getId() == cardId;
    });

    if (itr != cards.end()){
        cards.erase(itr);
        std::cout << "Card was successfully deleted." << std::endl;
    }
}

void CardHandler::listAllCards() {
    std::cout << std::endl;
    std::cout << "All cards in the system:" << std::endl;
    for (const auto& card : cards) {
        std::cout << card.getId() << " " << (card.getAccess() ? "Access" : "No Access") << " Added to system: " << card.printTimestamp() << std::endl;
    }

    std::cout << "Press any key to continue";
    getch();
    std::cout << std::endl;
}