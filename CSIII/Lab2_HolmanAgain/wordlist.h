#pragma once
#include "Wordoccurrence.h"
#include <iostream>
#include <string>
#include <algorithm>

using std::string; 
using std::cout; 
using std::endl; 
using std::cin; 

class WordList{
public:
  WordList(const WordList& organization);
  ~WordList(); 
  WordList& operator = (const WordList& right);

  WordList(); 
  WordList(const string& word);
  void addWord(const string& word);
  void print(); 
  void sort();// optional
  private:
  WordOccurrence* wordArray; 
  int size; 
};
