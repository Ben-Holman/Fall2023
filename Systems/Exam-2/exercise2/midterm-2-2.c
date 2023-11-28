#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// RESUSED CODE FROM ASSIGNMENT 4 WITH SLIGHT MODIFICATIONS
int main(int argc, char* argv[]){

  FILE * file; 
  char * filename; 
  char * bytes; 
//  char * word; 
  char * cptr = (char*)malloc(sizeof(char) + 10);
  if(argc < 2){
    printf("No File Name Given...\n"); 
    return (1);
  }
  else{
    filename = argv[1];
    printf("Filename: %s\n", filename); 
  }
  if(argc < 3){ // repeat the process for getting the other command line argument as I did the filename 
     printf("No Input Given...\n");
     return (1);
  }
  else{
    bytes = argv[2]; // the char number command line argument 
  }
  int num = atoi(bytes); // converts the command line char into an int 
  int i = 0;
  file = fopen(filename, "r");
  if(file){
    while((fscanf(file, "%c", cptr)) != EOF){
    //CODE USED FROM https://cboard.cprogramming.com/c-programming/146390-trim-last-character-string.html
    while(cptr[i] != '\0'){ // while the loop condition does not meet the enod of a string
        i++; // move on to the next character
    }

    cptr[i - num] = '\0'; // at the character index of the string, substract the command line numeric argument and set the null character value. 
  }
    printf("%s", cptr); // print the string
  }
  printf("\n");
  free(cptr); // free the memory
  fclose(file); // close the file
  return 0; 
}
