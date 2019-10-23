//Function Pointers in C/C++
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
// callback function should compare two integers, should return 1 if fst element has
// higher rank, 0 if elements are equal and -1 if second element has higher rank
int compare(int a, int b){
	if(a>b) return -1;
	else return 1;
}
int absolute_cmp(int a, int b){
	if (abs(a) > abs(b)) return 1;
	return -1;
}
void Sort(int *A, int n, int (*compare)(int,int)){
	int i,j,temp;
	for(i = 0; i<n; i++)
		for(j=0; j<n-1; j++){
			if(compare(A[j],A[j+1]) > 0){
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
}
int cmp(const void* a, const void* b){ //generic pointers , we can typecast them to a pointer of any data type
	int A = *((int*)a); //typecasting to int* and getting value
	int B = *((int*)b);
	return abs(A) - abs(B);
	//return A-B;
}
int main(){
	int i, A[] = {-31,22,-1,50,-6,4}; // => {-1,4,-6,22,-31,50}
	qsort(A, 6, sizeof(int),cmp); //can sort any array quick sort
	//Sort(A, 6, absolute_cmp);
	for(i=0; i<6; i++) printf("%d ",A[i]);
}


/*
void A(){ printf("Hello"); }

void B(void (*ptr)()) //Funcion pointer as argument
{
	ptr(); //Call-back function that "ptr" points to
}

int main(){
	B(A); // A is callback function
	//void (*p)() = A;
}

int Add(int a, int b){
	return a+b;
}
void PrintHello(char *name){
	printf("Hello %s\n", name);
}
int main(){
	int c;
	int (*p)(int,int); //void (*p)(int)
	p=Add; // function name will return us pointer
	c = (*p)(2,3); // de-referencing and executing the function. p(2,3) is the same
	printf("%d \n", c);
	void (*ptr)(char *);
	ptr = PrintHello;
	ptr("Diego");
}*/
