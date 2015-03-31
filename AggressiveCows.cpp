/*
297. Aggressive cows

Problem code: AGGRCOW

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ want to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input

t – the number of test cases, then t test cases follows. 
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output

For each test case output one integer: the largest minimum distance.
Example

Input:

1
5 3
1
2
8
4
9
Output:

3
Output details:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8, 
resulting in a minimum distance of 3.
*/

#include <stdio.h>
#include <algorithm>
#define ll long long

ll arr[500010];

int organisingCows(ll diff, ll numOfCows, ll n)
{
	ll i, cowsPlaced = 1, lastPlacedPos = arr[0];
	for(i = 1 ; i < n ; i++)
	{
		if(arr[i] - lastPlacedPos >= diff)
		{
			cowsPlaced++;
			lastPlacedPos = arr[i];
			if(cowsPlaced == numOfCows)
				return 1;
		}
	}

	return 0;
}

ll binarySearch(ll n, ll c)
{
	ll mid, low = arr[0], high = arr[n - 1], val;

	while(low < high)
	{
		mid = (low + high) / 2;
		val = organisingCows(mid, c, n);
		if(val)
			low = mid + 1;
		else
			high = mid; 
	}

	return low - 1;
}

int main()
{
	ll testCases, i, n, c, result;
	scanf("%lld", &testCases);

	while(testCases--)
	{
		scanf("%lld %lld", &n, &c);

		for(i = 0 ; i < n ; i++)
			scanf("%lld", &arr[i]);
		
		std :: sort(arr, arr + n);	
		result = binarySearch(n, c);

		printf("%lld\n", result);
	}

	return 0;
}