#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// CODE FROM https://stackoverflow.com/questions/19389439/splitting-strings-with-c
void split(char* name, char* output){ // a void function that takes 2 char pointer arguments
	while(*name){ // a whole loop that loops through the characters of the array 
		if(isupper(*name)){ // using the isupper() function to detech any upper case letters in the string
		 	*output++ = ' '; // when an uppercase is detected, a space is added at that index to the char array
		}
		*output++ = *name++; // the output with the space in it is assigned to the original char pointer
	}
	*output = '\0'; // added the null terminator to the string

}

int main(int argc, char* argv[]){
  
	char* output[20]; // creates a char array pointer with the max characters of 20. 
	char* finalOutput; // creates an empty char array that will be assigned to the strtok later
	char* name = argv[1]; // char pointer that taes the command line argument
	printf("%s\n", name); // prints the original, non-spaced name
	split(name, output); // this calls the split function to separate the string into 2
	finalOutput = strtok(output, " "); // the char pointer is using strtok to look for any spaces and separate the string
	while(finalOutput != NULL){ // a while function that loops through the array until the array ends
		printf("%s ", finalOutput); // prints the first and last token 
    //printf("%s last: ", finalOutput);
		
    finalOutput = strtok(NULL, " "); // the char pointer looks for the second token using strtok and since the string has been split into 2 tokens the function has nothing to look back on. 
    
    //printf("%s last: ", finalOutput); 
	}
  printf("\n");
  
	return 0; 
}


// I tried to get it to print 'first' & 'last', but with the loop, it would print them 2 times each. 
