// card.h
// Author: Skyler Brown, Cris Mendieta
// All class declarations related to defining a single card go here
#include <string>
#include <iostream>

#ifndef CARD_H
#define CARD_H

class Card {
    public:
        Card();
        Card(char s, int v);
        char getSuit() const;
        int getValue() const;
        static int valueFromString(const std::string& str);
        bool operator==(const Card& otherCard) const;
        bool operator<(const Card& otherCard) const;
        bool operator>(const Card& otherCard) const;
    private:
        char suit;
        int value;
};
std::ostream& operator<<(std::ostream& os, const Card& c);
#endif
