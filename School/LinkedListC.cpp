#include<iostream>

using namespace std;

class Node{
    private:
        int data;
        Node *next;
    friend class List;
};

class List{
    private:
        Node *head;
    public:
        List();
        void Print();
        void push_frnt(int x);
        void push_bck(int x);
        void InsertNth(int n, int x);
        void delete_frnt();
        void delete_bck();
        void RemoveElement(int x);
        void del_list();
};

List::List(){
    head = NULL;
}

void List::Print(){
	if(!head) cout<<"List Empty."<<endl;
	else {
		Node *temp = head;
		while(temp!=NULL){
			cout<<temp->data<<' ';
			temp = temp->next;
		}
		cout<<'\n';
	}
}

void List::push_frnt(int x){
	Node *temp = new Node;
	temp->data = x;
	temp->next = head;
	head = temp;
}

void List::push_bck(int x){
	Node *temp = new Node;
	temp->data = x;
	temp->next = NULL;
	if(head == NULL){
		head = temp;
		return;
	}else{
		Node *temp2 = head;
		while(temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = temp;
	}
}

void List::InsertNth(int n, int x){
	Node *temp = new Node;
	temp->data = x;
	if(n==1){
		temp->next = head;
		head = temp;
		return;
	}
	Node *temp2=head;
	for(int i=0; i < n-2; i++)
		temp2 = temp2->next;
	temp->next = temp2->next;
	temp2->next = temp;
}

void List::delete_frnt(){
	if(!head) cout<<"List Empty.";
	else{
		Node *temp=head;
		head = head->next;
		delete temp;
	}
}

void List::delete_bck(){
	Node *temp=head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	Node *temp2 = temp->next;
	temp->next = NULL;
	delete temp2;
}

void List::RemoveElement(int x){
	while(head->data == x){
		head = head->next;
		if(!head) return;
	}
	
	Node *temp = head;
	while(temp->next != NULL){
		if(temp->next->data == x) temp->next = temp->next->next;
		else temp = temp->next;
	}
}

void List::del_list(){
	Node *temp = head;
	while(temp!=NULL){
		Node *temp2 = temp;
		temp = temp->next;
		delete temp2;
	}
	head = NULL;
}

int main(){
	int i;
	List l;
	
	for(i=1; i<8; i++){
		l.push_bck(i);
	}
	l.Print();
	l.delete_frnt();
	l.Print();
	l.delete_bck();
	l.Print();
	l.InsertNth(3, 77);
	l.Print();
	l.InsertNth(1, 0);
	l.InsertNth(1, 0);
	l.Print();
	l.RemoveElement(5);
	l.Print();
	l.RemoveElement(0);
	l.Print();
	l.RemoveElement(6);
	l.Print();
	l.del_list();
	l.Print();
	
	
	return 0;
}
