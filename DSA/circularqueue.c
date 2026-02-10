//Aim:- To perform circular queue operations using array
//ALGORITHM:
1. Initialization
Read queue size n.
Set:
front = -1
rear = -1
max_size = n
2. ENQUEUE (Insert element)
Check overflow condition:
(rear + 1) % max_size == front
If overflow → print message and return.
Else:
If queue is empty (front == -1):
front = rear = 0
Else:
rear = (rear + 1) % max_size
Insert element at queue[rear].
3. DEQUEUE (Delete element)
Check underflow:
front == -1
If yes → print message.
Else:
Save deleted element = queue[front]
If there was only one element (front == rear):
front = rear = -1
Else:
front = (front + 1) % max_size
Display deleted item.
4. Repeat Process
Ask user whether to continue: "yes" or "no".
//PROGRAM:

#include<stdio.h>
#include<string.h>
int main()
{
	int n,rear,front,max,item,max_size,op;
	char choice[5];
	printf("\n enter the size of queue:\n");
	scanf("%d",&n);
	int queue[n];
	rear=-1;
	front=-1;
	max_size = n;
	do
	{
		printf("\n enter the operation of queue:\n1.enqueue\n2.dequeue\n");
	    scanf("%d",&op);
	    switch(op)
	    {
	    	case 1:
	    		{
	    			if((rear+1)%max_size==front)
	    			{
	    				printf("\n queue overflow\n");
	    				return 0;
					}
					else
					{
					if(front==-1)
						{
							front=0;
							rear=0;
								}
						else
						{
							rear=(rear+1)%max_size;
						}
					}
					printf("enter the item:\n");
					scanf("%d",&queue[rear]);
                    printf("\n entered item:%d\n rear value: %d\n",queue[rear],rear);
					break;
				}
			case 2:
				{
					if(front==-1)
					{
						printf("\nqueue is underflow\n");
						break;
					}
					else
					{
						item=queue[front];
						if(front==rear)
						{
							front=-1;
							rear=-1;
						}
						else
						{
							front=(front+1)%max_size;
						}
					}
					printf("\ndeleted item=%d\n front value: %d",item,front);
					break;
				}
			default:
				{
					printf("invalid operation");
					return 0;
				}
		}
		printf("\n enter your choice to repeat or not yes or no:\n");
		scanf("%s",choice);
	}
	while(strcmp(choice,"no"));
}
