/*
Coin change

Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.

For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

1) Optimal Substructure
To count total number solutions, we can divide all set solutions in two sets.
1) Solutions that do not contain mth coin (or Sm).
2) Solutions that contain at least one Sm.
Let count(S[], m, n) be the function to count the number of solutions, then it can be written as sum of count(S[], m-1, n) and count(S[], m, n-Sm).

Therefore, the problem has optimal substructure property as the problem can be solved using solutions to subproblems.

2) Overlapping Subproblems
Following is a simple recursive implementation of the Coin Change problem. The implementation simply follows the recursive structure mentioned above.
*/

#include <stdio.h>
#include <malloc.h>

int **dp;
//int dp[1000][1000];


void init(int *arr, int m, int n)
{
	int i, j;	
	dp = (int**)malloc(sizeof(int*) * (n + 1));
	
	for(i = 0 ; i < n + 1 ; i++)
		dp[i] = (int*)malloc(sizeof(int) * m);
	for(i = 0 ; i < m ; i++)
		dp[0][i] = 1;
	for(i = 1 ; i < n + 1 ; i++)
		for(j = 0 ; j < m ; j++)
			dp[i][j] = -1;
}

void deallocator(int m, int n)
{
	int i;

	for(i = 0 ; i < n + 1 ; i++)
		free(dp[i]);
	free(dp);
}

int recFun(int *arr, int m, int n)
{
	int x, y;

	if(n == 0)
		return 1;
	if(n < 0)
		return 0;
	//if(n > 0 && m < 0)
	//	return 0;
	if(m == 0 && n > 0)
	{
		if(n % arr[0] == 0)
			return 1;
		else
			return 0;
	}
	
	if(dp[m - 1][n] == -1)
	{
		x = recFun(arr, m - 1, n);
		dp[m - 1][n] = x;
	}
	else
		x = dp[m - 1][n];
	if(dp[m][n - arr[m - 1]] == -1)
	{
		y = recFun(arr, m, n - arr[m - 1]);
		dp[m][n - arr[m - 1]] = y;
	}
	else
		y = dp[m][n - arr[m - 1]];
	
	return x + y;
	//return recFun(arr, m - 1, n) + recFun(arr, m, n - arr[m - 1]);
}

int main()
{
	int i, m, n, testCases;
	int arr[100];

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%d %d", &m, &n);
		for(i = 0 ; i < m ; i++)
			scanf("%d", &arr[i]);

		init(arr, m, n);
		printf("%d\n", recFun(arr, m - 1, n));
		deallocator(m, n);
	}

	return 0;
}