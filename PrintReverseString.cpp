#include<iostream>
using namespace std;

void printReverse(const char *str){
	if(!*str) return;
	printReverse(str + 1);
	putchar(*str);
}

int main(){
	char text[30];a
	cin>>text;
	printReverse(text);
	
	return 0;
}
