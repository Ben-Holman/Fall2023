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
	cone.addItem(1); 
	cone.addItem(2); 
	cone.addItem(3); 
	cone.printCollection(); 
	cone.removeItems(2); 
	cone.printCollection(); 

	// manipulating strings string 
  string sa[] = {"yellow", "orange", "green", "blue"}; 
	list<string> ctwo; 
	for(auto s : sa) 
		ctwo.addItem(s); 
	cout << "String collection: "; 
	ctwo.printCollection(); 

	// manipulating character collections individal collections 
	list<char> a2g, h2n, o2u; 
	for(char c='a'; c <='g'; ++c){
		a2g.addItem(c);
  }

	for(char c='h'; c <='n'; ++c){ 
		h2n.addItem(c); 
  }

	for(char c='o'; c <='u'; ++c){ 
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
