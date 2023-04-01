#include<stdio.h>
void sum1()
{
   int n,i, sum=0;

   printf("Enter n value: ");
   scanf("%d",&n);

   for(i=1; i<=n; i++)
   {
     printf("%d+",i);
     sum += i; //sum = sum + i;
   }

   printf("\b=%d",sum);
}
void sum2()
{
    int n,sum=0,i=1;
    printf("Enter the range of number:");
    scanf("%d",&n);

    while(i<=n)
    {
        sum+=i;
        i+=2;
    }
    printf("The sum of the series = %d",sum);
}
void sum3()
{
   int n,i;
   float sum=0.0;

   printf("Enter nth value: ");
   scanf("%d",&n);

   for(i=1; i<=n; i++)
   {
     if(i%2==1)
        sum=sum+(1/pow(3,i-1));
     else
        sum=sum-(1/pow(3,i-1));
   }

   printf("\b=%f",sum);
}
int main()
{
    int n;
    printf("\nEnter the number to do specific operation :");
    scanf("%d",&n);
    switch(n)
    {
        case 1:sum1();
                break;
        case 2:sum2();
                break;
        case 3:sum3();
                break;
    }
    return 0;
}
