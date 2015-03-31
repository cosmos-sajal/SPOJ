/*
15259. Large Knapsack

Problem code: LKS

The knapsack problem or rucksack problem is a problem in combinatorial optimization: Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible. It derives its name from the problem faced by someone who is constrained by a fixed-size knapsack and must fill it with the most valuable items.
Just implement 0/1 Knapsack.

Input

First line contains two integers K and N, where K in the maximum knapsack size and N is the number of items. N lines follow where ith line describes ith item in the form vi and wi where vi is the value and wi is the weight of ith item.

Output

Output a single number - maximum value of knapsack. (All operations and the answer are guaranteed to fit in signed 32-bit integer.)

Time limit changed to 2s on 02.07.11.

Example

Input:
10 3
7 3
8 8
4 6

4 Output:
11

Constraints:
K <= 2000000
N <= 500
Vi <= 10^7
Wi <= 10^7
*/

#include <stdio.h>
#define ll int

ll val[510], weight[510], knapsackDP[2][2000010];

ll max(ll a, ll b)
{
	ll retVal = (a >= b) ? a : b;
	return retVal; 
}

void DP(ll k, ll n)
{
	ll i, j;

	for(i = 0 ; i <= k ; i++)
		knapsackDP[0][i] = 0;

	for(i = 1 ; i <= n ; i++)
	{
		if(i % 2) // odd
		{
			for(j = 0 ; j <= k ; j++)
			{
				if(j == 0)
					knapsackDP[1][j] = 0;
				else if(weight[i - 1] <= j)
					knapsackDP[1][j] = max(knapsackDP[0][j], knapsackDP[0][j - weight[i - 1]] + val[i - 1]);
				else
					knapsackDP[1][j] = knapsackDP[0][j];
			}
		}
		else //even
		{
			for(j = 0 ; j <= k ; j++)
			{
				if(j == 0)
					knapsackDP[0][j] = 0;
				else if(weight[i - 1] <= j)
					knapsackDP[0][j] = max(knapsackDP[1][j], knapsackDP[1][j - weight[i - 1]] + val[i - 1]);
				else
					knapsackDP[0][j] = knapsackDP[1][j];
			}
		}
	}
}

int main()
{
	ll i, k, n;

	scanf("%d %d", &k, &n);

	for(i = 0 ; i < n ; i++)
		scanf("%d %d", &val[i], &weight[i]);

	DP(k, n);

	if(n % 2) // odd
		printf("%d\n", knapsackDP[1][k]);
	else //even
		printf("%d\n", knapsackDP[0][k]);

	return 0;
}