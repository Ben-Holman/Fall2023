#include "roster.h"
/*
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <cstdlib>
//---------------------------
using std::cout; 
using std::endl; 
using std::ifstream; 
using std::vector;
using std::list; 
using std::string; 
using std::getline; 
using std::move; 

//--------------------------------------------------------------------------------------------------------------------------------------------------

void read(list<list<string>>& ros, string file); // takes a list of a list of strings reference and a string as parameters

void print(const list<list<string>>& ros); // print function that takes a list of a list of strings refere ce as a parameter 

//--------------------------------------------------------------------------------------------------------------------------------------------------
*/ 
int main(){
  int size = 4; 
  string array[size]; // creates an array with the size of the size variable, which is 4
  bool check = false; // a boolean check that will be used later
  // each index of the array is a different text file
  array[0] = "cs1.txt"; 
  array[1] = "cs2.txt";
  array[2] = "cs3.txt";
  array[3] = "cs4.txt";
  // then we have a string variable set to another text file
  string file = "dropouts.txt"; 

  vector<list<string>> students; // creates a vector of a list of strings
  list<list<string>> roster; // creates a list of a list of strings
  for (int i = 0; i < size; ++i){ // runs a for-loop the length of size variable (4)
   read(roster, array[i]);// using the read function
   cout << "\n\n" << array[i] << endl; 
    print(roster);
  }
  list<list<string>> drops; //creates another list of a list of strings 
  read(drops, file); // the dropouts list and the text file are both read through the function and the contents of the text file are placed into the list
  cout << "\n\n drops:" << endl;
  print(drops); // prints the drops 
  list<list<string>> all; // creates a new list of list of strings
  all = roster; // this new list is equal to roster list that was read into the read() function 
  cout << "All students (unsorted)\n"; 
  print(all);// prints the whole roster
  all.sort(); // using the built-in sort function to sort the roster of students 
  cout << "Sorted students:\n"; 
  print(all); // prints the new sorted list
  
  all.unique(); // uses the built-in unique function to disregard any duplicates 
  cout << "all unique students\n";
  print(all); // prints the roster again, this time with only the unique names, classes
  for(const auto& dropped : drops){ // for-loop that loops through the drops list 
    list<string> temp; // new list of strings
    for(auto& str: all){ // loop that loops through the sorted, unique roster
      if(str.front() == dropped.front()){ // if the students are on the roster and the dropped list then...they are pushed onto the temp list
        for(const auto& i : str){
          temp.push_back(i);
        }
        check = true; // the check is set to true to move on to removing them from the list  
      }
    } 
    if(check){ // removes the dropouts from the classes 
      all.remove(temp); 
      check = false; // the check is false as those who dropped have been removed 
    }
  }
  cout << "\nAll students with those who dropped removed\n"; 
  print(all); // prints the new list including students who dropped out of classes

  cout << "\n";

  cout << "\nRemoving students who are in CS4 and any other classes" << endl; 
  bool CS4Check; 
  for(int i = all.size() - 1; i >=0; i--){ // running a loop all all the students in the list to the last one 
    list<string> temp; // creating a temp list 
    list<string> removal; 
    for(auto& str: all){
      temp.clear(); // removes all elements in the list 
      removal.clear(); // removes all elements in the list 
      for(const auto& elim : str){
        removal.push_back(elim); 
        temp.push_back(elim); 
      }
      temp.pop_front(); 
      if(temp.front() == "cs4"){ // checks to see if the student is in anything else but CS4 because it is sorted so CS4 would be last instead of at the front 
        // do nothing
      }
      else if(temp.back() == "cs4"){
        cout << temp.back() << endl; 
        CS4Check = true; // the check is true that the student is not only in CS4
        break; 
      }
      else{
        // do nothing   
      }
    }
    if(CS4Check){
      all.remove(removal); // if the check is true, then those students who are in other classes besides CS4 are removed 
      CS4Check = false; 
    }
  }
  print(all); 
  return 0; 
}

//---------------------------
/*
void read(list<list<string>>& ros, string file){ // takes a list of a list of strings reference and a string as parameters
  ifstream input(file);
  // creates 2 strings, begin and end and a bool used later
  string begin; 
  string end;
  bool check; 
  while(input >> begin >> end){ // while loop with the condtion being the input of both beginning and end
    for(auto& str : ros){ // for loop using auto reference to loop through the list of list of strings, ros
      if(str.front() == begin + " " + end){ // checks to see if the frist element of the list is a string with the begin, a space, and end 
        int found = file.find(".txt"); // an int variable, found, that uses the find function to look for ".txt"
        if(found != std::string::npos){ // if ".txt" is found and the string is not at it's end then...
          file.erase(found, file.length());// ".txt" will be erased from the string
        }
        str.push_back(file); // the characters before ".txt" will be pushed onto the list
        check = false; // the bool is set to false
      } 
    }
    if(check){
      list<string> temp;// creates a new temp list  
      temp.push_back(begin + " " + end); // 
      int found = file.find(".txt");
      if(found != std::string::npos){ // if found is not equal to the end of the string 
        file.erase(found, file.length()); 
      }
      temp.push_back(file); // temp puts into the list the string parameter

      ros.push_back(temp); // ros puts into the list the contents of temp 
      check = true; 
    }

  }
  input.close(); 

}

void print(const list<list<string>>& ros){ // print function that takes a list of a list of strings refere ce as a parameter 
  for(const auto& run : ros){ // runs a const auto loop because nothing is being modified 
    for(const auto& iterate : run){ // a nested loop 
      cout << iterate << " "; // prints the contents of the list
    }
    cout << "\n";
  }

}
*/
