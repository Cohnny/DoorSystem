#include "Card.h"

Card::Card(int id, bool access) : id(id), access(access) {
    const std::chrono::time_point now{std::chrono::system_clock::now()};
    timestamp = std::chrono::year_month_day{std::chrono::floor<std::chrono::days>(now)};
}

void Card::setAccess(bool access) {
    this->access = access;
}

std::string Card::printTimestamp() const {
    return std::to_string(static_cast<int>(timestamp.year())) + "-" +
           std::to_string(static_cast<unsigned>(timestamp.month())) + "-" +
           std::to_string(static_cast<unsigned>(timestamp.day()));
}