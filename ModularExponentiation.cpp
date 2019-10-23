#include<iostream>
using namespace std;
//famous algorithm in the world of cryptography
int Mod(int x, int n, int m){
	if(n==0) return 1;
	if(n%2==0){
		int y = Mod(x, n/2, m); // very important this variable for not duplicate the function calls
		return (y*y) % m;
	}
	return ((x%m)*Mod(x, n-1, m)) % m;
}

int main(){
	int x,n,m;
	cin>>x;
	cin>>n;
	cin>>m;
	cout<<Mod(x,n,m);
	return 0;
}
