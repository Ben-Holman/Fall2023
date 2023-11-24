#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

void stringCheck(const char input[], int size){
  //char array[10];   
  //scanf("%s", array); 
  for (int i = 0; i <= size; i++){
  // uses the ASCII values of the capital letters to check if there are capital letters in the string
    if(input[i] >= 65 && input[i] <= 90){ 
      printf("a character in this string is Uppercase.\n");
      printf("Not a Valid Input\n");
    }
    // uses the ASCII values for the lowercase letters to check if lower case letters are present in the string
    else if(input[i] >= 97 && input[i] <= 122){
      printf("a character in this string is lowercase\n");
      printf("Valid Input...\n");
    }
    else if(input[i] >= 48 && input[i] <= 57){
    // uses the ASCII values of integers 1 - 0 to check if there are integers in the string
      printf("a character in this string is an integer\n");
      printf("Not a Valid Input\n");
    }
    else if(input[i] >= 42 && input[i] <= 47){ 
    // uses the ASCII values special symbols to check if special symbols are in the string
      printf("there is a mathmatical operator in this string\n");
      printf("Valid Input...\n");
    }
    // uses the isspace() function to check if there are spaces in the string 
    else if(isspace(input[i])){
      printf("There is a space in this string.\n"); 
      printf("Not a Valid Input.\n");
    }
  }
}
void operation(const char input[], int size){
  for(int i = 0; i <= size; i++){
    if(input[i] == 42){
      printf("Type of Operation: Multiplication\n");
      //multiplication();
    }
    else if(input[i] == 43){
      printf("Type of Operation: Addition\n");
      //addition();
    }
    else if(input[i] == 45){
      printf("Type of Operation: Subtraction\n");
      //substraction();
    }
    else if(input[i] == 47){
      printf("Type of Operation: Division\n");
      //division();
    }
  }
}
// there HAS TO BE A BETTER WAY TO DO THIS 
int* converttoInt(char* input, int* output, int size){ 
  for(int i = 0; i <= size; i++){
      if(input[i] == 'a'){
      output[i] = 1;
    }
    else if(input[i] == 'b'){
      output[i] = 2; 
    }
    else if(input[i] == 'c'){
      output[i] = 3; 
    }
    else if(input[i] == 'd'){
      output[i] = 4; 
    }
    else if(input[i] == 'e'){
      output[i] = 5; 
    }
    else if(input[i] == 'f'){
      output[i] = 6; 
    }
    else if(input[i] == 'g'){
      output[i] = 7; 
    }
    else if(input[i] == 'h'){
      output[i] = 8; 
    }
    else if(input[i] == 'i'){
      output[i] = 9; 
    }
    else if(input[i] == 'j'){
      output[i] = 10; 
    }
    else if(input[i] == 'k'){
      output[i] = 11; 
    }
    else if(input[i] == 'l'){
      output[i] = 12; 
    }
    else if(input[i] == 'm'){
      output[i] = 13; 
    }
    else if(input[i] == 'n'){
      output[i] = 14; 
    }
    else if(input[i] == 'o'){
      output[i] = 15; 
    }
    else if(input[i] == 'p'){
      output[i] = 16; 
    }
    else if(input[i] == 'q'){
      output[i] = 17; 
    }
    else if(input[i] == 'r'){
      output[i] = 18; 
    }
    else if(input[i] == 's'){
      output[i] = 19; 
    }
    else if(input[i] == 't'){
      output[i] = 20; 
    }
    else if(input[i] == 'u'){
      output[i] = 21; 
    }
    else if(input[i] == 'v'){
      output[i] = 22; 
    }
    else if(input[i] == 'w'){
      output[i] = 23; 
    }
    else if(input[i] == 'x'){
      output[i] = 24; 
    }
    else if(input[i] == 'y'){
      output[i] = 25; 
    }
    else if(input[i] == 'z'){
      output[i] = 26; 
    }
  }
  return output; 
}

