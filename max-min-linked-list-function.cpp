#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *nxt;
}*head=0,*newnode,*temp;
void display(struct node *h)
{
	if(h!=0){
		printf("%2d ",h->n);
		display(h->nxt);
	}
}
int min(struct node *p){
	int m=200;
	while(p!=0){
		if(m> p->n)
		m=p->n;
		p=p->nxt;
	}
	return m;
}
int max(struct node *p){
	int  m=-9874;
	while(p!=0){
		if(p->n>m)
		m=p->n;
		p=p->nxt;
	}
	return m;
}
int main(){
	int ch=1;
	while(ch){
		newnode=(struct node*)malloc(sizeof(struct node));
		puts("Enter the data : ");
		scanf("%d",&newnode->n);
		newnode->nxt=0;
		if(head==0){
			head=temp=newnode;
		}
		else{
			temp->nxt=newnode;
			temp=newnode;
		}
		puts("Do you want to continue : ");
		scanf("%d",&ch);
	}
	temp=head;
	display(temp);
	temp=head;
	int mini = min(temp);
	temp=head;
	int maxi = max(temp);
	printf("The maximun and minimum number in the linked list : %d %d",maxi,mini);
	
}
