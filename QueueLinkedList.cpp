#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

node *z=new node;
node *front=z;
node *rear=z;
void Enqueue(int x){
	node *temp = new node;
	temp->data = x;
	temp->next = z;
	if(front == z && rear == z){
		front = rear = temp;
		return;
	}else{
		rear->next = temp;
		rear = temp;
	}
}

void Dequeue(){
	node *temp = front;
	if(front == z) return;
	if(front == rear) front = rear = z;
	else front = front->next;
	delete temp; // free(temp);
}

bool isEmpty(){
	if(front == z && rear == z) return true;
	return false;
}

int Front(){
	if(front != z) return front->data;
	return 0;
}

int main(){
	int i;
	
	for(i = 1; i<5 ; i++){
		Enqueue(i);
	}
	
	while(!isEmpty()){
		cout<<Front()<<' ';
		Dequeue();
	}
	
	return 0;
}
