#include <stdio.h>
#include <stdlib.h>

// CODE USED/MODIFIED FROM 
// https://codeforwin.org/c-programming/c-program-to-count-occurrences-of-word-in-string
// https://www.opentechguides.com/how-to/article/c/45/c-read-file.html - was also used in exercise 2
// https://codeforwin.org/c-programming/c-program-count-characters-words-lines-in-file

int main(int argc, char * argv[]){
  FILE * file; // var for opening file 
  char * filename; // string for the filename input
  char c; // a character to be used later on
  char * param1;
  char * param2; 
  int intParam1, intParam2; 
  //int character; 
  //int word; 


  if(argc < 2){ // if argc is less than 2 than there was no command line input
    printf("No File Name Given...\n");
    return (1); 
  }
  else{
    filename = argv[1]; // the file name is equal to the command line argument
    printf("Filename: %s\n", filename); // prints the file name
  }
  if(argc < 3){
    printf("Parameter 1 Not Given...\n");
    return (1); 
  }
  else{
    param1 = argv[2];
  }
  if(argc < 4){
    printf("Parameter 2 Not Given...\n");
    return (1);
  }
  else{
    param2 = argv[3];
  }
  file = fopen(filename, "r"); // opens the file in read-mode
  //param1 = argv[2];
  //param2 = argv[3];
  intParam1 = atoi(param1);
  intParam2 = atoi(param2);
  int character = 0; // initalized character int to 0
  int word = 0; // initalized word int to 0
  if(file){ // if the file is opneed
    //printf("File Contents: \n");
    while((c = fgetc(file)) != EOF){ // run a loop with the character being equal to fscanc for all the characters in the strings 
      //character++; 
      if(c == ' ' || c == '\t' || c == '\n' || c == '\0'){ // checks to see if there are any line breaks or spaces
        if(character >= intParam1 && character <= intParam2){
          word++;  // if the bytes of each string are between 3 and 15 then the word is incremented by 1
        }   
        character = 0; // resets the character counter to 0
      }
      else{
        character++; // increments the chracters if the if-statement is false
      }
    }
  }
  printf("\ntotal words in file whose bytes are between 3 and 15 are %d\n", word); // prints the toal amount of words within the parameters

  fclose(file); // closes the file
  return 0; 
}
