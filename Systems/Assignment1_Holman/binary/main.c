#include <stdio.h>

// code from https://www.youtube.com/watch?v=LdqEJgW3N7s&
int main(void){
// creates to int variables
int i, j; 
printf("Enter a Integer Value: "); // asks for user input
scanf("%d", &j); // gets the user input
for(i = 31; i>=0; i--){ // runs a loop for 32 cycles for 32 bits
    if(j&(1<<i)){ // if the bit shifts match to 1 then one is printed, if not then 0 is printed. 
      printf("1"); 
    }
    else{
      printf("0");
    }
  }
printf("\n"); 
  
return 0; 

} 
