#include <iostream>
#include "LetterInventory.h"

using namespace std;

int main() {
  //test with string with alphabetical and non-alphabetical letters
  cout << "Testing with string Hello 8&82@ World:" << endl;
  LetterInventory inventory ("Hello 8&82@ World");
  cout << "\tTo string: " << inventory.toString() << endl;
  cout << "\tIs empty: " << inventory.isEmpty() << endl;
  cout << "\tSize: " << inventory.size() << endl;
  cout << "\tCount for l: " << inventory.get('l') << endl;
  //cout << "Count for *: " << inventory.get('*') << endl;
  inventory.set('l', 0); 
  cout << "\tSize: " << inventory.size() << endl; //7
  cout << "\tCount for l: " << inventory.get('l') << endl; //0
  cout << "\n";

  //test with empty string
  cout << "Testing with empty string:" << endl;
  LetterInventory emptyInventory ("");
  cout << "\tTo string: " << emptyInventory.toString() << endl;
  cout << "\tIs empty: " << emptyInventory.isEmpty() << endl;
  cout << "\tSize: " << emptyInventory.size() << endl;
  cout << "\tCount for x: " << emptyInventory.get('x') << endl;
  emptyInventory.set('Z', 35);
  cout << "\tSize: " << emptyInventory.size() << endl; //35
  cout << "\tCount for z: " << emptyInventory.get('z') << endl;
  cout << "\tIs empty: " << emptyInventory.isEmpty() << endl;
  emptyInventory.set('3', 2);
  emptyInventory.set('p', -9);
  cout << "\n";

  //testing add method
  cout << "Testing add method:" << endl;
  LetterInventory first ("qwert");
  cout << "\tTo string: " << first.toString() << endl;
  LetterInventory second ("yuiop");
  cout << "\tTo string: " << second.toString() << endl;
  LetterInventory *sum = first.add(second);
  cout << "\tTo string: " << sum->toString() << endl;
  cout << "\tSize: " << sum->size() << endl;
  cout << "\tIs empty: " << sum->isEmpty() << endl;
  //LetterInventory dereferenced = *sum;
  //cout << "\tTo string for deferenced inventory: " << dereferenced.toString() << endl;
  cout << "\n";

  //testing subtract method
  cout << "Testing subtract method:" << endl;
  LetterInventory sub1 ("abcdabcdabcdabcd");
  cout << "\tTo string: " << sub1.toString() << endl;
  LetterInventory sub2 ("abcd");
  cout << "\tTo string: " << sub2.toString() << endl;
  LetterInventory *difference = sub1.subtract(sub2);
  cout << "\tTo string: " << difference->toString() << endl;
  cout << "\tSize: " << difference->size() << endl;
  LetterInventory *negative = sub2.subtract(sub1);
  cout << negative << endl;
}
