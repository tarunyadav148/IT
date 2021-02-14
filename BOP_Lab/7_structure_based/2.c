#include<stdio.h>

struct student
{
	char name[30];
	int rollno;
	int marks;
	int fee_paid;
};

struct student input()			//function to take data input from user
{
    struct student s;
    printf("Enter name of student:");
    fflush(stdin);							//to solve input buffer problem, flushing input buffer
    gets(s.name);
    printf("Enter roll number of student:");
    scanf("%d",&s.rollno);
    printf("Enter marks of student:");
    scanf("%d",&s.marks);
    printf("Enter fee paid by student:");
    scanf("%d",&s.fee_paid);
    printf("\n");
    return s;
}

void  output(struct student s)			//function to print the details of student
{
    printf("Name of student:%s\n",s.name);
    printf("Roll number of student:%d\n",s.rollno);
    printf("Marks of student:%d\n",s.marks);
    printf("Fee paid by student:%d\n",s.fee_paid);
    printf("\n");
}

void toppers(struct student s[],int size)	//function to prints detail of toppers
{
	printf("\n-----------Deatils of toppers---------\n");
	int i,max_marks=0;
	for(i=0;i<size;i++)
	{
		if(s[i].marks>max_marks)
		{
			max_marks=s[i].marks;
		}
	}
	for(i=0;i<size;i++)
	{
		if(s[i].marks==max_marks)
		{
			output(s[i]);
		}
	}
}

void marks_greater_than_average(struct student s[],int size)	//function to print details of student who get marks greater than average
{
	printf("\n---------Deatils of student who get marks greater than average----------\n");
	int i,average=0;
	struct student stud=s[i];
	for(i=0;i<size;i++)
	{
		average+=(s[i].marks)/size;
	}
	for(i=0;i<size;i++)
	{
		if(s[i].marks>average)
		{
			output(s[i]);
		}
	}
}

void not_paid_fee(struct student s[],int size)	//function to print details of student who not paid fee
{
	printf("\n----------Deatils of who not paid the fees-----------\n");
	int i;
	for(i=0;i<size;i++)
	{
		if(s[i].fee_paid<=0)
		{
			output(s[i]);
		}
	}
}

int main()
{
	int n,i;
	printf("Enter the number of students:");
	scanf("%d",&n);
	struct student s[n];		//array of student of n size
	printf("Enter details of %d students\n\n",n);
	for(i=0;i<n;i++)
	{
		s[i]=input();
	}
	toppers(s,n);
	marks_greater_than_average(s,n);
	not_paid_fee(s,n);
    return 0;
}
