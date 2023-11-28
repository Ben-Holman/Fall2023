// node class tempate used to contruct lists 
// Wayne Cheng 
// 2/01/18 

#ifndef NODE_H_ 
#define NODE_H_ 
#include <iostream>
using std::cout; 
using std::endl; 

// the pointer part of every list is the same 
// lists differ by data part 
template <typename T> 
class node
{ 
	public: 
	node(): next_(nullptr) {}// sets the next pointer to null since there's no value initially 
	
	// functions can be inlined
  // these 2 functions are another adding anoter layer of abstraction with the setter and getter
	T getData()const
	{
		return data_; 
	} 

	void setData(const T& data) // this function sets the T referece of the data and should not be modified so it's const
	{
		data_ = data;
	} 
	// or can be defined outside 
	//node* getNext() const; 
	//void setNext(node* const next); 
  
  // this is the same as the Data function, just a slightly different syntax 
  node<T>* getNext() const { 
    return next_; 
  }


  void setNext(node* const next){ // this makes sure the pointer is pointer to the correct value
    next_ = next;
  }
// the private variables used in the setter and getter functions above
	private: 
	T data_; 
	node* next_; 
}; 

#endif // NODE_H_ 
