/*Q.8 given a linked list and a number k. Reverse every k nodes in the list.*/
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
	printf("\nNode value:");
	scanf("%d",&val);
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->val=val;
	tmp->next=(start==NULL?NULL:start);
	start=tmp;
	display();
return;
}

node *reverse(node *head,int k){
	int i;
	node *p,*q;
	if(head==NULL||head->next==NULL)
		return head;
	p=NULL;
	q=head;
	tmp=start;
	for(i=0;i<k&&tmp;i++){
		tmp=q->next;
		q->next=p;
		p=q;
		q=tmp;
	}
	head->next=reverse(tmp,k);
	return p;
}

int main() {
	int ch = 1,k;
	while (TRUE) {
		printf("\n0.Insert\n1.Reverse\n2.Display\n3.Exit\nEnter your choice: ");
		scanf("%d", &ch);
		switch (ch){
		case 0:
			insert();
			break;
		case 1:
			printf("\nEnter k: ");
			scanf("%d",&k);
			start=reverse(start,k);
			break;
		case 2:
			display();
			break;
		case 3:
			exit(0);
		default:
			printf("Wrong choice retry....");
			break;
		}
	}
	return 0;
}

