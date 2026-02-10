//AIM: To find the required element in Binary Search*/
//ALGORITHM:
Step 1: Start
Step 2: Input the number of elements n
Step 3: Input the sorted array elements A[0] to A[n-1]
Step 4: Input the element to search, called key
Step 5: Initialize:
  low = 0
  high = n - 1
Step 6: Repeat Steps 7–10 while low <= high
Step 7: Calculate mid = (low + high) / 2
Step 8: If A[mid] == key, print "Element found at position mid" and go to Step 11
Step 9: If A[mid] < key, set low = mid + 1
Step 10: Else, set high = mid - 1
Step 11: If low > high, print "Element not found"
Step 12: Stop
//PROGRAM:
#include <stdio.h>
int main()
{
    int i, n, low, high, mid, a[10], key;
    //user to enter the number of elements in the array
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    // user to enter the elements in sorted order
    printf("Enter the elements in sorted order:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
      printf("Enter the element to be searched:\n");
    scanf("%d", &key);
     low = 0; //lower bound of the search range
    high = n - 1;// upper bound of the search range
     while (low <= high)
    {
        mid = (low + high) / 2;
         if (key == a[mid])
        {
            printf("Successful search: element found at position %d\n", mid + 1);
            return 0;
        }
        else if (key < a[mid])
        {
            high = mid - 1;
        }
        else
        {
        low = mid + 1;
        }
    }
    printf("Element not found\n");
    return 0;
}
