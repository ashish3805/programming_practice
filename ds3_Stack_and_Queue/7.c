/*Program 7:implement Queue using array.*/
#include<stdio.h>
#include<malloc.h>
#include<stddef.h>
#include<stdlib.h>
#define TRUE 1
#define MAX 10
typedef struct queue queue;
struct queue {
	int ar[MAX];
	int front, rear;
} q1;
int tmp;

void init(queue *);
void enqueue(queue *, int);
int deque(queue *);
void display(queue);

void init(queue *q) {
	q->front = -1;
	q->rear = -1;
}

void enqueue(queue *q, int val) {
	if (q->rear == MAX - 1) {
		printf("\nFULL");
		return;
	}
	if ((q->front < 0) || (q->rear < 0))
		q->front = 0;
	q->ar[++(q->rear)] = val;
}

int deque(queue *q) {
	int r;
	if ((q->front < 0) || (q->front > q->rear)) {
		printf("\nEmpty");
		return -1;
	}
	tmp = q->front;
	r = q->ar[(q->front)];
	++(q->front);
	if ((q->front) >= MAX || q->front > q->rear) {
		q->rear = -1;
		q->front = -1;
	}
	return r;
}

void display(queue q) {
	tmp = q.front;
	printf("\nFront ");
	if (tmp >= 0) {
		do {
			printf("%d ", q.ar[tmp]);
			++tmp;
		} while (tmp <= q.rear);
		printf("Rear");
	} else
		printf("NULL");
	return;
}
int main() {
	int ch, t, c;
	init(&q1);
	while (TRUE) {
		c = 1;
		printf("\n0.Enqueue\n1.Dequeue\n2.Display\n3.Exit\nEnter your choice");
		scanf("%d", &ch);
		switch (ch) {
		case 0:
			while (c) {
				printf("\nValue : ");
				scanf("%d", &t);
				enqueue(&q1, t);
				printf("\nMore(1/0)..");
				scanf("%d", &c);
			}
			display(q1);
			break;
		case 1:
			deque(&q1);
			display(q1);
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

