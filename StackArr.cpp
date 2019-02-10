//stack using array

#include<iostream>
using namespace std;

int arr[5];

class stackArr{
	public:
	
	int i=0;
	//insert function
	void push(int value){
		arr[4-i]=value;
		i++;
	}
	//delete function
	int j=0;
	void pop(){
		for(int p=0; p<5-j; p++){
			arr[p] = arr[p+1];
		}	
		j++;
	}
	
	//display function
	void display(){
		for(int i=0; i <5-j; i++){
			cout << arr[i] <<"->";
		}
		cout <<endl;
	}
}s1;

int main(){

	for(int i =0; i<5; i++){ 
		s1.push(i);
	}
	s1.display();
	
	for(int i =0; i<6; i++){ 
		s1.pop();
		s1.display();
	}
}