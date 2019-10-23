#include<iostream>
using namespace std;

float Pow(float x, int n){
	if(n==0) return 1;
	if(n<0){
		return Pow(1/x,-n);
	}
	if(n%2==0){
		float y = Pow(x, n/2); // very important this variable for not duplicate the function calls
		return y*y;
	}
	return x*Pow(x, n-1);
}

int main(){
	int x,n;
	cin>>x;
	cin>>n;
	cout<<Pow(x,n);
	return 0;
}

/*
Time complexity
T(n) = 1 +c2 +clog n
O(log n)
*/
