/*
   Write a program by using structure that describes the set of books in a library. 
   For each book the members are name of author, publisher, price and branch information. The program should:
    • print the list of books supplied by a publisher
    • print the list of books in a particular branch in a file say “lib.txt”

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fptr;

void publisher(int);
void branch(int);

struct book
{
    char name[20];
    char Author[20];
    char Publisher[20];
    int price;
    char Branch[20];
}*ptr;

int main()
{
    int op,n,i;
    printf("\n Enter number of books: ");
    scanf("%d", &n);
    getchar();
    ptr = (struct book *)malloc(n*sizeof(struct book));

    for(i = 0; i < n; i++)
    {
        printf("\n Enter details of book %d: ", i+1);
        printf("\n\n Enter Name of Book: ");
        gets(ptr[i].name);
        printf("\n Enter Name of Author: ");
        gets(ptr[i].Author);
        printf("\n Enter Name of Publisher: ");
        gets(ptr[i].Publisher);
        printf("\n Enter Price: ");
        scanf("%d", &ptr[i].price);
        getchar();
        printf("\n Enter Name of Branch: ");
        gets(ptr[i].Branch);
    }

    publisher(n);
    branch(n);
    return 0;
}
void publisher(int n)
{
    int i;
    char temp[20];
    printf("\n Enter Name of Publisher of Books: ");
    gets(temp);
    fptr=fopen("lib.txt", "w");
    if(fptr==NULL)
    {
        printf(" Cannot Open File! ");
        return;
    }
    fprintf(fptr, "\n Books of the Publisher: ");
    fprintf(fptr,"\n\n Name of Book \t\t Author \t\tPublisher \t\t Price\t\tBranch ");

    for(i = 0; i < n; i++)
    {
        if(strcmpi(temp, ptr[i].Publisher)==0)
        {
            fprintf(fptr,"\n %s \t\t %s \t\t %s \t\t %d \t\t %s",ptr[i].name,ptr[i].Author,ptr[i].Publisher,ptr[i].price,ptr[i].Branch);
        }
    }
    return;
}
void branch(int n)
{
    int i;
    char temp[20];
    printf("\n Enter Name of Branch of Books: ");
    gets(temp);
    fprintf(fptr,"\n\n Books of the Branch: ");
    fprintf(fptr, "\n\n Name of Book \t\t Author \t\tPublisher \t\t Price\t\tBranch ");
    for(i = 0; i < n; i++)
    {
        if(strcmpi(temp, ptr[i].Branch)==0)
        {
            fprintf(fptr,"\n %s \t\t %s \t\t %s \t\t %d \t\t %s",ptr[i].name,ptr[i].Author,ptr[i].Publisher,ptr[i].price,ptr[i].Branch);
        }
    }
    fclose(fptr);
    printf("\n List of Books is printed in \"lib.txt\" ");
    return ;
}
