#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10
#define TRUE 1
void bubble_sort(int *ar){
    int i,j;
    for(i=0;i<MAX;i++){
        for(j=1;j<MAX-i;j++){
            if(ar[j-1]>ar[j]){
                ar[j-1]^=ar[j];
                ar[j]^=ar[j-1];
                ar[j-1]^=ar[j];
            }
        }
    }
}
void insertion_sort(int* ar){
    int i,j;
    for(i=1;i<MAX;i++){
        for(j=i;j>=0;--j){
            if(ar[j]<ar[j-1]){
                ar[j-1]^=ar[j];
                ar[j]^=ar[j-1];
                ar[j-1]^=ar[j];
            }
        }
    }
}
void merge_sort(int *ar,int p,int r){//call with p=0,r=MAX-1
    int q;
    if(p<r){
        q=(p+r)/2;
        merge_sort(ar,p,q);
        merge_sort(ar,q+1,r);
        merge(ar,p,q,r);
    }
}
void merge(int *ar,int p,int q,int r){
    int i,j,k,n1=q-p+1,n2=r-q;
    int b[n1],c[n2];
    for(i=0;i<n1;i++)
        b[i]=ar[i+p];
    for(i=0;i<n2;i++)
        c[i]=ar[q+1+i];
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2)
    {
        if (b[i] <= c[j])
        {
            ar[k] = b[i];
            i++;
        }
        else
        {
            ar[k] = c[j];
            j++;
        }
        k++;
    }
     while (i < n1)
        ar[k++] = b[i++];
    while (j < n2)
        ar[k++] = c[j++];
}

 void generate_array(int *ar){
    int c,n;
    printf("\nGenerated Seq:");
    for (c = 0; c < MAX; c++) {
    n = rand() % 100 + 1;
    ar[c]=n;
    printf("%d ", n);
  }
 }
 //radix
 int find_max(int *ar){
 int i,max=ar[0];
 for(i=0;i<MAX;i++){
    if(ar[i]>max)
        max=ar[i];
 }
 return max;
 }
 int maxdigit(int *ar){
    int i=0,max=find_max(ar);
    while(max){
        i++;
        max/=10;
    }
    return i;
 }
 void radix_digit_sort(int *ar,int d){
    int i,b[MAX],j,t;
    for(i=0;i<MAX;i++)
        b[i]=ar[i]/pow(10,d);
    for(i=0;i<MAX;i++)
        b[i]=b[i]%10;
    for(i=0;i<MAX;i++){
        for(j=1;j<MAX-i;j++){
            if(b[j-1]>b[j]){
                ar[j-1]^=ar[j];
                ar[j]^=ar[j-1];
                ar[j-1]^=ar[j];

                b[j-1]^=b[j];
                b[j]^=b[j-1];
                b[j-1]^=b[j];
            }
        }
    }

 }

 void radix_sort(int *ar){
     int i,d=maxdigit(ar);
     for(i=0;i<d;i++){
        radix_digit_sort(ar,i);
     }
 }
void display(int *ar){
    int i;
    printf("\n");
    for(i=0;i<MAX;i++)
        printf("%d ",ar[i]);
}
void sort(int *ar){
    int ch;
            printf("\nselect: \n1.radix\n2.bubble\n3.insertion\n4.merge\n5.exit\n:");
            scanf("%d",&ch);
            switch(ch){
                case 1:
                    radix_sort(ar);
                    break;
                case 2:
                    bubble_sort(ar);
                    break;
                case 3:
                    insertion_sort(ar);
                    break;
                case 4:
                    merge_sort(ar,0,MAX-1);
                    break;
                case 5:
                    exit(0);
                    break;
                default:
                    printf("\n wrong choice.. retry ");
                    break;
            }
}
 int main(){
    int ar[MAX];
    generate_array(ar);
    sort(ar);
    display(ar);
 }
