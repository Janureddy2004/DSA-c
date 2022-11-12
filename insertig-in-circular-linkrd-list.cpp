#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *nxt;
}*head;
void inserting(struct node *,int,int);
void display(struct node *p){
	if(p->nxt!=head){
		printf("%3d ",p->n);
		return display(p->nxt);
	}
	printf("%3d \n",p->n);
}
int count(struct node *p){
	int c=0;
	while(p->nxt!=head){
		c++;
		p=p->nxt;
	}
	c+=1;
	return c;
}
void create_circular(){
	head=0;
	int n,i,x,ind;
	struct node *t,*newnode;
	puts("Enter n : ");
	scanf("%d",&n);
	puts("Enter the data : ");
	for(i=0;i<n;i++){
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->n);
		newnode->nxt=0;
		if(head==0)
		head=t=newnode;
		else{
			t->nxt=newnode;
			t=newnode;
		}
	}
	t->nxt=head;
	t=head;
	puts("Enter the data  and index you want to insert in the linked-list : ");
	scanf("%d%d",&x,&ind);
	inserting(t,x,ind);
}
void inserting(struct node *p,int x,int ind){
	struct node *u;
	int i;
	if(ind>count(p) || i<0)
	puts("Insertion cannot happen");
	if(ind==0){
		u=(struct node*)malloc(sizeof(struct node));
		u->n=x;
		if(head==0){
			head=u;
			head->nxt=head;
		}
		else{
			while(p->nxt!=head)	p=p->nxt;
			p->nxt=u;
			u->nxt=head;
			head=u;
		}
	}
	else{
		u=(struct node *)malloc(sizeof(struct node));
		u->n=x;
		for(i=0;i<count(p)-1;i++)
		p=p->nxt;
		u->nxt=p->nxt;
		p->nxt=u;
	}
	p=head;
	display(p);
}
int main(){
	create_circular();
	
}
