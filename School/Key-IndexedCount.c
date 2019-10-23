#include<stdio.h>
#define M 11
#define maxN 30

void discount(int a[], int l, int r){
	int i, j, cnt[M];
	int b[maxN];
	
	for(j=0; j<M; j++) cnt[j]=0;
	for(i=l; i<=r; i++) cnt[a[i]+1]++;
	for(j=1; j<M; j++) cnt[j] += cnt[j-1];
	for(i=l; i<=r; i++) b[cnt[a[i]]++] = a[i];
	for(i=l; i<=r; i++) a[i] = b[i-l];
	
}

int main(){
	int a[maxN],i;
	
	for(i=1; i<11; i++){
		scanf("%d",&a[i]);
	}
	
	discount(a, 1, 11);
	
	for(i=1; i<12; i++){
		printf("%d ",a[i]);
	}
	return 0;
}
