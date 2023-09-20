// THIS IS CODE FOR lAB 5
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <string>
#include <algorithm> 

using std::cout;
using std::endl; 
using std::ifstream; 
using std::string; 
using std::map;
using std::list; 

void checkFile(ifstream file){ 
file.open("file1.txt"); 
if(file.fail()){
    cout << "File failed to open." << endl; 
    exit(1); 
  }
}

void print(){

}

int main(){

bool classCheck; 
ifstream file1; 
checkFile(file1); 




  return 0; 
}
