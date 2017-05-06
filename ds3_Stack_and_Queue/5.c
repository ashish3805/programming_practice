/*Program 5:Design a stack using queue*/
#include<stdio.h>
#include<malloc.h>
#include<stddef.h>
#include<stdlib.h>
#define TRUE 1
typedef struct node node;
typedef struct queue queue;
struct node {
	int val;
	node *next;
}*top = NULL, *tmp;

struct queue {
	node* front, *rear;
	int size;
} q1, q2, t;

void push();
int pop();
void display();
void init(queue *q) {
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}
void enqueue(queue *q, int val) {
	tmp = malloc(sizeof(node));
	tmp->val = val;
	tmp->next = NULL;
	if (q->front && q->rear)
		q->rear->next = tmp;
	else {
		q->front = tmp;
	}
	q->rear = tmp;
	++(q->size);
}
int deque(queue *q) {
	int r;
	if (!(q->front)) {
		printf("\nEmpty");
		return -1;
	}
	tmp = q->front;
	r = tmp->val;
	q->front = q->front->next;
	if (!(q->front))
		q->rear = NULL;
	free(tmp);
	--(q->size);
	return r;
}

void push() {
	int val;
	printf("\nNode value:");
	scanf("%d", &val);
	enqueue(&q1, val);
	display(q1);
	return;
}
void disp_all(node *move) {
	if (move->next == NULL) {
		printf("%d ", move->val);
		return;
	}
	disp_all(move->next);
	printf("%d ", move->val);
}

void display(queue q) {

	if (q.front == NULL) {
		printf("\nEmpty");
		return;
	}
	disp_all(q.front);
	return;
}

int pop() {
	int r;
	if ((q1.size) <= 0) {
		printf("\nEmpty");
		return -1;
	}
	while (q1.size != 1) {
		enqueue(&q2, deque(&q1));
	}
	r = deque(&q1);
	t = q1;
	q1 = q2;
	q2 = t;
	display(q1);
	return r;
}

int main() {
	int ch, tmp;
	while (TRUE) {
		printf("\n0.Push\n1.Pop\n2.Display\n3.Exit\nEnter your choice");
		scanf("%d", &ch);
		switch (ch) {
		case 0:
			push();
			break;
		case 1:
			pop();
			break;
		case 2:
			display(q1);
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

