/*
11372. Blueberries

Problem code: RPLB

Teresa picked up enough strawberries, now she wants to pick blueberries from the magical blueberry bush from Rainbowland.

 

Knowing her previous experience with the strawberries, Teresa wants to pick up the blueberries in a way that she may not exceed the limit proposed.

 

When picking the blueberries, she noticed that if she pick from the bush i, she couldn't pick the blueberries at the bush i+1 (some sort of magic in rainbowland).

 

Worried about this, Teresa wants to know the maximum blueberries she can pick, given the number of bushes and the number of blueberries in each bush.

 

INPUT:

Will contain an integer T, then, T cases will follow, each case starts with a number N and K, being N the number of bushes and K the number of blueberries Teresa will pick as maximum, the next line contains N integers, each one representing the blueberries there is on the i-th bush.

 

OUTPUT:

You will output for each test case the string: “Scenario #i: “ where i is the test case you are analyzing, then, an integer denoting the maximum number of blueberries you can grab.

 

INPUT

OUTPUT

2

5 100

50 10 20 30 40

 

5 87

21 45 30 12 14

Scenario #1: 90

Scenario #2: 65


 

“Blank line between test cases for clarification and separation”

Output explanation (first scenario)

Teresa picks the 1st blueberry bush (50), she cannot pick the 2nd, she decides not to pick until the 5th one where she picks the “40” blueberry, she could pick the 3rd bush, but she would exceed the limit (100).

Output explanation (second scenario)

Teresa picks the 1st, the 3rd and the 5th bush, total of (21+30+14 = 65) blueberries

 

CONSTRAINTS:

1<=N<=1000; 1<=K<=1000
*/

#include <stdio.h>

int arr[1010], DP[1010][1010];

int max(int a, int b)
{
	int max = a >= b ? a : b;
	return max;
}

int knapsack(int k, int n)
{
	int i, j;

	for(i = 0 ; i <= k ; i++)
		DP[0][i] = 0;
	for(i = 0 ; i <= k ; i++)
	{
		if(i < arr[0])
			DP[1][i] = 0;
		else
			DP[1][i] = arr[0];
	}
	for(i = 2 ; i <= n ; i++)
	{
		for(j = 0 ; j <= k ; j++)
		{
			if(j < arr[i - 1])
				DP[i][j] = max(DP[i - 1][j], DP[i - 2][j]);
			else
				DP[i][j] = max(DP[i - 1][j], arr[i - 1] + DP[i - 2][j - arr[i - 1]]);
		}
	}

	return DP[n][k];
}

int main()
{
	int i, n, k, testCases, testCaseNo = 1;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%d %d", &n, &k);
		for(i = 0 ; i < n ; i++)
			scanf("%d", &arr[i]);

		printf("Scenario #%d: %d\n", testCaseNo++, knapsack(k, n));
	}

	return 0;
}