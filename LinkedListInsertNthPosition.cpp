#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* link;
};

Node* Insert(Node* head, int val, int n){
	Node* temp= new Node;
	temp->data=val;
	temp->link=NULL;
	if(n==1){
		temp->link = head;
		head = temp;
		return head;
	}
	Node* temp2 = head;
	//bool band=false;
	for(int i=1; i <= n-2; i++){
		temp2 = temp2->link;
		//band=true;
	}
	temp->link = temp2->link;
	temp2->link = temp;
	//if(band) return head;
	return head;
}


void Print(Node* head){ //como la que llega es una copia no se modifica nada
	while(head != NULL){
		cout<<head->data<<' ';
		head=head->link;
	}
	cout<<endl;
}

int main(){
	int x;
	Node* head = NULL;
	head = Insert(head, 5,1); //List: 5
	head = Insert(head, 3,2); //List: 5,3
	head = Insert(head, 7,1); //List: 7,5,3
	head = Insert(head, 4,2); //List: 7,4,5,3
	head = Insert(head, 10,3); //List: 7,4,10,5,3
	head = Insert(head, 11,5); //List: 7,4,10,5,11,3
	Print(head);
	
	return 0;
}
