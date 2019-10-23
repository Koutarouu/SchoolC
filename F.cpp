/*Somethings*/
#include<iostream>

using namespace std;

int fibo_chafa(int N){
	if(N<=1) return 1;
	return fibo_chafa(N-1)+ fibo_chafa(N-2);
}

int factorial(int N){
	if(N<2) return 1;
	return N*factorial(N-1);
}

int fibo_iter(int N){
	const int max = 25;
	int i, a[max];
	a[0]=1; a[1]=1;
	for(i=2; i<max; i++){
		a[i] = a[i-1] + a[i-2];
	}
	return a[N];
}
int main(){
	int n=8;
	
	cout<<fibo_chafa(n)<<endl;
	cout<<factorial(n)<<endl;
	cout<<fibo_iter(n);
	
	return 0;
}
