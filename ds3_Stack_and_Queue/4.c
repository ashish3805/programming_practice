/*Program 4: How can you implement two stacks in a single array, where no stack overflows until no space left in the entire array space?*/
#include<stdio.h>
#include<malloc.h>
#include<stddef.h>
#include<stdlib.h>
#define TRUE 1
#define MAX 5
int stack[MAX];

int top1, top2;
top1 = -1;
top2 = MAX;
void push(int *top, int val) {
	if (top1 > top2 - 2) {
		printf("\nNo space can't push the last given value!");
		return;
	}
	if ((top == &top1) && (top1 < MAX - 1))
		++(*top);
	else if ((top == &top2) && (top2 > 0))
		--(*top);
	else {
		printf("\nNo space can't push the last given value!");
		return;
	}
	stack[*top] = val;
	return;
}
int pop(int *top) {
	int r;
	if (top == &top1) {
		if (top1 < 0)
			return -1;
		r = stack[*top];
		--top1;
	} else if (top == &top2) {
		if (top2 > MAX - 1)
			return -1;
		r = stack[*top];
		++top2;
	} else
		return -1;
	return r;
}
void display() {
	int i;
	printf("\nStack1 :");
	for (i = 0; i <= top1; i++)
		printf("%d ", stack[i]);
	printf("\nStack2: ");
	for (i = MAX - 1; i >= top2; --i)
		printf("%d ", stack[i]);
}
int main() {
	int ch, n, c;
	while (TRUE) {
		printf(
				"\nEnter your choice: \n1.Push in stack1\n2.Push in stack 2\n3.Pop from stack1\n4.Pop from stack 2\n5.Display\n6.Exit\n...:");
		scanf("%d", &ch);
		c = 1;
		switch (ch) {
		case 1:
			while (c) {
				printf("\nenter val:");
				scanf("%d", &n);
				push(&top1, n);
				printf("\nmore(1/0)..:");
				scanf("%d", &c);
			}
			break;
		case 2:
			while (c) {
				printf("\nenter val:");
				scanf("%d", &n);
				push(&top2, n);
				printf("\nmore(1/0)..:");
				scanf("%d", &c);
			}
			break;
		case 3:
			n = pop(&top1);
			if (!(n + 1)) {
				printf("\nAlready empty!");
			} else
				printf("\nPopped val: %d", n);
			break;
		case 4:
			n = pop(&top2);
			if (!(n + 1)) {
				printf("\nAlready empty!");
			} else
				printf("\nPopped val: %d", n);
			break;
		case 5:
			display();
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("\nWrong choice ! Retry...");
			break;
		}
	}
}


