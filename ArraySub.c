/*
10582. subarrays

Problem code: ARRAYSUB

Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.

Input

the number n denoting number of elements in the array then after a new line we have the numbers of the array

and then k in a new line

n<10^6

k<10^5

1 <= k <=n

and each element of the array is between 0 and 10^6

Output

print the output array

Example

Input:
9
1  2  3  1  4  5  2  3  6
3
Output:
3 3 4 5 5 5 6

*/

#include <stdio.h>
#define SIZE 1000010

int arr[SIZE];

int main()
{
	int n, i, j, k, max, maxPos;

	scanf("%d", &n);
	for(i = 0 ; i < n ; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &k);

	max = arr[0];
	maxPos = 0;
	for(i = 1 ; i < k ; i++)
		if(max < arr[i])
		{
			max = arr[i];
			maxPos = i;
		}
	printf("%d ", max);
	for(i = 1 ; i <= n - k ; i++)
	{
		if(maxPos >= i)
		{
			if(max < arr[i + k - 1])
			{
				max = arr[i + k - 1];
				maxPos = i + k - 1;
			}
			printf("%d ", max);
		}
		else
		{
			max = arr[i];
			maxPos = i;
			for(j = i + 1 ; j < i + k ; j++)
				if(max < arr[j])
				{
					max = arr[j];
					maxPos = j;
				}
			printf("%d ", max);
		}
	}
	printf("\n");

	return 0;
}