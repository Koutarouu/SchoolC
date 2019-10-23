//Bitwise Operators
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

void calculate_the_maximum(int n, int k) {
	int maxnd=0,maxor=0,maxxor=0,a,b;
	for(a=1; a<n; a++){
		for(b=a+1; b<=n; b++){
			if((a&b) > maxnd && (a&b) < k) maxnd = (a&b);//putos parentesis
			if((a|b) > maxor && (a|b) < k) maxor = (a|b);
			if((a^b) > maxxor && (a^b) < k) maxxor = (a^b);
		}
	}
	printf("%d\n%d\n%d\n",maxnd,maxor,maxxor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}


/*
unsigned int by(unsigned int k) {
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * by(k / 2)));
}

if(by(a)&by(b) > maxnd && by(a)&by(b) < k) maxnd=by(a)&by(b);
if(by(a)|by(b) > maxor && by(a)|by(b) < k) maxor=by(a)|by(b);
if(by(a)^by(b) > maxxor && by(a)^by(b) < k) maxxor=by(a)^by(b);
*/
