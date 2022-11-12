#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *nxt;
}*head;
void display(struct node *u){
	if(u->nxt!=head){
		printf("%3d ",u->n);
		return display(u->nxt);
	}
	printf("%3d \n",u->n);
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
void inserting(struct node *p,int ind,int x){
	struct node *t;
	if(ind>count(p)||ind<0)
	puts("Insertion cannot happen : ");
	if(ind==0){
		t=(struct node*)malloc(sizeof(struct node));
		t->n=x;
		
		if(head==0){
			head=t;
			head->nxt=head;
		}
		else
		while(p->nxt!=head) p=p->nxt;
		p->nxt=t;
		t->nxt=head;
		head=t;
	}
	else{
		t=(struct node*)malloc(sizeof(struct node));
		t->n=x;
		for(int i=0;i<ind-2;i++)
			p=p->nxt;
			t->nxt=p->nxt;
			p->nxt=t;	
	}
	p=head;
	display(p);
}
void deleting(struct node *p,int ind){
	struct node *t;
	if(ind>count(p)||ind<0)
	puts("Deletion cannot happen ");
	if(ind==0){
		while(p->nxt!=head)
		p=p->nxt;
		p->nxt=head->nxt;
		int x=head->n;
		delete head;
	}
	else{
		for(int i=0;i<ind-2;i++){
			p=p->nxt;
		}
		t=(struct node*)malloc(sizeof(struct node));
		t=p->nxt;
		p->nxt=t->nxt;
		int x=t->n;
		delete t;
	}
	p=head;
	display(p);
}
void creating(){
	head=0;
	struct node *t,*newnode;
	int n,i;
	puts("Enter n: ");
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
	int j;
	puts("do you want to delete or inserrt the linked-list :(insert-1,delete -2)");
	scanf("%d",&j);
	if(j==1){
		int x,y;
		puts("Enter the position and data to be insert : ");
		scanf("%d%d",&x,&y);
		inserting(t,x,y);
	}
	else{
		int x;
		puts("Enter the position to be delete : ");
		scanf("%d",&x);
		deleting(t,x);
	}
}
int main(){
	creating();
}
