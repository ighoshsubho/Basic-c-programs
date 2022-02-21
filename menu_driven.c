#include <stdio.h>
void factorial() {
    int n, i;
    long fact = 1;
    printf("Enter an integer: ");
    scanf("%d", &n);
    if (n < 0)
        printf("Error! Factorial of a negative number doesn't exist.");
    else {
        for (i = 1; i <= n; ++i) {
            fact *= i;
        }
        printf("Factorial of %d = %d", n, fact);
    }
}
void prime_chk(){
    int n,i,m=0,flag=0;
    printf("Enter the number to check prime:");
    scanf("%d",&n);
    m=n/2;
    for(i=2;i<=m;i++)
    {
    if(n%i==0)
    {
    printf("Number is not prime");
    flag=1;
    break;
    }
    }
    if(flag==0)
    printf("Number is prime");
 }
void palindrome() {
    int n, reversed = 0, remainder, original;
    printf("Enter an integer: ");
    scanf("%d", &n);
    original = n;
    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    if (original == reversed)
        printf("%d is a palindrome.", original);
    else
        printf("%d is not a palindrome.", original);
}
int main()
{
    int n;
    printf("\nEnter 1 to find factorial, 2 to check for prime and 3 to check for palindrome");
    scanf("%d",&n);
    switch(n)
    {
        case 1:factorial();
                break;
        case 2:prime_chk();
                break;
        case 3:palindrome();
                break;
    }
    return 0;
}
