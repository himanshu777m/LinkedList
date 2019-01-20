#include<iostream>
using namespace std;

//create circle
class Node{
	public:
	
	//three part- data and two pointer
	int data;
	Node * next;
	Node * pre;
	
	Node(){
		next = NULL;
		pre = NULL;
	}
};

//create Double LinkList
class D_L_List{
	public:
	
	Node * head;
	Node * tail;

	//intilisation head to NULL	
	D_L_List(){
		head = NULL;
	}
	
	//insert function 
	// insert Node at Last
	void insert(int value){
		
		//create Node and pointer pointing to Node
		Node * temp = new Node;
		temp -> data = value;		//save value in Node
		
		//for first circle
		if(head == NULL){
			head = temp;
			tail = temp;
		}
		
		//for Other Circle
		else{
			tail -> next = temp;
			temp -> pre = tail;
			tail = temp;
		}
	}
	
	//Display data
	void display(){
		Node * current = head;
		
		while(current != NULL){
			cout << current -> data << "->";
			current = current -> next;
		}
		cout << endl;
	}
	
	//Display data in reverce order
	void revDisplay(){
		Node * current = tail;
		
		while(current != NULL){
			cout << current -> data << "->";
			current = current -> pre;
		}
		cout << endl;
	}
	
	//function for insert circle at first position
	void insertFirst(int value){
		Node * temp = new Node;
		temp -> data = value;
		
		temp -> next = head;
		head -> pre = temp;
		head = temp;
	}
	
	//function for insert Node at b/w Link
	void insertAt(int pos, int value){
		Node * temp = new Node;
		temp -> data = value;
		Node * current = head;
		
		//for first position
		if(pos == 1){
			temp -> next = head;
			head -> pre = temp;
			head = temp;
		}
		
		//for other position but not last
		else{
			int i=1;
			//reach the position
			while(i < pos-1){
				current = current -> next;
				i++;
			}
			//join link of new node	
			temp -> next = current -> next;
			current -> next -> pre = temp;
			temp -> pre = current;
			current -> next = temp;
		}
	}
		
		//delete  last Node
		void deleteLast(){
			Node * temp = tail;
			tail = temp -> pre;
			temp -> pre = NULL;
			tail -> next = NULL;
			delete temp;
		}
		
		//delete Node b/w link
		void deleteAt(int pos){
			Node * current = head;
		
		//for first position
			if(pos == 1){
				head = head -> next;
				head -> pre = NULL;
				current -> next = NULL;
				delete current;
			}
			
			//for other position
			else{
				int i=1;
				//reach the position
				while(i < pos -1){
					current = current -> next;
					i++;
				}
				Node * temp = current -> next;
				current -> next = current -> next -> next;
				current -> next -> pre = current;
				delete temp;
			}
		}
		
		void countItem(){
			Node * temp = head;
			int i=1;
			while(temp != NULL){
				temp = temp -> next;
				i++;
			}
			cout << "Number of Elements " << i-1 <<endl;
		}
		
}l1;

int main(){
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insertFirst(0);
	l1.insertAt(2,9);
	l1.display();
	
	l1.deleteLast();
	l1.deleteAt(2);
	l1.display();
	l1.revDisplay();
	l1.countItem();
}