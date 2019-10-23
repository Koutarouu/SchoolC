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
	bool f=false;
	for(int i=1; i <= n-2; i++){
		temp2 = temp2->link;
		bool f=true;
	}
		
	temp->link = temp2->link;
	temp2->link = temp;
	if(f) return head;
	return temp2;
}


void Print(Node* head){ //como la que llega es una copia no se modifica nada
	while(head != NULL){
		cout<<head->data<<' ';
		head=head->link;
	}
	cout<<endl;
}
//Delete node at nth Position
Node* Delete(Node* head, int n){
	Node* temp1=head;
	if(n==1){
		head = temp1->link; //head now points to second node.
		delete temp1; //(*temp1).link lo liberamos de la memoria ese espacio
		return head;
	}
	for(int i=1; i <= n-2; i++)
		temp1 = temp1->link;
	// temp1 points to (n-1)th Node
	Node* temp2 = temp1->link; // nth Node
	temp1->link = temp2->link; // (n+1)th Node
	delete temp2;
	return head;
}

int main(){
	int x;
	Node* head = NULL;
	head = Insert(head, 5,1); //List: 5
	head = Insert(head, 3,2); //List: 5,3
	head = Insert(head, 7,1); //List: 7,5,3
	head = Insert(head, 4,2); //List: 7,4,5,3
	Print(head);
	int n;
	cout<<"Enter a position\n";
	cin>>n;
	head = Delete(head,n);
	Print(head);
	
	return 0;
}
