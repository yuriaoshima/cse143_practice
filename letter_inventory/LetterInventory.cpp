#include <string>
#include <iostream>
#include "LetterInventory.h"

using namespace std;

//constructor: initializes inventory with count of each letter. Ignores case and
//non-alphabetic charactersd
//member initialization of inventory and isTrue
LetterInventory::LetterInventory(string data) : inventory{}, empty(true), totalChars(0) {
  //go through each char, if already lowercase, increment at index char
  //if uppercase, convert then increment. Ignore non-alphabetic chars
  if (data.length()) { //only do the following for non-empty strings
    for (int i = 0; i < data.length(); i++) {
      char letter = data[i]; //get the individual char
      if (letter >= 'a' && letter <= 'z') { //if lowercase
        inventory[letter - 'a']++; //for indexing 0-25, increment at corresponding char
        totalChars++;
      }
      if (letter >= 'A' && letter <= 'Z') { //if uppercase
        letter += 'a' - 'A'; //uppercase plus 'a'-'A' (32) gives lowercase
        inventory[letter - 'a']++;
        totalChars++;
      }
    }
    empty = false;
  }
}

string LetterInventory::toString() {
  string result = "[";
  for (int i = 0; i < 26; i++) { //for each count of each letter in inventory
    for (int j = 0; j < inventory[i]; j++) { //inventory[i] is the count of each letter
      result += (char)(i + 'a'); //adds the letter corresponding to index i to string
    }
  }
  result += "]";
  return result;
}

bool LetterInventory::isEmpty() {
  return empty;
}

int LetterInventory::size() {
  return totalChars;
}
