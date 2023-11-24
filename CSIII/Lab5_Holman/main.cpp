 #include "mapping.h"

int main(int argc, char* argv[]){ // used to input the file names 

  if(argc <= 1){ // if only the ./main is called, but no other commands are put it, the following prints
    cout << "Nothing Entered. Please Enter text file names " << argv[0] << " List of all courses, dropouts listed last.\n";
    exit(1);
  }

  vector <list<string>> students; // creating a vector of a list of strings for the students

  for(int i = 1; i < argc - 1; ++i){ // a loop that goes decrements through the command lines and puts those into the ros list 
    list<string> ros; 
    readInRoster(ros, argv[i]); // reads in the contents of the command line arguments, which in this case are text files.
    cout << endl; 
    cout << endl; 
    cout << argv[i] << endl; // prints the names of the command line text files 
    printOutRoster(ros); // prints the roster(s)
    students.push_back(move(ros)); // pushes the contents to the students list moved from the ros list 
  }

  list<string> drops; // creates the dropouts string list 

  readInRoster(drops, argv[argc - 1]); // reads in the contents of the droputs list and decrements through the command line text files 
  cout << endl; 
  cout << "\n Those Who Dropped" << endl; 
  printOutRoster(drops); // prints the roster of the dropouts

  map<string, list<string>> everyone; // finally, creating the giant map of everyone. Being a map of strings and a list of strings together 

  for(auto& listed : students){ // a loop the iterations through the students list 
    static int i = 1; // creates a static int that will be used to iterate through the loops 
    string courses; // creates a new string 
    courses = argv[i]; // the courses string is equal to the command line arguments 
    courses.erase(courses.end() - 4, courses.end()); // removes the courses, 4 spaces from the end 
    for(auto& str : listed){ // a loop that goes through all the students 
      if(everyone.find(str) != everyone.end()){ // if courses are found then that person will not be put on the 'everyone' map 
        everyone[str].push_back(courses);
      }
      else{
        list<string> temp { courses }; // if courses are found then that person is placed on a temp list 
        everyone.emplace(str, temp); // the map creates a new element and inserts the values into it
      }
    }
    i++; // interating through the loops
  }

  cout << endl; 
  cout << endl;
  cout << "All Students Sorted By Their First Name\n";
  printOutMap(everyone); // prints out the map 

for(auto& name : drops){ // this loop goes through the drops list and erases the names of theose people 
    everyone.erase(name);
  }

  cout << "\n\n All Students With Those Who Dropped Out Removed\n";
  printOutMap(everyone); // prints the new map with the people who dropped out removed 

  for(auto listed = everyone.begin(); listed != everyone.end();){ // a loop that goes through the map from the beginning, but not the end 
    bool check = true; // the check is set to true for the loop to work 
    for(auto elements = listed->second.begin(); elements != listed->second.end(); ++elements){ // a nested loop that goes through the first and second elements of the list which is the map 
      if(*elements == "cs4" && listed->second.size() >= 2){ // if the dereferenced iterator equals "cs4" and the seconds size of the elements is more than 2
        everyone.erase(listed++); // those are erased 
        elements = listed->second.begin(); // the nested iterator is now equal to the first loop iterator 
        check = false; // the flag is set to false as those people with those parameters have been found 
      }
    }
    if(check){
      ++listed; // if the person is found to not satisfy the above parameters, the loop iterates 
    }
  }

  cout << "\n\n All Students, Those With CS4 And Other Classes Have Been Removed\n";
  printOutMap(everyone); // prints out the new, final map 

  return 0; 
}
