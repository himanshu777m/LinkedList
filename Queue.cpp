#include "cl11.cpp"

class Queue{
	public:
	Node * end;
	Node * front;
	
	Queue(){
		end = l1.head;
	}
	
	void Enqueue(int value){
		//same as insertAt pos One
		l1.insertAt(1, value);
		//end = New_head
		end = l1.head;
		
	}
	
	void Dequeue(){
		if(isEmpty()){
			cout <<"Poping out from Empty Queue" <<endl;
		}
		else{
			//same as delet function
			l1.delet();
			//if last element change than head change
			end = l1.head;
		}	
	}
	
	bool isEmpty(){
		if(end == NULL) return true;
		return false;
	}
	
	int size(){
		l1.CountItems();
	}
	
	int display(){
		l1.display();
	}
	
}q1;

int main(){
	
	for(int i =0; i<5; i++){ 
		q1.Enqueue(i);
	}
	
	for(int i=0; i<7; i++){
		q1.Dequeue();
		q1.display();
	}
	q1.size();
}