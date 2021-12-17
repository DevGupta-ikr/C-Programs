#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node node;

node *front;
node *rear;
void insert();
void del();
void display();

int main()
{
	int choice;
	printf("\n Queue Program is Starting ----> \n ");
	while(choice != 3)
	{
		printf("\n --- MAIN MENU --- \n ");
		printf("\n 1. Insert an Element\n 2. Delete an Element\n 3. Exit Program \n");
		printf("\n Enter your choice (1-3) : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: insert();
				display();
				break;
				
			case 2: del();
				display();
				break;
				
			case 3: exit(0);
			
			default: printf("\n Invalid Choice ! \n ");
		}
	}
}

void insert()
{
	struct node *ptr;
	int item;
	ptr = (struct node *)malloc(sizeof(struct node));
	
	if(ptr == NULL)
	{
		printf("\n OVERFLOW \n");
		return;
	}
	else
	{
		printf("\n Enter value = ");
		scanf("%d", &item);
		ptr->data = item;
		if(front == NULL)
		{
			front = ptr;
			rear = ptr;
			front->next= NULL;
			rear->next = NULL;
		}
		else
		{
			rear->next = ptr;
			rear = ptr;
			rear->next = NULL;
		}
	}
}

void del()
{
	struct node *ptr;
	if(front == NULL)
	{
		printf("\n UNDERFLOW \n ");
		return;
	}
	else
	{
		printf("\n %d is Deleted", front->data);
		ptr = front;
		front = front->next;
		free(ptr);
	}
}

void display()
{
	struct node *ptr; 
	ptr = front;
	if(front==NULL)
	{
		printf("\n Queue is Empty ! ");
	}
	else
	{
		printf("\n Queue : \n ");
		while(ptr != NULL)
		{
			printf(" %d ", ptr->data);
			ptr = ptr->next;
		}
	}
	printf("\n");
}
