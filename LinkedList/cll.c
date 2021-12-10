#include<stdio.h>
#include<stdlib.h>
struct node
{
	int x;
	struct node *next;
};
typedef struct node node;

node *insert_front(node *, node **);
node *insert_end(node *, node **);
node *insert_before(node *, node **);
node *insert_after(node *, node **);
void display(node *);
node *delete_front(node *, node **);
node *delete_end(node *, node **);
node *delete_given(node *, node **);
void search(node *);
int count(node *);

int main()
{
	int n,c;
	node *start = NULL, *tail = NULL; 
	do{
		printf("\n MAIN MENU: ");
		printf("\n 1) Insert a Node\n 2) Delete a Node\n 3) Searching for a Node\n 4) Count Number of Nodes\n 5) End Program ");
		printf("\n Enter your choice (1-5): ");
		scanf("%d", &n);
		
		switch(n)
		{
			case 1:printf("\n INSERT MENU:\n 1) Insert at beginning\n 2) Insert at End\n 3) Insert before a Node\n 4) Insert after a Node ");
			printf("\n Enter your choice (1-4) : ");
			scanf("%d", &c);
			
			switch(c)
			{
				case 1: start = insert_front(start, &tail);
					break;
				case 2: start = insert_end(start, &tail);
					break;
				case 3: start = insert_before(start, &tail);
					break;	
				case 4: start = insert_after(start, &tail);
					break;
				default: printf("\n Invalid Option ");
			}
			break;
			
			case 2:printf("\n DELETE MENU:\n 1) Deletion from front\n 2) Deletion from End\n 3) Deletion from given Node ");
				printf("\n Enter your choice (1-3) : ");
				scanf("%d", &c);
			
				switch(c)
				{
					case 1: start = delete_front(start, &tail);
						break;
					case 2: start = delete_end(start, &tail);
						break;
					case 3: start = delete_given(start, &tail);
						break;	
					default: printf("\n Invalid Option ");
				}
				break;
			
			case 3: search(start);
				break;
				
			case 4: printf("\n Number of Nodes = %d\n", count(start));
				break;
								
			case 5: printf("\n ---Program Terminated--- \n");
				break;
				
			default: printf("\n Invalid Choice ");
		}
		
	display(start);
	}while(n!=5);
		
	return 0;
}

