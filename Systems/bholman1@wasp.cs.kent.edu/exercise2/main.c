#include <stdio.h>
// CODE FROM https://www.techiedelight.com/implement-strcpy-function-c/
char* copy(char* dest, char* input){ // a char pointer functions that takes 2 char pointer parameters
  if(dest == NULL){ // checks if there is memory allocated
    return NULL;
  }
  char* change = dest; // this pointer is for the beginning of the dest string 
  // this loops copies each character from one array to the other until it reaches
  // the terminating character
  while(*input != '\0'){
    *dest = *input; 
    dest++; 
    input++; 
  }
  // the copied string will have the terminating character added to it 
  *dest = '\0';
// returns the new copied string with the terminating character
  return change; 

}

int main(void){
// the driver program that has 2 char arrays with one array being empty waiting to be copied into 
// and the calling function in the print statement
  char input[] = "Ben Holman strcpy Function"; 
  char output[30]; 
  printf("%s\n", copy(output, input));
  return 0; 
}
