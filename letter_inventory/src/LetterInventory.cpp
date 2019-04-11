#include <string>
#include <iostream>
#include "LetterInventory.h"

using namespace std;

//define static constant for inventory size
const int LetterInventory::inventory_size = 26;

//constructor: initializes inventory with count of each letter. Ignores case and
//non-alphabetic charactersd
//member initialization of inventory and isTrue
LetterInventory::LetterInventory(string data) : inventory{}, totalChars(0) {
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
  }
}

//returns the array as a string of sorted letters
string LetterInventory::toString() {
  string result = "[";
  for (int i = 0; i < inventory_size; i++) { //for each count of each letter in inventory
    for (int j = 0; j < inventory[i]; j++) { //inventory[i] is the count of each letter
      result += (char)(i + 'a'); //adds the letter corresponding to index i to string
    }
  }
  result += "]";
  return result;
}

//returns whether the inventory is empty (all counts are zero)
bool LetterInventory::isEmpty() {
  //check if count of total chars is zero (empty, returns true)
  return (totalChars == 0);
}

//returns a sum of all counts in the inventory
int LetterInventory::size() {
  return totalChars;
}

//returns the count of the given letter ignoring case
//throws invalid argument exception if a non-alphabetic letter is given
int LetterInventory::get(char letter) {
  //using a try/catch block so that if exception is thrown, the program continues and doens't crash
  try {
    //check if letter is lowercase
    if (letter >= 'a' && letter <= 'z') {
      return inventory[letter - 'a']; //to account for indexing offset
    } else if (letter >= 'A' && letter <= 'Z') { //check if uppercase, if so convert
      letter += 'a' - 'A';
      return inventory[letter - 'a'];
    } else { //otherwise, non-alphabetic, throw exception
      throw invalid_argument("Non-alphabetic letter was given");
    }
  } 
  catch (const invalid_argument& invalid_arg) {
    cerr << "Invalid argument: non-alphabetic letter was given" << endl;
  }
  return -1;
}

//sets the count at given letter to the value given ignoring case 
//throws invalid argument exception if letter is non-alphabetic or
//value given is negative
void LetterInventory::set(char letter, int value) {
  //throw invalid argument exception if value is negative
  try {
    if (value < 0) throw invalid_argument("Negative value given");
    if (letter >= 'a' && letter <= 'z') { //check if lowercase
      //first adjust the total count 
      totalChars += value - inventory[letter - 'a'];
      //then replace the old count with new
      inventory[letter - 'a'] = value;
    } else if (letter >= 'A' && letter <= 'Z') { //check if uppcase, if so convert
      letter += 'a' - 'A';
      totalChars += value - inventory[letter - 'a'];
      inventory[letter - 'a'] = value;
    } else {
      throw invalid_argument("Non-alphabetic letter was given");
    }
  }
  catch (const invalid_argument& invalid_arg) {
    cerr << "Invalid argument: non-alphabetic letter or negative value given" << endl;
  }
}

//returns a new letter inventory whose counts are the total of this letter inventory
//and the one passed as 'other'
LetterInventory* LetterInventory::add(LetterInventory other) {
  //create a new letter inventory
  //we can directly call the toString method of the object this function is being called on
  string combined_string = toString() + other.toString();
  //dynamically allocate new LetterInventory object and save it to a pointer 
  //Note: 'new' in c++ returns a pointer to dynamically allocated memory which is why we save it to a pointer
  LetterInventory *combined_inventory = new LetterInventory(combined_string);
  return combined_inventory;
}

//Returns a new letter inventory whose counts are equal to the difference between this letter inventory
//and the one passed as 'other'. (i.e. other's inventory is subtracted from this one's)
//If the subtraction of counts leads to a negative number, return a nullptr
LetterInventory* LetterInventory::subtract(LetterInventory other) {
  //create a new empty letter inventory
  LetterInventory *difference = new LetterInventory("");
  //go through each index in this letter inventory
  int temp_result;
  for (int i = 0; i < inventory_size; i++) {
    //get the difference between count in each inventory
    temp_result = inventory[i] - other.get(i + 'a');
    //if difference is negative return a null pointer
    if (temp_result < 0)
      return nullptr;
    //otherwise, set index at char in new inventory to temp_result
    difference->set(i + 'a', temp_result);
  }
  //if we've made it through the forloop, return the pointer to the object
  return difference;
}