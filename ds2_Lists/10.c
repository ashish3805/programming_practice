/*Q.10 Write a C function that moves last element to front in a given Singly Linked List.*/
#include<stdio.h>
#include<malloc.h>
#include<stddef.h>
#include<stdlib.h>
#define TRUE 1
typedef struct node node;
struct node {
	int val;
	struct node *next;
}*start = NULL, *tmp;

void display() {
	tmp = start;
	printf("\n");
	if (tmp != NULL) {
		do {
			printf("%d-->", tmp->val);
			tmp = tmp->next;
		} while (tmp != NULL);
		printf("END");
	} else
		printf("NULL");

	return;
}

void insert(){
	int val;
	char ch='Y';
	while(ch=='Y'||ch=='y'){
		printf("\nNode value:");
		scanf("%d",&val);
		tmp=(struct node *)malloc(sizeof(struct node));
		tmp->val=val;
		tmp->next=(start==NULL?NULL:start);
		start=tmp;
		display();
		printf("\nMore(Y/N) : ");
		scanf("%s",&ch);
	}
return;
}
void exchange(){
	node *p,*move=start;
	while(move->next!=NULL){
			p=move;
			move=move->next;
	}
	p->next=start;
	move->next=start->next;
	start->next=NULL;
	start=move;
}

int main(){
	int ch=1;

	while(TRUE){
		printf("\n0.Insert\n1.Exchange\n2.Display\n3.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 0:insert();
					break;
			case 1:exchange();
					break;
			case 2:display();
					break;
			case 3:exit(0);
					break;
			default:printf("Wrong choice retry....");
					break;
		}
	}
return 0;
}
