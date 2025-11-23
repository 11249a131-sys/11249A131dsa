//Aim:
To convert an infix expression to postfix expression using stack operation.

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

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int top = -1;
int max;
char *stack;
void push(char item)
{
    if (top == max - 1)
    {
        printf("Stack overflow!\n");
    }
    else
    {
        stack[++top] = item;
    }
}
char pop()
{
    if (top == -1)
    {
        printf("Stack underflow!\n");
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}
char peek()
{
    if (top == -1)
        return '\0';
    else
        return stack[top];
}
int getPrecedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}
int main()
{
    printf("Enter maximum size of infix expression: ");
    scanf("%d", &max);
    stack = (char *)malloc(max * sizeof(char));
    char infix[max], postfix[max];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    int i = 0, j = 0;
    char c, temp;
    while ((c = infix[i++]) != '\0')
    {
        if (isalnum(c))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (peek() != '(' && peek() != '\0')
            {
                postfix[j++] = pop();
            }
            pop(); 
        }
        else 
        {
            while (getPrecedence(c) <= getPrecedence(peek()) && peek() != '\0')
            {
                postfix[j++] = pop();
            }
            push(c);
        }
    }
    while (peek() != '\0')
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
    free(stack);
    return 0;

}
