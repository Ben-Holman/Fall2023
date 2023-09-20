#include <stdio.h>

void reverse(int array[], int begin, int end){

	int temp; 
	while(begin < end){
		temp = array[begin];
		array[begin] = array[end];
		array[end] = temp; 
		begin++; 
		end--; 
	}
}

void print(int array[], int size){
for(int i =0; i < size; i++){
	printf("%d\n", array[i]);
}
}

int main(void){
	int array[] = {1,2,3,4,5,6,7,8,9,0};
	int size = sizeof(array)/sizeof(array[0]);
	printf("non-reversed array \n");
	print(array, size); 
	printf("the reversed array \n");
	reverse(array, 0, size - 1);
	print(array, size);

	return 0;
}
