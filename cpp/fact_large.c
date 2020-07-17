#include<stdio.h>
#include<string.h>

char s[200];
int top=1;

void fact(int n)
{
    int i=0,c=0,m,x,j,z;
    s[0]='1';
    for(j=n; j>1; j--)
    {
        // printf("\nj is %d",j);
        i=0;
        while(i!=top)
        {
           // printf("\ntop is %d, i is %d",top,i);
            x=s[i]-48;
            //printf("\nx : %d",x);
            m=x*j+c; //printf("\nm : %d ",m);
            c=m/10;//printf("\nc : %d",c);
            m=m%10;//printf("\nm : %d",m);
            s[i]=m+48;//printf("\ns[%d] :%c",i,s[i]);
            i++;
        }
        if(c){
            z=c;
            while(z){
            s[i]=z%10+48;
            z/=10;
            top++;
            i++;
        }
        c=0;
    }
}}

void print_fact(){
    int i=0;
    printf("\nFact is : ");
    for(i=top;i>=0;i--){
        printf("%c",s[i]);
    }
}
int main()
{
    int n;
    printf("\nenter n: ");
    scanf("%d",&n);
    fact(n);
    print_fact();
    return 0;
}
