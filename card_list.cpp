// card_list.cpp
// Author: Skyler Brown and Cris Mendieta
// Implementation of the classes defined in card_list.h
#include "card_list.h"
#include <iostream>
using namespace std;
CardBST::CardBST() {
    root = nullptr;
}
CardBST::~CardBST() {
    clear(root);
}
void CardBST::clear(Node * n) {
    if (!n) {
        return;
    }
    clear(n->left);
    clear(n->right);
    delete n;
}
bool CardBST::insert(const Card& c) {
    if (!root) {
        root = new Node(c, nullptr);
        return true;
    }
    Node * curr = root;
    Node * parent = nullptr;
    while (curr) {
        parent = curr;
        if (c == curr->data) {
            return false;
        }
        else if (c < curr->data) {
            curr = curr->left;
        }
        else if (c > curr->data) {
            curr = curr->right;
        }
    }
    if (c < parent->data) {
        parent->left = new Node(c, parent);
    }
    else {
        parent->right = new Node(c, parent);
    }
    return true;
}
CardBST::Node * CardBST::findNode(const Card& c) const {
    Node * curr = root;
    while (curr) {
        if (curr->data == c) {
            return curr;
        }
        else if (c < curr->data) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    return nullptr;
}
CardBST::Node * CardBST::minimum(Node * n) const {
    if (!n) return nullptr;
    Node * curr = n;
    while (curr->left) {
        curr = curr->left;
    }
    return curr;
}
CardBST::Node * CardBST::maximum(Node * n) const {
    if (!n) return nullptr;
    Node * curr = n;
    while (curr->right) {
        curr = curr->right;
    }
    return curr;
}
CardBST::Node * CardBST::predecessor(Node * n) const {
    if (n->left) {
        return maximum(n->left);
    }
    Node * par = n->parent;
    while (par && n == par->left) {
        n = par;
        par = par->parent;
    }
    return par;
}
CardBST::Node * CardBST::successor(Node * n) const {
    if (n->right) {
        return minimum(n->right);
    }
    Node * par = n->parent;
    while (par && n == par->right) {
        n = par;
        par = par->parent;
    }
    return par;
}
bool CardBST::remove(const Card& c) {
    Node * n = findNode(c);
    if (!n) {
        return false;
    }
    if (n->left && n->right) {
        Node * succ = successor(n);
        n->data = succ->data;
        n = succ;
    }
    Node * child;
    if (n->left) {
        child = n->left;
    }
    else {
        child = n->right;
    }
    if (!n->parent) {
        root = child;
    }
    else if (n == n->parent->left) {
        n->parent->left = child;
    }
    else {
        n->parent->right = child;
    }
    if (child) {
        child->parent = n->parent;
    }
    delete n;
    return true;
}
bool CardBST::contains(const Card& c) const {
    if (findNode(c)) {
        return true;
    }
    return false;
}
void CardBST::printInOrder() const {
    for (auto it = begin(); it != end(); ++it) {
        cout << *it << endl;
    }
}
CardBST::Iterator::Iterator(Node * n, const CardBST * t) {
    curr = n;
    tree = t;
}
const Card& CardBST::Iterator::operator*() const {
    return curr->data;
}
CardBST::Iterator& CardBST::Iterator::operator++() {
    curr = tree->successor(curr);
    return *this;
}
CardBST::Iterator& CardBST::Iterator::operator--() {
    if (!curr) {
        curr = tree->maximum(tree->root);
    }
    else {
        curr = tree->predecessor(curr);
    }
    return *this;
}
bool CardBST::Iterator::operator==(const Iterator& other) const {
    if (curr == other.curr) {
        return true;
    }
    return false;
}
bool CardBST::Iterator::operator!=(const Iterator& other) const {
    if (curr != other.curr) {
        return true;
    }
    return false;
}
CardBST::Iterator CardBST::begin() const {
    return Iterator(minimum(root), this);
}
CardBST::Iterator CardBST::end() const {
    return Iterator(nullptr, this);
}
CardBST::Iterator CardBST::rend() const {
    return Iterator(nullptr, this);
}
CardBST::Iterator CardBST::rbegin() const {
    return Iterator(maximum(root), this);
}
void playGame(CardBST& aliceSet, CardBST& bobSet) {
    bool turnAlice = true;
    while (true) {
    bool cardMatch = false;
    if (turnAlice) {
        for (auto it = aliceSet.begin(); it != aliceSet.end(); ++it) {
            if (bobSet.contains(*it)) {
                cout << "Alice picked matching card " << *it << endl;
                bobSet.remove(*it);
                aliceSet.remove(*it);
                cardMatch = true;
                break;
            }
        }
    }
    else {
        for (auto it = bobSet.end(); it != bobSet.begin();) {
            --it;
            if (aliceSet.contains(*it)) {
                cout << "Bob picked matching card " << *it << endl;
                aliceSet.remove(*it);
                bobSet.remove(*it);
                cardMatch = true;
                break;
            }
        }
    }
    if (!cardMatch) {
        break;
    }
    turnAlice = !turnAlice;
  }
  cout << "Alice's cards:" << endl;
  aliceSet.printInOrder();
  cout << "Bob's cards:" << endl;
  bobSet.printInOrder();
}