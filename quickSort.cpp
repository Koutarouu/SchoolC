#include<iostream>
#include<stdlib.h>
using namespace std;
#define swap(A,B) { int t = A; A=B; B=t; }

int Partition(int *A, int start, int end){
	int pivot = A[end];
	int partitionIndex = start; // set partition index as start initially
	for(int i = start; i < end; i++) {
		if(A[i] <= pivot) {
			swap(A[i], A[partitionIndex]); // swap if element is lesser than pivot
			partitionIndex++;
		}
	}
	swap(A[partitionIndex], A[end]); // swap pivot with element at partition index
	return partitionIndex;
}

void QuickSort(int *A, int start, int end){
	if(start < end){
		int pIdx = Partition(A, start, end); // calling partition
		QuickSort(A, start, pIdx-1);
		QuickSort(A, pIdx-1, end);
	}
}
int main(){
	int A[] =  {7,6,5,4,3,2,1,4};
	QuickSort(A, 0, 7);
	for(int i=0; i<8; i++) cout<<A[i]<<' ';
	return 0;
}

