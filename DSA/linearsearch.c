//AIM:
To write a C program to search for a given element in an array using the Linear Search algorithm and display its position if found.
//ALGORITHM:
Step 1: Start
Step 2: Input the size of the infix expression MAX
Step 3: Read the infix expression into a character array
Step 4: Initialize an empty stack and set TOP = -1
Step 5: Scan the infix expression from left to right
Step 6: For each character c:
If c is an operand, add it to the postfix expression
If c is '(', push it onto the stack
If c is ')', pop and add all operators until '(' is encountered
If c is an operator:
While the precedence of the top of the stack is greater than or equal to precedence of c, pop and add it to postfix
Push the current operator onto the stack
Step 7: After scanning, pop all remaining operators from the stack and add them to postfix
Step 8: Append '\0' to postfix to mark end
Step 9: Display the postfix expression
Step 10: Stop
//PROGRAM:
#include<stdio.h>
int main()
{
    int i, n, key, found = 0;
    printf("enter the size of the array:");
    scanf("%d", &n);
    int a[n];
    printf("enter %d elements:", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the element to be searched:");
    scanf("%d", &key);
    for(int i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            printf("element found at index :%d", i);
            found = 1;
            break;
        }
    }
    if(found == 0)
    {
        printf("Invalid Input");
    }
    return 0;
}
