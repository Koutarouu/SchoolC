#include<iostream>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

using namespace std;

int w[]={0,1,2,4,2,5,7,3,2},v[]={0,5,3,5,3,2,4,3,7};
int arr[9][15];

int KS(int n, int C){
	int res,tmp1,tmp2;
	if(arr[n][C]) return arr[n][C];
	if(n==0 || C==0) res = 0;
	else if(w[n] > C) res = KS(n-1, C);
	else{
		tmp1 = KS(n-1, C);
		tmp2 = v[n] + KS(n-1, C - w[n]);
		res = MAX(tmp1, tmp2);
	}
	arr[n][C] = res;
	return res;
}

int main(){
	int n=9,c=15;
	
	cout<<KS(n,c)<<endl;
	
	
	return 0;
}
