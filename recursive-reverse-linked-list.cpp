#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *nxt;
}*head=0,*newnode,*temp,*q;
void display(struct node *p){
	if(p!=0){
		printf("%3d ",p->n);
		return display(p->nxt);
	}
	puts("\n");
}
void reverse(struct node *p){
	if(p->nxt==NULL){
		head=p;
		return;
	}
		reverse(p->nxt);
		struct node *q =p->nxt;
		q->nxt=p;
		p->nxt=NULL;
}
int main(){
	int n,i;
	puts("Enter n : ");
	scanf("%d",&n);
	puts("Enter the data : ");
	for(i=0;i<n;i++){
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->n);
		newnode->nxt=0;
		if(head==0){
			head=temp=newnode;
		}
		else{
			temp->nxt=newnode;
			temp=newnode;
		}
	}
	temp=head;
	reverse(temp);
	temp=head;
	display(temp);
	
}
