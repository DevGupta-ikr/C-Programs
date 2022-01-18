#include<stdio.h>
#include<stdlib.h>

void Sort(int *, int);
int Linear_Search(int *, int, int);
int Binary_Search(int *, int, int);
int Interpolation_Search(int *, int, int);

void Sort(int *a, int n) // Bubble Sorting
{
	int i, j, flag = 0;
	for(i=0; i < n-1; i++)
	{
		flag = 0;
		for(j=0; j < n-i-1; j++)
		{
			if(a[j] > a[j+1])
			{
			    int temp = a[j];
			    a[j] = a[j+1];
			    a[j+1] = temp;
			    flag = 1;
			}
		}
		if(flag==0)
		{
		    break;
		}
	}
}


int Linear_Search(int *a, int n, int x)  // O(n)
{
	int i, flag = 0;
	for(i=0; i < n; i++)

	if(a[i]==x)
	{
		flag = 1;
		break;
	}
	return flag;
}

int Binary_Search(int *a, int n, int x) // O(log n)
{
	int i = 0, flag = 0, mid, j = n;

	mid=(i+j)/2;

	while(i<=j)
    {
        if(a[mid] > x)
        {
            j = mid-1;
            mid = (i+j)/2;
        }
        else if(a[mid] < x)
        {
            i = mid+1;
            mid = (i+j)/2;
        }
        else
        {
            flag = 1;
            break;
        }
   }
   return flag;
}

int Interpolation_Search(int *a, int n, int x)  // O(log log n)
{
	int l = 0, h = n-1, flag = 0, p;
	while(x >= a[l] && x <= a[h] && l <= h)
	{
		p = l+ ((x-a[l])/(a[h]-a[l]))*(h-l);

		if(x<a[p])
		{
		    h = p-1;
		}
		else if(x>a[p])
		{
		    l = p+1;
		}
		else
		{
			flag = 1;
			break;
		}
	}
	return flag;
}

int main()
{
	int n, c, x, flag;
	printf("\n Enter the size of array = ");
	scanf("%d", &n);
	int *a = (int *)malloc(n*sizeof(int));

	int i;
	printf("\n Enter %d elements in array : \n", n);
	for(i = 0; i < n; i++)
	{
	    scanf("%d", &a[i]);
	}

	do
  {
		  printf("\n 1) Linear Search\n 2) Binary Search\n 3) Interpolation Search\n 4) Exit Program");
	    printf("\n\n  Enter your choice (1-4) : ");
	    scanf("%d", &c);
	    
      if(c>=1 && c<=3)
	    {
	    	printf("\n Enter element to search = ");
	    	scanf("%d", &x);

            switch(c)
            {
                case 1: flag = Linear_Search(a, n, x);
                        break;

                case 2: Sort(a, n);
                        flag = Binary_Search(a, n, x);
                        break;

                case 3: Sort(a,n);
                        flag = Interpolation_Search(a, n, x);
                        break;

                default: printf("\n Invalid option \n");

            }

            if(flag==0)
            {
                printf("\n Value  %d  is not found", x);
            }
            else
            {
                printf("\n Value  %d  is found", x);
            }
        }
        else if(c<1 || c>=5)
        {
            printf("\n Invalid Option \n");
        }
        else
        {
            printf("\n ---Program Terminated--- \n");
            break;
        }

    }while(c!=4);

	return 0;
}
