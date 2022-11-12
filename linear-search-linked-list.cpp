#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	struct node *nxt;
}*head=0,*newnode,*temp;
struct node * search(struct node *p,int k){
	int count=0;
	if(p!=0){
		count++;
		if(p->n==k){
			int t;
			t=head->n;
			head->n=p->n;
			p->n=t;
			return p;
		}
	else
		return search(p->nxt,k);
	}
	
}
void display(struct node *p){
	if(p!=0){
		printf("%3d ",p->n);
		return display(p->nxt);
	}
}
int main(){
	int k,m;
	struct node *p;
	puts("Enter no of nodes :");
	scanf("%d",&k);
	puts("Enter the data : ");
	for(int i=0;i<k;i++){
		newnode=(struct node*)calloc(k,sizeof(struct node));
		scanf("%d",&newnode->n);
		newnode->nxt=NULL;
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
	puts("Enter the key element : ");
	scanf("%d",&m);
	temp=head;
	p=search(temp,m);
	if(p!=NULL){
		printf("The element found : %u",p);
	}
	else{
		puts("The element not found :(");
	}
	
}
