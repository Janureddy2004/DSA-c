#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *nxt;
}*head=0,*newnode,*temp;
int isloop(struct node *p){
	struct node *t,*q;
	t=q=p;
	do{
		t=t->nxt;
		q=q->nxt;
		q = (q!=NULL)?q->nxt:NULL;
	}while(p&&q);
	return (p==q)?1:0;
}
void makingloop(struct node *p,struct node *q){
	struct node *t;
	t=head->nxt->nxt;
	while(p->nxt!=0){
		p=p->nxt;
	}
	p->nxt=t;
}
int main(){
	int n,i;
	puts("Enter n : ");
	scanf("%d",&n);
	puts("Enter data : ");
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
	makingloop(temp,temp);
	temp=head;
	int k = isloop(temp);
	if(k==1){
		puts("It is loop\n");
	}
	else{
		puts("It is not a loop\n");
	}
	
}
