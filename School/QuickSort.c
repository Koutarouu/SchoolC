#include<stdio.h>

typedef int Item;
#define less(A,B) (A<B)
#define exch(A,B) { Item t=A; A=B; B=t; }

int partition(Item a[], int l, int r){
	int i=l-1, j=r; Item v = a[r];
	
	for( ; ; ){
		while(less(a[++i], v)) ;
		while(less(v, a[--j])) if(r==l) break;
		if(i >= j) break;
		exch(a[i], a[j]);
	}
	
	exch(a[i], a[r]);
	return i;
}

void quickSort(Item a[], int l, int r){
	int i;
	if(r<=l) return;
	i=partition(a, l, r);
	quickSort(a, l, i-1);
	quickSort(a, i+1, r);
}

int main(){
	int a[30],i;
	
	for(i=0; i<10; i++){
		scanf("%d",&a[i]);
	}
	
	quickSort(a, 0, 10);
	
	for(i=0; i<10; i++){
		printf("%d ",a[i]);
	}
	
	return 0;
}
