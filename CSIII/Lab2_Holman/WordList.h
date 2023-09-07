#pragma once
#include <iostream> 
#include <string>

struct Node{
  std::string word; 
  Node* next; 
};

class WordOccurrence {
public:
    WordOccurrence(const std::string& word="", int num=0);
    WordOccurrence(const std::string& word ="");
    bool matchWord(const std::string &); // returns true if word matches stored
    void increment(); // increments number of occurrences
    std::string getWord() const; 
    int getNum() const;

private:
  std::string word_;
  int num_;
};

class WordList{
public:
  
    WordList(); // constructor
    ~WordList(); // destructor
    WordList(const WordList&); // Copy 

    // implement comparison as friend
    friend bool equal(const WordList&, const WordList&);
  void Search();
    void addWord(const std::string &);
    std::string WordPop(); 
    void print();
private:
    Node* head; 
    WordOccurrence *wordArray_; // a dynamically allocated array of WordOccurrences
                                // may or may not be sorted
    int size_;
};
