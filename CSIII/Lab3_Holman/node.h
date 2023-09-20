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
	node(): next_(nullptr) {} 
	
	// functions can be inlined
	T getData()const
	{
		return data_;
	} 

	void setData(const T& data)
	{
		data_ = data;
	} 
	// or can be defined outside 
	//node* getNext() const; 
	//void setNext(node* const next); 
  

  node<T>* getNext() const { 
    return next_; 
  }


  void setNext(node* const next){
    next_ = next;
  }

	private: 
	T data_; 
	node* next_; 
}; 

#endif // NODE_H_ 
