#include "wordlist.h" 
// CODE USED FROM LAB2 VIDEO 
WordList::WordList(const WordList& organization){ // default constructor that allocates the memory needed for the wordArray 
  size = organization.size; 

  wordArray = new WordOccurrence[organization.size]; 
  for (int i = 0; i < size; i++){
    wordArray[i] = WordOccurrence(organization.wordArray[i].getWord(), organization.wordArray[i].getNum());
  }
}

WordList::~WordList(){ // deletes the wordArray to not cause a memory leak
  delete[] wordArray; 
} 

WordList& WordList::operator = (const WordList& right){ // this makes it so that an object cannot copy or reassign itself 
  if(this != &right){
    size = right.size; 
    delete [] wordArray;
    wordArray = new WordOccurrence[right.size];
    for(int i = 0; i < size; i++){
      wordArray[i] = WordOccurrence(right.wordArray[i].getWord(), right.wordArray[i].getNum());
    }
  }
  return *this; 
}

WordList::WordList(){ // defualt constructor with no parameters that creates a blank wordArray and sets the size to 1
  wordArray = new WordOccurrence[1000];
  size = 1; 
} 

WordList::WordList(const string& word){ // another default constructor that sets the WordOccurrence to the second index, but the first index of the wordArray with a size of 1
  wordArray = new WordOccurrence[1];
  wordArray[0] = WordOccurrence(word, 1);
  size = 1;

}

void WordList::addWord(const string& word){ // when a word is added, it is checked to see if that word already exists in the Array and if it is then the WordOccurrence num is incremented by 1.
  bool check = false; 
  for (int i = 0; i < size; i++){
    if(wordArray[i].matchWord(word) == true){
      wordArray[i].increment();
      check = true; 
      break; 
    }
  }
  if(check == false){
      wordArray[size] = word; 
      wordArray[size++].increment();
  }
}

void WordList::sort(){ // this sorts the wordArray by a nested for-loop that sorts by the highest to lowest number of WordOccurrence
  for(int i = 0; i < size; ++i){
    for(int j = 0; j < size; ++j){
      if(wordArray[j].getNum() < wordArray[j + 1].getNum()){
        WordOccurrence temp = wordArray[j + 1]; 
        wordArray[j + 1] = wordArray[j]; 
        wordArray[j] = temp;  
      }
    }
  }
}

  void WordList::print(){ // a for loop that prints the contents of the wordArray 
  for(int i = 0; i < size; i++){
    cout << "Word: " << wordArray[i].getWord() << endl; 
    cout << "Occurs " << wordArray[i].getNum() << " times" << endl; 

  }
} 

  


