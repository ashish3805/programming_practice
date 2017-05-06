/*Q.7 write a program that will delete any duplicates node from the linked list.*/
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

void remove_dup(){
	node* move,*chk,*p;
	chk=start;
	while(chk!=NULL){
		p=chk;
		move=chk->next;
		while(move!=NULL){
			if(chk->val==move->val){
					tmp=move;
					p->next=move->next;
					move=move->next;
					free(tmp);
					continue;
			}
			p=move;
			move=move->next;
		}
		chk=chk->next;
	}
	display();
}

int main() {
	int ch = 1;
	while (TRUE) {
		printf("\n0.Insert\n1.Remove duplicates\n2.Display\n3.Exit\nEnter your choice: ");
		scanf("%d", &ch);
		switch (ch){
		case 0:
			insert();
			break;
		case 1:
			remove_dup();
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

