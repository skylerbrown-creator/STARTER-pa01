//contain test code for all classes and methods in game with custom BST
#include <iostream>
#include <cassert>
#include "card_list.h"
#include "card.h"
using namespace std;
void testInsertAndRemoveAndContainsEmptyTree() {
    CardBST bst;
    assert(!bst.contains(Card('c', 1)));
    assert(bst.insert(Card('c', 1)));
    assert(bst.contains(Card('c', 1)));
    assert(!bst.insert(Card('c', 1)));
    assert(bst.remove(Card('c', 1)));
    assert(!bst.contains(Card('c', 1)));
    assert(!bst.remove(Card('c', 1)));
}
void testInsertAndRemoveAndContainsSingleNode() {
    CardBST bst;
    bst.insert(Card('c', 1));
    assert(bst.contains(Card('c', 1)));
    assert(bst.remove(Card('c', 1)));
    assert(!bst.contains(Card('c', 1)));
}
void testInsertAndRemoveAndContainsMultipleNodes() {
    CardBST bst;
    bst.insert(Card('c', 1));
    bst.insert(Card('d', 1));
    bst.insert(Card('s', 1));
    bst.insert(Card('h', 1));
    assert(bst.contains(Card('c', 1)));
    assert(bst.contains(Card('d', 1)));
    assert(bst.contains(Card('s', 1)));
    assert(bst.contains(Card('h', 1)));
    assert(bst.remove(Card('d', 1)));
    assert(!bst.contains(Card('d', 1)));
    assert(bst.remove(Card('c', 1)));
    assert(!bst.contains(Card('c', 1)));
    assert(bst.remove(Card('s', 1)));
    assert(!bst.contains(Card('s', 1)));
    assert(bst.remove(Card('h', 1)));
    assert(!bst.contains(Card('h', 1)));
}
void testInsertAndRemoveAndContainsEdgeCases() {
    CardBST bst;
    bst.insert(Card('c', 1));
    bst.insert(Card('d', 1));
    bst.insert(Card('s', 1));
    bst.insert(Card('h', 1));
    assert(!bst.contains(Card('c', 2)));
    assert(!bst.contains(Card('d', 2)));
    assert(!bst.contains(Card('s', 2)));
    assert(!bst.contains(Card('h', 2)));
    assert(!bst.remove(Card('c', 2)));
    assert(!bst.remove(Card('d', 2)));
    assert(!bst.remove(Card('s', 2)));
    assert(!bst.remove(Card('h', 2)));
}
void testInsertAndRemoveAndContainsMemory() {
    CardBST bst;
    for (int i = 1; i <= 13; i++) {
        bst.insert(Card('c', i));
        bst.insert(Card('d', i));
        bst.insert(Card('s', i));
        bst.insert(Card('h', i));
    }
    for (int i = 1; i <= 13; i++) {
        assert(bst.contains(Card('c', i)));
        assert(bst.contains(Card('d', i)));
        assert(bst.contains(Card('s', i)));
        assert(bst.contains(Card('h', i)));
    }
    for (int i = 1; i <= 13; i++) {
        assert(bst.remove(Card('c', i)));
        assert(bst.remove(Card('d', i)));
        assert(bst.remove(Card('s', i)));
        assert(bst.remove(Card('h', i)));
    }
}
void testIteratorsEmptyTree() {
    CardBST bst;
    assert(bst.begin() == bst.end());
}
void testIteratorsSingleNode() {
    CardBST bst;
    bst.insert(Card('c', 1));
    auto it = bst.begin();
    assert(*it == Card('c', 1));
    ++it;
    assert(it == bst.end());
}
void testIteratorsMultipleNodes() {
    CardBST bst;
    bst.insert(Card('c', 1));
    bst.insert(Card('d', 1));
    bst.insert(Card('s', 1));
    bst.insert(Card('h', 1));
    auto it = bst.begin();
    assert(*it == Card('c', 1));
    ++it; assert(*it == Card('d', 1));
    ++it; assert(*it == Card('s', 1));
    ++it; assert(*it == Card('h', 1));
    ++it; assert(it == bst.end());
}
void testIteratorsEndBehavior() {
    CardBST bst;
    bst.insert(Card('c', 1));
    auto it = bst.begin();
    ++it;
    assert(it == bst.end());
}
void testIteratorsComparison() {
    CardBST bst;
    bst.insert(Card('c', 1));
    bst.insert(Card('d', 1));
    auto it1 = bst.begin();
    auto it2 = bst.begin();
    assert(it1 == it2);
    ++it1;
    assert(it1 != it2);
}
void testReverseIteratorsEmptyTree() {
    CardBST bst;
    assert(bst.rbegin() == bst.rend());
}
void testReverseIteratorsMultipleNodes() {
    CardBST bst;
    bst.insert(Card('c', 1));
    bst.insert(Card('d', 1));
    bst.insert(Card('s', 1));
    bst.insert(Card('h', 1));
    auto it = bst.rbegin();
    assert(*it == Card('h', 1));
    --it; assert(*it == Card('s', 1));
    --it; assert(*it == Card('d', 1));
    --it; assert(*it == Card('c', 1));
    --it; assert(it == bst.rend());
}
void testPlayGameCommonCards() {
    CardBST alice, bob;
    alice.insert(Card('c', 1));
    alice.insert(Card('d', 1));
    alice.insert(Card('s', 1));
    alice.insert(Card('h', 1));
    bob.insert(Card('c', 1));
    bob.insert(Card('d', 2));
    bob.insert(Card('s', 3));
    bob.insert(Card('h', 4));
    playGame(alice, bob);
    assert(!alice.contains(Card('c', 1)));
    assert(!bob.contains(Card('c', 1)));
}
void testPlayGameOneEmptyHand() {
    CardBST alice, bob;
    bob.insert(Card('c', 1));
    playGame(alice, bob);
    assert(bob.contains(Card('c', 1)));
}
void testPlayGameNoCommonCards() {
    CardBST alice, bob;
    alice.insert(Card('c', 1));
    bob.insert(Card('d', 2));
    playGame(alice, bob);
    assert(alice.contains(Card('c', 1)));
    assert(bob.contains(Card('d', 2)));
}
int main() {
    testInsertAndRemoveAndContainsEmptyTree();
    testInsertAndRemoveAndContainsSingleNode();
    testInsertAndRemoveAndContainsMultipleNodes();
    testInsertAndRemoveAndContainsEdgeCases();
    testInsertAndRemoveAndContainsMemory();
    testIteratorsEmptyTree();
    testIteratorsSingleNode();
    testIteratorsMultipleNodes();
    testIteratorsEndBehavior();
    testIteratorsComparison();
    testReverseIteratorsEmptyTree();
    testReverseIteratorsMultipleNodes();
    testPlayGameCommonCards();
    testPlayGameOneEmptyHand();
    testPlayGameNoCommonCards();
    cout << "All tests passed" << endl;
    return 0;
}