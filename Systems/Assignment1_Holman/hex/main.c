#include <stdio.h>
// code from https://www.youtube.com/watch?v=3u_YzeCIbSw
int convertToHex(int num); 

int main(void){
int num; 
printf("Enter a Number: \n"); // asks for input
scanf("%d", &num); // gets user input
printf("Your number %d \n", num); // prints the number before conversion
printf("Hexadecimal Representation: %x \n", num); // uses the built in hex converter
return 0; 
}

