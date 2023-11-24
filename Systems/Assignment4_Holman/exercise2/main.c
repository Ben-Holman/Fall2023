#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CODE USED/MODIFIED FROM:
//https://cboard.cprogramming.com/c-programming/40527-reading-file-word-word.html/
//https://codeforwin.org/c-programming/c-program-to-search-all-occurrences-of-word-in-string 
// https://www.opentechguides.com/how-to/article/c/45/c-read-file.html 

#define MAX_SIZE 100 // Maximum string size

int main(int argc, char* argv[]){
  FILE * file; // var for file read
  char * filename; // string for file name
  //char * c;
  char * cptr = (char*)malloc(sizeof(char) * 10); // dynamic allocation for a char array 
  char word[MAX_SIZE]; // setting the word array to max size of 100 as defined at the start


  if(argc < 2){ // error detection for the file input, if it is less than 2 than no file was inputted.
    printf("No File Name Given...\n");
    return (1); 
  }
  else{
    filename = argv[1]; // the char array is equal to the command line argument file name
    printf("Filename: %s\n", filename); // prints the file name 
  }
  printf("Enter a substring to search:\n"); // asks the user to search for the substring
  gets(word); // uses the get() function to get the string from user 
  file = fopen(filename, "r"); // the file var opens the file in read-mode
  if(file){
    //printf("File Contents: \n");
    while((fscanf(file, "%s", cptr)) != EOF){ // using a while loop with fscanf to read until the end of the file
    //char str[MAX_SIZE];
    //char word[MAX_SIZE];
    int i; // used in loop
    int found = 1; // bool
    int strLen, wordLen; // to find the length of the string and word
    //int wordCount;
    /* Input string and word from user */
    //printf("Enter any string: ");
    //gets(str);
    //printf("Enter any word to search: ");
    //gets(word);

    //strLen  = strlen(str);  // Find length of string
    wordLen = strlen(word); // Find length of word


    /*
     * Run a loop from starting index of string to
     * length of string - word length
     */
    for(i=0; i < wordLen; i++){ 
      if(word[i] == cptr[i]){ // if the word is equal to the malloc pointer 
         found = 1; // then the bool is set to true
      }
      else {
        found = 0; // bool is set to false if nothing is found
        break; // breaks out of the if statement 
        }

        // If word have been found then print found message
    }
      if(found == 1){
        printf("%s\n", cptr); // if the bool is true than the result is printed to the screen
      }
    }
    //printf("The number of times this word occurs is: %d\n", wordCount);
    
  }
  free(cptr); // frees the memory
  fclose(file); // closes the file 
  return 0;
}

/*
 Write a program that reads a text file and prints out any words that begin with a user-given string. 
 The filename should be given at the command line as an argument. 
 The program should prompt the user for the search string. 
 The program should then read the file one word at a time and print out the word 
 if its first N bytes match the search string, where N is the length of the search string.
 */
