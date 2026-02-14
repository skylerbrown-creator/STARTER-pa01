// card.cpp
// Author: Skyler Brown, Cris Mendieta
// Implementation of the classes defined in card.h

#include "card.h"
Card::Card() {
    suit = 'c';
    value = 1;
}
Card::Card(char s, int v) {
    suit = s;
    value = v;
}
char Card::getSuit() const {
    return suit;
}
int Card::getValue() const {
    return value;
}
int Card::valueFromString(const std::string& str) {
    if (str == "a") return 1;
    if (str == "j") return 11;
    if (str == "q") return 12;
    if (str == "k") return 13;
    return stoi(str);
}
bool Card::operator==(const Card& otherCard) const {
    if (suit == otherCard.getSuit() && value == otherCard.getValue()) {
        return true;
    }
    return false;
}
bool Card::operator<(const Card& otherCard) const {
    if (suit == 'c') {
        if (otherCard.getSuit() != 'c') {
            return true;
        }
        return value < otherCard.getValue();
    }
    if (suit == 'd') {
        if (otherCard.getSuit() == 'c') {
            return false;
        }
        if (otherCard.getSuit() != 'd') {
            return true;
        }
        return value < otherCard.getValue();
    }
    if (suit == 's') {
        if (otherCard.getSuit() == 'c' || otherCard.getSuit() == 'd') {
            return false;
        }
        if (otherCard.getSuit() != 's') {
            return true;
        }
        return value < otherCard.getValue();
    }
    if (suit == 'h') {
        if (otherCard.getSuit() != 'h') {
            return false;
        }
        return value < otherCard.getValue();
    }
    return false;
}
bool Card::operator>(const Card& other) const {
    return other < *this;
}
std::ostream& operator<<(std::ostream& os, const Card& c) {
    os << c.getSuit() << " ";
    int val = c.getValue();
    if (val == 1) os << "a";
    else if (val == 11) os << "j";
    else if (val == 12) os << "q";
    else if (val == 13) os << "k";
    else os << val;
    return os;
}