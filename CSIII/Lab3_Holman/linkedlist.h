#pragma once
#include "node.h"
template <typename T>
class list{
public:
  //void addItem(T inputData);
  //void removeItems(T removeData); 
  //void lastItem();
  //void printCollection();
list(){
        // initiallize head to nullptr
  head = new node<T>;
  head->setNext(nullptr);
}
//template <typename T>
void addItem(const T& inputData){
  node<T>* data = new node<T>;
  data->setData(inputData);
  /*
  if(head == NULL){
    head = data; 
    return; 
  }
  */
  data->setNext(head); 
  head = data; 
  
}

//template <typename T>

void removeItems(const T& removeData){
  node<T>* lastEntered; 
  lastEntered = head; 
  listofItems = head->getNext();

  while(listofItems != nullptr){

    if(listofItems->getData() == removeData){

      lastEntered->setNext(listofItems->getNext());
      delete listofItems;
      listofItems = lastEntered->getNext(); 
    }
    else{

      listofItems = listofItems->getNext();      
      lastEntered = lastEntered->getNext();
    }
  }
}

//template <typename T>
T lastItem(){
  return head->getData(); 
   
}

//template <typename T>
void printCollection(){
    node<T>* list = head; 
  while(list != nullptr){
    cout << list->getData() << endl;
    list = list->getNext(); 
  }
}
  private:
  node<T>* head; 
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
