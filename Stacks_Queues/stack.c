#include<stdio.h>
#include<stdlib.h>

struct node
{
	int x;
	struct node *next;
}*top;

void push()
{
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
		printf("\n Stack OVERFLOW ");
		return;
	}
	printf("\n Enter element to Push to node = ");
	scanf("%d", &ptr->x);
	ptr->next = top;
	top = ptr;
}

void pop()
{
	struct node *ptr;
	ptr = top;
	if(top == NULL)
	{
		printf("\n Stack is Empty ! ");
		return;
	}
	printf("\n %d is popped ", ptr->x);
	top = top->next;
	free(ptr);
	printf("\n");
}

void peep()
{
	struct node *ptr;
	ptr = top;
	if(top==NULL)
	{
		//printf("\n Stack is Empty ! ");
		return;
	}
	printf("\n Stack is : ");
	while(ptr != NULL)
	{
		printf("\n Element = %d ", ptr->x);
		ptr = ptr->next;
	}
	printf("\n");
}

int main()
{
	int choice;
	printf("\n Stack Program is Starting ----> \n");
	do
	{
		printf("\n --- MAIN MENU --- ");
		printf("\n 1. Push to a NODE\n 2. Pop a NODE\n 3. EXIT  program \n");
		printf("\n Enter your choice (1-3) : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: push();
				peep();
				break;
				
			case 2: pop();
				peep();
				break;
				
			case 3: printf("\n --- Exiting Program--- \n");
				break;
				
			default: printf("\n Invalid Choice ! \n");
				 break;
		}
	}while(choice != 3);
}			 
