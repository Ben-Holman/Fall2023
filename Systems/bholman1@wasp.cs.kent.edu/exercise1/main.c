#include <stdio.h>

int compare(const char* a, const char* b){
  int result; 
  if(a < b){
    result = 1;
    printf("1");
    return result;
  }
  else{
    result = 0; 
    printf("0");
    return result; 
    
  }
}

int main(void){
char string1[10] = {"abcd"}; 
char string2[10] = {"edfg"};
char string3[5]={"hi"};
printf("strings: \n");
printf("%s \n", string1);
printf("%s \n", string2);
printf("%s \n", string3);
printf("comparing string1 and string2: \n");
  compare(string1, string2);
  printf("\n"); 
printf("comparing string1 and string3: \n");
  compare(string1, string3);
  printf("\n");
  return 0; 
}
