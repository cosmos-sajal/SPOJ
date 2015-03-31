/*
7975. Tri graphs

Problem code: ACPC10D

Here’s a simple graph problem: Find the shortest path from the top-middle vertex to the bottom-middle vertex in a given tri-graph. A tri-graph is an acyclic graph of (N ≥ 2) rows and exactly 3 columns. Unlike regular graphs, the costs in a tri-graph are associated with the vertices rather than the edges.

So, considering the example with N = 4, the cost of going straight down from the top to bottom along the middle vertices is 7 + 13 + 3 + 6 = 29. The layout of the directional edges in the graph are always the same as illustrated in the figure.

Input

Your program will be tested on one or more test cases.
Each test case is specified using N + 1 lines where the first line specifies a single integer (2 ≤ N ≤ 100, 000) denoting the number of rows in the graph. N lines follow, each specifying three integers representing the cost of the vertices on the ith row from left to right. The square of each cost value is less than 1,000,000.
The last case is followed by a line with a single zero.

Output

For each test case, print the following line:
k. n
Where k is the test case number (starting at one,) and n is the least cost to go from the top-middle vertex to the bottom-middle vertex.

Example

Input:
4
13 7 5
7 13 6
14 3 12
15 6 16
0

Output:
1. 22

question url : http://www.spoj.com/problems/ACPC10D/
*/

#include <stdio.h>
#define MAX 999999999999

long long int graphMatrix[100010][3];
long long int helperMatrix[100010][3];
int n;

void recFun(int, int);

void right(int i, int j)
{
	if(i == n - 1 && (j + 1) == 1)
	{
		helperMatrix[i][j + 1] = graphMatrix[i][j + 1];
		return;
	}

	if(helperMatrix[i][j + 1] == MAX)
		recFun(i, j + 1);
}

void down(int i, int j)
{
	if((i + 1) == n - 1 && j == 1)
	{
		helperMatrix[i + 1][j] = graphMatrix[i + 1][j];
		return;
	}

	if(helperMatrix[i + 1][j] == MAX)
		recFun(i + 1, j);	
}

void diagonalRight(int i, int j)
{
	if((i + 1) == n - 1 && (j + 1) == 1)
	{
		helperMatrix[i + 1][j + 1] = graphMatrix[i + 1][j + 1];
		return;
	}

	if(helperMatrix[i + 1][j + 1] == MAX)
		recFun(i + 1, j + 1);
}

void diagonalLeft(int i, int j)
{
	if((i + 1) == n - 1 && (j - 1) == 1)
	{
		helperMatrix[i + 1][j - 1] = graphMatrix[i + 1][j - 1];
		return;
	}

	if(helperMatrix[i + 1][j - 1] == MAX)
		recFun(i + 1, j - 1);
}

void recFun(int i, int j)
{
	long long int temp[4];
	long long int min;
	int k;

	if(j == 0)
	{
		if(i == n - 1)
		{
			right(i, j);
			temp[0] = helperMatrix[i][j + 1] + graphMatrix[i][j];
			if(temp[0] < helperMatrix[i][j])
				helperMatrix[i][j] = temp[0];
		}
		else
		{
			down(i, j);
			diagonalRight(i, j);
			right(i, j);
			temp[0] = helperMatrix[i + 1][j] + graphMatrix[i][j];
			temp[1] = helperMatrix[i + 1][j + 1] + graphMatrix[i][j];
			temp[2] = helperMatrix[i][j + 1] + graphMatrix[i][j];
			min = temp[0];
			for(k = 1 ; k < 3 ; k++)
			{
				if(temp[k] < min)
					min = temp[k];
			}

			if(min < helperMatrix[i][j])
				helperMatrix[i][j] = min;
		}
	}
	else if(j == 1)
	{
		if(i != n - 2)
		{
			diagonalLeft(i, j);
			down(i, j);
			diagonalRight(i, j);
			right(i, j);
			temp[0] = helperMatrix[i + 1][j - 1] + graphMatrix[i][j];
			temp[1] = helperMatrix[i + 1][j] + graphMatrix[i][j];
			temp[2] = helperMatrix[i + 1][j + 1] + graphMatrix[i][j];
			temp[3] = helperMatrix[i][j + 1] + graphMatrix[i][j];
			min = temp[0];
			for(k = 1 ; k < 4 ; k++)
			{
				if(temp[k] < min)
					min = temp[k];
			}

			if(min < helperMatrix[i][j])
				helperMatrix[i][j] = min;

		}
		else
		{
			diagonalLeft(i, j);
			down(i, j);
			right(i, j);
			temp[0] = helperMatrix[i + 1][j - 1] + graphMatrix[i][j];
			temp[1] = helperMatrix[i + 1][j] + graphMatrix[i][j];
			temp[2] = helperMatrix[i][j + 1] + graphMatrix[i][j];
			min = temp[0];
			for(k = 1 ; k < 3 ; k++)
			{
				if(temp[k] < min)
					min = temp[k];
			}

			if(min < helperMatrix[i][j])
				helperMatrix[i][j] = min;

		}
	}
	else
	{
		if( i != n - 2)
		{
			diagonalLeft(i, j);
			down(i, j);
			temp[0] = helperMatrix[i + 1][j - 1] + graphMatrix[i][j];
			temp[1] = helperMatrix[i + 1][j] + graphMatrix[i][j];
			if(temp[0] < temp[1])
				min = temp[0];
			else
				min = temp[1];

			if(min < helperMatrix[i][j])
				helperMatrix[i][j] = min;

		}
		else
		{
			diagonalLeft(i, j);
			temp[0] = helperMatrix[i + 1][j - 1] + graphMatrix[i][j];
			min = temp[0];

			if(min < helperMatrix[i][j])
				helperMatrix[i][j] = min;

		}
	}
}

int main()
{
	int i, j;
	long long int testCasenum = 1;

	while(1)
	{
		scanf("%d",&n);

		if(n == 0)
			break;

		for(i = 0 ; i < n ; i++)
		{
			for(j = 0 ; j < 3 ; j++)
			{
				scanf("%lld",&graphMatrix[i][j]);
				helperMatrix[i][j] = MAX; 
			}
		}

		recFun(0, 1);

		printf("%lld. %lld\n", testCasenum++, helperMatrix[0][1]);
	}

	return 0;
}