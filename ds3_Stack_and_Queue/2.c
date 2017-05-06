/*Program 2: implement stack using linked list*/
#include<stdio.h>
#include<malloc.h>
#include<stddef.h>
#include<stdlib.h>
#define TRUE 1
typedef struct stack node;
struct stack {
	int val;
	node *next;
}*top = NULL, *tmp;

void push();
int pop();
void display();
void empty();

void push() {
	int val;
	printf("\nNode value:");
	scanf("%d", &val);
	tmp = (node *) malloc(sizeof(node));
	tmp->val = val;
	tmp->next = (top == NULL ? NULL : top);
	top = tmp;
	display();
	return;
}

void display() {
	tmp = top;
	printf("\n");
	if (tmp != NULL) {
		do {
			printf("%d ", tmp->val);
			tmp = tmp->next;
		} while (tmp != NULL);
		printf("END");
	} else
		printf("NULL");
	return;
}

int pop() {
	int r;
	if (top == NULL) {
		printf("\nStack empty!");
		return -1;
	}
	tmp = top;
	r = top->val;
	top = top->next;
	free(tmp);
	display();
	return r;
}

void empty() {
	display();
	while (top != NULL) {
		tmp = top;
		top = top->next;
		free(tmp);
	}
	printf("\nStack empty now");
}

int main() {
	int ch;
	while (TRUE) {
		printf(
				"\n0.Push\n1.Pop\n2.Display\n3.Empty\n4.Exit\nEnter your choice");
		scanf("%d", &ch);
		switch (ch) {
		case 0:
			push();
			break;
		case 1:
			pop();
			break;
		case 2:
			display();
			break;
		case 3:
			empty();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("\nWrong Choice. Retry...");
			break;
		}
	}
	return 0;
}

