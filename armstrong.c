#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
    int count =0,digit,n,p,d,u,l;
    float sum=0.0;
    printf("\nEnter the upper and lower limit :");
    scanf("%d%d",&u,&l);
    printf("\nThe armstrong numbers are :");
    for(n=l;n<=u;n++)
    {
        p=n;
        while(p!=0)
        {
            d=p%10;
            count++;
            p=p/10;
        }
        p=n;
        while(p!=0)
        {
            d=p%10;
            sum=sum+pow(d,count);
            p=p/10;
        }
        if((int)sum == n)
            printf("%d,",n);
    }
}
