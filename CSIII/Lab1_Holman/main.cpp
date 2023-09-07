#include <iostream>
#include <fstream>
//#include <stdio.h>
//#include <stdlib.h>
#include <string>
//#include <vector>
//#include "functions.h"



// Code from example on Canvas. Got the second string to display properly, but the carrot is not
// correct. 
int main(int argc, char* argv[]){
// this checks to see if the command line arguments as file inputs are valid and can be opened. 
std::ifstream inputFile1; 
inputFile1.open(argv[1]); 
if(inputFile1.fail()){
    std::cout << "Error opening " << argv[1] << " file." << std::endl;
    exit(1);
  }

  std::ifstream inputFile2; 
inputFile2.open(argv[2]); 
if(inputFile2.fail()){
    std::cout << "Error opening " << argv[2] << " file." << std::endl; 
    exit(1);
  }
// the lineCounter is sor the number of lines read into the program 
// the difference is to determine when there is no character match
// the spaces is for the length of the string length
int lineCounter = 1; 
bool difference = false; 
int spacesCounter = 0; 
// assigns the input from the files to the string variables
std::string str1; 
std::string str2;

while(!inputFile1.eof() || !inputFile2.eof()){
    // creates a loop that checks to see if either file reaches the end. 
    // if a file reaches the the end before the other, the file that finished first is assigned
    // character spaces to make the files even in length. 
    if(inputFile1.eof()){
      str1.assign(str2.length(), ' '); 
    }
    else{
      std::getline(inputFile1, str1);
      if(str1.length() == 0){
        str1.assign(str2.length(), ' '); 
      }
    }
    if(inputFile2.eof()){
      str2.assign(str1.length(), ' '); 
    }
    else{
      std::getline(inputFile2, str2); 
      if(str2.length() == 0){
      str2.assign(str1.length(), ' ');
      }
    }

    std::string Length = "file1.txt: " + std::to_string(lineCounter) + ": "; 
    std::string spaces(Length.length(), ' '); 

    int j; 

    if(str1.length() > str2.length()){
       j = str2.length();
    }
    else{
      j = str1.length(); 
    }
    
    for(int i = 0; i <= j; i++){
      // if the characters in the strings do not match, then set the bool to true and break out
      // of the loop. If they do match then continue comparing the characters and adding 
      // the spaces.
      if(str1[i] != str2[i]){
         difference = true; 
         break; 
      }
      else{
        spacesCounter++; 
      }
    }
      if(difference){
      // prints out the file names, line numbers, and where the difference in characters are -- kind of
      std::cout << argv[1] << ": " <<  lineCounter << ":" << str1 << std::endl;
      std::cout << argv[2] << ": " << lineCounter << ":" << str2 << std::endl;
      std::cout << spaces; 
      for(int i = 0; i < spacesCounter; i++){
        std::cout << " "; 
        //std::cout << "^";
      } 
        std::cout << "^  "; // since my corrot was one space off, I thought I could offset that by 
        // having a space in front of the carrot, pushung it back a space. 
        std::cout << "\n"; 
    }
    // resets the counter and Bool to their original values
    spacesCounter = 0; 
    difference = false; 
    lineCounter++;
}






  //std::cout << "\n"; 

inputFile1.close(); 
inputFile2.close(); 




  return 0; 
}
