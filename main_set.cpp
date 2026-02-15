// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
  std::set<Card> aliceSet;
  std::set<Card> bobSet;

  while (getline (cardFile1, line) && (line.length() > 0)){
      char suit = line[0];
      string strVal = line.substr(2);
      int value = Card::valueFromString(strVal);
      aliceSet.insert(Card(suit, value));
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    char suit = line[0];
    string strVal = line.substr(2);
    int value = Card::valueFromString(strVal);
    bobSet.insert(Card(suit, value));
  }
  cardFile2.close();
  
  bool turnAlice = true;
  while (true) {
    bool cardMatch = false;
    if (turnAlice) {
      for (auto it = aliceSet.begin(); it != aliceSet.end(); it++) {
        if (bobSet.find(*it) != bobSet.end()) {
          cout << "Alice picked matching card " << *it << endl;
          bobSet.erase(*it);
          aliceSet.erase(it);
          cardMatch = true;
          break;
        }
      }
    }
    else {
      for (auto it = bobSet.end(); it != bobSet.begin();) {
        it--;
        if (aliceSet.find(*it) != aliceSet.end()) {
          cout << "Bob picked matching card " << *it << endl;
          aliceSet.erase(*it);
          bobSet.erase(it);
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
  cout << endl;
  cout << "Alice's cards:" << endl;
  for (auto it = aliceSet.begin(); it != aliceSet.end(); ++it) {
    cout << *it << endl;
  }
  cout << endl;
  cout << "Bob's cards:" << endl;
  for (auto it = bobSet.begin(); it != bobSet.end(); ++it) {
    cout << *it << endl;
  }
  return 0;
}
