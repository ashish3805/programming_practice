/*
 * 1.c
 *
 *  Created on: 30-Sep-2015
 *      Author: ashish
 */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define M 10
#define TRUE 1
struct node{
	int s;
} graph[M][M];
int ar[M];
int min=M;

void init_graph(){
    int i,j;
    for(i=0;i<M;i++){
        for(j=0;j<M;j++)
            graph[i][j].s=0;
    }
    printf("Done: initialised.");
}

void create_graph(){
    FILE *fp;
    int i,j;
    fp=fopen("data.txt","r");
    printf("Opened File.");
    while(!feof(fp)){
        fscanf(fp,"%d%d",&i,&j);
        graph[i-1][j-1].s=1;
    }
    printf("Read File.");
}

void display_graph(){
    int i,j;
    for(i=0;i<M;i++){
            printf("\n");
        for(j=0;j<M;j++)
            printf("%d\t",graph[i][j].s);
    }
}

void find_path(int s,int d,int ar[],int l){
	int i,j,fl=0;
	ar[++l]=s;
	if(s==d)
	{
		printf("\n");
		if(min>=l)
			min=l;
		for(j=0;j<=l;j++)
			printf("%d ",ar[j]+1);
		return;
	}
	for(i=0;i<M;i++){
		if(graph[s][i].s){
			for(j=0;j<=l;j++){
				if(i==ar[j]){
					fl=1;
					break;
				}
			}
			if(!fl)
			find_path(i,d,ar,l);
		}
	}
	return;
}
void shortest_path(){
	printf("\nmin junctions : %d",min);
}
void max_con(){
	int i,j,max=0,count,r=0;
	for(i=0;i<M;i++){
		count=0;
		for(j=0;j<M;j++){
			if(graph[i][j].s)
				count++;
		}
		if(max<=count){
			r=i+1;
			max=count;
		}
	}
	printf("\nmax connections is for city %d having %d connections",r,max);
}

void only_two(){
	int i,j,count;
	printf("\ncities having only two connections: ");
	for(i=0;i<M;i++){
		count=0;
		for(j=0;j<M;j++){
			if(graph[i][j].s)
				count++;
		}
			if(count==2)
				printf("%d ",i+1);
	}
}

int main(){
	int ch,s,d;
	init_graph();
	create_graph();
	while(TRUE){
		printf("\nEnter choice: \n1:Find paths between cities\n2:cities with only 2 "
				"connections\n3:city with max connection\n4:Exit");
		scanf("%d",&ch);
		switch(ch){
		case 1:
			printf("\nenter source then destination :");
			scanf("%d%d",&s,&d);
			find_path(--s,--d,ar,-1);
			shortest_path();
			break;
		case 2:
			only_two();
			break;
		case 3:
			max_con();
			break;
		case 4:
			exit(0);
			break;
		default: printf("\nWrong choice .. Retry..");
			break;
		}
	}
    return 0;
}

