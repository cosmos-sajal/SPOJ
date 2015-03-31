/*
130. Rent your airplane and make money

Problem code: RENT

"ABEAS Corp." is a very small company that owns a single airplane. The customers of ABEAS Corp are large airline companies which rent the airplane to accommodate occasional overcapacity.

Customers send renting orders that consist of a time interval and a price that the customer is ready to pay for renting the airplane during the given time period. Orders of all the customers are known in advance. Of course, not all orders can be accommodated and some orders have to be declined. Eugene LAWLER, the Chief Scientific Officer of ABEAS Corp would like to maximize the profit of the company.

You are requested to compute an optimal solution.

Small Example

Consider for instance the case where the company has 4 orders:

Order 1 (start time 0, duration 5, price 10)
Order 2 (start time 3, duration 7, price 8)
Order 3 (start time 5, duration 9, price 7)
Order 4 (start time 6, duration 9, price 8)
The optimal solution consists in declining Order 2 and 3 and the gain is 10+8 = 18.
Note that the solution made of Order 1 and 3 is feasible (the airplane is rented with no interruption from time 0 to time 14) but non-optimal.

Input

The first line of the input contains a number T ≤ 30 that indicates the number of test cases to follow. The first line of each test case contains the number of orders n (n ≤ 10000). In the following n lines the orders are given. Each order is described by 3 integer values: The start time of the order st (0 ≤ st < 1000000), the duration d of the order (0 < d < 1000000), and the price p (0 < p < 100000) the customer is ready to pay for this order.

Output

You are required to compute an optimal solution. For each test case your program has to write the total price paid by the airlines.

Example

Input:
2
4
0 5 10
3 7 14
5 9 7
6 9 8
10 
0 5 6 
2 3 1 
8 5 11 
15 2 1 
15 5 10 
1 4 3 
20 1 1 
20 2 10 
25 2 15 
25 2 11 
Output:
18
52
Warning: large Input/Output data, be careful with certain languages
*/

#include <stdio.h>
#define ll long

struct node
{
	int start, end, profit;
};

int DPArr[2000010];
struct node b[10010];

int max(int a, int b)
{
	int max = a >= b ? a : b;
	return max;
}

void merge(struct node *a, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
  
    while (i <= mid && j <= high) {
        if (a[i].end <= a[j].end)
        {
         	if(a[i].end == a[j].end)
         	{
         		if(a[i].profit >= a[j].profit)
         			b[k++] = a[i++];
         		else
         			b[k++] = a[j++];
         	}
         	else
            	b[k++] = a[i++];
        }
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
  
    while (j <= high)
        b[k++] = a[j++];
  
    k--;
    while (k >= 0) {
        a[low + k] = b[k];
        k--;
    }
}
  
void mergesort(struct node *a, int low, int high)
{
    if (low < high) {
        int m = (high + low)/2;
        mergesort(a, low, m);
        mergesort(a, m + 1, high);
        merge(a, low, m, high);
    }
}

int main()
{
	int i, j, n, testCases;
	int start, duration, profit, maxEnd, temp;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%d", &n);

		maxEnd = -1;
		struct node arr[10010];
		for(i = 0 ; i < n ; i++)
		{
			scanf("%d %d %d", &start, &duration, &profit);
			arr[i].start = start;
			arr[i].end = start + duration;
			arr[i].profit = profit;
			temp = start + duration;
			if(temp > maxEnd)
				maxEnd = temp;
		}

		mergesort(arr, 0, n - 1);
		/*for(i = 0 ; i < n ; i++)
			printf("%d %d %d\n", arr[i].start, arr[i].end, arr[i].profit);
		printf("-------\n");
		*/
		DPArr[0] = 0;
		for(i = 1, j = 0 ; i <= maxEnd ; i++)
		{
			if(i == arr[j].end)
			{
				DPArr[i] = max(DPArr[i - 1], arr[j].profit + DPArr[arr[j].start]);
				j++;
				while(i == arr[j].end)
				{
					DPArr[i] = max(DPArr[i], arr[j].profit + DPArr[arr[j].start]);
					j++;
				}
			}
			else
				DPArr[i] = DPArr[i - 1];
		}

		/*for(i = 0 ; i <= maxEnd ; i++)
			printf("%ld ", DPArr[i]);
		printf("\n");*/

		printf("%d\n", DPArr[maxEnd]);
	}
}