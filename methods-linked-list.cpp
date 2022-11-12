#include<stdio.h>
#include<stdlib.h>
#define emp printf("Sorry Try Again\n")
#define o temp=head
#define r printf("The linked-list Before applying Operation :\n")
#define t printf("The linked-list After applying Operation :\n ")
// Creating a node
struct node{
	int n;
	struct node *nxt;
}*head=0,*newnode,*temp,*second=0,*temp1,*newnode1;
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
void displaya(struct node *p){
	if(p!=0){
		printf("%3d ",p->n);
		return displaya(p->nxt);
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
	struct node *ti;
	int i;
	if(index>count(p)||index<0)
	emp;
	else if(index == 0){
		ti=(struct node*)malloc(sizeof(struct node));
		ti->n=x;
		ti->nxt=head;
		head=ti;
		p=head;
		displaya(p);
	}
	else{
		ti=(struct node*)malloc(sizeof(struct node));
		ti->n=x;
		for(i=0;i<index-1&&p;i++){
			p=p->nxt;
		}
		if(p){
			ti->nxt=p->nxt;
			p->nxt=ti;	
		}
		p=head;
		displaya(p);
	}
}
// Deleting the node in the linked-list
int deleting(struct node *p,int index){
	struct node *ti=0;
	int x,i;
	if(index<0 || index > count(p))
		emp;
	else if(index == 1){
		head->nxt=head;
		x=p->n;
		delete p;
		return x;
	}
	else{
		for(i=0;i<index-1&&p;i++){
			ti=p;
			p=p->nxt;
		}
		ti->nxt=p->nxt;
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
	for(i=0;i<=c && p;i++){
		a[i]=p->n;
		p=p->nxt;
	}
	p=head;
	for(i=c-1;i>=0 && p;i--){
		p->n=a[i];
		p=p->nxt;
	}
} 
//Reversing the linked-list using sliding pointers
void reverse1(struct node *p){
	struct node *q,*u;
	u=0;
	q=0;
	while(p!=0){
		u=q;
		q=p;
		p=p->nxt;
		q->nxt=u;
	}
	displaya(q);
}
// Reversing the linked-list in recursive method
void reverse_recursive(struct node *p){
	if(p->nxt == NULL){
		head=p;
		return;
	}
	reverse_recursive(p->nxt);
	struct node *q=p->nxt;
	q->nxt=p;
	p->nxt=NULL;
}
//Searching an element is there or not 
int search(struct node *p,int x){
	int c=0;
	if(p!=0){
		c++;
		if(p->n==x){
			int u;
			u=head->n;
			head->n=p->n;
			p->n=u;
			return c;
		}
		else
		return search(p->nxt,x);
	}//puts("Element not found :) ");
}
//Sorting the linked-list
void sort(struct node *p){
	struct node *q=head;
	if(p==NULL){
		emp;
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
	struct node *u,*q=0;
	if(head->n>x){
		swap1(&head->n,&x);
	}
	while(p && p->n<x){
		q=p;
		p=p->nxt;
	}
	u->n=x;
	u->nxt=q->nxt;
	q->nxt=u;
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
void secondl(int n){
	puts("Enter the data :");
	for(int i=0;i<n;i++){
		newnode1=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode1->n);
		newnode1->nxt=0;
		if(second==0)
		second=temp1=newnode1;
		else{
			temp1->nxt=newnode1;
			temp1=newnode1;
		}
	}
}
void concate(struct node *p,struct node *q){
	if(p->nxt!=0){
		return concate(p->nxt,q);
	}
	p->nxt=q;
	q=NULL;
}
void duplicate(struct node *p){
	struct node *u;
	u=head->nxt;
	while(t!=0){
		if(p->n!=u->n){
			p=u;
			u=u->nxt;
		}
		else{
			p->nxt=u->nxt;
			delete u;
			u=p->nxt;
		}
	}
}
int main(){
	int n,i,k,a=1,j,l,f,p;
	char b,c;
	while(a){
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
		while(p){
			puts("\n------| Welcome to linked-list Game |------");
			puts("The following are the operations on linked-list :  ");
			puts("1.Inserting newnode:\na)Insert at given position\nb)inserting in sorted linked-list\n2.Deleting a node\n3.Reversing the linked list :\na)using normal method\nb)using sliding pointers\nc)using recusrion\n4.Searching an element\n5.Sort the linked-list\n6.Minimum & Maximum numbers in the linked-list\n7.Concatenate linked list\n8.Removing Duplicate");
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
							r;
							o;
							display(temp);
							puts("Enter the index and value : ");
							scanf("%d%d",&j,&l);
							o;
							t;
							insert(temp,j,l);
							break;
						case 'b':
							puts("You have selected b) inserting in sorted linked-list :");
							o;
							r;
							display(temp);
							puts("Enter the value : ");
							scanf("%d",&l);
							o;
							sort(temp);
							o;
							insert_sorted(temp,l);
							o;
							t;
							displaya(temp);
							break;
					}
					break;
				case 2:
					puts("You have selected 2.Deleting a node : ");
					o;
					r;
					display(temp);
					puts("Enter the index : ");
					scanf("%d",&j);
					o;
					l=deleting(temp,j);
					printf("The deleted element : %d\n",l);
					o;
					t;
					displaya(temp);
					break;
				case 3:
					puts("You have selected 3.Reversing the linked-list\nSelect the method:\na)Normal method\nb)Sliding pointers method\nc)Recursion method");
					puts("Enter your choice : ");
					fflush(stdin);
					scanf("%c",&b);
					switch(b){
						case 'a':
							puts("You have seleted 'Normal method'");
							o;
							r;
							display(temp);
							o;
							reverse(temp);
							o;
							t;
							displaya(temp);
							break;
						case 'b':
							puts("You have selected 'Sliding pointers method'");
							o;
							r;
							display(temp);
							o;
							t;
							reverse1(temp);
							break;
						case 'c':
							puts("You have selected 'Recursion method'");
							o;
							r;
							display(temp);
							o;
							reverse_recursive(temp);
							o;
							t;
							displaya(temp);
							break;
					}
					break;
				case 4:
					puts("You have selected Searching an element : ");
					o;
					r;
					display(temp);
					puts("Enter the key : ");
					scanf("%d",&l);
					o;
					f =search(temp,l);
					if(f!=0){
						printf("The element %d found at %d\n",l,f);
					}
					else{
						puts("The element not found :(\n");
					}
					o;
					t;
					displaya(temp);
					break;
				case 5:
					puts("You have selected the Sorting the linked list :");
					o;
					r;
					display(temp);
					o;
					sort(temp);
					o;
					t;
					displaya(temp);
					break;
				case 6:
					puts("You have selected Minimum and Maximum number in the linked-list ");
					o;
					l=min(temp);
					o;
					f=max(temp);
					printf("The minimum and maximum number in the linked-list are : %d , %d\n",l,f);
					break;
				case 7:
					o;
					r;
					display(temp);
					puts("You have selected concatenate linked lists\nFor concatenation we need 2 linked lists\nEnter no of nodes and data for 2nd linked list :");
					scanf("%d",&l);
					secondl(l);
					o;
					temp1=second;
					concate(temp,temp1);
					o;
					t;
					displaya(temp);
					break;
				case 8:
					puts("You have selected Removing duplicates from the linked-list ");
					o;
					r;
					display(temp);
					o;
					duplicate(temp);
					o;
					t;
					display(temp);
					break;
				default :
					puts("Enter the correct option :) ");
			}
		puts("Do you want to continue with same linked list :(0,1)");
		scanf("%d",&p);
		}
		puts("do you want to continue by new linked-list : (0,1)");
		scanf("%d",&a);
	}
	puts("------| Thank you |------");
}

