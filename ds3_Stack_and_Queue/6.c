/*Program 6:implement a Doubly linked list using Stack(As much you required)*/
#include<stdio.h>
#include<malloc.h>
#include<stddef.h>
#include<stdlib.h>
#define TRUE 1
typedef struct node node;
typedef struct stack stack;
struct node{
	int val;
	node *next;
}*tmp;
struct stack{
    node *top;
}s,s2;
//Stack ADT Operations<--------------
void init_stack(stack *);
void push(stack *,int);
int pop(stack *);
void disp_stack(stack *);
//----------------------------------->
//Doubly Linked List ADT Operations<--
void init_dll();
void ins_first();
void ins_mid();
void ins_last();
void display();
void del_first();
void del_mid();
void del_last();
//----------------------------------->
void init_dll(){
    init_stack(&s);
    init_stack(&s2);
}
void ins_first(){
	int val;
	printf("\nNode value:");
	scanf("%d",&val);
	push(&s,val);
	display();
return;
}
void ins_mid(){
	int after,val,tmp;
	printf("\nAfter : ");
	scanf("%d",&after);
	printf("\nValue : ");
	scanf("%d",&val);
	while(s.top){
        tmp=pop(&s);
        push(&s2,tmp);
        if(tmp==after){
            push(&s,val);
        break;
       }
	}
	while(s2.top){
        push(&s,pop(&s2));
    }
	display();
}
void ins_last(){
	int val;
	printf("\nValue : ");
	scanf("%d",&val);
	while(s.top)
        push(&s2,pop(&s));
    push(&s,val);
	while(s2.top)
        push(&s,pop(&s2));
	display();
return ;
}
void display(){
    disp_stack(&s);
}
void del_first(){
    pop(&s);
	display();
return ;
}
void del_mid(){
	int val;
	printf("\nNode value : ");
	scanf("%d",&val);
    while(s.top){
        tmp=pop(&s);
        if(tmp==val)
            break;
       push(&s2,tmp);
	}
	while(s2.top){
        push(&s,pop(&s2));
    }
	display();
return;
}
void del_last(){
    while(s.top)
        push(&s2,pop(&s));
    pop(&s2);
	while(s2.top)
        push(&s,pop(&s2));
	display();
return;
}
void init_stack(stack *s){
    s->top=NULL;
}
void push(stack *s,int val){
	tmp=(node *)malloc(sizeof(node));
	tmp->val=val;
	tmp->next=(s->top==NULL?NULL:s->top);
	s->top=tmp;
return;
}

int pop(stack *s){
	int r;
	if(s->top==NULL){
		return -1;
	}
	tmp=s->top;
	r=s->top->val;
	s->top=s->top->next;
	free(tmp);
return r;
}
void disp_stack(stack *s){
	tmp=s->top;
	printf("\n");
	if(tmp!=NULL)
	{
		do
		{
			printf("%d ",tmp->val);
			tmp=tmp->next;
		}while(tmp!=NULL);
	printf("END");
	}
	else
	printf("NULL");
return ;
}
int main(){
	int ch=1;
	init_dll();
	while(TRUE){
		printf("\n0.Insert at First\n1.Insert at middle\n2.Insert at last\n3.Delete first node\n4.Delete middle node\n5.Delete last node\n6.Diplay\n7.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 0:ins_first();
					break;
			case 1:ins_mid();
					break;
			case 2:ins_last();
					break;
			case 3:del_first();
					break;
			case 4:del_mid();
					break;
			case 5:del_last();
					break;
			case 6:display();
					break;
			case 7:exit(0);
					break;
			default:printf("Wrong choice retry....");
					break;
		}
	}
return 0;
}

