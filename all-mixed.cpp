#include<stdio.h>
#include<stdlib.h>
// Creating a node
struct node{
	int n;
	struct node *nxt;
}*head=0,*newnode,*temp;
// Counting no of nodes in a linked-list
int count(struct node *p){
	int c=0;
	while(p!=0){
		c++;
		p=p->nxt;
	}
	return c;
}
//Display's the linked-list
void display(struct node *p){
	if(p!=0){
		printf("%3d ",p->n);
		return display(p->nxt);
	}
	puts("\n");
}
// Swap's the linked-list
void swap(struct node *p,struct node *q){
	int temp=p->n;
	p->n=q->n;
	q->n=temp;
}
//Swap's the numbers
void swap1(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
// Inserting a newnode into the linked-list
void insert(struct node *p,int index,int x){
	struct node *t;
	int i;
	if(index>count(p)||index<0)
	return;
	else if(index == 0){
		t=(struct node*)malloc(sizeof(struct node));
		t->n=x;
		t->nxt=head;
		head=t;
		p=head;
		display(p);
	}
	else{
		t=(struct node*)malloc(sizeof(struct node));
		t->n=x;
		for(i=0;i<index-1&&p;i++){
			p=p->nxt;
		}
		if(p){
			t->nxt=p->nxt;
			p->nxt=t;	
		}
		p=head;
		display(p);
	}
}
// Deleting the node in the linked-list
int deleting(struct node *p,int index){
	struct node *t=0;
	int x,i;
	if(index<0 || index > count(p))
		return 0;
	else if(index == 1){
		head->nxt=head;
		x=p->n;
		delete p;
		return x;
	}
	else{
		for(i=0;i<index-1&&p;i++){
			t=p;
			p=p->nxt;
		}
		t->nxt=p->nxt;
		x=p->n;
		delete p;
		return x;	
	}	
}
//Reversing the linked-list
void reverse(struct node *p){
	int *a,i;
	int c= count(p);
	a=(int *)calloc(c,sizeof(int));
	for(i=0;i<c;i++){
		a[i]=p->n;
		p=p->nxt;
	}
	for(i=c-1;i>=0&&p;i--){
		p->n=a[i];
		p=p->nxt;
	}
	p=head;
	display(p);
} 
//Reversing the linked-list using sliding pointers
void reverse1(struct node *p){
	struct node *q,*r;
	r=0;
	q=0;
	while(p!=0){
		r=q;
		q=p;
		p=p->nxt;
		q->nxt=r;
	}
	display(q);
}
// Reversing the linked-list in recursive method
void reverse_recursive(struct node *p){
	if(p->nxt==NULL){
		head=p;
		return;
	}
	reverse_recursive(p->nxt);
	struct node *q=p->nxt;
	q->nxt=p;
	p->nxt=NULL;
}
//Searching an element is there or not 
void search(struct node *p,int x){
	if(p!=0){
		if(p->n==x){
			puts("Element found :)");
		}
		return search(p->nxt,x);
	}
	puts("Element not found :) ");
}
//Sorting the linked-list
void sort(struct node *p){
	struct node *q=head;
	if(p==NULL){
		return;
	}
	while(p->nxt!=NULL){
		if(p->n>p->nxt->n){
			swap(p,p->nxt);
		}
		p=p->nxt;
	}
}
// Insertion in the sorted linked-list
void insert_sorted(struct node *p,int x){
	struct node *t,*q=0;
	if(head->n>x){
		swap1(&head->n,&x);
	}
	while(p && p->n<x){
		q=p;
		p=p->nxt;
	}
	t->n=x;
	t->nxt=q->nxt;
	q->nxt=t;
}
int main(){
	int n,i,k,a=1,j,l;
	char b,c;
	puts("Enter n :");
	scanf("%d",&n);
	puts("Enter the data : ");
	for(i=0;i<n;i++){
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->n);
		newnode->nxt=0;
		if(head==0)
			head=temp=newnode;
		else{
			temp->nxt=newnode;
			temp=newnode;
		}
	}
	while(a){
		puts("\n------| Welcome to linked-list Game |------");
		puts("The following are the operations on linked-list :  ");
		puts("1.Inserting newnode:\na)Insert at given position\nb)inserting in sorted linked-list\n2.Deleting a node\n3.Reversing the linked list :\na)using normal method\nb)using sliding pointers\nc)using recusrion\n4.Searching an element\n");
		puts("Enter your choice : ");
		scanf("%d",&k);
		switch(k){
			case 1:
				puts("You have selected Inserting newnode \nselect the method:\na)Insert at given position\nb)Insert in sorted linked-list");
				puts("Enter the method : ");
				fflush(stdin);
				scanf("%c",&b);
				switch(b){
					case 'a':
						puts("You have selected a) inserting newnode at given position : ");
						temp=head;
						display(temp);
						puts("Enter the index and value : ");
						scanf("%d%d",&j,&l);
						temp=head;
						insert(temp,j,l);
						break;
					case 'b':
						puts("You have selected b) inserting in sorted linked-list :");
						temp=head;
						display(temp);
						puts("Enter the value : ");
						scanf("%d",&l);
						temp=head;
						insert_sorted(temp,l);
						temp=head;
						display(temp);
						break;
				}
				break;
			case 2:
				puts("You have selected 2.Deleting a node : ");
				temp=head;
				display(temp);
				puts("Enter the index : ");
				scanf("%d",&j);
				temp=head;
				l=deleting(temp,j);
				printf("The deleted element : %d\n",l);
				temp=head;
				display(temp);
				break;
			case 3:
				puts("You have selected 3.Reversing the linked-list\nSelect the method:\na)Normal method\nb)Sliding pointers method\nc)Recursion method");
				puts("Enter your choice : ");
				fflush(stdin);
				scanf("%c",&b);
				switch(b){
					case 'a':
						puts("You have seleted 'Normal method'");
						temp=head;
						display(temp);
						head=temp;
						reverse(temp);
						break;
					case 'b':
						puts("You have selected 'Sliding pointers method'");
						temp=head;
						display(temp);
						temp=head;
						reverse1(temp);
						break;
					case 'c':
						puts("You have selected 'Recursion method'");
						temp=head;
						display(temp);
						temp=head;
						reverse_recursive(temp);
						temp=head;
						display(temp);
						break;
				}
				break;
			case 4:
				puts("You have selected Searching an element : ");
				temp=head;
				display(temp);
				puts("Enter the key : ");
				scanf("%d",&l);
				temp=head;
				search(temp,l);
				temp=head;
				display(temp);
				break;
		}
		puts("Do you want to continue :(0,1)");
		scanf("%d",&a);
	}
	puts("------| Thank you |------");
}
