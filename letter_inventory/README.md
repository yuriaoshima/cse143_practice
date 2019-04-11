# Summary
This project is the implementation of the LetterInventory class which takes a string as an argument and stores the counts of each letter of the string in an integer array. The array is size 26, an index for each letter of the alphabet. Non-alphabetic characters and case are ignored. 

# Class functions
### LetterInventory(String data)
    Constructs an inventory (a count) of the alphabetic letters in the given string, ignoring the case of letters and ignoring any non-alphabetic characters.

### int get(char letter)
    Returns a count of how many of this letter are in the inventory.  Letter might be lowercase or uppercase (your method shouldn’t care).  If a nonalphabetic character is passed, your method should throw an invalid_argument exception.

### void set(char letter, int value)
    Sets the count for the given letter to the given value.  Letter might be lowercase or uppercase.  If a nonalphabetic character is passed or if value is negative, your method should throw an invalid_argument exception

### int size()
    Returns the sum of all of the counts in this inventory.  This operation should be “fast” in that it should store the size rather than having to compute it each time this method is called.

### bool isEmpty()
    Returns true if this inventory is empty (all counts are 0).  This operation should be fast in that it should not need to examine each of the 26 counts when it is called.

### string toString()
    Returns a String representation of the inventory with the letters all in lowercase and in sorted order and surrounded by square brackets.  The number of occurrences of each letter should match its count in the inventory.  For example, an inventory of 4 a’s, 1 b, 1 l and 1 m would be represented as “[aaaablm]”.

### LetterInventory* add(LetterInventory other)
    Constructs and returns a pointer to a new LetterInventory object that represents the sum of this letter inventory and the other given LetterInventory.  The counts for each letter should be added together.  The two LetterInventory objects being added together (this and other) should not be changed by this method

### LetterInventory* subtract(LetterInventory other)
    Constructs and returns a pointer to a new LetterInventory object that represents the result of subtracting the other inventory from this inventory (i.e., subtracting the counts in the other inventory from this object’s counts).  If any resulting count would be negative, your method should return null.  The two LetterInventory objects being subtracted (this and other) should not be changed by this method

## How to compile and run
To compile the project run the following:  
    $ g++ -std=c++11 -o main -I include src/main.cpp src/LetterInventory.cpp

Then run:   
    ./main