#include<stdio.h>
int main()
{
	int n,i;
	int a =0, b = 1, next;
	printf("enter the number of terms:");
	scanf("%d",&n);
	printf("fibonacci series:\n");
	for(i = 1; i<n; i++)
{
	printf("%d",a);
	next = a + b;
	a = b;
	b = next;
}
return 0;
}
