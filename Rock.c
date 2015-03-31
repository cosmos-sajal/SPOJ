/*
154. Sweet and Sour Rock

Problem code: ROCK

A manufacturer of sweets has started production of a new type of sweet called rock. Rock comes in sticks composed of one-centimetre-long segments, some of which are sweet, and the rest are sour. Before sale, the rock is broken up into smaller pieces by splitting it at the connections of some segments.

Today's children are very particular about what they eat, and they will only buy a piece of rock if it contains more sweet segments than sour ones. Try to determine the total length of rock which can be sold after breaking up the rock in the best possible way.

Input

The input begins with the integer t, the number of test cases. Then t test cases follow.

For each test case, the first line of input contains one integer N - the length of the stick in centimetres (1<=N<=200). The next line is a sequence of N characters '0' or '1', describing the segments of the stick from the left end to the right end ('0' denotes a sour segment, '1' - a sweet one).

Output

For each test case output a line with a single integer: the total length of rock that can be sold after breaking up the rock in the best possible way.

Example

Sample input:
2
15
100110001010001
16
0010111101100000

Sample output:
9
13
*/

#include <stdio.h>
#include <string.h>

int dp[210][210], memo[210][210];

/*
void init(int n)
{
	int i, j;

	for(i = 0 ; i <= n ; i++)
		for(j = 0 ; j <= n ; j++)
			dp[i][j] = 0;
}
*/
/*
void print(int n)
{
	int i, j;

	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < n ; j++)
			printf("%d\t", dp[i][j]);
		printf("\n");
	}
}
*/

int solve(int start, int end)
{
	int i, temp, retVal;

	if(start > end)
		return 0;

	retVal = memo[start][end];
	if(retVal == -1)
	{	
		for(i = start ; i <= end ; i++)
		{
			temp = dp[start][i] + solve(i + 1, end);
			if(temp > retVal)
				retVal = temp;
		}
		memo[start][end] = retVal;
	}
		
	return retVal;
}


int main()
{
	int i, j, k, n, diff, testCases;
	char str[210];

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%d %s", &n, str);

		//init(n);
		memset(dp, 0, sizeof(dp));
		for(i = 0 ; i < n ; i++)
		{
			for(j = i ; j < n ; j++)
			{
				for(k = j, diff = 0 ; k >= i ; k--)
				{
					if(str[k] == '1')
						diff++;
					else
						diff--;
					if(diff > 0)
						dp[i][j] = j - k + 1;
				}
			}
		}

		memset(memo, -1, sizeof(memo));
		printf("%d\n", solve(0, n - 1));
	}

	return 0;
}