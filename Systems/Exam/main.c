#include "functions.hpp"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
//#define SIZE 10;

int main(void){
  printf("Welcome to String Math, where we do arithmetic on strings!\n");
  printf("You will be prompted to give an input or quit the program\n");
  char answer;
  //bool condition = true;
  printf("Begin? (Y/N)\n"); 
  scanf("%c", &answer); 
  if(answer == 'Y' || answer == 'y'){
    printf("Beginning Program...\n");
    sleep(3); // pauses the program for 3 seconds and then continues 
  }
  else{
    printf("Exiting Program...\n"); 
    sleep(3); // pauses the program for 3 seconds and then continues 
    exit(1);
  }
  printf("Enter a String of up to 9 characters and must have a aritmetic symbol separating a set of characters.\n"); 
  char input[10];
  int size = 10; 
  char left[5]; 
  char right[5];
  int Iright[5]; 
  int Ileft[5];
  int complete[10];
  scanf("%s", input); 
  printf("You Entered: %s\n", input); 
  stringCheck(input, size);
  operation(input, size);
  substring(input, left, 4, 3);
  substring(input, right, 5, 3);
  printf("Conversion:\n"); 
  printf("%s %d \n",converttoInt(right, Iright, 5));
  converttoInt(left, Ileft, 5);
  //converttoInt(input, size);
 add(Ileft, Iright, complete, 10);
  
  return 0; 
}

// CODE BIBLIOGRAPHY
// Sleep() Function: https://www.geeksforgeeks.org/sleep-function-in-c/#
// stringCheck() Function: https://www.youtube.com/watch?v=NBcG-r0P9P8
// substring() Function: https://www.youtube.com/watch?v=lEvpLI50MSU
// adding all elements in an array: https://www.javatpoint.com/c-program-to-print-the-sum-of-all-elements-in-an-array
