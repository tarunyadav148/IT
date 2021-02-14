#include<stdio.h>
#include<string.h>

struct book
{
	char title[50];
	char author_name[30];
	int cost;
	int year_of_publication;
};

struct book input()			//function to take data input from user
{
    struct book b;
    printf("Enter title of book:");
    fflush(stdin);							//to solve input buffer problem, flushing input buffer
    gets(b.title);
    printf("Enter name of author:");
    fflush(stdin);							//to solve input buffer problem, flushing input buffer
    gets(b.author_name);
    printf("Enter cost of book:");
    scanf("%d",&b.cost);
    printf("Enter year of publication:");
    scanf("%d",&b.year_of_publication);
    printf("\n");
    return b;
}

void  output(struct book b)			//function to print the details of book
{
    printf("Title of book:%s\n",b.title);
    printf("Name of author:%s\n",b.author_name);
    printf("Cost of book:%d\n",b.cost);
    printf("Year of publication:%d\n",b.year_of_publication);
    printf("\n");
}

void title_cs_cost_less_500(struct book b[],int size)
{
	printf("\n----------Deatils of books having title computer and cost less than 500-----------\n");
	int i;
	for(i=0;i<size;i++)
	{
		if(!strcmp(b[i].title,"computer")&&b[i].cost<500)
		{
			output(b[i]);
		}
	}
}

void book_after_paticular_year(struct book b[],int size,int particular_year)
{
	printf("\n----------Deatils of books are published on or after a particular year----------\n");
	int i;
	for(i=0;i<size;i++)
	{
		if(b[i].year_of_publication>=particular_year)
		{
			output(b[i]);
		}
	}
}

int main()
{
	int n,i,particular_year;
	printf("Enter the number of books:");
	scanf("%d",&n);
	struct book b[n];		//array of book of n size
	printf("Enter details of %d books\n\n",n);
	for(i=0;i<n;i++)
	{
		b[i]=input();
	}
	printf("Enter the particular year:");
	scanf("%d",&particular_year);
	title_cs_cost_less_500(b,n);
	book_after_paticular_year(b,n,particular_year);
    return 0;
}
