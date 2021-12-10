#include<stdio.h>
#include<stdlib.h>
struct node
{
	int x;
	struct node *next, *prev;
};
typedef struct node node;

node *insert_front(node *);
node *insert_end(node *);
node *insert_before(node *);
node *insert_after(node *);
void display(node *);
node *delete_front(node *);
node *delete_end(node *);
node *delete_given(node *);
void search(node *);
int count(node *);

int main()
{
	int n,c;
	node *start = NULL;
	printf("\n Program for Double LinkedList is Starting ---> \n");
	do{
		printf("\n MAIN MENU: ");
		printf("\n 1) Insert a Node\n 2) Delete a Node\n 3) Searching for a Node\n 4) Count Number of Nodes\n 5) End Program ");
		printf("\n Enter your choice (1-5): ");
		scanf("%d", &n);
		
		switch(n)
		{
			case 1:printf("\n INSERT MENU:\n 1) Insert at beginning\n 2) Insert at End\n 3) Insert before a Node\n 4) Insert after a node");
			printf("\n Enter your choice (1-4) : ");
			scanf("%d", &c);
			
			switch(c)
			{
				case 1: start = insert_front(start);
					break;
				case 2: start = insert_end(start);
					break;
				case 3: start = insert_before(start);
					break;
				case 4: start = insert_after(start);
					break;		
				default: printf("\n Invalid Option ");
			}
			break;
			
			case 2:printf("\n DELETE MENU:\n 1) Deletion from front\n 2) Deletion from End\n 3) Deletion of a node value");
				printf("\n Enter your choice (1-3) : ");
				scanf("%d", &c);
			
				switch(c)
				{
					case 1: start = delete_front(start);
						break;
					case 2: start = delete_end(start);
						break;
					case 3: start = delete_given(start);
						break;	
					default: printf("\n Invalid Option ");
				}
				break;
			
			case 3: search(start);
				break;
				
			case 4: printf("\n Number of Nodes in DLL = %d\n", count(start));
				break;
								
			case 5: printf("\n ---Program Terminated--- \n");
				break;
				
			default: printf("\n Invalid Choice ");
		}
		
		display(start);
	}while(n!=5);
		
	return 0;
}

node *insert_front(node *start)
{
	node *ptr;
	int n;
	ptr = (node *)malloc(sizeof(node));
	printf("\n Enter node value to insert = ");
	scanf("%d", &n);
	
	if(start == NULL)
	{
		ptr->x = n;
		start = ptr;
		ptr->next = NULL;
		ptr->prev = NULL;
		return start;
	}
	ptr->x = n;
	ptr->next = start;
	start->prev = ptr;
	ptr->prev = NULL;
	start=ptr;
	return start;
}
node *insert_end(node *start)
{
	node *ptr, *fpt = start;
	int n;
	ptr = (node *)malloc(sizeof(node));
	printf("\n Enter node value to insert = ");
	scanf("%d", &n);
	
	if(start == NULL)
	{
		ptr->x = n;
		ptr->prev=NULL;
		ptr->next = NULL;
		start = ptr;
		return start;
	}
	while(fpt->next!=NULL)
	{
		fpt = fpt->next;
	}
	ptr->x = n;
	fpt->next=ptr;
	ptr->prev = fpt;
	ptr->next = NULL;
	return start;
}
node *insert_before(node *start)
{
	node *ptr, *fpt = start;
	int n, t, flag=0;
	if(start==NULL)
	{
		printf("\n Insertion before a target node is not possible");
		return NULL;
	}
	printf("\n Enter target node value = ");
	scanf("%d", &t);
	
	while(fpt != NULL)
	{
		if(fpt->x == t)
		{
			printf("\n Target node value found. Enter node value to insert = ");
			scanf("%d", &n);
			flag = 1;
			break;
		}
		else
		{
			fpt = fpt->next;
		}
	}
	if(flag==0)
	{
		printf("\n Target node value not found ");
		return start;
	}
	ptr = (node *)malloc(sizeof(node));
	if(fpt==start)
	{
		ptr->x=n;
		ptr->next=fpt;
		fpt->prev=ptr;
		ptr->prev=NULL;
		start=ptr;
		return start;
	}
	ptr->x=n;
	ptr->next=fpt;
	fpt->prev->next=ptr;
	fpt->prev=ptr;
	return start; 
	
}

