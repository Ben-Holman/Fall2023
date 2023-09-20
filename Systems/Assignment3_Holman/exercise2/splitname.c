#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// CODE FROM 
void split(char* name, char* output){
	while(*name){
		if(isupper(*name)){
		 	*output++ = ' '; 
		}
		*output++ = *name++; 
	}
	*output = '\0';

}

int main(int argc, char* argv[]){
	char* output[20];
	char* finalOutput; 
	char* name = argv[1];
	printf("%s\n", name);
	split(name, output);
	finalOutput = strtok(output, " ");
	while(finalOutput != NULL){
		printf("%s\n", finalOutput); 
		finalOutput = strtok(NULL, " ");
	}
	return 0; 
}

