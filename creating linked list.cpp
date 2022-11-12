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
int count(struct node *p){
	int c=0;
	while(p!=0){
		c++;
		p=p->nxt;
	}
	return c;
}
void insert(struct node *p,int index,int x){
	struct node *t;
	if(index<0 || index>count(p))
	return;
	if(index==0){
		t=(struct node*)malloc(sizeof(struct node));
		t->n=x;
		t->nxt=head;
		head=t;
	}
	else{
		t=(struct node*)malloc(sizeof(struct node));
		t->n=x;
		for(int i=0;i<index-1&&p;i++){
			p=p->nxt;
		}
		if(p){
			t->nxt=p->nxt;
			p->nxt=t;
		}
	}
}
int main(){
	int m,i;
	puts("Enter no of nodes : ");
	scanf("%d",&m);
	puts("Enter the data : ");
	for(i=0;i<m;i++){
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
	puts("List before inserting : ");
	display(temp);
	temp=head;
	insert(temp,2,8);
	temp=head;
	puts("After inserting : ");
	display(temp);
	
}
