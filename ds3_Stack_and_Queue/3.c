/*Program 3: Sort the element of a given stack by only using another stack and push, pop operation.*/
#include<stdio.h>
#include<malloc.h>
#include<stddef.h>
#include<stdlib.h>
#define TRUE 1
typedef struct stack node;
struct stack {
	int val;
	node *next;
}*top = NULL, *tmp, *top2 = NULL;

void push(node **, int);
int pop(node **);
void display(node **);
void sort();

void push(node** head, int val) {
	tmp = (node *) malloc(sizeof(node));
	tmp->val = val;
	tmp->next = (*head == NULL ? NULL : *head);
	*head = tmp;
	return;
}

void display(node** head) {
	node *top = *head;
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

int pop(node **head) {
	int r;
	if (*head == NULL) {
		return -1; //if empty
	}
	tmp = *head;
	r = (*head)->val;
	*head = (*head)->next;
	free(tmp);
	return r;
}

void sort() {
	int t;
	while (top) {
		while (top && (!top2 || (top2->val <= top->val))) {
			push(&top2, pop(&top));
		}
		t = pop(&top);
		if (t < 0) //if top is empty
			break;
		else {
			while (top2)
				push(&top, pop(&top2));
			push(&top, t);
		}
	}
	while (top2)
		push(&top, pop(&top2));
}

int main() {
	int ch, tmp;
	while (TRUE) {
		printf("\n0.Push\n1.Pop\n2.Display\n4.Sort\n5.Exit\nEnter your choice");
		scanf("%d", &ch);
		switch (ch) {
		case 0:
			do {
				printf("\nvalue to be pushed: ");
				scanf("%d", &tmp);
				push(&top, tmp);
				printf("\nmore(1/0)");
				scanf("%d", &ch);
			} while (ch);
			break;
		case 1:
			pop(&top);
			break;
		case 2:
			display(&top);
			break;
		case 4:
			sort(&top, &top2);
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("\nWrong Choice. Retry...");
			break;
		}
	}
	return 0;
}

