#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *nxt;
}*head=0,*newnode,*temp;
void display(struct node *p){
	if(p!=0){
		printf("%3d ",p->n);
		return display(p->nxt);
	}
	puts("\n");
}
void reverse(struct node *p,struct node *q){
	if(p!=0){
		reverse(p->nxt,p);
		p->nxt=q;
	}
	else{
		head=q;
	}
}
int main(){
	int n,i;
	puts("Enter no of nodes : ");
	scanf("%d",&n);
	puts("Enter data : ");
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
	reverse(temp,NULL);
	temp=head;
	display(temp);
}
