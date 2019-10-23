/*Nombre del integrante: Dominguez Aguilar Diego Francisco */

#include<iostream>
#include<stack>

using namespace std;

int operacion(char a, int op1, int op2);

int main(){
	string postfix;
	int op1,op2,res;
	stack<int> p;
	cout<<"Type your expresion postfix: "<<endl;
	getline(cin,postfix);
	int l=postfix.length();
	
	for(int i=0; i<l; i++){
		if(postfix[i]>='1' && postfix[i]<='9'){
			p.push(postfix[i]-'0');
		}else{
			op2=p.top(); p.pop();
			op1=p.top(); p.pop();
			res = operacion(postfix[i], op2, op1);
			p.push(res);
		}
	}
	
	cout<<"The result of your expresion is: "<<p.top()<<endl;	
	return 0;
}

int operacion(char a, int op1, int op2){
	if(a=='+') return (op2+op1);
	if(a=='-') return (op2-op1);
	if(a=='*') return (op2*op1);
	if(a=='/') return (op2/op1);
}

// Hice mis pruebas con las siguientes expresiones:
//1. 47*88/+=29 2. 65-8*=1 3. 45*82+/=2 4. 777-*=0


