//#include <format>
#include <iostream>
#include <fstream>
#include "wordlist.h"
#include "Wordoccurrence.h"
using std::ifstream;
//using std::format;
//
void copyFunc(WordList& list){ // uses the copy constructor
  cout << "The Word List In The 'copyFunc' Function:" << endl;
  list.print();
}

// CODE USED FROM LAB2 DISCUSSION VIDEO 
int main(){ 
WordList list; // creates the object
  list.addWord("one"); 
  list.addWord("one");
  list.addWord("two");
  list.addWord("three");
  cout << "word list as is:" << endl; 
  list.print();

WordList list2, list3; 

  list3 = list3; 

  copyFunc(list);

  cout << "\n";

 // with file now 
WordList fileList;
string word; 
ifstream file1; 
file1.open("file1.txt");

  if(file1.fail()){
    cout << "File could not be opened"; 
    exit(1); 
  }
  // uses the strings from the file to put into the wordArray and sort them by occurrence and print them.
  while(file1 >> word){
    //std::format(word); 
    fileList.addWord(word); 
  }
  cout << "\n";
  cout << "Word List From File:" << endl;
  fileList.sort(); 
  fileList.print();
  cout << "\n"; 
  file1.close();
  
  return 0; 
}
