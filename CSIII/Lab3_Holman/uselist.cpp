// demoes list template usage 
// Wayne Cheng 
// 2/1/18 

#include <iostream> 
#include "list.h" 
using namespace std;

// list template
int main()
{ 
	node *head, *currentPtr; 
	// 
	// integer list manipulation 
	// 
	// first node 
	head =new node; 
	head->setData(1); 
	currentPtr=new node; 

	// second node 
	currentPtr->setData(2); 
	head->setNext(currentPtr); 

	// list contains two nodes 
	cout << head->getData() << " "; 

	// printing head node 
	// deallocating head node 
	currentPtr=head; 
	head=head->getNext(); 
	delete currentPtr; 

	// printing and deallocating the last element 
	cout << head->getData() << endl; 
	delete head; 

	// 
	// character list manipulation 
	// 
	// allocating head node 
	node *charHead = new node; 
	node *current = charHead; 
	current->setData('a'); 

	// creating list 
	for(char letter = 'b'; letter <= 'z'; ++letter)
	{ 
		node *newNode = new node; 
		newNode->setData(letter); 
		current->setNext(newNode); 
		current = newNode; 
	} 

	// printing character list 
	for(current = charHead; current != nullptr; current=current->getNext()) 
		cout << current->getData() << ' '; 
	cout << endl; 
} 
