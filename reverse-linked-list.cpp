#include<stdio.h>
#include<stdlib.h>
#define max 100
struct node{
	int n;
	struct node *nxt;
}*head=0,*newnode,*temp;
int count(struct node *p){
	int c=0;
	while(p!=0){
		c++;
		p=p->nxt;
	}
	return c;
}
void display(struct node *p){
	if(p!=0){
		printf("%3d ",p->n);
		return display(p->nxt);
	}
	puts("\n");
}
void reverse(struct node *p){
	int *a,i=0;
	int c= count(p);
	a=(int *)calloc(c,sizeof(int));
	for(i=0;i<=c && p;i++){
		a[i] = p->n;
		p=p->nxt;
	}
	p=head;
	for(i=c-1;i>=0 && p;i--){
		p->n=a[i];
		p=p->nxt;
	}
}

int main(){
	int n,i;
	puts("Enter n : ");
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
	temp=head;
	reverse(temp);
	temp=head;
	display(temp);
}
