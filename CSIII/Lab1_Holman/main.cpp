#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

void compare(std::string inputString1, std::string inputString2){
if(inputString1.compare(inputString2) == 0){ // code from "comparing Strings in C++ from NetSecProf YouTube"
    std::cout << "Strings are the same" << std::endl; 
  }
  else if(inputString1.compare(inputString2) < 0){
    std::cout << "String are not the same" << std::endl; 
  }
}


int main(int argc, char* argv[]){

/* Need to get the files read properly 
FILE *f1;  
  f1 = fopen(argv[1], "r");  
FILE *f2;  
  f2 = fopen(argv[2], "r");
*/
int linecounter = 1, linecounter2 = 1; 

  for(int i = 0; i < argc; i++){
    std::cout <<"Arg: " << i << " " << argv[i] << std::endl; 
  }
  // C version:
  //FILE *file_to_read = fopen("file1.txt", "r"); <-- gave an unused var error

  //C++ version:
  std::string inputString;
  std::ifstream inputFile(argv[1]); 
  if(inputFile.is_open()){
    while(std::getline(inputFile, inputString)){
      std::cout << "file1.txt: " << linecounter << ": " << inputString << std::endl;
      linecounter++; 
    }
  }
  std::cout << "\n"; 
  std::string inputString2;
  std::ifstream inputFile2(argv[2]); 
  if(inputFile2.is_open()){
    while(std::getline(inputFile2, inputString2)){
      std::cout <<"file2.txt: " << linecounter2 << ": " << inputString2 << std::endl;
      linecounter2++; 
    }
  }
  //inputString.compare() 
  compare(inputString, inputString2); 
    inputFile.close(); 
    inputFile2.close();
  return 0; 
}
