#include<stdio.h>
#include<malloc.h>
#include<stddef.h>
#include<stdlib.h>
#define TRUE 1
typedef struct node node;

struct node {
	int rno, sub[5], avg;
	struct node *next;
}*start = NULL, *tmp;

void MergeSort(node **);
void split(node *, node **, node **);
node *merge(node *, node *);

void display() {
	node *move;
	int i;
	move = start;
	while (move != NULL) {
		printf("\n%d   ", move->rno);
		for (i = 0; i < 5; i++)
			printf("%d ", move->sub[i]);
		printf("  %d", move->avg);
		move = move->next;
	}
}
int fail_one() {
	int fl = 0, no = 0, i;
	tmp = start;
	while (tmp != NULL) {
		fl = 0;
		for (i = 0; i < 5; i++) {
			if ((tmp->sub[i]) < 35)
				fl++;
		}
		if (fl == 1)
			no++;
		tmp = tmp->next;
	}
	return no;
}

void del_failed() {
	node *p, *move, *q;
	move = start;
	while (move != NULL) {
		q = move->next;
		if ((move->sub[0]) < 35 && (move->sub[1]) < 35 && (move->sub[2]) < 35
				&& (move->sub[3]) < 35 && (move->sub[4]) < 35) {
			if (move == start) {
				tmp = start;
				start = start->next;
				free(tmp);
				move = q;
			} else {
				tmp = move;
				p->next = move->next;
				move = q;
				free(tmp);
				continue;
			}
		} else {
			p = move;
			move = q;
		}
	}
}

void import() {
	FILE *fp;
	char fname[20];
	int data, i, sum = 0;
	printf("\nFile: ");
	scanf("%s",fname);
	if(!(fp = fopen(fname, "r"))){
		printf("\nProblem accessing file!");
		return;
	}
	while (!feof(fp)) {
		sum = 0;
		fscanf(fp, "%d", &data);
		tmp = (struct node *) malloc(sizeof(struct node));
		tmp->rno = data;
		for (i = 0; i < 5; i++) {
			fscanf(fp, "%d", &data);
			tmp->sub[i] = data;
			sum += data;
		}
		tmp->avg = sum / 5;
		tmp->next = (start == NULL ? NULL : start);
		start = tmp;
	}
}

void ins_manually() {
	int data, i, sum = 0;
	char ch = 'Y';
	while (ch == 'Y' || ch == 'y') {
		tmp = (node*) malloc(sizeof(node));
		printf("\nRoll no:");
		scanf("%d", &data);
		tmp->rno = data;
		for (i = 0; i < 5; i++) {
			printf("\nSub[%d]", i + 1);
			scanf("%d", &data);
			tmp->sub[i] = data;
			sum += data;
		}
		tmp->avg = sum / 5;
		tmp->next = (start == NULL ? NULL : start);
		start = tmp;
		printf("\nmore(Y/N) : ");
		scanf("%s", &ch);
	}
}

void sort() {
	MergeSort(&start);
}

void MergeSort(node **source) {
	node *a, *b, *head;
	a = b = NULL;
	head = *source;
	if (head == NULL || head->next == NULL)
		return;
	split(head, &a, &b);
	MergeSort(&a);
	MergeSort(&b);

	*source = merge(a, b);
}

void split(node *head, node **front, node **back) {
	node *fast, *slow;
	if (head == NULL || head->next == NULL) {
		*front = head;
		*back = NULL;
	} else {
		slow = head;
		fast = head->next;
		while (fast != NULL) {
			fast = fast->next;
			if (fast != NULL) {
				fast = fast->next;
				slow = slow->next;
			}
		}
		*front = head;
		*back = slow->next;
		slow->next = NULL;
	}
}

node *merge(node *a, node *b) {
	node *mergedlist = NULL;
	if (a == NULL)
		return b;
	if (b == NULL)
		return a;
	if (a->avg < b->avg) {
		mergedlist = a;
		mergedlist->next = merge(a->next, b);
	} else {
		mergedlist = b;
		mergedlist->next = merge(a, b->next);
	}
	return mergedlist;
}

void grace() {
	node *move = start;
	int fl = 0, gr, i, index;
	while (move != NULL) {
		fl = 0;
		for (i = 0; i < 5; i++) {
			if (move->sub[i] < 35) {
				fl++;
				index = i;
			}
		}
		if (fl == 1) {
			gr = 0.05 * move->avg;
			move->sub[index] += gr;
		}
		move = move->next;
	}
}

void insert() {
	int ch;
	while (TRUE) {
		printf(
				"\n1.Add manually\n2.Import from file\n3.Return\nEnter your choice : ");
		scanf("%d", &ch);
		switch (ch) {
		case 1:
			ins_manually();
			return;
		case 2:
			import();
			return;
		case 3:
			return;
		default:
			printf("\nWrong choice, Retry: ");
			break;
		}
	}
}

int main() {
	int ch = 1;

	while (TRUE) {
		printf(
				"\n1.Insert\n2.Display\n3.Failed in one\n4.DEL failed.\n5.Sort\n6.Grace\n7.EXit\nenter your choice: ");
		scanf("%d", &ch);
		switch (ch) {
		case 1:
			insert();
			break;
		case 2:
			display();
			break;
		case 3:
			printf("\nfailed in one :%d", fail_one());
			break;
		case 4:
			del_failed();
			break;
		case 5:
			sort();
			break;
		case 6:
			grace();
			break;
		case 7:
			exit(0);
			break;
		default:
			printf("Wrong choice retry....");
			break;
		}
	}
	return 0;
}
