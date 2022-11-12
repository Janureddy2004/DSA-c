#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *pre;
	int n;
	struct node *nxt;
}*head=0,*temp,*newnode;
void display(struct node *p){
	if(p!=0){
		printf("%3d ",p->n);
		return display(p->nxt);
	}
	puts("\n");
}
void creating(){
	int n,i;
	puts("Enter n : ");
	scanf("%d",&n);
	puts("Enter the data : ");
	for(i=0;i<n;i++){
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->n);
		newnode->pre=newnode->nxt=0;
		if(head==0){
			head=temp=newnode;
		}
		else{
			temp->nxt=newnode;
			newnode->pre=temp;
			temp=newnode;
		}
	}
	temp=head;
	display(temp);
}
int main(){
	creating();
}
