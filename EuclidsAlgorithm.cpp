#include<iostream>
using namespace std;

int euclid_gcd(int a, int b){
	return b==0 ? a : euclid_gcd(b, a%b);
}

int main(){
	int x,y,res;

	cout<<"Type two numbers for calculate the gcd of both: "<<endl;
	cin>>x>>y;

	res = euclid_gcd(x, y);
	cout<<res<<endl;

	return 0;
}

/*

int euclid_gcd(int a, int b){
	while(b){
		int remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}

int euclid_gcd(int a, int b){
	int divisor = a;
	int dividend = b;
	while(dividend){
		int remainder = divisor % dividend;
		divisor = dividend;
		dividend = remainder;
	}
	return divisor;
}


int euclid_gcd(int a, int b){
	int divisor = a>=b ? a : b;
	int dividend = a<=b ? a : b;
	while(dividend){
		int remainder = divisor % dividend;
		divisor = dividend;
		dividend = remainder;
	}
	return divisor;
}*/
