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
int deleting(struct node *p,int pos){
	struct node *t;
	int x;
	if(pos>count(p)||pos<0){
		return 0;
	}
	else if(pos==0){
		head=head->nxt;
		x = p->n;
		delete p;
	}
	else{
		t=NULL;
		for(int i=0;i<pos-1;i++){
			t=p;
			p=p->nxt;
		}
		t->nxt=p->nxt;
		x = p->n;
		delete p;
	}
	return x;
}
int main(){
	int m,i,p;
	puts("Enter n : ");
	scanf("%d",&m);
	puts("Enter the data : ");
	for(i=0;i<m;i++){
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
	puts("The list before deleting : ");
	display(temp);
	puts("Enter the position of the node : ");
	scanf("%d",&p);
	temp=head;
	int c=deleting(temp,p);
	temp=head;
	display(temp);
	printf("The deleted value : %d",c);
}
