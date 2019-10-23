//Pila Mediante Lista Enlazada
#include<iostream>
using namespace std;

template <class T>
class Stack{
	public:
		Stack(int max);
		~Stack();
		void push(T v);
		T pop();
		bool empty();
	private:
		struct node { T key; node *next; };
		node *head, *z;
};

template <class T>
Stack<T>::Stack(int max){
	head = new node; z = new node;
	head->next = z; z->next = z;
}

template <class T>
Stack<T>::~Stack(){
	node *t = head;
	while(t!=z){
		head = t; t=t->next; delete head;
	}
}

//Para finalizar se muestra la implementacion real de las operaciones de la pila:
template <class T>
void Stack<T>::push(T v){
	node *t = new node;
	t->key = v; t->next = head->next;
	head->next = t;
}

template <class T>
T Stack<T>::pop(){
	T x;
	node *t = head->next;
	head->next = t->next; x = t->key;
	return x;
}

template <class T>
bool Stack<T>::empty(){ return head->next == z; }

int main(){
	Stack<int> s(5);
	
	for(int i=1; i<5; i++) s.push(i);
	
	while(!s.empty()){
		cout<<s.pop()<<endl;
	}
	
	return 0;
}
