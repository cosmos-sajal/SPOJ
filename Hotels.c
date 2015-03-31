/*
9861. Hotels Along the Croatian Coast

Problem code: HOTELS

There are N hotels along the beautiful Adriatic coast. Each hotel has its value in Euros.

Sroljo has won M Euros on the lottery. Now he wants to buy a sequence of consecutive hotels, such that the sum of the values of these consecutive hotels is as great as possible - but not greater than M.

You are to calculate this greatest possible total value.

Input

In the first line of the input there are integers N and M (1 ≤ N ≤ 300 000, 1 ≤ M < 231).

In the next line there are N natural numbers less than 106, representing the hotel values in the order they lie along the coast.

Output

Print the required number (it will be greater than 0 in all of the test data).

Example

input
5 12
2 1 3 4 5
output
12

input
4 9
7 3 5 6
output
8

*/

#include <stdio.h>
#define ll long long
#define MAX 9999999999999

ll arr[300010];

int main()
{
	ll n, m, i, ptr, diff, minDiff, sum;

	scanf("%lld %lld", &n, &m);

	ptr = 0;
	sum = 0;
	minDiff = MAX;
	for(i = 0 ; i < n ; i++)
	{
		scanf("%lld", &arr[i]);
		sum += arr[i];
		diff = m - sum;
		if(diff >= 0 && diff < minDiff)
			minDiff = diff;
		if(diff < 0)
		{
			while(diff < 0)
			{
				sum -= arr[ptr];
				ptr++;
				diff = m - sum;
			}
			if(diff >= 0 && diff < minDiff)
			minDiff = diff;
		}
	}

	printf("%lld\n", m - minDiff);

	return 0;
}