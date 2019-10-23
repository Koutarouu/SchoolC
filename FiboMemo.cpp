#include<iostream>
using namespace std;

int fibo_memo(int n, int *memo){
	int res;
	if(memo[n]) return memo[n];
	else res = fibo_memo(n-1, memo) + fibo_memo(n-2, memo);
	memo[n] = res;
	return res;
}

int main(){
	int n;
	int memo[25]={1,1}; //now the fibo_memo function could compare with 0 and 1 and it would return the correct value
	
	cin>>n;
	
	cout<<fibo_memo(n, memo);
	return 0;
}


