#pragma once
#include "node.h"
// always need to have the <typename T> above the class and it's functions
template <typename T>
class list{
public:
  //void addItem(T inputData);
  //void removeItems(T removeData); 
  //void lastItem();
  //void printCollection();
list(){ // this is the constructor
        // initiallize head to a new pointer and sets the next pointer to nullptr because there is no 'next' yet
  head = new node<T>;
  head->setNext(nullptr);
}
//template <typename T>
void addItem(const T& inputData){
  node<T>* data = new node<T>; // creates a new node and sets the value of that node to the data parameter. It is not being modified so it is const
  data->setData(inputData); // the data node is putting the value of the function parameter as the new set of data
  /*
  if(head == NULL){
    head = data; 
    return; 
  }
  */
  data->setNext(head); // the node variable is making the head the next value to be pointed to 
  head = data; // the data node bcomes the head which will be pointed to as per the previous line 
  
}

//template <typename T>

void removeItems(const T& removeData){
  node<T>* lastEntered; // creates a new node
  lastEntered = head; // sets the new node to the head of the list 
  listofItems = head->getNext(); // the private node has the head pointer get the next value and is equal to that next value 

  while(listofItems != nullptr){ // a while that runs as long as the node is not null

    if(listofItems->getData() == removeData){ // if the value of the data is the same as the function parameter then...

      lastEntered->setNext(listofItems->getNext()); // the node that is equal to the head sets the next value to the listofItems head value
      delete listofItems; // deletes the listofItems nodes
      listofItems = lastEntered->getNext(); // the new list of items is equal to the new next value
    }
    else{ // if the function parameter is not found... 

      listofItems = listofItems->getNext(); // the listofItems is equal to itself pointing to the next value      
      lastEntered = lastEntered->getNext(); // same thing with the lastEntered as listofItems
    }
  }
}

//template <typename T>
T lastItem(){
  return head->getData(); // this just returns the top value of the list 
   
}

//template <typename T>
void printCollection(){
    node<T>* list = head; // a new node is created 
  while(list != nullptr){ // checks to see if the list is empty and if not run the loop 
    cout << list->getData() << endl; // prints the data from the list
    list = list->getNext(); // gets the next node to be printed 
  }
}
  private:
  node<T>* head; // creates the head of the list 
  node<T>* listofItems; 
};

/*
template <typename T>
void list<T>::addItem(T inputData){
  node<T>* data = new node<T>;
  data->setData(inputData);
  if(head == NULL){
    head = data; 
    return; 
  }
  data->setNext(head); 
  head = data; 
  
}

template <typename T>
void list<T>::removeItems(T removeData){
  node<T>* lastEntered; 
  lastEntered = head; 
  head->getNext();
  while(){
    if(head->getData() == removeData){
      lastEntered->setNext(head->getNext());
      lastEntered = lastEntered->getNext(); 
    }
    else {
      head = head->getNext();      
      lastEntered = lastEntered->getNext();
    }
  }
}

template <typename T>
void list<T>::lastItem(){
  head->getData(); 
  return head; 
}

template <typename T>
void list<T>::printCollection(){
  if(head == NULL){
    cout << "List is empty." << endl; 
  }
    node<T>* list = head; 
  while(list != NULL){
    cout << list->getData() << endl;
    list->getNext(); 
  }
}
*/
