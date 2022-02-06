#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int *, int);
void modified_bubble_sort(int *, int);
void insertion_sort(int *, int);
void selection_sort(int *, int);
void quick_sort(int *,int, int);
void heap_sort(int *, int);
void swap(int *, int *);
int partition(int *, int, int);
void heap_pop(int *, int);
void cocktail_sort(int *, int);
void display(int *a, int);

int main()
{
	int n, c, i;
	printf("\n Enter the size of the Array : ");
	scanf("%d", &n);

	int *a=(int *)malloc(n*sizeof(int));
	printf("\n Enter %d elements : \n", n);

	for(i=0; i<n; i++)
	scanf("%d", &a[i]);
	do{
		int *t=(int *)malloc(n*sizeof(int));
		for(i=0; i<n; i++)
        {
             t[i]=a[i];
        }
		printf("\n 1) Bubble Sort\n 2) Modified Bubble sort\n 3) Cocktail Shaker Sort\n 4) Insertion Sort\n 5) Selection Sort\n 6) Quick Sort\n 7) Heap Sort\n 8) EXIT");
		printf("\n Enter your option : ");
		scanf("%d", &c);

		switch(c)
		{
			case 1: bubble_sort(t,n);
                    break;
			case 2: modified_bubble_sort(t,n);
                    break;
			case 3: cocktail_sort(t,n);
                    break;
			case 4: insertion_sort(t,n);
                    break;
			case 5: selection_sort(t,n);
                    break;
			case 6: quick_sort(t,0,n);
                    break;
			case 7: heap_sort(t,n);
                    break;
			case 8: printf("\n --- Program Terminated --- \n");
                    break;
			default : printf("\n Invalid option chosen ! ");
		}
		if(c>=1 && c<=7)
        {
             display(t,n);
        }
	}while(c!=8);

	return 0;
}

void display(int *a, int n)
{
	printf("\n Array after sorting is : \n");
	for(int i=0;i<n;i++)
    {
        printf(" %d",a[i]);
    }
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void bubble_sort(int *a, int n)
{
	for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

void modified_bubble_sort(int *a, int n)
{
	int i, j, flag=0;
	for(i=0; i<n-1; i++)
	{
		flag=0;
		for(j=0; j<n-1-i; j++)
	    {
	        if(a[j] > a[j+1])
            {
                swap(&a[j], &a[j+1]);
                flag = 1;
            }
	    }
	    if(flag==0)
            break;
	}
}

void cocktail_sort(int *a, int n)
{
	int i=0, j=n-1, k, max, min, pos;
	while(i<=j)
	{
		max = a[i];
		min = a[i];
		for(k=i; k<=j; k++)
		{
			if(max < a[k])
			{
				max = a[k];
				pos = k;
			}
		}
		swap(&a[j], &a[pos]);
		j--;

		for(k=j; k>=i; k--)
		{
			if(min > a[k])
			{
				min = a[k];
				pos = k;
			}
		}
		swap(&a[i], &a[pos]);
		i++;
	}
}

void insertion_sort(int *a, int n)
{
	int i, j=1;
	for(i=0; i<n-1; i++)
	{
		int k = j;
		while(k>0)
		{
			int flag = 0;
			if(a[k] < a[k-1])
			{
				swap(&a[k], &a[k-1]);
			    k--;
			    flag=1;
			}
			if(flag==0)
                break;
		}
		j++;
	}
}

void selection_sort(int *a, int n)
{
	int i=0, j, k, min;
	for(i=0; i<n-1; i++)
	{
		k=i;
		for(j=i+1; j<n; j++)
		{
			min=a[k];
			if(min > a[j])
                k = j;
		}
		swap(&a[k], &a[i]);
	}
}

int partition(int *a, int l, int h)
{
	int i=l+1, j=h-1, k=i-1;
	int pivot = a[k];
	while(i<=j)
	{
		while(pivot>=a[i] && i<=h-1)
            i++;

	    while(pivot<=a[j] && j>l)
            j--;

	    if(i<j)
	    {
	    	swap(&a[i], &a[j]);
	        i++;
	        j--;
		}
		else
            break;
	}
	if(k<j)
        swap(&a[k], &a[j]);

	return j;
}

void quick_sort(int *a, int l, int h)
{
	int j;
	if(l<h)
	{
		j = partition(a, l, h);
		quick_sort(a, l, j);
		quick_sort(a, j+1, h);
	}
}

void heap_sort(int *a, int n)
{
	int t, k = 1;

	while(k<n)
    {
		int j = k;
		t = a[j];
		while(j/2>=0 && j!=j/2 && t>a[j/2])
		{
			a[j] = a[j/2];
			j = j/2;
		}
		a[j] = t;
		k++;
	}
	if(n>1)
        heap_pop(a,n);
}

void heap_pop(int *a, int n)
{
	swap(&a[0], &a[n-1]);
	n--;
	heap_sort(a, n);
}
