#include <stdio.h>
#include <stdlib.h>

void print1();
void print2();
void print3();
void print4();
void print5();
void print6();
void print7();
void print8();
int main()
{
    int n;
    printf("Enter the serial no. of the pattern you want to print\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1: print1();
                break;
        case 2: print2();
                break;
        case 3: print3();
                break;
        case 4: print4();
                break;
        case 5: print5();
                break;
        case 6: print6();
                break;
        case 7: print7();
                break;
        case 8: print8();
                break;
    }
    return 0;
}
void print1()
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<=i;j++)
            printf("*");
    printf("\n");
    }
}
void print2()
{
    int i,j, k, sp=4;
    for(i=1;i<=5;i++)
    {
        for(k=4;k>sp;k--)
            printf(" ");
        sp--;
        for(j=5;j>=i;j--)
            printf("*");
        printf("\n");
    }
}
void print3()
{
    int i,j;
    for(i=1;i<=5;i++)
    {
        for(j=5;j>=i;j--)
            printf("*");
        printf("\n");
    }
}
void print4()
{
    int i,j,k,sp=4;
    for(i=1;i<=5;i++)
    {
        for(k=1;k<=sp;k++)
        {
            printf(" ");
        }
        sp--;
        for(j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void print5()
{
    int i,j,k, sp=2;
    for(i=1;i<=5;i+=2)
    {
        for(k=2;k>sp;k--)
        {
            printf(" ");
        }
        sp--;
        for(j=1;j<=6-i;j++)
        {
            printf("*");
        }
    printf("\n");
    }
    sp=1;
    for(i=3;i<=5;i+=2)
    {
        for(k=0;k<sp;k++)
            printf(" ");
        sp--;
        for(j=1;j<=i;j++)
            printf("*");
        printf("\n");
    }
}
void print6()
{
    int i,j,k,sp=4;
    for(i=1;i<=9;i+=2)
    {
        for(k=1;k<=sp;k++)
            printf(" ");
        sp--;
        for(j=1;j<=i;j++)
            printf("*");
        printf("\n");
    }
}
void print7()
{
    int i,j,k,sp=4;
    for(i=9;i>=1;i-=2)
    {
        for(k=4;k>sp;k--)
            printf(" ");
        sp--;
        for(j=1;j<=i;j++)
            printf("*");
        printf("\n");
    }
}
void print8()
{
    int i,j,k,sp=4;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=i;j++)
            printf("*");
        for(k=1;k<=sp;k++)
            printf(" ");
        sp-=2;
        for(j=1;j<=i;j++)
            printf("*");
        printf("\n");
    }
    sp=2;
    for(i=1;i<=2;i++)
    {
        for(j=2;j>=i;j--)
            printf("*");
        for(k=1;k<=sp;k++)
            printf(" ");
        sp+=2;
        for(j=2;j>=i;j--)
            printf("*");
        printf("\n");
    }
}
