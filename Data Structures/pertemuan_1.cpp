#include<stdio.h>

int main(){
	
	int n = 9;
	
	int * pn = &n;
	
	printf("value of X: %d\n", n);
	printf("value of pn: %d\n", pn);
	
	*pn = 22;
	
	printf("new value of n: %d\n", n);
	
	
return 0;	
}
