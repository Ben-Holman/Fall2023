#include <string.h>
#include <stdio.h>
// CODE FROM https://stackoverflow.com/questions/2488563/strcat-implementation
char *strcat(char *new, const char *input){ // char pointer function that takes 2 char pointer parameters

    size_t i,j; // size (in bytes) of the strings used in the loops.

    for (i = 0; new[i] != '\0'; i++){ 
    // loop that runs for the new string that checks the allocation of memory.
      ;
  }
    for (j = 0; input[j] != '\0'; j++){
        // loop that runs the length of the input array until the terminating character
        // the input array is recieving the characters from the input and tacking them on the end 
        // of the current character array. 
        new[i+j] = input[j];
    }
  
    // the new array has the terminating character added to it. 
    new[i+j] = '\0';

    return new; // returns the new character array. 

}


int main(void){
// creates the 2 strings.
  char a[10]={"abc"}, b[10]={"def"};
  printf("string1: %s\n", a);
  printf("string2: %s\n", b);
  strcat(a,b); // calls the function.
  printf("The String Concatonated:\n");
  printf("%s",a); // prints the new string.
  printf("\n");
return 0; 
}
