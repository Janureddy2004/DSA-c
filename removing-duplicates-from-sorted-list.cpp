#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *nxt;
}*head=0,*newnode,*temp;
void duplicate(struct node *p){
	struct node *t;
	t=head->nxt;
	while(t!=0){
		if(p->n!=t->n){
			p=t;
			t=t->nxt;
		}
		else{
			p->nxt=t->nxt;
			delete t;
			t=p->nxt;
		}
	}
}
void display(struct node *p){
	if(p!=0){
		printf("%3d ",p->n);
		return display(p->nxt);
		
	}
	puts("\n");
}
int main(){
	int n,i;
	puts("Enter n :");
	scanf("%d",&n);
	puts("Enter the data : ");
	for(i=0;i<n;i++){
		newnode = (struct node*)malloc(sizeof(struct node));
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
	display(temp);
	temp=head;
	duplicate(temp);
	display(temp);
}