//THERE HAS TO BE A BETTER WAY TO DO THIS 
char* converttoChar(char* input, int* output, int size){ 
  for(int i = 0; i <= size; i++){
    if(output[i] == 1){
      input[i] = 'a';
    }
    else if(output[i] == 2){
      input[i] = 'b'; 
    }
    else if(output[i] == 3){
      input[i] = 'c'; 
    }
    else if(output[i] == 4){
      input[i] = 'd'; 
    }
    else if(output[i] == 5){
      input[i] = 'e'; 
    }
    else if(output[i] == 6){
      input[i] = 'f'; 
    }
    else if(output[i] == 7){
      input[i] = 'g'; 
    }
    else if(output[i] == 8){
      input[i] = 'h'; 
    }
    else if(output[i] == 9){
      input[i] = 'i'; 
    }
    else if(output[i] == 10){
      input[i] = 'j'; 
    }
    else if(output[i] == 11){
      input[i] = 'k'; 
    }
    else if(output[i] == 12){
      input[i] = 'l'; 
    }
    else if(output[i] == 13){
      input[i] = 'm'; 
    }
    else if(output[i] == 14){
      input[i] = 'n'; 
    }
    else if(output[i] == 15){
      input[i] = 'o'; 
    }
    else if(output[i] == 16){
      input[i] = 'p'; 
    }
    else if(output[i] == 17){
      input[i] = 'q'; 
    }
    else if(output[i] == 18){
      input[i] = 'r'; 
    }
    else if(output[i] == 19){
      input[i] = 's'; 
    }
    else if(output[i] == 20){
      input[i] = 't'; 
    }
    else if(output[i] == 21){
      input[i] = 'u'; 
    }
    else if(output[i] == 22){
      input[i] = 'v'; 
    }
    else if(output[i] == 23){
      input[i] = 'w'; 
    }
    else if(output[i] == 24){
      input[i] = 'x'; 
    }
    else if(output[i] == 25){
      input[i] = 'y'; 
    }
    else if(output[i] == 26){
      input[i] = 'z'; 
    }
  } 
  return input; 
}

// CODE FROM https://www.javatpoint.com/c-program-to-print-the-sum-of-all-elements-in-an-array
int* add(int* input1, int* input2, int* full, int size){
  int* sum1, sum2; //creates a int pointer sum 
  for (int i = 0; i < size; i++){ // loops through the size of the array
  sum1 = sum1 + input1[i]; // the pointer sum1 is added over and over again through each element of the first input
}

for(int i = 0; i < size; i++){ // same for sum2 as sum1
  sum2 = sum2 + input2[i]; 
}

return full = sum1 + sum2; // returns the sum of the left and right substrings 
}

void substring(char *original, char* sub, int index, int length){
  int i = 0;  // an empty int
  while(i < length){ // the int variable being less than the length of the whole string as the loop condition
    sub[i] = original[index + 1]; // the substring being set to the original string plus 1 of the index of the original string to make room for the null terminator 
    i++; // increments the loop condition 
  }
  sub[length] = '\0'; // the substring adds the null terminator to the end 
}

void calculator(){ // this is the final function 

}


/*
void symbolCheck(const char input[], int size){
  bool check; 
  for(int i = 0; i <= size; i++){
    if(input[i] != '+' || input[i] != '-' || input[i] != '*' || input[i] != '/'){
      
      check = true; 
    }
    else{
      check = false;  
    }
  }
  if(check == true){
    printf("No Arithmetic Detected. Try Again.\n");
  }
  else if(check == false){
    printf("Input Accepted...\n"); 
  }
}


void lowercaseCheck(const char input[], int size){
  bool check; 
  for(int i = 0; input[i] <= '\0'; i++){
    if(isupper(input[i])){
      check = true; 
    }
    else{
      check = false; 
    }
  }
  if(check){
    printf("Upper Case Detected. Try Again.\n"); 
  }
  else{
    printf("Input Accepted...\n");
  }
} 

bool spacesCheck(const char input[], int size){
  //bool check; 
  for (int i = 0; input[i] <= '\0'; i++){
    if(input[i] == ' '){
      return false; printf("Spaces In Equation. Try Again.\n");
    }
    else{
      return true; printf("Input Accepted...\n"); 
    }
  }
}
*/
