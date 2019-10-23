#include<stdio.h>

typedef int Item;
#define less(A,B) (A<B)
#define exch(A,B) { Item t=A; A=B; B=t; }
#define compexch(A, B) if(less(B,A)) exch(A,B)

void shellSort(Item a[], int l, int r){
	int i, j, h;
	
	for(h=1; h<=(r-1)/9; h=3*h+1) ;
	for( ; h>0; h/=3)
		for(i = l+h; i<=r; i++){
			int j=i; Item v = a[i];
			while(j >= l+h && less(v, a[j-h]))
			{ a[j] = a[j-h]; j-=h; }
			a[j]=v;
		}
}

int main(){
	int a[30],i;
	
	for(i=0; i<10; i++){
		scanf("%d",&a[i]);
	}
	
	shellSort(a, 0, 10);
	
	for(i=0; i<10; i++){
		printf("%d ",a[i]);
	}
}
