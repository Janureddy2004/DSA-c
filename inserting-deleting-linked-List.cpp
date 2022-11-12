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
	else if(pos==1){
		head=head->nxt;
		x=p->n;
		delete p;
	}
	else{
		t=NULL;
		for(int i=0;i<pos-1;i++){
			t=p;
			p=p->nxt;
		}
		t->nxt=p->nxt;
		x=p->n;
		delete p;
	}
	return x;
}
void insert(struct node *p,int pos,int val){
	struct node *t;
	if(pos<0||pos>count(p)){
		return;
	}
	else if(pos==0){
		t=(struct node*)malloc(sizeof(struct node));
		t->n=val;
		t->nxt=head;
		head=t;
	}
	else{
		t=(struct node*)malloc(sizeof(struct node));
		t->n=val;
		for(int i=0;i<pos-1;i++){
			p=p->nxt;
		}
		t->nxt=p->nxt;
		p->nxt=t;
	}
}
int main(){
	int n,i,p,x,s,j=1;
	puts("Enter the n : ");
	scanf("%d",&n);
	puts("Enter the data : ");
	for(i=0;i<n;i++){
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
	while(j!=0){
		temp=head;
		puts("Enter your choice :\n1.Insertion of node\n2.Deletion of node\n");
		scanf("%d",&s);
		switch(s){
			case 1:
				display(temp);
				puts("You have selected Insertion of node\nEnter the position and value of the node :");
				scanf("%d%d",&p,&x);
				temp=head;
				insert(temp,p,x);
				temp=head;
				puts("The list after Insertion : ");
				display(temp);
				break;
			case 2:
				display(temp);
				puts("You have selected Deletion of node\nEnter the position of the node : ");
				scanf("%d",&p);
				temp=head;
				x=deleting(temp,p);
				temp = head;
				puts("\nThe list after Deletion :");
				display(temp);
				printf("The value deleted is %d\n",x);
				
		}
		puts("Do you want to continue : (1-continue,0-stop)");
		scanf("%d",&j);
	}
	puts("--- |Thank you| ---");
}
