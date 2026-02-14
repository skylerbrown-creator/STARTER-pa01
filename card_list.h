// card_list.h
// Author: Skyler Brown and Cris Mendieta
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H
#include "card.h"
#include <iostream>

class CardBST {
    private:
        struct Node {
            Card data;
            Node * left;
            Node * right;
            Node * parent;
            Node(const Card& c, Node * par) {
                data = c;
                left = nullptr;
                right = nullptr;
                parent = par;
            }
        };
        Node * root;
        void clear(Node * n);
        Node * findNode(const Card& c) const;
        Node * successor(Node * n) const;
        Node * predecessor(Node * n) const;
        Node * minimum(Node * n) const;
        Node * maximum(Node * n) const;
    public:
        CardBST();
        ~CardBST();
        bool insert(const Card& c);
        bool remove(const Card& c);
        bool contains(const Card& c) const;
        void printInOrder() const;
        class Iterator {
            private:
                Node * curr;
                const CardBST * tree;
            public:
                Iterator(Node * n, const CardBST * t);
                const Card& operator*() const;
                Iterator& operator++();
                Iterator& operator--();
                bool operator==(const Iterator& other) const;
                bool operator!=(const Iterator& other) const;
        };
        Iterator begin() const;
        Iterator rbegin() const;
        Iterator end() const;
        Iterator rend() const;
};
void playGame(CardBST& alice, CardBST& bob);

#endif
