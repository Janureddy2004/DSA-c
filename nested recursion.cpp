#include<stdio.h>
#include<stdlib.h>
int fun(int n){
	if(n>100)
	return n-10;
	else
	return fun(fun(n+11));
}
int main(){
	int a = fun(23);
	printf("%d ",a);
}
