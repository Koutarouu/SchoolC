
#include<iostream>

const int N=1000;

using namespace std;

int main(){
	
	int i,j,a[N+1];
	
	for(a[1]=0, i=2; i<=N; i++) a[i]=1;
	
	for(i=2; i<=N/2; i++)
		for(j=2; j<=N/i; j++)
			a[i*j] = 0;
	
	for(i=1, j=0; i<N; i++)
		if(a[i]) cout<<i<<endl;
	cout<<'\n';
	
	return 0;
}
