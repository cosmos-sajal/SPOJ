/*
101. Fishmonger

Problem code: FISHER

A fishmonger wants to bring his goods from the port to the market. On his route he has to traverse an area with many tiny city states. Of course he has to pay a toll at each border.

Because he is a good business man, he wants to choose the route in such a way that he has to pay as little money for tolls as possible. On the other hand, he has to be at the market within a certain time, otherwise his fish start to smell.

Input

The first line contains the number of states n and available time t. The first state is the port, the last state is the market. After this line there are n lines with n numbers each, specifying for each state the travel time to the i-th state. This table is terminated with an empty line. The table of the tolls follows in the same format.

n is at least 3 and at most 50. The time available is less than 1000. All numbers are integers.

There are many test cases separated by an empty line. Input terminates with number of states and time equal 0 0.

Output

For each test case your program should print on one line the total amount of tolls followed by the actual travelling time.

Example

Sample input:
4 7
0 5 2 3
5 0 2 3
3 1 0 2
3 3 2 0

0 2 2 7
2 0 1 2
2 2 0 5
7 2 5 0

0 0

Sample output:
6 6
This corresponds to the following situation, the connections are labeled with (time, toll):

URL: http://www.spoj.com/problems/FISHER/
*/

#include <stdio.h>
#define ll long long
#define MAX 9999999999

ll riskArr[110][110], timeArr[110][110], visited[110], n, maxTime, dp[110][110];
ll rsum, tsum, minRisk, minTime;

ll recFun(int pos)
{
	int i;
	ll min, val;
	
	min = MAX;
	if(pos == n - 1)
	{
		if(minRisk > rsum && tsum <= maxTime)
		{
			minRisk = rsum;
			minTime = tsum;
			return minRisk;
		}

		return MAX;
	}
	for(i = 0 ; i < n ; i++)
	{
		if(!visited[i])
		{
			visited[i] = 1;
			rsum += riskArr[pos][i];
			tsum += timeArr[pos][i];
			if(tsum <= maxTime && rsum <= minRisk && rsum <= dp[pos][i])
			{
				val = recFun(i);
				if(val + riskArr[pos][i] < dp[pos][i])
					dp[pos][i] = val + riskArr[pos][i];
				if(min > val + riskArr[pos][i])
					min = val + riskArr[pos][i];
			}

			rsum -= riskArr[pos][i];
			tsum -= timeArr[pos][i];
			visited[i] = 0;
		}
	}

	return min;
}

void calculate()
{
	int i;
	
	visited[0] = 1;
	minRisk = minTime = MAX;
	for(i = 1 ; i < n ; i++)
	{
		rsum = riskArr[0][i];
		tsum = timeArr[0][i];
		visited[i] = 1;
		recFun(i);
		visited[i] = 0;
	}
}

void init()
{
	int i, j;

	for(i = 0 ; i < 110 ; i++)
	{
		visited[i] = 0;
		for(j = 0 ; j < 110 ; j++)
			dp[i][j] = MAX;
	}
}

int main()
{
	int i, j;

	while(1)
	{
		scanf("%lld %lld", &n, &maxTime);
		if(!n && !maxTime)
			break;
		init();
		for(i = 0 ; i < n ; i++)
			for(j = 0 ; j < n ; j++)
				scanf("%lld", &timeArr[i][j]);
		for(i = 0 ; i < n ; i++)
			for(j = 0 ; j < n ; j++)
				scanf("%lld", &riskArr[i][j]);
		calculate();

		if(minRisk == MAX)
			printf("-1\n");
		else
			printf("%lld %lld\n", minRisk, minTime);

	}

	return 0;
}