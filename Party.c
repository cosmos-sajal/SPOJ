/*
97. Party Schedule

Problem code: PARTY

You just received another bill which you cannot pay because you lack the money.
Unfortunately, this is not the first time to happen, and now you decide to investigate the cause of your constant monetary shortness. The reason is quite obvious: the lion's share of your money routinely disappears at the entrance of party localities. 

You make up your mind to solve the problem where it arises, namely at the parties themselves. You introduce a limit for your party budget and try to have the most possible fun with regard to this limit. 

You inquire beforehand about the entrance fee to each party and estimate how much fun you might have there. The list is readily compiled, but how do you actually pick the parties that give you the most fun and do not exceed your budget? 

Write a program which finds this optimal set of parties that offer the most fun. Keep in mind that your budget need not necessarily be reached exactly. Achieve the highest possible fun level, and do not spend more money than is absolutely necessary.

Input

The first line of the input specifies your party budget and the number n of parties. 

The following n lines contain two numbers each. The first number indicates the entrance fee of each party. Parties cost between 5 and 25 francs. The second number indicates the amount of fun of each party, given as an integer number ranging from 0 to 10. 

The budget will not exceed 500 and there will be at most 100 parties. All numbers are separated by a single space. 

There are many test cases. Input ends with 0 0.

Output

For each test case your program must output the sum of the entrance fees and the sum of all fun values of an optimal solution. Both numbers must be separated by a single space.

Example

Sample input:


50 10
12 3
15 8
16 9
16 6
10 2
21 9
18 4
12 4
17 8
18 9 

50 10
13 8
19 10
16 8
12 9
10 2
12 8
13 5
15 5
11 7
16 2

0 0

Sample output:


49 26
48 32
*/

#include <stdio.h>

struct node
{
	int fee, fun;
};

int DP[2][510], actualSpent[2][510];
struct node arr[110];

int min(int a, int b)
{
	int min = a <= b ? a : b;
	return min;
}

void knapsack(int budget, int noOfParties)
{
	int i, j;

	for(i = 0 ; i <= budget ; i++)
		DP[0][i] = actualSpent[0][i] = 0;
	for(i = 1 ; i <= noOfParties ; i++)
	{
		if(i % 2) //odd
		{
			for(j = 0 ; j <= budget ; j++)
			{
				if(j == 0)
					DP[1][j] = actualSpent[1][j] = 0;
				else if(arr[i - 1].fee <= j)
				{
					if(DP[0][j] <= DP[0][j - arr[i - 1].fee] + arr[i - 1].fun)
					{
						DP[1][j] = DP[0][j - arr[i - 1].fee] + arr[i - 1].fun;
						if(DP[0][j] == DP[0][j - arr[i - 1].fee] + arr[i - 1].fun)
							actualSpent[1][j] = min(actualSpent[0][j - arr[i - 1].fee] + arr[i - 1].fee, actualSpent[0][j]);
						else
							actualSpent[1][j] = actualSpent[0][j - arr[i - 1].fee] + arr[i - 1].fee;
					}
					else
					{
						DP[1][j] = DP[0][j];
						actualSpent[1][j] = actualSpent[0][j];
					}

				}
				else
				{
					DP[1][j] = DP[0][j];
					actualSpent[1][j] = actualSpent[0][j];
				}
			}
		}
		else //even
		{
			for(j = 0 ; j <= budget ; j++)
			{
				if(j == 0)
					DP[0][j] = actualSpent[0][j] = 0;
				else if(arr[i - 1].fee <= j)
				{
					if(DP[1][j] <= DP[1][j - arr[i - 1].fee] + arr[i - 1].fun)
					{
						DP[0][j] = DP[1][j - arr[i - 1].fee] + arr[i - 1].fun;
						if(DP[1][j] == DP[1][j - arr[i - 1].fee] + arr[i - 1].fun)
							actualSpent[0][j] = min(actualSpent[1][j - arr[i - 1].fee] + arr[i - 1].fee, actualSpent[1][j]);
						else
							actualSpent[0][j] = actualSpent[1][j - arr[i - 1].fee] + arr[i - 1].fee;
					}
					else
					{
						DP[0][j] = DP[1][j];
						actualSpent[0][j] = actualSpent[1][j];
					}

				}
				else
				{
					DP[0][j] = DP[1][j];
					actualSpent[0][j] = actualSpent[1][j];
				}
			}
		}
	}
}

int main()
{
	int i, budget, noOfParties;

	while(1)
	{
		scanf("%d %d", &budget, &noOfParties);
		for(i = 0 ; i < noOfParties ; i++)
			scanf("%d %d", &arr[i].fee, &arr[i].fun);

		if(!budget && !noOfParties)
			break;
		knapsack(budget, noOfParties);

		if(noOfParties % 2) //odd
			printf("%d %d\n", actualSpent[1][budget], DP[1][budget]);
		else //even
			printf("%d %d\n", actualSpent[0][budget], DP[0][budget]);
	}

	return 0;
}