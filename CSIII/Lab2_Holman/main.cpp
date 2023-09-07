#include <iostream>
#include <fstream>
#include <string>
#include "WordList.h"

int main(int argc, char* argv[]){
  WordList list; 
  std::ifstream inputFile1; 
  std::string fileWord, output, findWord, addedWord; 
  char switchAnswer; 
//  int numberofOccur = 0;
  inputFile1.open(argv[1]);

  if(inputFile1.fail()){
    std::cout << "error opening file." << std::endl; 
    exit(1);
  }
  else{
    std::cout << "successfully opened file." << std::endl; 
  }
  while(inputFile1 >> fileWord){
    list.addWord(fileWord); 
  }

  // ------------ INTERFACE ---------------
  std::cout << "What do you want to do with the file?" << std::endl; 
  std:: cout << "Output All Words [o]" << std::endl;
  std::cout << "Search Word? [s]" << std::endl;
  std::cout << "Add Word To List [a]" << std::endl;   
  switch(switchAnswer){
  case 'o':
    list.print();
    break;
  case 's':
      std::cout << "Input The Word You Would Like To Find And See How Many Times It Occures:" << std::endl;
      std::cin >> findWord; 
    //list.search(findWord)
    break; 
  case 'a':
      std::cout << "Enter Word You Would Like To Add To The List:" << std::endl;
      std::cin >> addedWord; 
      list.addWord(addedWord);
    default:
      std::cout << "no option chosen" << std::endl; 
      exit(1); 
  };
  /*
  while(inputFile1 >> fileWord){
    // string object.addWord(fileWord)
  }
  while(output = object.addWord()){
    // std::cout << output << std::endl;
  }
  */
  
  

  return 0; 
}
