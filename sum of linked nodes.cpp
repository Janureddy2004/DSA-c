#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *nxt;
}*head=0,*newnode,*temp;
int sum(struct node *a){
	int sum =0;
	while(a!=0){
		sum+=a->n;
		a=a->nxt;
	}
	return sum;
}
int main(){
	int ch=1;
	while(ch){
		newnode=(struct node*)malloc(sizeof(struct node));
		puts("Enter the data :");
		scanf("%d",&newnode->n);
		newnode->nxt=0;
		if(head==0){
			head=temp=newnode;
		}
		else{
			temp->nxt=newnode;
			temp=newnode;
		}
		puts("Do you want to continue : ");
		scanf("%d",&ch);
	}
	temp = head;
	while(temp!=0){
		printf("%3d",temp->n);
		temp=temp->nxt;
	}
	temp=head;
	int res=sum(temp);
	printf("Sum of the nodes are : %d",res);
}
