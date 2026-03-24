#include <stdio.h>
struct Item
{
int profit;
int weight;
float ratio;
};
/* funtion to sort in descending order*/
void sort(struct Item  items[], int n)
{
struct Item temp;
    for (int i = 0; i < n-1; i++)
{
for(int j=0; j<n-i-1; j++)
{
if (items [j].ratio < items [j+1].ratio)
  {
temp=items[j];
items[j]=items[j+1];
items[j+1]=temp;
 }
}
  }
}
int main()
{
int n,capacity;
float totalprofit =0;
printf("enter no of items:");
scanf("%d",&n);
struct Item itm [n];
printf("enter capacity:");
scanf("%d",& capacity);
printf("enter weight and profit details of items:");
for(int i=0;i<n;i++)
{
scanf("%d %d",&itm[i].weight,&itm[i].profit);
itm[i].ratio = (float)itm[i].profit/itm[i].weight;
}
sort (itm,n);
for(int i=0;i<n;i++)
{
itm [i].weight <= capacity;
 if (itm [i].weight <= capacity)
  {
  capacity-=itm[i].weight;
  totalprofit+= itm[i].profit;
 
 }
 else
 {
 
  totalprofit+=(itm[i].ratio*capacity);
  break;
 }
}
printf("totalprofit is %f",totalprofit);
return 0;
}

