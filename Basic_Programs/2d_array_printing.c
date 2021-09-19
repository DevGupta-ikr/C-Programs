// Program to print 2-D array
#include<stdio.h>

int main()
{
    int a[100][100],row,col,i,j;
    printf("\n Enter the no. of rows & cols.: \n");
    scanf("%d %d", &row, &col);

    printf("\n Enter the elements: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n Given 2-D array is: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
         {
             printf("%d\t", a[i][j]);
         }
        printf("\n");
    }

    return 0;
}
