#include "Wordoccurrence.h"
// CODE USED FROM LAB2 VIDEO
WordOccurrence::WordOccurrence(const string& word, int num){ // default constructor
  word_ = word; 
  num_ = num; 
}

bool WordOccurrence::matchWord(const string& word){ // bool for matching the words in the wordArray that can increment the counter 
  if(word.compare(word_) == 0){
    return true; 
  }
  else {
    return false; 
  }
}

void WordOccurrence::increment(){ // increments the num variable
  num_++; 
}

string WordOccurrence::getWord(){ // gets the word to be printed
 return word_;
}

int WordOccurrence::getNum(){ // prints the number of times the word has occured
  return num_; 
} 
