#include <iostream>
using namespace std;

template <class T>
struct StackNode {              
	T data;                     
	StackNode *next;    
		
	StackNode(const T& newData, StackNode *nextNode = 0){
		data = newData;
		next = nextNode;
	}
};
	


template <class T>
class Stack{
public:
	StackNode<T>* top; 
	Stack(){  
		top = 0;
	}
	
	bool isEmpty(){
		if (top == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	
	void push (const T& object){
		StackNode<T> *temp = new StackNode<T>(object);
		StackNode<T> *temp2;
		if(!top){ //top==0
			top = temp;
			top->next = 0;
		}
		else{
			temp2 = top;
			top = temp;
			top->next = temp2;
		}
		
	}
	
	void pop(){
		
		if(top != 0){
			
			StackNode<T> *temp2;
			temp2 = top->next;
			delete top;
			top = temp2;
		}
		else
		   return;

	}
	
	
	
	void print(){
		StackNode<T> *print= top;
		while(print!= 0){
			cout<<"  "<<print->data<<endl;
			print = print->next;
		}
		if(print = 0){
			cout<<"Vacio"<<endl;
		}
	}

};

int main(){
	Stack<int> yaes;
	yaes.push(6);
	yaes.push(5);
	yaes.push(4);
	yaes.push(3);
	yaes.push(2);
	yaes.push(1);
	yaes.print();
	cout<<"haciendo pop"<<endl;
	yaes.pop();
	yaes.pop();
	yaes.pop();
	yaes.print();
}
