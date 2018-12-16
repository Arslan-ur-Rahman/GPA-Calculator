#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void degree_status (int sem_num,float newCGPA,int* C_Degree_sts);

int main()
{
 int std_marks[8][7],i,j,sem,sem_number,status=0,Degree_Status = 0;
 char GRADE1,SIGN;
 float GPA,SGPA,CGPA,p,q,semcgpa;

  printf("\n_______________________________________________________\n");
	printf("\n             Welcome to GPA Assistant!             \n");
	printf("_______________________________________________________\n");
do
{
 printf("\n  How many semesters have you completed? (Maximum:8):");
 scanf("%d",&sem);
}
 while (sem>8 || sem<1);
for (i=0;i<sem;i++)
 {
   for (j=0;j<7;j++)
    {
   		std_marks[i][j]=-1;
	}
}

 for (i=0;i<sem;i++)
 {
   printf("\n\n\t\t * Semester : %d ***\n\n\n",i+1);
   for (j=0;j<7;j++)
   {
   do
{
     printf("  Enter marks for subject# %d:",j+1);
     scanf("%d",&std_marks[i][j]);
     if (std_marks[i][j] == -1)
   {
       break;
   }
   }
   while (std_marks[i][j]<1 || std_marks[i][j]>100);
   if (std_marks[i][j] == -1)
   {
       break;
   }
 }
 }
  for (i=0;i<sem;i++)
 {
 	SGPA=0;
printf("\n__________________________________\n");
printf("\n     Result of Semester : %d",i+1);
printf("\n__________________________________\n\n");

   printf("Subject No# : \t\t GRADE: \t\t GPA: \t\t Marks:\n");
         for (j=0;j<7 && std_marks[i][j]!=-1;j++)
         {
         	p=i,q=j;
              if (std_marks[i][j]>=90 && std_marks[i][j]<100)
 {
     GRADE1 = 'A';
     SIGN = '+';
     GPA = 4.0;
 }
 else if (std_marks[i][j]>=85 && std_marks[i][j]<90)
 {
     GRADE1 = 'A';
     SIGN='-';
     GPA = 3.7;

 }
 else if (std_marks[i][j]>80 && std_marks[i][j]<85)
 {
    GRADE1 = 'B';
	SIGN='+';
    GPA = 3.3;

 }
 else if (std_marks[i][j]>=75 && std_marks[i][j]<80)
 {
    GRADE1 = 'B';
	SIGN=' ';
    GPA = 3.0;

 }
 else if (std_marks[i][j]>=70 && std_marks[i][j]<75)
 {
    GRADE1 = 'B';
   	SIGN='-';
    GPA = 2.7;

 }
 else if (std_marks[i][j]>=65 && std_marks[i][j]<70)
 {
    GRADE1 = 'C';
	SIGN='+';
    GPA = 2.3;

 }
 else if (std_marks[i][j]>=60 && std_marks[i][j]<65)
 {
    GRADE1 = 'C';
	SIGN=' ';
    GPA = 2.0;

 }
 else if (std_marks[i][j]>=55 && std_marks[i][j]<60)
 {
    GRADE1 = 'C';
	SIGN='-';
    GPA = 1.7;

 }
else if (std_marks[i][j]>=50 && std_marks[i][j]<55)
 {
    GRADE1 = 'D';
	SIGN=' ';
    GPA = 1.3;

 }
 else if (std_marks[i][j]>=0 && std_marks[i][j]<50)
 {
    GRADE1 = 'F';
	SIGN=' ';
    GPA = 0.0;

 }
 SGPA+= GPA;
           printf("\n    %d \t\t\t   %c%c \t\t\t %.1f \t\t   %d",j+1,GRADE1,SIGN,GPA,std_marks[i][j]);

         }
         SGPA = SGPA/(q+1);
         CGPA=CGPA+SGPA;
         printf("\n_______________________________________________________________________\n");
         printf("\n\t\t\t          Semester GPA : %.1f\n \t\t\t          CGPA         : %.1f\n",SGPA,CGPA/(p+1));
         printf("\n_______________________________________________________________________\n");
         degree_status(i+1,CGPA/(p+1),&status);
         if (status ==0)
         {
          printf("\n\t\t\t\t\tDegree status: Continued\n");
         }
         else if (status ==1)
         {
          printf("\n\t\t\t\t\tDegree status: Probation\n");
         }
         else if (status ==2)
         {
          printf("\n\t\t\t\t\tDegree status: DI\n Start over from 1st semester. Better luck next time.");
         }
          else if (status==3)
         {
          printf("\n\t\t\t\t\tDegree status: Degree completed\n");
         }
 }
 return 0;
}
void degree_status(int sem_number,float newCGPA,int* C_Degree_sts)
{
	if(*C_Degree_sts==0)
	{
		if(newCGPA<2 && sem_number>=1 && sem_number<=8)
		{
			*C_Degree_sts=1;
		}
		else if(newCGPA>2 && sem_number==8)
		{
			*C_Degree_sts=3;
		}
	}
	else if(*C_Degree_sts==1)
	{
		if(newCGPA<2 && sem_number>=1 && sem_number<=8)
		{
			*C_Degree_sts=2;
		}
		else if(newCGPA>2 && sem_number>=1 && sem_number<=7)
		{
			*C_Degree_sts=0;
		}
	}
}
