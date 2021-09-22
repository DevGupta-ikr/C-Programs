#include<stdio.h>
#include<stdlib.h>

/*
Define a structure named employee to store information of an employee (empNo, name, department, basicPay, DA, HRA and grossSalary).
Write a program, which will take as input the empNo, name, department, basicPay for several employees from a file named I_P.txt. 
The program will calculate the DA, HRA and total for each employee and display the details of the employee having 
the highest gross salary in a file O_P.txt
*/

struct emp
{
	char name[20];
	char dept[5];
	int EmpNo;
	int basicpay;
	float DA,HRA;
	float gross_salary;
};

void Sort(struct emp* ptr, int n);

int main()
{
	struct emp* ptr;
	int n,i;
	printf("\n Enter Number of Employees = ");
	scanf("%d",&n);

	ptr=(struct emp *)malloc(n*sizeof(struct emp));

	FILE* f1,*f2;
	f1=fopen("I_P.txt", "wb");
	f2=fopen("O_P.txt", "w+");

	if(f1==NULL || f2==NULL)
	{
		printf("\n Cannot Open File! ");
		exit(1);
	}

	fprintf(f1," Name: \t\t Dept.: \t EmpNo.: \t BasicPay: \t  DA: \t HRA: \n");
	for(i=0;i<n;i++)
	{
		printf("\n Enter name, dept., EmpNo., basicPay, DA and HRA in percent of Employee %d : \n", i+1);
		getchar();

		scanf("%[^\n]s",ptr[i].name);

		scanf("%s %d %d %f %f", ptr[i].dept, &ptr[i].EmpNo, &ptr[i].basicpay, &ptr[i].DA, &ptr[i].HRA);
	}

	fwrite(ptr, sizeof(struct emp), n, f1);
	printf("\n All Input Stored in I_P.txt file \n");
	rewind(f1);

	fread(ptr,sizeof(struct emp),n,f1);

	for(i=0;i<n;i++)
	{
	    ptr[i].gross_salary=ptr[i].basicpay+ptr[i].basicpay*(ptr[i].DA+ptr[i].HRA)/100;
	}

	Sort(ptr,n);
	fprintf(f2," Name: \t\t\t Dept.: \t EmpNO.: \t Gross Salary");

	for(i=0;i<n;i++)
	{
	    fprintf(f2,"\n %s \t\t %s \t\t %d \t\t %.2f",ptr[i].name,ptr[i].dept,ptr[i].EmpNo,ptr[i].gross_salary);
	}

	printf("\n All Details for Employees are in O_P.txt file \n");

	fclose(f1);
	fclose(f2);
	return 0;
}

void Sort(struct emp* ptr, int n)
{
	int i,j;
	struct emp temp;
	float s=0;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			temp=ptr[i];
			if(ptr[i].gross_salary<ptr[j].gross_salary)
            {
                ptr[i]=ptr[j];
                ptr[j]=temp;
		    }
		}
	}
}

