/* @Author
 * Student Name: Burak Aslantas
 * Student ID: 20190702029
 * Date: 27.12.2021
 */
#include <iostream>
#include <string>

// Well, power operation in C++ requires this library.
// I'm pretty sure you'll find out why the power operation would be required.
#include <math.h>
#include "intSLList.h"
using namespace std;

// This one is our hash table
IntSLList hashTable[10];

// Also we need to store our input types to differentiate strings and large integers
// Using 0 for Int, 1 for String, basically?
IntSLList hashType[10];

// Function initial declarations
void pleaseHelpMeWithHashValues();
void insertIntoHashTable(int input);
void insertIntoHashTable(const char* input);
bool searchInHashTable(int input);
bool searchInHashTable(const char* input);
void printHashTable();

// Hashing function for integer inputs.
// This function should insert an element only
// if there are no duplicates within the table.
void insertIntoHashTable(int input) {
	int hashAddress = input % 10;

	// We need to check whether the value is in hash or not
	if (!searchInHashTable(input)) {
		// We need to input for both our Hash Table and Hash Type tables
		hashTable[hashAddress].addToTail(input);
		hashType[hashAddress].addToTail(0);
	}

	return;
}

// This may be helpful for your understanding.
void pleaseHelpMeWithHashValues() {
	cout << "Printable ASCII [48..90]:\n";
	for (char i = '0'; i <= 'Z'; ++i) {
		cout << i << ((i % 16 == 15) ? '\n' : ' ');
	}
	cout << endl << "ASCII val. of 'A' is: " << (int)'A' << endl;
	cout << "Value 65 equals to character: " << (char)65 << endl;

	// Hint: The largest integer that C++ supports is 2147483647
	// These characters are 2-digit each.
	// Let's go with 4-character string support then.
	// Listed values are greater than 21, that's why we aren't using 5 digits.

	return;
}

// Hashing function for string inputs.
// Remember, one of the best features of C++ is function overloading,
// as long as the function signatures are different
// you can have two different functions with the same name.
void insertIntoHashTable(const char* input) {
	// Now... Strings. How would you store a string within an integer list?
	// IntSLList, as the "Int" in its name indicates, only stores Integers.
	// Then, what magic allows us to somehow do it?..
	// Hashing itself! Hashing your string into an integer!
	// So you should hash your value to hash it.
	// "Çifte kavrulmuş" hash? Sort of...
	int stringConvertedIntoInt = 0;
	int hashAddress;
	
	if (!searchInHashTable(input)) {
		// We need to input for both our Hash Table and Hash Type tables
		// To treat const char* as a string, you should use string's standard constructor
		string s = input;
		
        for(auto i : s)
        {
            stringConvertedIntoInt += (int)i;
            stringConvertedIntoInt *= 100;
        }
        
        stringConvertedIntoInt /= 100;
        hashAddress = stringConvertedIntoInt % 10;
        hashTable[hashAddress].addToTail(stringConvertedIntoInt);
	    hashType[hashAddress].addToTail(1);
	}

	// And you need to hash elements into 2-digits, each, right?
	// Therefore you need to multiply values to add 0's and separate them.
	return;
}

// Function to return whether a value is in our hash table or not.
bool searchInHashTable(int input) {
	// This one is simple. Simply get input's hash value and search input within HashTable[hash].
	// There is a function that scans a linked list implemented already.
	// If the value exists, this function returns true. False otherwise.
	int hashAddress = input % 10;
	
	return hashTable[hashAddress].isInList(input);
}

// The same as above, overloaded as hash table insertion.
bool searchInHashTable(const char* input) {
	// Same as above. However, now you should first hash string to integer for lookup first.
	int stringConvertedIntoInt = 0;
	int hashAddress;
	string s = input;
		
    for(auto i : s)
    {
        stringConvertedIntoInt += (int)i;
        stringConvertedIntoInt *= 100;
    }
    
    stringConvertedIntoInt /= 100;
    hashAddress = stringConvertedIntoInt % 10;
    
    return hashTable[hashAddress].isInList(stringConvertedIntoInt);
}

// You already know printing. No need to take your time with this function.
void printHashTable() {
	for (int i = 0; i < 10; i++) {
		cout << "\tPrinting hash table for hash " << i << ":" << endl;
		cout << "Hash Table values are: ";
		hashTable[i].printAll();
		cout << "Value types are (0 for int, 1 for string): ";
		hashType[i].printAll();
	}
}

int main() {
	
	// ASCII helper function call
	pleaseHelpMeWithHashValues();

	// Sample test lines, comment/delete them initially to be able to run your code.
	insertIntoHashTable(1);
	insertIntoHashTable(11);
	insertIntoHashTable(6);
	insertIntoHashTable(121);
	insertIntoHashTable("AAA");
	insertIntoHashTable("Y");
	insertIntoHashTable("30E");
	printHashTable();
	cout << "search begin:" << endl;
	cout << searchInHashTable(11) << endl;
	cout << searchInHashTable(10) << endl;
	cout << searchInHashTable(66) << endl;
	cout << searchInHashTable("AAA") << endl;
	cout << searchInHashTable("AA") << endl;

	return 0;
}
