#include<iostream>
#include<stdio.h>
#include <string.h>

using namespace std;

void print(char *C)
{
	*C = 'E';
	while(*C != '\0')
	{
		printf("%c", *C);
		C++;
	}
	printf("\n");
}

int main(){
	char C[20] = "Hello";
	print(C);
	printf("%s",C);
	
	/*
	int a=10;
	int *p=&a;
	cout<<"Address p is "<<p<<endl;
	cout<<"size of integer is "<<sizeof(int)<<" bytes "<<endl;
	cout<<"Address p is "<<p+1<<endl;
	cout<<*(p+1);*/
	return 0;
}