node *insert_front(node *start, node **tail)
{
	node *ptr;
	int n;
	ptr = (node *)malloc(sizeof(node));
	printf("\n Enter node value = ");
	scanf("%d", &n);
	
	if(start == NULL)
	{
		ptr->x=n;
		start = ptr;
		ptr->next = start;
		*tail = ptr;
		return start;
	}
	ptr->x = n;
	ptr->next = start;
	start = ptr;
	(*tail)->next = start;
	return start;
}
node *insert_end(node *start, node **tail)
{
	node *ptr, *fpt = start;
	int n;
	ptr = (node *)malloc(sizeof(node));
	printf("\n Enter node value = ");
	scanf("%d", &n);
	
	if(start == NULL)
	{
		ptr->x = n;
		start = ptr;
		ptr->next = start;
		return start;
	}
	while(fpt->next!=start)
	{
		fpt = fpt->next;
	}
	ptr->x = n;
	fpt->next=ptr;
	ptr->next = start;
	*tail=ptr;
	return start;
}
node *insert_before(node *start, node **tail)
{
	node *ptr, *fpt=start, *p=start;
	int n, t, flag=0;
	
	if(start == NULL)
	{
		printf("\n List is Empty! Insertion before a target node is not possible ");
		return NULL;
	}
		
	printf("\n Enter target node value = ");
	scanf("%d", &t);
	
	do
	{
		if(fpt->x==t)
		{
			printf("\n Target node Found, Enter node Value = ");
			scanf("%d", &n);
			flag = 1;
			break;
		}
		else
		{
			p = fpt;
			fpt = fpt->next;
		}
	}while(fpt != start);

	if(flag==0)
	{
		printf("\n Target node not found ");
		return start;
	}	
	
	ptr = (node *)malloc(sizeof(node));
	if(fpt == start)
	{		
		ptr->x=n;
		ptr->next = fpt;
		start = ptr;
		(*tail)->next=start;
		return start;
	}
	ptr->x = n;
	ptr->next=p->next;
	p->next = ptr;
	return start;
}
node *insert_after(node *start, node **tail)
{
	node *ptr, *fpt = start, *p;
	int n, t, flag=0;
	
	if(start == NULL)
	{
		printf("\n List is Empty! Insertion after a target node is not possible ");
		return NULL;
	}
		
	printf("\n Enter target node value = ");
	scanf("%d", &t);
	
	do
	{
		if(fpt->x==t)
		{
			printf("\n Target node Found, Enter node Value = ");
			scanf("%d", &n);
			flag = 1;
			break;
		}
		else
		{
			fpt = fpt->next;
		}
	}while(fpt != start);

	if(flag==0)
	{
		printf("\n Target node not found ");
		return start;
	}	
	
	ptr = (node *)malloc(sizeof(node));
	if(fpt->next==start)
	{		
		ptr->x = n;
		fpt->next = ptr;
		ptr->next = start;
		*tail = ptr;
		return start;
	}
	ptr->x = n;
	ptr->next = fpt->next;
	fpt->next = ptr;
	return start;
}
void display(node *start)
{
	node *ptr = start;
	if(start == NULL)
	{
		printf("\n List is Empty ");
		return;
	}
		
	printf("\n List is : ");
	do
	{
		printf("%d ", ptr->x);
		ptr = ptr->next;
	}while(ptr!=start);
	printf("\n");
	return;
}
int count(node *start)
{
	node *ptr = start;
	int c = 0;
	do
	{
		c++;
		ptr = ptr->next;
	}while(ptr!=start);
	return c;
}
void search(node *start)
{
	node *ptr = start;
	int n, flag=0;
	if(start == NULL)
	{
		printf("\n List is Empty ");
		return;
	}
		
	printf("\n Enter searching value of node = ");
	scanf("%d", &n);
	
	do
	{
		if(ptr->x==n)
		{
			flag = 1;
			break;
		}
		else
		{
			ptr = ptr->next;
		}
	}while(ptr != start);

	if(flag==1)
	{
		printf("\n Node value %d is found ", n);
	}
	else if(flag==0)
	{
		printf("\n Node value not found ");
	}
	return;
}
node *delete_front(node *start, node **tail)
{
	if(start == NULL)
	{
		return NULL;
	}
	node *ptr=start;
	if(ptr->next==start)
	{
		free(ptr);
		printf("\n First node Deleted ");
		return NULL;
	}
	start = ptr->next;
	(*tail)->next=start;
	free(ptr);
	printf("\n First node Deleted ");
	return start;
}
node *delete_end(node *start, node **tail)
{
	node *fpt, *ptr=start;
	if(start == NULL)
	{
		return NULL;
	}
	
	if(ptr->next == start)
	{
		free(ptr);
		printf("\n Last node is deleted ");
		return NULL;
	}
	
	while(ptr->next != start)
	{
		fpt = ptr;
		ptr = ptr->next;
	}
	
	fpt->next = start;
	*tail=fpt;
	free(ptr);
	printf("\n Last node Deleted ");
	return start;
}
node *delete_given(node *start, node **tail)
{
	node *fpt=start, *ptr=start;
	
	int n, flag=0;
	
	if(start == NULL)
	{
		return NULL;
	}
	printf("\n Enter node value that you want to delete = ");
	scanf("%d", &n);
	
	do
	{
		if(ptr->x==n)
		{	flag = 1;
			if(ptr==start && ptr->next==start)
			{
				free(ptr);
				printf("\n Node value %d is deleted ", n);
				return NULL;
			}
			else if(ptr== start && ptr->next!=start)
			{
				start=ptr->next;
				(*tail)->next=start;
			}
			else if(ptr==*tail)
			{
				fpt->next = start;
				*tail = fpt;
			}
			else
			{
				fpt->next = ptr->next;
			}
			free(ptr);
			break;
		}
		fpt = ptr;
		ptr = ptr->next;
	}while(ptr != start);
	
	if(flag==0)
	{
		printf("\n Target node not found ");
	}
	else if(flag==1)
	{
		printf("\n Node value %d is Deleted ", n);
	}
	return start;
}
