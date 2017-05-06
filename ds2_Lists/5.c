/*Q.5 given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes, continue the same until end of the linked list.*/
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
void del(int m, int n) {
	int l, c;
	node *move = start, *p, *q;
	while (move != NULL) {
		for (l = m; l > 0 && move != NULL; --l) {
			p = move;
			move = move->next;
		}
		for (c = n; c > 0 && move != NULL; --c) {
			q = move->next;
			if (move == start) {
				tmp = start;
				start = q;
				free(tmp);
				move = q;
			} else {
				tmp = move;
				p->next = q;
				free(tmp);
				move = q;
			}
		}
	}
}
int main() {
	int ch = 1,m,n;
	while (TRUE) {
		printf("\n0.Insert\n1.Del\n2.Dispaly\n3.Exit\nEnter your choice: ");
		scanf("%d", &ch);
		switch (ch){
		case 0:
			insert();
			break;
		case 1:
		    printf("\nEnter M(nodes to leave) : ");
		    scanf("%d",&m);
		    printf("\nEnter N(nodes to delete) : ");
		    scanf("%d",&n);
			del(m,n);
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

