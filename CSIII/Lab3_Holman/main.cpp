// 1/25/2018
#include <string>
#include <iostream>
#include "linkedlist.h"
//#include "Collection.h" // template definition 
using namespace std; 

int main(){ 
	// manipulating integers 
	list<int> cone; 
	cout << "Integer collection: ";
  // using the template classes in linkedlist.h to create an integer list
	cone.addItem(1);  
	cone.addItem(2); 
	cone.addItem(3); 
	cone.printCollection(); // prints list before removal 
	cone.removeItems(2); // removes the list node containing the value "2"
	cone.printCollection(); // prints the integer list

	// manipulating strings string 
  // using the linkedlist.h template class to create a string list 
  string sa[] = {"yellow", "orange", "green", "blue"}; // string array
	list<string> ctwo; // created a string list 
	for(auto s : sa) // using an auto for loop to add the contents from the array into the string list 
		ctwo.addItem(s); 
	cout << "String collection: "; 
	ctwo.printCollection(); // prints the string list 

	// manipulating character collections individal collections
  // // using the linkedlist.h template class to create a character list 
	list<char> a2g, h2n, o2u; // creating 3 character lists 
	for(char c='a'; c <='g'; ++c){ // the first list runs through the ASCII values of 'a' through 'g' and puts those letters in the first list 
		a2g.addItem(c);
  }

	for(char c='h'; c <='n'; ++c){ // the second list runs through the ASCII values of 'h' through 'n' and puts those letters in the second list 
		h2n.addItem(c); 
  }

	for(char c='o'; c <='u'; ++c){ // the third list runs through the ASCII values of 'o' through 'u' and puts those letters in the third list
		o2u.addItem(c); 
  }

	// collection of collections 
	list<list<char>> cpile; 

	// adding individual collections 
	cpile.addItem(a2g); 
	cpile.addItem(h2n); 
	cpile.addItem(o2u); 

	// printing characters from last collection added 
	cout << "Last added character collection: " << endl; 
	cpile.lastItem().printCollection(); 
} 
