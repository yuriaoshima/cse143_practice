#include <iostream>
#include "LetterInventory.h"

using namespace std;

int main() {
  LetterInventory inventory ("Hello 8&82@ World");
  cout << "To string: " << inventory.toString() << endl;
  cout << "Is empty: " << inventory.isEmpty() << endl;
  cout << "Size: " << inventory.size() << endl;
  LetterInventory emptyInventory ("");
  cout << "To string: " << emptyInventory.toString() << endl;
  cout << "Is empty: " << emptyInventory.isEmpty() << endl;
  cout << "Size: " << emptyInventory.size() << endl;
}
