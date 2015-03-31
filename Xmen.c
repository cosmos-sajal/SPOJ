/*
13805. X-MEN

Problem code: XMEN

Dr. Charles Xavier is trying to check the correlation between the DNA samples of Magneto and Wolverine. Both the DNAs are of length N, and can be described by using all integers between 1 to N exactly once. The correlation between two DNAs is defined as the Longest Common Subsequence of both the DNAs.
Help Dr. Xavier find the correlation between the two DNAs.

Input :

First line of input contains number of Test Cases T.
ach test case starts with an integer N, size of DNA.
Next two lines contains N integers each, first line depicting the sequence of Magneto's DNA and second line depicting Wolverine's DNA.

Output :

For each test case print one integer, the correlation between the two DNAs.

Sample Input :

2
2
1 2
2 1
3
1 2 3
1 3 2
Sample Output :

1
2
Constraints :

1 ≤ T ≤ 10 
1 ≤ N ≤ 100000
*/

#include <stdio.h>

long long int a[100010], b[100010], c[100010];

int modifiedBinarySearch(long long int *arr, long long int num, int len)
{
	int start = 1, end = len, mid;
	int flag = 0;
	while(start <= end)
	{
		mid = (start + end) / 2;
		if(arr[mid] > num && arr[mid - 1] < num)
		{
			flag = 1;
			break;
		}
		if(arr[mid] < num)
			start = mid + 1;
		else if(arr[mid] > num && arr[mid - 1] > num)
			end = mid - 1;	
	}
	if(flag)
		return mid;
	else
		return 0;
}

int lis(int n)
{
	long long int arr[100010];
	int i, len, pos;

	arr[1] = a[1];
	len = 1;
	for(i = 2 ; i <= n ; i++)
	{
		if(a[i] == 0)
			continue;
		if(a[i] < arr[1])
			arr[1] = a[i];
		else if(a[i] > arr[len])
		{
			len++;
			arr[len] = a[i];
		}
		else
		{
			pos = modifiedBinarySearch(arr, a[i], len);
			arr[pos] = a[i];
		}
	}

	return len;
}

int main()
{
	int testCases, n, lcsLength, i;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%d", &n);

		for(i = 1 ; i <= n ; i++)
		{
			scanf("%lld", &a[i]);
			c[a[i]] = i;
		}
		for(i = 1 ; i <= n ; i++)
		{
			scanf("%lld", &b[i]);
			a[i] = c[b[i]];
		}
		lcsLength = lis(n);

		printf("%d\n", lcsLength);
	}

	return 0;
}