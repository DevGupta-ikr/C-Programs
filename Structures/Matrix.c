#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	int row;
	int col;
};
typedef struct node node;

void display(int r, node* t)
{
	int i;
	for(i=0; i<r; i++)
    {
        printf("%d  %d  %d\n",t[i].row,t[i].col,t[i].value);
    }
}

int main()
{
	int r, c, i, k, j, val, n = 0;
	printf("\n Enter the number of Rows and Columns :\n");
	scanf("%d %d",&r,&c);
	printf("\n Enter Elements of %dx%d matrix: \n",r,c);

	node *T = NULL;
	T = (node *)realloc(T,(++n)*sizeof(node));

	T[0].value = 0;
	T[0].row = r;
	T[0].col = c;

// Input of numbers
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			scanf("%d", &val);
			if(val != 0)
			{
				T = (node *)realloc(T,(++n)*sizeof(node));
				T[n-1].value = val;
	            T[n-1].row = i;
	            T[n-1].col = j;
	            T[0].value++;
			}
		}
	}

//	Making Transpose of Triplet Array
	node* TT = NULL;
	TT = (node *)malloc(n*sizeof(node));
	TT[0].row = c;
	TT[0].col = r;
	TT[0].value = T[0].value;

	int m=1;
	for(i=0; i<c; i++)
	{
		for(j=0; j<r; j++)
		{
			for(k=1; k<n; k++)
			{
				if(T[k].row==j && T[k].col==i)
				{
					TT[m].row = i;
					TT[m].col = j;
					TT[m].value = T[k].value;
					m++;
					break;
				}
			}
		}
	}

//	Displaying Transpose of Original Matrix
	printf("\n Transpose of original matrix :\n");
	k=1;
	for(i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
		{
			if(TT[k].row==i && TT[k].col==j)
                printf("%d ", TT[k++].value);
			else
                printf("0 "); // For empty elements
		}
		printf("\n");
	}

	printf("\n Triplet of Original Matrix: \n");
	display(n, T);
	printf("\n Triplet of Transpose Matrix: \n");
	display(n, TT);

	free(T);
	free(TT);

	return 0;

}
