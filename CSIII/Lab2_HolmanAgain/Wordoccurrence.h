#pragma once
#include <iostream>
#include <string>
//#include "wordlist.h"

using std::cout; 
using std::endl;
using std::cin; 
using std::string; 

class WordOccurrence{
public: 
  WordOccurrence(const string& word = "", int num = 0);
  bool matchWord(const string& word); 
  void increment();
  string getWord(); 
  int getNum(); 
private:
  string word_; 
  int num_;
};
