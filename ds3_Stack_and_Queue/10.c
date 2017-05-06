/*Program 10:implement a queue using stack(as much as required).*/
#include<stdio.h>
#include<malloc.h>
#include<stddef.h>
#include<stdlib.h>
#define TRUE 1

typedef struct node node;
typedef struct stack stack;
struct node {
	int val;
	node *next;
}*tmp;
struct stack {
	node *top;
	int size;
} s, s2;
//Stack ADT Operations<--------------
void init_stack(stack *);
void push(stack *, int);
int pop(stack *);
//----------------------------------->
//Queue ADT Operations<---------------
void init_queue();
void enqueue(int);
int deque();
void display_queue();
//------------------------------------>

void init_stack(stack *s) {
	s->top = NULL;
	s->size = 0;
}
void push(stack *s, int val) {
	tmp = (node *) malloc(sizeof(node));
	tmp->val = val;
	tmp->next = (s->top == NULL ? NULL : s->top);
	s->top = tmp;
	++(s->size);
	return;
}

int pop(stack *s) {
	int r;
	if (s->top == NULL) {
		return -1;
	}
	tmp = s->top;
	r = s->top->val;
	s->top = s->top->next;
	--(s->size);
	free(tmp);
	return r;
}
void disp_all(node *move) {
	if (move->next == NULL) {
		printf("%d ", move->val);
		return;
	}
	disp_all(move->next);
	printf("%d ", move->val);
}

void display_queue() {
	stack q = s;
	if (q.top == NULL) {
		printf("\nEmpty");
		return;
	}
	disp_all(q.top);
	return;
}
void init_queue() {
	init_stack(&s);
	init_stack(&s2);
}

void enqueue(int val) {
	push(&s, val);
}

int deque() {
	int r;
	if (!s.top) {
		printf("\nEmpty");
		return -1;
	}
	while (s.size != 1) {
		push(&s2, pop(&s));
	}
	r = pop(&s);
	while (s2.size)
		push(&s, pop(&s2));
	return r;
}

int main() {
	int ch, t, c;
	init_queue();
	while (TRUE) {
		c = 1;
		printf("\n0.Enqueue\n1.Dequeue\n2.Display\n3.Exit\nEnter your choice");
		scanf("%d", &ch);
		switch (ch) {
		case 0:
			while (c) {
				printf("\nValue : ");
				scanf("%d", &t);
				enqueue(t);
				printf("\nMore(1/0)..");
				scanf("%d", &c);
			}
			display_queue();
			break;
		case 1:
			deque();
			display_queue();
			break;
		case 2:
			display_queue();
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("\nWrong Choice. Retry...");
			break;
		}
	}
	return 0;
}

