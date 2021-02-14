#include<stdio.h>

struct date
{
    int dd;
    int mm;
    int yyyy;

};

struct date date_input()			//function to take date input from user
{
    struct date d;
    printf("Enter (dd/mm/yyyy or d/mm/yyyy or d/m/yyyy):");
    scanf("%d/%d/%d",&d.dd,&d.mm,&d.yyyy);
    return d;
}

void date_output(struct date d)			//function to take date input from user
{
    printf("%d/%d/%d",d.dd,d.mm,d.yyyy);
}



struct account
{
	char acc_no[10];
	char name[20];
	int balance;
	int last_transaction_amount;
	struct date last_transaction_date;
};

struct account acc_input()
{
	struct account a;
	printf("Enter account number:");
	scanf("%s",a.acc_no);
	printf("Enter name of person:");
	fflush(stdin);
	gets(a.name);
	printf("Enter last transaction amount:");
	scanf("%d",&a.last_transaction_amount);
	printf("Enter last transaction date:");
	a.last_transaction_date=date_input();
	printf("\n");
	return a;
}

void acc_output(struct account a)
{
	printf("Account number:%s\n",a.acc_no);
	printf("Name of person:%s\n",a.name);
	printf("Last transaction amount:%d\n",a.last_transaction_amount);
	printf("Last transaction date:\n");
	date_output(a.last_transaction_date);
	printf("\n");
}

void NIT_KKR(struct account a[],int size)
{
	printf("\n----------Deatils of accounts of NIT KKR----------\n");
	int i;
	for(i=0;i<size;i++)
	{
		if(a[i].acc_no[0]=='1'&&a[i].acc_no[1]=='0'&&a[i].acc_no[2]=='1')
		{
			acc_output(a[i]);
		}
	}
}

void No_transaction_last_1_year(struct account a[],int size,struct date d)
{
	printf("\n----------Deatils of accounts who have not done their transaction during last 1 year----------\n");
	int i;
	for(i=0;i<size;i++)
	{
		if(d.yyyy-a[i].last_transaction_date.yyyy>1)
		{
			acc_output(a[i]);
		}
		else if(d.yyyy-a[i].last_transaction_date.yyyy==1&&d.mm>a[i].last_transaction_date.mm)
		{
			acc_output(a[i]);
		}
		else if(d.yyyy-a[i].last_transaction_date.yyyy==1&&d.mm==a[i].last_transaction_date.mm&&d.dd>a[i].last_transaction_date.dd)
		{
			acc_output(a[i]);
		}
	}
}

int main()
{
	int n,i;
	struct date d;
	printf("Enter the number of accounts:");
	scanf("%d",&n);
	struct account a[n];		//array of book of n size
	printf("Enter details of %d accounts\n",n);
	for(i=0;i<n;i++)
	{
		a[i]=acc_input();
	}
	printf("Enter current date\n");
	d=date_input();
	NIT_KKR(a,n);
	No_transaction_last_1_year(a,n,d);
	return 0;
}
