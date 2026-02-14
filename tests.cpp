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
        assert(!bst.contains(Card('c', i)));
        assert(bst.remove(Card('d', i)));
        assert(!bst.contains(Card('d', i)));
        assert(bst.remove(Card('s', i)));
        assert(!bst.contains(Card('s', i)));
        assert(bst.remove(Card('h', i)));
        assert(!bst.contains(Card('h', i)));
    }
}
void testIteratorsEmptyTree() {
    CardBST bst;
    auto it = bst.begin();
    auto end = bst.end();
    assert(it == end);
}
void testIteratorsSingleNode() {
    CardBST bst;
    bst.insert(Card('c', 1));
    auto it = bst.begin();
    auto end = bst.end();
    assert(it != end);
    assert(*it == Card('c', 1));
    ++it;
    assert(it == end);
}
void testIteratorsMultipleNodes() {
    CardBST bst;
    bst.insert(Card('c', 1));
    bst.insert(Card('d', 1));
    bst.insert(Card('s', 1));
    bst.insert(Card('h', 1));
    auto it = bst.begin();
    auto end = bst.end();
    assert(it != end);
    assert(*it == Card('c', 1));
    ++it;
    assert(it != end);
    assert(*it == Card('d', 1));
    ++it;
    assert(it != end);
    assert(*it == Card('s', 1));
    ++it;
    assert(it != end);
    assert(*it == Card('h', 1));
    ++it;
    assert(it == end);
}
void testIteratorsIncrementingPastEnd() {
    CardBST bst;
    bst.insert(Card('c', 1));
    auto it = bst.begin();
    auto end = bst.end();
    assert(it != end);
    assert(*it == Card('c', 1));
    ++it;
    assert(it == end);
    --it;
    assert(it != end);
    assert(*it == Card('c', 1));
    --it;
    assert(it == end);
}
void testIteratorsComparison() {
    CardBST bst;
    bst.insert(Card('c', 1));
    bst.insert(Card('d', 1));
    auto it1 = bst.begin();
    auto it2 = bst.begin();
    auto end = bst.end();
    assert(it1 == it2);
    assert(it1 != end);
    assert(it2 != end);
    ++it1;
    assert(it1 != it2);
    assert(it1 != end);
    assert(it2 != end);
}
void testPlayGameCommonCards() {
    CardBST aliceSet;
    CardBST bobSet;
    aliceSet.insert(Card('c', 1));
    aliceSet.insert(Card('d', 1));
    aliceSet.insert(Card('s', 1));
    aliceSet.insert(Card('h', 1));
    bobSet.insert(Card('c', 1));
    bobSet.insert(Card('d', 2));
    bobSet.insert(Card('s', 3));
    bobSet.insert(Card('h', 4));
    playGame(aliceSet, bobSet);
    assert(!aliceSet.contains(Card('c', 1)));
    assert(aliceSet.contains(Card('d', 1)));
    assert(aliceSet.contains(Card('s', 1)));
    assert(aliceSet.contains(Card('h', 1)));
    assert(!bobSet.contains(Card('c', 1)));
    assert(bobSet.contains(Card('d', 2)));
    assert(bobSet.contains(Card('s', 3)));
    assert(bobSet.contains(Card('h', 4)));
}
void testPlayGameOneEmptyHand() {
    CardBST aliceSet;
    CardBST bobSet;
    bobSet.insert(Card('c', 1));
    bobSet.insert(Card('d', 2));
    playGame(aliceSet, bobSet);
    assert(aliceSet.begin() == aliceSet.end());
    assert(bobSet.contains(Card('c', 1)));
    assert(bobSet.contains(Card('d', 2)));
}
void testPlayGameNoCommonCards() {
    CardBST aliceSet;
    CardBST bobSet;
    aliceSet.insert(Card('c', 1));
    aliceSet.insert(Card('d', 1));
    aliceSet.insert(Card('s', 1));
    aliceSet.insert(Card('h', 1));
    bobSet.insert(Card('c', 2));
    bobSet.insert(Card('d', 2));
    bobSet.insert(Card('s', 2));
    bobSet.insert(Card('h', 2));
    playGame(aliceSet, bobSet);
    assert(aliceSet.contains(Card('c', 1)));
    assert(aliceSet.contains(Card('d', 1)));
    assert(aliceSet.contains(Card('s', 1)));
    assert(aliceSet.contains(Card('h', 1)));
    assert(bobSet.contains(Card('c', 2)));
    assert(bobSet.contains(Card('d', 2)));
    assert(bobSet.contains(Card('s', 2)));
    assert(bobSet.contains(Card('h', 2)));
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
    testIteratorsIncrementingPastEnd();
    testIteratorsComparison();
    testPlayGameCommonCards();
    testPlayGameOneEmptyHand();
    testPlayGameNoCommonCards();
    cout << "All tests passed" << endl;
    return 0;
}
