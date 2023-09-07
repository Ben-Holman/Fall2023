#include "WordList.h"

  
WordOccurrence::WordOccurrence(const std::string& word="", int num=0){
  word = word_; 
  num = num_; 
}

WordOccurrence::WordSearch(const std::string& word=""){
  word = word_; 
  
}

bool WordOccurrence::matchWord(const std::string&){
  
} // returns true if word matches stored

void WordOccurrence::increment(){
  num_++; 
} // increments number of occurrences

std::string WordOccurrence::getWord() const{
  return word_;
}

int WordOccurrence::getNum() const{
  return num_; 
}

//----------------------------------------------------   WORDLIST  ----------------------------------------------------------------------------
// add copy constructor, destructor, overloaded assignment
  
WordList::WordList(){
  head = NULL; 
}

WordList::~WordList(){
  delete[] wordArray;
  Node* deletion = next; 
  next = next->next; 
  delete deletion; 
}

WordList::WordList(const WordList&){

};

// implement comparison as friend
bool equal(const WordList&, const WordList&){

}

void WordList::Search(){
  for(){
   
    num_++; 
  }
}

void WordList::addWord(const std::string &added){
  Node* newWord = head; 
  newWord->word = added; 
  newWord->next = head; 
  head = newWord; 
}

std::string WordPop(){
  Node *pop = head;
  std::string popString;
  if(!head){
    return 
  }

   popString = pop->word; 
}

void WordList::print(){
 Node* print; 
  print = head; 
  while(print != NULL){
      std::cout << print->word << std::endl;
      print = print->next; 
  }
}
  

