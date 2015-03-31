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
#include <deque>
#define SIZE 1000010

using namespace std;

int main()
{
	int n, i, k;
	int arr[SIZE];
	deque <int> q;

	scanf("%d", &n);
	for(i = 0 ; i < n ; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &k);

	for(i = 0 ; i < k ;i++)
	{
		while(!q.empty() && arr[i] >= arr[q.back()])
			q.pop_back();
		q.push_back(i);
	}
	if(n > k)
	{
		for(i = k ; i < n ; i++)
		{
			printf("%d ", arr[q.front()]);
			while(!q.empty() && arr[i] >= arr[q.back()])
				q.pop_back();
			while(!q.empty() && i - k >= q.front())
				q.pop_front();
			q.push_back(i);
		}
		printf("%d\n", arr[q.front()]);
	}	
	return 0;
}