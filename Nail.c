/*
661. Nail Them

Problem code: QUEST5

To get to the treasure, Jones must complete one more task. He comes across a table, where there are a number of wooden planks lying along the length of the table. He notices that the width of the table is exactly equal to the width of every plank on it. The planks are so heavy that they cannot be manually moved in any way. Some of these wooden planks are overlapping. Jones has a hammer and the Gods grant him infinite nails. The planks have to be joined to the table with nails such that every plank is connected to the table through at least one nail. The nails are of sufficient length, and have to be hammered vertically into the table. One or more planks can be joined to the table through a single nail provided they have a common overlap. Find out the minimum number of nails he needs to nail all planks to the table.

Planks
Input

The first line of the input is a positive integer t <= 20, denoting the number of tables.
The descriptions of the table follow one after the other.
Table description:
The first line of the description of the kth table contains a positive integer n (n <= 10010), the number of planks on it.
This is followed by n lines containing the description of the planks.
The description of each plank is a pair of integers a and b (0 <= a <= b <= 10000010), denoting the distance of the left end and right end of the plank from the left end of the table.
Output

The output must contain t lines , the kth line corresponding to the kth table. The output on the kth line must be an integer ik, the minimum number of nails required.

Example

Input: 
2 
3 
1 5 
3 5 
2 4 
2 
1 4 
4 5

Output: 
1 
1

URL : http://www.spoj.com/problems/QUEST5/
*/

#include <stdio.h>
#define ll long long

ll startArr[10020], endArr[10020], b[10020], c[10020];

void merge(long long int *a, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
  
    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
        {
            if(a[i] < a[j])
            {
            	b[k] = a[i];
            	c[k] = startArr[i];
            	k++; i++;
            }
            else
            {
            	if(startArr[i] < startArr[j])
            	{
            		b[k] = a[i];
            		c[k] = startArr[i];
            		k++; i++;
            	}
            	else
            	{
            		b[k] = a[j];
            		c[k] = startArr[j];
            		k++; j++;
            	}
            }

        }
        else
        {
            b[k] = a[j];
            c[k] = startArr[j];
            k++; j++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        c[k] = startArr[i];
        k++; i++;
    }
  
    while (j <= high)
    {
        b[k] = a[j];
        c[k] = startArr[j];
        k++; j++;
    }
  
    k--;
    while (k >= 0) {
        a[low + k] = b[k];
        startArr[low + k] = c[k];
        k--;
    }
}
  
void mergesort(long long int *a, int low, int high)
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
	int testCases, n, i;
	ll lastBeg, lastEnd, count;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%d", &n);

		for(i = 0 ; i < n ; i++)
			scanf("%lld %lld", &startArr[i], &endArr[i]);
		
		mergesort(endArr, 0, n - 1);
		count = 1;
		lastBeg = startArr[0];
		lastEnd = endArr[0];

		for(i = 1 ; i < n ; i++)
		{
			if(startArr[i] > lastEnd)
			{
				count++;
				lastBeg = startArr[i];
				lastEnd = endArr[i];
			}
		}

		printf("%lld\n", count);

	}

	return 0;
}