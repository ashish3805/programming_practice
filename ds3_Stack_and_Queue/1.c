/* Program 1: write a program to show stack operation using array.*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define TRUE 1
int stack[MAX];
int top = -1;
void push();
int pop();
void display();
void empty();
int peek();
int search(const int);
void push() {
	printf("\nEnter val: ");
	if (top == MAX - 1) {
		printf("\nStack Full, Cant push!");
		return;
	}
	++top;
	scanf("%d", &stack[top]);
	display();
	return;
}
void display() {
	int i = 0;
	if (top == -1) {
		printf("\nEmpty, nothing to display");
		return;
	}
	printf("\n| ");
	for (i = top; i >= 0; --i)
		printf("%d ", stack[i]);
	printf("|");
	return;
}
int pop() {
	int r;
	if (top == -1) {
		printf("\nStack empty");
		return -1;
	}
	r = stack[top];
	--top;
	display();
	return r;
}
void empty() {
	int i = 0;
	while (top != -1) {
		printf("%d ", stack[top]);
		--top;
	}
	printf("\nStack empty now!");
	return;
}
int peek() {
//return -1 if empty
	if (top == -1) {
		printf("\nEmpty");
		return -1;
	} else
		printf("\nTop most : %d", stack[top]);
	return stack[top];
}
int search(const int n) {
	int i;
	for (i = top; i >= 0; --i) {
		if (stack[i] == n) {
			printf("\nfound at %d index from bottom: ", i);
			return MAX - (i + 1);
		}
	}
	printf("\nNot found");
	return -1;
}
int main() {
	int ch, tmp;
	while (TRUE) {
		printf(
				"\n0.Push\n1.Pop\n2.Display\n3.Peek\n4.Empty\n5.Search\n6.Exit\nEnter your choice");
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
			peek();
			break;
		case 4:
			empty();
			break;
		case 5:
			printf("\nEnter no to be searched");
			scanf("%d", &tmp);
			search(tmp);
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("\nWrong Choice. Retry...");
			break;
		}
	}
	return 0;
}

