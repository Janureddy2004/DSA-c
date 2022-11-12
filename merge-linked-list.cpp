#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *nxt;
};
void display(struct node *p){
	if(p!=0){
		printf("%3d ",p->n);
		return display(p->nxt);
	}
	puts("\n");
}
int count(struct node *p){
	int c=0;
	while(p!=0){
		c++;
		p=p->nxt;
	}
	return c;
}
struct node *create(){
	struct node *head=0,*temp,*newnode;
	int n,i;
	puts("enter n :");
	scanf("%d",&n);
	puts("Enter the data : ");
	for(i=0;i<n;i++){
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->n);
		newnode->nxt=0;
		if(head==0)
		head=temp=newnode;
		else{
			temp->nxt=newnode;
			temp=newnode;
		}
	}
	return head;
}
struct node *merge(struct node *p,struct node *q){
	node *t=p;
	while(t->nxt!=0){
		t=t->nxt;
	}
	t->nxt=q;
	return p;
}
int main(){
	struct node *h1=create();
	struct node *h2= create();
	struct node *h = merge(h1,h2);
	display(h);
}

