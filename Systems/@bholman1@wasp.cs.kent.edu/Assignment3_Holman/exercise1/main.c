#include <stdio.h>
//CODE FROM https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/# 

void reverse(int array[], int begin, int end){ // void function that takes the array, a beginning index and end index 

	int temp; // creates the temp variable for indexes to be swapped
	while(begin < end){ // while loop to loop from beginning to end
		temp = array[begin];// the temp variable is assigned to the beginning of the array
		array[begin] = array[end]; // the beginning indexes are being assigned to the end indexes
		array[end] = temp; // the end indexes are being transgerred to the temp variable that held the beginning indexes
    // this loops and swaps begin -> temp -> end -> temp
		begin++; // the beginning integer is added 
		end--; // the ending indexes decreases
  
	}
}

void print(int array[], int size){ // prints the array by running a loop through the indexes of the array
for(int i =0; i < size; i++){
	printf("%d\n", array[i]);
}
}

int main(void){
	int array[] = {1,2,3,4,5,6,7,8,9,0}; // created array
	int size = sizeof(array)/sizeof(array[0]); // uses the sizeof() function to get the size of the array which is done by the size of the array divided by the first index of the array
	printf("non-reversed array \n"); 
	print(array, size); // function call to print the non-reversed array
	printf("the reversed array \n"); 
	reverse(array, 0, size - 1); // function call to reverse the array. Since the beginning index is 0, the size needs to be -1 
	print(array, size); // prints the reversed array 

	return 0;
}
