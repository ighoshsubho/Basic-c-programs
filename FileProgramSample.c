#include <stdio.h>
#include <stdlib.h>

/*Write a C program to create a file named “info.txt” to store the roll number and marks obtained in
physics, chemistry and mathematics of several students. Then the program should take input from
the file “info.txt” and find the total marks obtained by each student and write all these information
(roll number, physics, chemistry, mathematics and total marks) in another file named “result.txt”*/
struct student
{
    int roll;
    char name[20];
    float marksInPhysics;
    float marksInChemistry;
    float marksInMathematics;
    float totalMarks;
};
int main()
{
    struct student s;
    FILE *f1,*f2;
    int n,i;
    f1 = fopen("info.txt","w");
    f2 = fopen("result.txt","w");
    if((f1 == NULL) || (f2 == NULL))
    {
        printf("\nERROR !! in file opening...");
        exit(1);
    }
    printf("\nEnter the no. of students :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the details for student %d",i+1);
        printf("\nRoll :");
        scanf("%d",&s.roll);
        fflush(stdin);
        printf("\nName :");
        scanf("%[^\n]s",s.name);
        printf("\nMarks in Physics :");
        scanf("%f",&s.marksInPhysics);
        printf("\nMarks in Chemistry :");
        scanf("%f",&s.marksInChemistry);
        printf("\nMarks in Mathematics :");
        scanf("%f",&s.marksInMathematics);
        fwrite(&s,sizeof(s),1,f1);
    }
    printf("Student details are successfully written in info.txt...");
    fclose(f1);
    f1=fopen("info.txt","r");
    if(f1 == NULL)
    {
        printf("\nERROR !! in file opening...");
        exit(1);
    }
    /*while(fread(&s,sizeof(s),1,f1))
    {
        printf("\nRoll :%d\tName :%s\tMarks in physics :%.2f\tMarks in chemistry :%.2f\tMarks in mathematics :%.2f\t",s.roll, s.name, s.marksInPhysics, s.marksInChemistry, s.marksInMathematics);
    }*/
        while(fread(&s,sizeof(s),1,f1))
        {
            s.totalMarks = s.marksInPhysics + s.marksInChemistry + s.marksInMathematics ;
            fwrite(&s,sizeof(s),1,f2);
        }
	fclose(f2);
	f2 = fopen("result.txt","r");
        while(fread(&s,sizeof(s),1,f2))
        {
            printf("\nRoll :%d\tName :%s\tMarks in physics :%.2f\tMarks in chemistry :%.2f\tMarks in mathematics :%.2f\tTotal marks :%.2f\t",s.roll, s.name, s.marksInPhysics, s.marksInChemistry, s.marksInMathematics, s.totalMarks);
        }
    fclose(f1);
    fclose(f2);
    return 0;
}
