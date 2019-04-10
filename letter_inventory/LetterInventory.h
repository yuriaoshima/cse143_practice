//header guard
#ifndef LETTER_INVENTORY_H
#define LETTER_INVENTORY_H

#include <string>
#include <iostream>

class LetterInventory {

public:
  LetterInventory(std::string data); //constructor, fills inventory array
  std::string toString(); //returns string representation of array with brackets
  bool isEmpty(); //returns if the inventory is empty or not
  int size(); //returns the total chars in inventory
  int get(char letter);
  void set(char letter, int value);
  LetterInventory* add(LetterInventory other);

private:
  int inventory[26]; //to hold count of each letter
  int totalChars;
};

#endif
