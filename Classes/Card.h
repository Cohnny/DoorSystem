#ifndef CARD_H
#define CARD_H

#include <chrono>
#include <iostream>

class Card {
public:
    Card(int id, bool access);

    int getId() const { return id; }
    bool getAccess() const { return access; }
    void setAccess(bool access);
    std::string printTimestamp() const;
    
private:
    int id{};
    bool access{};
    std::chrono::year_month_day timestamp;
};

#endif // CARD_H