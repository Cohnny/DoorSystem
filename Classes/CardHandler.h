#ifndef CARDHANDLER_H
#define CARDHANDLER_H

#include <vector>
#include "Card.h"

class CardHandler {
public:
    CardHandler();

    bool cardExists(int cardId);
    bool checkAccess(int cardId);
    bool getUserInput();
    void grantAccess(int cardId, bool access);
    void createCard(int cardId, bool access);
    void deleteCard(int cardId);
    void listAllCards();
    

private:
    std::vector<Card> cards;
};

#endif // CARDHANDLER_H