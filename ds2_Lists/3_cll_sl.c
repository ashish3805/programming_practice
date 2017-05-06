/*Q.3 Create a Circular Singly Linked List and perform following operation on it-
	Insert a node at middle of the Circular Singly linked list.
	Insert a node at the last of the Circular Singly linked list.
	Delete first node of a Circular Singly linked list.
	Delete middle node of a Circular Singly linked list.
	Delete last node of a Circular Singly linked list.*/

#include<stdio.h>
#include<malloc.h>
#include<stddef.h>
#include<stdlib.h>
#define TRUE 1
typedef struct node node;
struct node{
	int val;
	struct node *next;
}*start=NULL,*tmp,*last;

void display(){
	tmp=start;
	printf("\n");
	if(tmp!=NULL)
	{
		do
		{
			printf("%d-->",tmp->val);
			tmp=tmp->next;
		}while(tmp!=start);
	printf("END");
	}
	else
	printf("NULL");

return ;
}

void ins_mid(){
	int after,val;
	printf("\nAfter : ");
	scanf("%d",&after);
	printf("\nValue : ");
	scanf("%d",&val);
	node *move;
	move=start;
	while(move->val!=after)
		move=move->next;
	tmp=(node *)malloc(sizeof(node));
	tmp->val=val;
	tmp->next=move->next;
	move->next=tmp;
	display();
}

void ins_last(){
	int val;
	printf("\nValue : ");
	scanf("%d",&val);
	tmp=(node *)malloc(sizeof(node));
	tmp->val=val;
	tmp->next=start;
	last->next=tmp;
	last=tmp;
	display();
return ;
}

void del_first(){
	tmp=start;
	start=start->next;
	last->next=start;
	free(tmp);
	display();
return ;
}

void del_mid(){
	int val;
	printf("\nNode value : ");
	scanf("%d",&val);
	node *p,*move;
	move=p=start;
	while(move->val!=val)
	{
		p=move;
		move=move->next;
	}
	p->next=move->next;
	free(move);
	display();
return;
}

void del_last(){
	node *move=start;
	while(move->next!=last)
		move=move->next;
	tmp=last;
	move->next=start;
	last=move;
	free(tmp);
	display();
return;
}

void ins_first(){
	int val;
	printf("\nNode value:");
	scanf("%d",&val);
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->val=val;
	if(start==NULL)
	{
		tmp->next=tmp;
		start=last=tmp;
	}
	else
	{
		tmp->next=start;
		last->next=tmp;
		start=tmp;
	}
	display();
return;
}


int main(){
	int ch=1;

	while(TRUE){
		printf("\n0.Insert at First\n1.Insert at middle\n2.Insert at last\n3.Delete first node\n4.Delete middle node\n5.Delete last node\n6.Diplay\n7.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 0:ins_first();
					break;
			case 1:ins_mid();
					break;
			case 2:ins_last();
					break;
			case 3:del_first();
					break;
			case 4:del_mid();
					break;
			case 5:del_last();
					break;
			case 6:display();
					break;
			case 7:exit(0);
					break;
			default:printf("Wrong choice retry....");
					break;
		}
	}
return 0;
}
