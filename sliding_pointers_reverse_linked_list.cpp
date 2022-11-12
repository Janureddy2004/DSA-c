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
void sliding_rev(struct node *p){
	struct node *q,*r;
	q=0;
	r=0;
	while(p!=0){
		r=q;
		q=p;
		p=p->nxt;
		q->nxt=r;
	}
	display(q);
}
int main(){
	int m,i;
	puts("Enter n : ");
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
	sliding_rev(temp);
}
