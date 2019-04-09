//header guard
#ifndef LETTER_INVENTORY_H
#define LETTER_INVENTORY_H

#include <string>
#include <iostream>

class LetterInventory {
public:
  LetterInventory(std::string data);
  void printInventory();
private:
  int inventory[26]; //to hold count of each letter
  bool isEmpty; //tracks of the inventory is empty or not
};

#endif
