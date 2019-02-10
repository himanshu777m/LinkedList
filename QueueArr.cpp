//Queue using array

#include<iostream>
using namespace std;

int arr[5];

class queueArr{
	public:
	
	int i=0;
	//insert function
	void EnQuA(int value){
		arr[4-i]=value;
		i++;
	}
	//delete function
	int j=0;
	void DeQuA(){
		for(int p=4; p>-1; p--){
			arr[p+1] = arr[p];
		}
		j++;
	}
	
	//display function
	void display(){
		for(int i=j; i <5; i++){
			cout << arr[i] <<"->";
		}
		cout <<endl;
	}
}q1;

int main(){

	for(int i =0; i<5; i++){ 
		q1.EnQuA(i);
	}
	q1.display();
	
	for(int i =0; i<6; i++){ 
		q1.DeQuA();
		q1.display();
	}
}