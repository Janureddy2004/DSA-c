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
void insert(struct node *p,int pos){
	struct node *t;
	if(pos<0 || pos>count(p))
		return;
	if(pos==0){
		t=(struct node*)malloc(sizeof(struct node));
		puts("Enter the data for newnode : ");
		scanf("%d",&t->n);
		t->nxt=head;
		head=t;
	}
	else if(pos>0){
		p=head;
		for(int i=0;i<pos-1 && p;i++){//checking p is not null
			p=p->nxt;
		}
		if(p){//checking not null
			t=(struct node*)malloc(sizeof(struct node));
			puts("Enter the data for newnode : ");
			scanf("%d",&t->n);
			t->nxt=p->nxt;
			p->nxt=t;
		}
	}
}
int main(){
	int m,i,k;
	struct node *t;
	puts("Enter no of nodes : ");
	scanf("%d",&m);
	puts("Enter the data : ");
	for(i=0;i<m;i++){
		newnode=(struct node*)calloc(m,sizeof(struct node));
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
	puts("The list before the insertion : ");
	display(temp);
	temp=head;
	puts("enter the position for newnode to insert : ");
	scanf("%d",&k);
	insert(temp,k);
	temp=head;
	puts("The list after insertion : ");
	display(temp);
}
