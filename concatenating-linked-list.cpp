//concatenating 2 linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *nxt;
}*head=0,*temp,*newnode,*second=0,*temp1,*newnode1;
void display(struct node *p){
	if(p!=0){
		printf("%3d ",p->n);
		return display(p->nxt);
	}
	puts("\n");
}
void appending(struct node *p,struct node *q){
	if(p->nxt!=0){
		return appending(p->nxt,q);
	}
	p->nxt=q;
	q=NULL;
}
int main(){
	int n,i,m;
	puts("Enter the no of nodes for 1st linked list : ");
	scanf("%d",&n);
	puts("Enter the data : ");
	for(i=0;i<n;i++){
		newnode=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&newnode->n);
		newnode->nxt=0;
		if(head==0)
			head=temp=newnode;
		else{
			temp->nxt=newnode;
			temp=newnode;
		}
	}
	temp=head;
	puts("Enter no of nodes for 2nd linked list : ");
	scanf("%d",&m);
	puts("Enter the data : ");
	for(i=0;i<m;i++){
		newnode1=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode1->n);
		newnode1->nxt=0;
		if(second==0)
		second=temp1=newnode1;
		else{
			temp1->nxt=newnode1;
			temp1=newnode1;
		}
	}
	temp1=second;
	appending(temp,temp1);
	temp=head;
	display(temp);
}

