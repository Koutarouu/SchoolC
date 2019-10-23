//Problema de Josefo
#include<iostream>
using namespace std;

struct node{ int key; node *next; };

int main(){
	int i,N,M;
	node *t,*x;
	cin>>N>>M;
	t=new node; t->key=1; x=t;
	
	for(i=2; i<=N; i++){
		t->next = new node;
		t = t->next; t->key=i;
	}
	t->next=x; //para que apunte al primer elemento de la lista
	node *y;
	while(t!=t->next){
		for(i = 1; i < M; i++){
			t = t->next;
			y = t;
		}
		cout<<t->next->key<<' '; t->next = y->next->next;
		delete y->next; //pero tambien funciona eliminando simplemente a x;
	}
	cout<<"El que sobrevive es: "<<t->key<<endl;
	
	return 0;
}
/*
for(i = 1; i <= N; i++){
	cout<<t->key;
	t = t->next;
}
*/
