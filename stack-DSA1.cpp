#include<stdio.h>
#include<stdlib.h>
#define m 100
int top =-1;
int a[m],n;
int isfull(){
	if(top+1 == n)
	return 1;
	else return 0;
}
int isempty(){
	if(top==-1) return 1;
	else return 0;
}
void push(int k){
	if(isfull()) puts("The stack is overflow :(");
	else{
		a[top+=1]=k;
	}
}
int pop(){
	if(isempty()) puts("The stack is empty :(");
	else{
		return a[top--];
	}
}
void display(int a[]){
	for(int i=0;i<(top+1);i++){
		printf("%4d ",a[i]);
	}
}
int main(){
	puts("Enter n : ");
	scanf("%d",&n);
	int i=1;
	while(i){
		puts("Menu:\n1.Push\n2.Pop\n3.length\nEnter your option : ");
		int k;
		scanf("%d",&k);
		switch(k){
			case 1:
				puts("Enter the data to be pushed into the stack : ");
				int j;
				scanf("%d",&j);
				push(j);
				break;
			case 2:
				printf("The element deleted from the stack is : %d",pop());
				break;
			case 3:
				printf("the length of the stack is : %d",top+1);
				break;
			default:
				puts("Entered wrong option :(");
		}
		puts("Do you want to continue or not :");
		scanf("%d",&i);
	}
	display(a);
}

