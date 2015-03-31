/*
By Cosmos

10394. Buying Apples!

Problem code: ABA12C

Harish went to a supermarket to buy exactly ‘k’ kilograms apples for his ‘n’ friends. The supermarket was really weird. The pricing of items was very different. He went to the Apples section and enquired about the prices. The salesman gave him a card in which he found that the prices of apples were not per kg. The apples were packed into covers, each containing ‘x’ kg of apples, x > 0 and ‘x’ is an integer. An ‘x’ kg packet would be valued at ‘y’ rupees. So, the placard contained a table with an entry ‘y’ denoting the price of an ‘x’ kg packet. If ‘y’ is -1 it means that the corresponding packet is not available. Now as apples are available only in packets, he decides to buy atmost ‘n’ packets for his ‘n’ friends i.e he will not buy more than n packets of apples.

Harish likes his friends a lot and so he does not want to disappoint his friends. So now, he will tell you how many friends he has and you have to tell him the minimum amount of money he has to spend for his friends.

Input

The first line of input will contain the number of test cases, C.

Each test case will contain two lines.

The first line containing N and K, the number of friends he has and the amount of Apples in kilograms which he should buy.

The second line contains K space separated integers in which the ith integer specifies the price of a ‘i’kg apple packet. A value of -1 denotes that the corresponding packet is unavailable.

0 < N <= 100

0 < K <= 100

0 < price <= 1000

Output

The output for each test case should be a single line containing the minimum amount of money he has to spend for his friends. Print -1 if it is not possible for him to satisfy his friends.

Sample I/O:

Input:

2

3 5

-1 -1 4 5 -1

5 5

1 2 3 4 5

Output:

-1

5

Explanation of test cases:

1) As there are only 3 and 4kg packets in the shop, he will not be able to satisfy his friends as he would not be able to buy exactly 5kg of apples.

2) He can buy five 1kg packet as he has to buy 5 kg. So the min money he should spend is 5.
*/

#include <stdio.h>
#include <limits.h>
#include <math.h>

int end, minCost, noOfFriends;
int costArr[110], DP[110][110];

void init(int n, int k)
{
	int i, j;

	minCost = INT_MAX;
	end = k;
	noOfFriends = n;
	for(i = 0 ; i < k ; i++)
		for(j = 0 ; j <= k ; j++)
			DP[i][j] = INT_MAX;
}

int recFun(int i, int n, int weightLeft, int cost)
{
	int val1, val2;
	if(n < 0)
		return 0;
	if(i == end || weightLeft < 0)
		return 0;
	if(weightLeft == 0)
	{
		if(minCost > cost)
			minCost = cost;
		return minCost;
	}
	if(costArr[i] != -1)
	{
		val1 = val2 = INT_MAX;
		if(cost + costArr[i] <= minCost && weightLeft - (i + 1) >= 0)
		{
			DP[i][weightLeft - (i + 1)] = fmin(DP[i][weightLeft - (i + 1)], recFun(i, n - 1, weightLeft - (i + 1), cost + costArr[i]));
			val1 = DP[i][weightLeft- (i + 1)];
		}
		if(cost <= minCost && i + 1 < end)
		{
			DP[i + 1][weightLeft] = fmin(DP[i + 1][weightLeft], recFun(i + 1, n, weightLeft, cost));
			val2 = DP[i + 1][weightLeft];
		}
		DP[i][weightLeft] = fmin(DP[i][weightLeft], fmin(val1, val2));

		return DP[i][weightLeft];
	}
	else
	{
		val1 = INT_MAX;
		if(cost <= minCost && i + 1 < end)
		{
			DP[i + 1][weightLeft] = fmin(DP[i + 1][weightLeft], recFun(i + 1, n, weightLeft, cost));
			val1 = DP[i + 1][weightLeft];
		}
		DP[i][weightLeft] = fmin(DP[i][weightLeft], val1);

		return DP[i][weightLeft];
	}

	return INT_MAX;
}

void calculate(int n, int k)
{
	recFun(0, n, k, 0);
}

int main()
{
	int i, n, k, testcases;

	scanf("%d", &testcases);

	while(testcases--)
	{
		scanf("%d %d", &n, &k);
		for(i = 0 ; i < k ; i++)
			scanf("%d", &costArr[i]);

		init(n, k);
		calculate(n, k);
		if(minCost != INT_MAX)
			printf("%d\n", minCost);
		else
			printf("-1\n");
	}

	return 0;
}