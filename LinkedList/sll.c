#include<stdio.h>
#include<stdlib.h>
struct node
{
	int x;
	struct node *next;
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
	node *start=NULL;
	do{
        printf("\n MAIN MENU: ");
        printf("\n 1)Insert a Node\n 2)Delete a Node\n 3)Searching a Node\n 4)Count number of nodes\n 5)Display\n 6)Exit");
        printf("\n Enter your choice (1-6) :");
        scanf("%d",&n);

	switch(n)
	{
		case 1:printf("\n INSERT MENU: \n 1)Insert at beginning\n 2)Insert at End\n 3)Insert before a node");
		       printf("\n 4)Insert after a node");
		       printf("\n Enter your choice (1-4) :");
		       scanf("%d",&c);

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
		       	    default: printf("\n Invalid option");
			   }
			   break;

	    case 2:printf("\n DELETE MENU: \n 1)Deletion from start\n 2)Deletion from End\n 3)Deletion of a target node");
	           printf("\n Enter your choice (1-3) :");
	           scanf("%d",&c);

	           switch(c)
	           {
	           	    case 1: start = delete_front(start);
                            break;
	           	    case 2: start = delete_end(start);
                            break;
	           	    case 3: start = delete_given(start);
                            break;
	           	    default: printf("\n Invalid option");
			   }
			   break;

		case 3: search(start);
                break;

		case 4: printf("\n Number of node=%d",count(start));
		        break;

		case 5: display(start);
                break;

		case 6: printf("\n ---Program terminated--- \n");
                break;

		default: printf("\n Invalid Choice ");
	}

   }while(n!=6);

    return 0;
}

node *insert_front(node *start) // Insert a node in front of LinkedList
{
	node *ptr;
	int n;
	ptr = (node *)malloc(sizeof(node));
	printf("\n Enter node value = ");
	scanf("%d", &n);

	if(start == NULL)
	{
		ptr->x = n;
		start = ptr;
		ptr->next = NULL;
		return start;
	}
	ptr->x = n;
	ptr->next = start;
	start = ptr;
	return start;
}

node *insert_end(node *start) // Insert a node at the end of LinkedList
{
	node *ptr, *fpt = start;
	int n;
	ptr = (node *)malloc(sizeof(node));
	printf("\n Enter node value = ");
	scanf("%d",&n);

	if(start == NULL)
	{
		ptr->x = n;
		start = ptr;
		ptr->next = NULL;
		return start;
	}

	while(fpt->next != NULL)
	{
	    fpt = fpt->next;
	}

	ptr->x = n;
	fpt->next = ptr;
	ptr->next = NULL;
	return start;
}

node *insert_before(node *start) // Insert a node before a target node value of LinkedList
{
	node *fpt = start, *ptr, *p = start;
	int n, t, flag = 0;

	if(start == NULL)
	{
		printf("\n List is Empty! Insertion before a target node is not possible");
		return NULL;
	}

	printf("\n Enter target node value = ");
	scanf("%d", &t);

	while(fpt != NULL)
	{
		if(fpt->x == t)
		{
			printf("\n Target node found. Enter node value = ");
			scanf("%d", &n);
			flag = 1;
			break;
		}
		else
		{
			p = fpt;
		    fpt = fpt->next;
		}
	}
	if(flag == 0)
	{
		printf("\n Target node Not found");
		return start;
	}

	ptr = (node *)malloc(sizeof(node));
	if(p == start)
	{
		ptr->x = n;
		ptr->next = p;
		start = ptr;
		return start;
	}

	ptr->x = n;
	ptr->next = p->next;
	p->next = ptr;
	return start;
}

node *insert_after(node *start) // Insert a node after a target node value of LinkedList
{
	node *ptr, *fpt = start, *p;
	int n, t, flag = 0;
	if(start == NULL)
	{
		printf("\n List is Empty! Insertion after a target is not possible");
		return NULL;
	}

	printf("\n Enter target node value = ");
	scanf("%d", &t);

	while(fpt != NULL)
	{
		if(fpt->x == t)
		{
			printf("\n Target node found. Enter node value = ");
			scanf("%d", &n);
			flag = 1;
			break;
		}
		else
        {
            fpt = fpt->next;
        }
	}
	if(flag == 0)
	{
		printf("\n Target node not found");
		return start;
	}

	ptr = (node *)malloc(sizeof(node));
	if(fpt->next == NULL)
	{
		ptr->x = n;
		fpt->next = ptr;
		ptr->next = NULL;
		return start;
	}

	ptr->x = n;
	ptr->next = fpt->next;
	fpt->next = ptr;
	return start;
}

void display(node *start) // Display the LinkedList
{
	node *ptr = start;
	if(start == NULL)
	{
		printf("\n List is Empty");
		return;
	}
	printf("\n List is : ");
	while(ptr != NULL)
	{
		printf("%d ", ptr->x);
		ptr = ptr->next;
	}
	return ;
}

int count(node *start) // Count the number of node of Linkedlist
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

void search(node *start) // Searching in the LinkedList
{
	node *ptr = start;
	int n, flag = 0;
	if(start == NULL)
	{
		printf("\n List is empty");
		return;
	}

    printf("\n Enter searching node value = ");
	scanf("%d", &n);

	while(ptr != NULL)
	{
		if(ptr->x == n)
		{
			flag = 1;
			break;
		}
		else
        {
            ptr = ptr->next;
        }
	}
	if(flag == 1)
	{
	    printf("\n %d node is found",n);
	}
	else if(flag == 0)
	{
	    printf("\n Node not found");
	}
	return ;
}

node *delete_front(node *start) // Deleting from the front of LinkedList
{
	if(start == NULL)
	{
		printf("\n List is empty");
		return NULL;
	}
	node *ptr = start;
	start = ptr->next;
	free(ptr);
	printf("\n First node is deleted");
	return start;
}

node *delete_end(node *start) // Deleting from the end of LinkedList
{
	node *fpt, *ptr = start;
	if(start == NULL)
	{
		printf("\n List is empty");
		return NULL;
	}
	if(ptr->next == NULL)
	{
		free(ptr);
		return NULL;
	}
	while(ptr->next != NULL)
	{
		fpt = ptr;
		ptr = ptr->next;
	}
	fpt->next = NULL;
	free(ptr);
	printf("\n Last node is deleted");
	return start;
}

node *delete_given(node *start) // Deleting a target node of LinkedList
{
	node *fpt = start, *ptr = start;

	int n, flag = 0;

	if(start == NULL)
	{
		printf("\n List is empty");
		return NULL;
	}

	printf("\n Enter node that you want to delete = ");
	scanf("%d", &n);

	while(ptr != NULL)
	{
		if(ptr->x == n)
		{
			flag = 1;
			if(fpt == start)

                start = ptr->next;

            else if(ptr->next == NULL)

			    fpt->next = NULL;

			else

			    fpt->next = ptr->next;

			free(ptr);
			break;
		}
		fpt = ptr;
		ptr = ptr->next;
	}
	if(flag == 0)

	    printf("\n Target node is not found");

	else if(flag == 1)

	    printf("\n %d node is deleted",n);

	return start;
}
