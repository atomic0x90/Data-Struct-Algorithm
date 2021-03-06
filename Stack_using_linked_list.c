#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node *link;
}Node;

typedef struct Stack
{
	Node *top;
}Stack;

Stack* Create_Stack()
{
	Stack* stack;
	stack = (Stack*)malloc(sizeof(Stack));
	stack->top = NULL;
	return stack;
}
void Push_Stack(Stack *s,int data)
{
	Node *push_node = (Node*)malloc(sizeof(Node));

	push_node->value = data;
	push_node->link = s->top;
	s->top = push_node;
}

int Pop_Stack(Stack *s)
{
	int pop_data;

	if(s->top == NULL)
		return 0;
	Node* pop_node = s->top;
	
	pop_data = pop_node->value;
	s->top = pop_node->link;
	free(pop_node);

	return pop_data;
}

int Search_Number(Stack *s,int data)
{
	if(s->top == NULL)
		return 0;

	Node* search_node = s->top;

	while(1)
	{
		if(search_node->value != data)
		{
			if(search_node -> link == NULL)
				return 0;
			else
				search_node = search_node->link;
		}
		else if(search_node->value == data)
			return search_node->value;
	}
}

void Print_Stack(Stack *s)
{
	if(s->top == NULL)
	{
		printf("\n");
		return;
	}
	Node *temp = s->top;
	while(1)
	{
		printf("%d\n",temp->value);
		if(temp->link == NULL)
			break;
		temp = temp->link;
	}
}

void Initialization_Stack(Stack *s)
{
	s->top = NULL;
}

void Peek_Stack(Stack *s)
{
	if(s->top == NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	printf("Stack top data -> %d\n",s->top->value);

	return;
}

int main()
{
	int num1,num2;
	char answer;

	Stack *stack;
	stack = Create_Stack();
	while(1)
	{
		printf("-------------------------------------------------------------\n");
		printf("\t\t-------------------------\n");
		printf("\t\t\t  Stack\n");
		printf("\t\t-------------------------\n\n");
		
		printf("\t\tPlease select an activity\n");
		printf("\t\t--Please enter a number--\n\n");
		
		printf("\t1.Push Number\t\t2.Pop Number\n");
		printf("\t3.Search Number\t\t4.Print Stack\n");
		printf("\t5.Stack Initialization\t6.Peek Stack\n");
		printf("\t0.Exit Program\n");
		printf("-------------------------------------------------------------\n");

		scanf("%d",&num1);
		getchar();
		
		if(num1 == 1)	//Push Number
		{
			for(;;)
			{
				printf("\nPlease enter a number to push into the Stack\n");
				printf("The range of numbers is a positive integer\n");
			
				scanf("%d",&num2);
				getchar();

				if(num2 < 1)
					printf("Please check the range of numbers ! ! !\n\n");
				else
					break;
			}
			
			Push_Stack(stack,num2);
			printf("Successfully Push ! ! !\n");
		}
		else if(num1 == 2)	//Pop Number
		{

			int check_NULL = Pop_Stack(stack);
			if(check_NULL != 0)
			{
				printf("Successfully pop ! ! !\n");
				printf("Pop result : %d\n",check_NULL);
			}
			else
				printf("Stack is empty...(Not POP)\n");
		}
		else if(num1 == 3)	//Search Number
		{
			printf("\nPlease enter a number to search Stack\n");

			scanf("%d",&num2);
			getchar();

			int check_search;
			check_search = Search_Number(stack,num2);

			if(check_search != 0)
				printf("Successfully searched! (search number = %d)\n",check_search);
			else
				printf("This number does not exist Stack...\n");

		}
		else if(num1 == 4)	//Print Stack
		{
			printf("\nPrint Stack----\ntop\n");
			Print_Stack(stack);
			printf("bottom\n---------------\n\n");
		}
		else if(num1 == 5)	//Stack Initialization
		{
			for(;;)
			{
				printf("Are you sure you want to INITIALIZATION STACK?\n");
				printf("\tPlease answer y/n\n");

				scanf("%c",&answer);
				getchar();

				if(answer == 'y' || answer == 'Y')
				{
					Initialization_Stack(stack);
					printf("Successfully initialized Stack!\n");
					break;
				}
				else if(answer == 'n' || answer == 'N')
				{
					printf("Not initialized Stack\n");
					break;
				}
				else
					printf("Please enter y or n\n\n");
			}
		}
		else if(num1 == 6)	//Peek Stack
		{
			Peek_Stack(stack);
		}
		else if(num1 == 0)	//Exit Program
		{
			for(;;)
			{
				printf("Are you sure you want to EIXT PROGRAM?\n");
				printf("\tPlease answer y/n\n");
				
				scanf("%c",&answer);
				getchar();

				if(answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N')
					break;
				else
					printf("Please enter y or n\n\n");
			}
			if(answer == 'y' || answer == 'Y')
			{
				printf("--------------------------------------------------------\n");
				printf("\t\tThank you for using it ! ! !\n");
				printf("--------------------------------------------------------\n");
				break;
			}
			else
				continue;
		}
		else		//Enter a charater, not number OR out of range
		{
			printf("---------------------------------------------------------\n");
			printf("\tPlease enter a number (non-character)\n");
			printf("\tPlease enter a number in the range (0 ~ 6)\n");
			printf("---------------------------------------------------------\n");
		}

	}
	return 0;
}
