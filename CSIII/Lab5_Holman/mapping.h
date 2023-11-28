#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <list>
//-----------------------
using namespace std; // when you're using all these different types, it's just easier   


void readInRoster(list<string>& ros, string File){ // function that takes in a string list reference and a file name string
  ifstream fileIn(File); // the file being read in through ifstream
  string firstName, lastName; // creating the strings for the name
  while(fileIn >> firstName >> lastName) // a while loop that takes the first and last names of people in the file(s) until eof
    ros.push_back(firstName + ' ' + lastName); // pushes the first and last name, with a space inbetween, into the string list of ros
  
  fileIn.close(); // closes the file
}

void printOutRoster(const list<string>& ros){ // funtion to print the roster using a string list reference 
  for (const auto& str : ros){ // a loop to iterate throufh the roster to print it to the console
    cout << str << endl; 
  }
}

void printOutMap(const map<string, list<string>>& students){ // function to print the map of strings and a list string reference of students
  for(auto& all : students){ // loop that iterates though the students 
    cout << all.first << " "; // prints the first name and a space
    for(auto& elements : all.second){ // a nested loop that prints the second name and a space 
      cout << elements << " ";
    }
    cout << "\n";
  }
}


