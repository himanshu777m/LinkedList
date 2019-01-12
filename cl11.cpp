#include<iostream>
using namespace std;

class Node{

	public:
	//data
	int data;
	
	//pointer to the next Node
	Node * next;
	
	//construct that makes the ptr to NULL
	Node(){
		next = NULL;
	}
	
};

class Linkedlist{
	// head + circles inside linked with each other
	
	public:
	//head = circle type ptr
	Node * head;
	Node * tail;  		//not nesscerry
	
	//Construct
	Linkedlist(){
		head = NULL;
	}
	
	//circle inside linked with each other
	//rules how circles will be linked
	
	//insert
	void insert( int value){
		//If 1st Node is added
		Node * temp = new Node;
		
		//insert data in node
		temp -> data = value;
		
		//1st node only
		if(head == NULL){
			head = temp;
			// tail = temp;
		}
		//any other node
		else{
			tail -> next = temp;
			// tail = temp;
		}
		tail = temp;
	}
	
	void insertAt(int pos, int value){
		
		//create a node
		Node * temp = new Node;
		temp -> data = value;
		
		if(pos ==1){
			temp -> next = head;
			head = temp;
		}
		else{
			//reach thr place before the pos
			Node * current = head;
			int i=1;
			while (i< pos-1){
				i++;
				current = current -> next;
			}
			//moving ptrs
			temp -> next = current -> next;
			current -> next = temp;
		}
	}
	
	//deletion
	void delet(){
		//store tail in temp
		Node * temp = tail;
		
		//before tail has to point to null
		Node * current = head;
		while(current->next != tail){
			current = current -> next;
		} 
		current -> next = NULL;
		// update tail
		//delete temp
	}
	
	//delete at position
	void deleteAt(int pos){
	
		Node * current = head;
		if (pos ==1){
			head = current -> next;
			delete current;		
		}	
		
		else{
			//reach the place before the po
			int i=1;
			while(i < pos-1){
				i++;
				current = current -> next;
			}
			
			// declaring temp for that pos
			Node * temp = current ->next;
			//joing currnent to next of temp
			current -> next = temp -> next;
			delete temp;
		}
	}
	
	//display
	void display(){
		Node * current = head;
		
		while(current != NULL){
			cout << current -> data << "->";
			current = current -> next;
		} 
		
		cout << "NULL" << endl;
	}
	
	// count items
	void CountItems(){
		Node *current = head;
		int i=0;
		while(current != NULL){
			i++;
			current= current->next;
		}
		cout<<"Number of items = "<< i <<endl;
	}
};

int main(){
	Linkedlist l1;
	cout << "Linked List " << endl;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.display();
	
	cout << endl << "delete the last element \n";
	l1.delet();
	l1.display();
	
	int p,v,a;
	cout << endl << "insert Node at position\n";
	cout <<  "insert position and value\n";
	cin >> p >> v;
	l1.insertAt(p,v);
	l1.display();
	
	cout << endl << "delete at position\n";
	cout << "Enter the position\n";
	cin >>a;
	l1.deleteAt(a);
	l1.display();
	
	l1.CountItems();
	return 0;
}