#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#define Max_Seat 50
#define Max_Index 19
#define SIZE 20
#define TRUE 1
void pop();
void init_queue();
void push();
void reserv(int *,int);
int top = -1, front = -1, lseat = 0;

FILE *fp, *nf, *ap;

struct time {
	int h, m, s;
	char ap[3];
};

struct user {
	int id, sn;
	struct time login;
	char sa[10], da[10];
};

struct user ar[20];

void init_queue() {
	fp = fopen("data.txt", "r");
	ap = fopen("data.txt", "a");
	++front;
	while (top < Max_Index) {
		++top;
		fscanf(fp, "%d%s%s%d:%d:%d%s %d", &ar[top].id, ar[top].sa, ar[top].da,
				&ar[top].login.h, &ar[top].login.m, &ar[top].login.s,
				ar[top].login.ap, &ar[top].sn);
	}
}

void push() {
	int i;
	if (front == -1) {
		return;
	}
	if (feof(fp)) {
		return;
	}
	if ((top + 1) % SIZE == (front % SIZE)) {
		printf("top==size");
		return;
	}
	++top;
	i = top % SIZE;
	fscanf(fp, "%d%s%s%d:%d:%d%s%d", &ar[i].id, ar[i].sa, ar[i].da,
			&ar[i].login.h, &ar[i].login.m, &ar[i].login.s, ar[i].login.ap,
			&ar[top].sn);
	return;
}

void reserv(int *c,int ch){
	int i = front % SIZE;
	if (ar[i].login.h == 8 && ar[i].login.ap[0] == 'A'
			&& (!strcmp(ar[i].sa, "Indore")) && (!strcmp(ar[i].da, "Bhopal")))
	{
		switch(ch){
		case 1:
		if (lseat == Max_Seat) {
			nf = fopen("next.txt", "a");
			fprintf(nf, "%d %s %s %d:%d:%d%s %d\n", ar[i].id, ar[i].sa, ar[i].da,
					ar[i].login.h, ar[i].login.m, ar[i].login.s,
					ar[i].login.ap,0);
			pop();
			return;
		}
		++c;
		++lseat;
		fprintf(ap, "\n%d %s %s %d:%d:%d%s %d", ar[i].id, ar[i].sa, ar[i].da,
				ar[i].login.h, ar[i].login.m, ar[i].login.s, ar[i].login.ap,
				lseat);
		printf("\nSeat reserved, SN : %d", lseat);
		pop();
		break;
		case 2:
			if(ar[i].sn){
				fprintf(ap, "\n%d %s %s %d:%d:%d%s %d", ar[i].id, ar[i].sa, ar[i].da,
								ar[i].login.h, ar[i].login.m, ar[i].login.s, ar[i].login.ap,
								0);
				printf("\nSeat Cancelled");
			}else
				printf("\nCant cancell. No seat reserved by you!");
			pop();
			break;
		}
	} else
		pop();
}

void pop() {
	if (front % SIZE == top % SIZE)
		top = front = -1;
	else
		front++;
}

int main() {
	int c1 = 0, ch;
	init_queue();
	while (TRUE) {
		printf("\nwhat do u want:\n1.reservation\n2.cancellation\n3.exit\nYour choice");
		scanf("%d", &ch);
		switch (ch) {
		case 1:
			reserv(&c1,1);
			push();
			break;
		case 2:
			reserv(&c1,2);
			push();
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("\nWrong choice. Retry..");
			break;
		}
	}
	return 0;
}