node *insert_after(node *start)
{
	node *ptr, *fpt = start;
	int n, t, flag=0;
	if(start==NULL)
	{
		printf("\n Insertion after a target node is not possible");
		return NULL;
	}
	printf("\n Enter target node value = ");
	scanf("%d", &t);
	
	while(fpt != NULL)
	{
		if(fpt->x == t)
		{
			printf("\n Target node value found. Enter node value to insert = ");
			scanf("%d", &n);
			flag = 1;
			break;
		}
		else
		{
			fpt = fpt->next;
		}
	}
	if(flag==0)
	{
		printf("\n Target node value not found ");
		return start;
	}
	ptr = (node *)malloc(sizeof(node));
	if(fpt->next==NULL)
	{
		ptr->x=n;
		fpt->next=ptr;
		ptr->prev=fpt;
		ptr->next=NULL;
		return start;
	}
	ptr->x=n;
	ptr->next=fpt->next;
	fpt->next->prev=ptr;
	fpt->next=ptr;
	ptr->prev=fpt;
	return start; 
	
}

void display(node *start)
{
	node *ptr = start;
	if(start == NULL)
	{
		printf("\n List is Empty! ");
		return;
	}
		
	printf("\n List is : ");
	while(ptr != NULL)
	{
		printf("%d ", ptr->x);
		ptr = ptr->next;
	}
	printf("\n");
	return;
}

int count(node *start)
{
	node *ptr = start;
	int c = 0;
	while(ptr != NULL)
	{
		c++;
		ptr = ptr->next;
	}
	return c;
}

void search(node *start)
{
	node *ptr = start;
	int n, flag=0;
	if(start == NULL)
	{
		return;
	}
		
	printf("\n Enter value of node to search = ");
	scanf("%d", &n);
	
	while(ptr != NULL)
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
	}

	if(flag==1)
	{
		printf("\n Node value %d is found \n", n);
	}
	else if(flag==0)
	{
		printf("\n Node value not found ");
	}
	return;
}
node *delete_front(node *start)
{
	if(start == NULL)
	{
		return NULL;
	}
	node *ptr = start;	
	if(ptr->next != NULL)
	{
		ptr->next->prev=NULL;
	}
	start=ptr->next;
	free(ptr);
	
	printf("\n First node is Deleted \n");
	return start;
}

node *delete_end(node *start)
{
	node *ptr = start;
	if(start == NULL)
	{
		return NULL;
	}
		
	if(ptr->next == NULL)
	{
		free(ptr);
		printf("\n Last node is deleted ");
		return NULL;
	}
	
	while(ptr->next!=NULL)
	{
		ptr = ptr->next;
	}
	ptr->prev->next=NULL;
	free(ptr);
	printf("\n Last node is Deleted \n");
	return start;
}

node *delete_given(node *start)
{
	node *ptr = start;
	int n, flag=0;
	
	if(start == NULL)
	{
		return NULL;
	}
	printf("\n Enter node value that you want to delete = ");
	scanf("%d", &n);
	
	while(ptr != NULL)
	{
		if(ptr->x==n)
		{	flag = 1;
			if(ptr->prev==NULL)
			{
				if(ptr->next!=NULL)
				{
					ptr->next->prev=NULL;
				}
				start=ptr->next;
			}
			
			else if(ptr->next==NULL)
			{
				ptr->prev->next=NULL;
			}
			else
			{
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
			}
			free(ptr);
			break;
		}
		ptr=ptr->next;
	}
	
	if(flag==0)
	{
		printf("\n Target node value is not found ");
	}
	else if(flag==1)
	{
		printf("\n Node value %d is deleted ", n);
	}
	return start;
}
