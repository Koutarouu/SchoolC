#include<iostream>
#include<stack>
using namespace std;

int operation(char a, int op1, int op2){
	if(a=='+') return (op1+op2);
	if(a=='-') return (op1-op2);
	if(a=='*') return (op1*op2);
	if(a=='/') return (op1/op2);
}

int main() {
	int op1,op2,res;
	string prefix;
	stack<int> st;
	cout<<"Type your expresion prefix: "<<endl;
	getline(cin,prefix);
	int l=prefix.length();
	
	for(int i=l-1; i>=0; --i){
		if(prefix[i]>='1' && prefix[i]<='9'){
			st.push(prefix[i]-'0');
		}else{
			op2=st.top(); st.pop();
			op1=st.top(); st.pop();
			st.push(operation(prefix[i], op2, op1));
		}
	}
	cout<<"The result is: "<<st.top()<<endl;
	st.pop();
	return 0;
}
//-+*2 3*5 4 9
//-/8 2 5
