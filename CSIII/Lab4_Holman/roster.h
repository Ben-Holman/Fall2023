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
//---------------------------

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
