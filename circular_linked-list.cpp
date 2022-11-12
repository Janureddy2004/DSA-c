#include<stdio.h>
#include<stdlib.h>
struct node {
	int n;
	struct node *nxt;
}*head;
void display(struct node *p){
	if(p->nxt!=head){
		printf("%3d ",p->n);
		return display(p->nxt);
	}
	puts("\n");
}
void insert(struct node *p,int x){
	while(p->nxt!=head)
	p=p->nxt;
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	t->n=x;
	p->nxt=t;
	t->nxt=head;
}
void create_circular(){
	head=0;
	int n,i;
	struct node *temp,*newnode;
	puts("Enter n :");
	scanf("%d",&n);
	puts("Enter data : ");
	for(i=0;i<n;i++){
		newnode=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&newnode->n);
		newnode->nxt=0;
		if(head==0){
			head=temp=newnode;
		}
		else{
			temp->nxt=newnode;
			temp=newnode;
		}
		temp->nxt=head;
	}
	temp = head;
	insert(temp,5);
	temp=head;
	display(temp);
}
int main(){
	create_circular();
}
