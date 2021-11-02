#include<stdio.h>
#include<stdlib.h>
struct poly
{
    int coeff;
    int exp;
};
typedef struct poly poly;

poly* Get(poly*, int*);
void display(poly*, int);
void Add(poly*, poly*, int, int);


int main()
{
	int n1 = 0, n2 = 0;
	poly *p1=NULL,*p2=NULL;   // Setting Base address

	printf("\n Enter highest exponent of 1st polynomial : ");
	scanf("%d", &n1);
	p1 = Get(p1, &n1);
	printf("\n Enter highest exponent of 2nd polynomial : ");
    scanf("%d", &n2);
    p2 = Get(p2,&n2);

    printf("\n 1st polynomial : ");
	display(p1,n1);
	printf("\n 2nd polynomial : ");
	display(p2,n2);

	Add(p1,p2,n1,n2);

	free(p1);   // Free up memory
	free(p2);   // Free up memory

	return 0;
}

poly* Get(poly* p,int* n)
{
	int i, x = 0, c;
	for(i = *n; i >= 0; i--)
	{
		if(i != 0)
		{
            printf("\n Enter coff. of x^%d exponent : ", i);
		}
		else
		{
            printf("\n Enter constant term : ");
		}
		scanf("%d", &c);

		if(c != 0)
		{
            x++;
            p = (poly*)realloc(p,x*sizeof(poly));   // Here realloc works the same way as malloc or calloc due to NULL declaration of pointer
            p[x-1].coeff = c;
            p[x-1].exp = i;
	    }
	    *n = x;
	}
	return p;
}

void display(poly* p, int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
		if(i != 0 && p[i].coeff > 0)
            printf(" + ");
		if(p[i].coeff == 1 && p[i].exp == 0)
            printf("%d", p[i].coeff);
		if(p[i].coeff != 1 && p[i].exp != 0)
            printf("%d", p[i].coeff);
		if(p[i].coeff != 1 && p[i].exp == 0)
            printf("%d", p[i].coeff);
		if(p[i].exp > 1)
            printf(" x^%d", p[i].exp);
		if(p[i].exp == 1)
            printf(" x");
	}
    printf("\n");
}

void Add(poly* p1,poly* p2,int n1,int n2)
{
	int x=0,i=0,j=0;
	poly* p = NULL;
	while(i < n1 && j < n2)
	{
			x++;
			p = (poly*)realloc(p,x*sizeof(poly));
		    if(p1[i].exp > p2[j].exp)
			{
				p[x-1].exp = p1[i].exp;
				p[x-1].coeff = p1[i].coeff;
				i++;
			}
			else if(p1[i].exp < p2[j].exp)
			{
				p[x-1].exp = p2[j].exp;
				p[x-1].coeff = p2[j].coeff;
				j++;
			}
			else if(p1[i].exp == p2[j].exp)
			{
				if(p1[i].coeff+p2[j].coeff!=0)
				{
                    p[x-1].exp = p1[i].exp;
                    p[x-1].coeff = p1[i].coeff + p2[j].coeff;
			    }
			    else
                    x--;

				i++;
				j++;
			}
		}
	while(i < n1)   // To take in remaining terms when coefficients do not match
	{
		x++;
		p = (poly*)realloc(p,x*sizeof(poly));
		p[x-1].exp = p1[i].exp;
		p[x-1].coeff = p1[i].coeff;
		i++;
	}
	while(j < n2)   // To take in remaining terms when coefficients do not match
	{
		x++;
		p = (poly*)realloc(p,x*sizeof(poly));
		p[x-1].exp = p2[j].exp;
		p[x-1].coeff = p2[j].coeff;
		j++;
	}
	printf("\n After addition of both above polynomials : ");
	display(p, x);
	free(p);   // Free up memory
}
