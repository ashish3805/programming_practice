/*Program 8: implement Queue using linked list.*/
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
} q1;

void init(queue *);
void enqueue(queue *, int);
int deque(queue *);
void display(queue);

void init(queue *q) {
	q->front = NULL;
	q->rear = NULL;
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
	return r;
}

void display(queue q) {
	tmp = q.front;
	printf("\nFront ");
	if (tmp != NULL) {
		do {
			printf("%d ", tmp->val);
			tmp = tmp->next;
		} while (tmp != NULL);
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

