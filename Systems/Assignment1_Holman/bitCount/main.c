#include <stdio.h>


int main(void){
//bool isFound; 
// resued code from the Binary exercise
int i, j, k; // created a new variable, k
printf("Enter a Integer Value: "); 
scanf("%d", &j); 
for(i = 31; i>=0; i--){ // run the same loop for 32 bits
    if(j&(1<<i)){
      k++; // if the bit is a 1 then the bit counter variable goes up
      printf("1"); 
    }
    else{
      printf("0");
    }
  }
printf("\n"); 
printf("the number of 1-bits found in the binary number is: %d \n", k); // prints the bit counter after the loop 
printf("\n"); 
  
return 0; 

} 
