#include <stdio.h>
int main(void){
int num;
printf("Enter your mark ");
scanf("%d",&num);
printf(" You entered %d", num); // printing outputs

	if(num >= 90){
	printf(" You got O grade"); // printing outputs
		}
	else if ( num >=80){ // Note the space between else & if
		printf(" You got E grade");
		}
	else if ( num >=70){
		printf(" You got A grade");
		}
	else if ( num >=60){
		printf(" You got B grade");
		}
    else if ( num >=50){
		printf(" You got C grade");
		}
    else if ( num >=40){
		printf(" You got D grade");
		}
    else if ( num <40){
		printf(" You Failed in this exam");
		}
return 0;
}
