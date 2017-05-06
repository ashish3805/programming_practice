/*Program 9:Given two integer sequences, one of which is the push sequence of a stack,
 please check whether the other sequence is a corresponding pop sequence or not. */
#include<stdio.h>
#include<malloc.h>
#include<stddef.h>
#include<stdlib.h>
#define TRUE 1
#define MAX 10
typedef struct node node;
typedef struct stack stack;
struct node {
	int val;
	node *next;
}*tmp;
struct stack {
	node *top;
} s;
//Stack ADT Operations<--------------
void init_stack(stack *);
void push(stack *, int);
int pop(stack *);
void disp_stack(stack *);
int find(stack*, int);
//----------------------------------->
void init_stack(stack *s) {
	s->top = NULL;
}
void push(stack *s, int val) {
	tmp = (node *) malloc(sizeof(node));
	tmp->val = val;
	tmp->next = (s->top == NULL ? NULL : s->top);
	s->top = tmp;
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
	free(tmp);
	return r;
}
void disp_stack(stack *s) {
	tmp = s->top;
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

int get_s(int ar[MAX]) {
	int i = 0, n;
	char buf[100], *p = buf;
	if (fgets(buf, sizeof buf, stdin) == NULL) {
		printf("problem getting numbers.. terminating!!");
		exit(0);
	}
	while ((i < MAX) && (sscanf(p, "%d%n", &ar[i], &n) == 1)) {
		i++;
		p += n;
	}
	return i;
}
int find(stack *s, int val) {
	node *move = s->top;
	while (move) {
		if (move->val == val)
			return 1;
		move = move->next;
	}
	return 0;
}
int chk_pop(int* ppush, int* ppop, int spush_length, int spop_length) {
	int npop;
	int i, j, l = 0;
	if (spush_length && spop_length) {
		i = 0;
		j = 0;
		for (i = 0; i < spop_length; i++) {
			npop = ppop[i];
			if (!find(&s, npop)) {
				for (j = l; j < spush_length; j++) {
					push(&s, ppush[j]);
					if (ppush[j] == npop) {
						break;
					}
				}
				l = j + 1;
			}
			if (s.top->val != npop) {
				return 0;
			}
			pop(&s);
		}
	}
	return 1;
}

int main() {
	int spush[MAX], spop[MAX], spush_size, spop_size;
	init_stack(&s);
	printf("\nEnter Push seq(space separated): ");
	spush_size = get_s(spush);
	printf("\nEnter Pop seq(space separated): ");
	spop_size = get_s(spop);
	if (chk_pop(spush, spop, spush_size, spop_size)) {
		printf("\nPossible");
		return 0;
	}
	printf("\nNot Possible");
	return 0;
}

