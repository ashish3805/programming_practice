/*Q.9 Given two linked lists, insert nodes of second list into first list at alternate positions of first list.*/
#include<stdio.h>
#include<malloc.h>
#include<stddef.h>
#include<stdlib.h>
#define TRUE 1
typedef struct node node;
struct node{
	int val;
	struct node *next;
}*start1=NULL,*start2=NULL,*tmp1=NULL,*tmp2=NULL;

void display(node **source){
	tmp1=*source;
	printf("\n");
	if(tmp1!=NULL)
	{
		do
		{
			printf("%d-->",tmp1->val);
			tmp1=tmp1->next;
		}while(tmp1!=NULL);
	printf("END");
	}
	else
	printf("NULL");

return ;
}



void insert(node **source){
	char ch='Y';
	node *tmp;
	while(ch=='Y'||ch=='y'){
		int val;
		printf("\nNode value:");
		scanf("%d",&val);
		tmp=(node *)malloc(sizeof(node));
		tmp->val=val;
		tmp->next=(*source==NULL?NULL:*source);
		*source=tmp;
		display(source);
		printf("\nMore(Y/N) :");
		scanf("%s",&ch);
	}
return;
}
void merge_list(node **s1,node **s2){
	node *m1,*m2;
	m1=tmp1=*s1;
	m2=tmp2=*s2;
	while(tmp1&&tmp2){
		tmp1=m1->next;
		tmp2=m2->next;
		m1->next=m2;
		m2->next=tmp1;
		m1=tmp1;
		m2=tmp2;
	}
}

int main(){
	int ch=1;

	while(TRUE){
		printf("\n0.Insert\n1.Merge lists\n2.Display\n3.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 0:printf("\nlist 1:");
					insert(&start1);
					printf("\nlist 2:");
					insert(&start2);
					break;
			case 1:merge_list(&start1,&start2);
					break;
			case 2:display(&start1);
					break;
			case 3:exit(0);
					break;
			default:printf("Wrong choice retry....");
					break;
		}
	}
return 0;
}
