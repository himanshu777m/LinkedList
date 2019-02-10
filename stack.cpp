#include <iostream>
#include "cl11.cpp"

using namespace std;

class Stack{
	public:
	Node * top;
	
	Stack(){
		top = l1.head;	//top = NULL
	}
	
	void push(int value){
		//same as insertAt pos One
		l1.insertAt(1,value);
		//top = New_head
		top = l1.head;
	}
	
	void pop(){
		if(isEmpty()){
			cout << " Popping out from an empty stack" <<endl;
		}
		
		else{
			//same as deleteAt pos One
			l1.deleteAt(1);
			//top = new_head
			top = l1.head;
		}	
	}
	
	bool isEmpty(){
		if(top == NULL) return true;
		return false;
	}
	
	int size(){
		l1.CountItems();
	}
	
	int topDisplay(){
		
	}
	
	int display(){
		l1.display();
	}
	
};

int main(){
	Stack s1;
	
	for(int i =0; i<5; i++){ 
		s1.push(i);
	}
	
	for(int i =0; i<6; i++){ 
		s1.pop();
		s1.display();
	}
	
}