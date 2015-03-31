/*
338. Roads

Problem code: ROADS

N cities named with numbers 1 ... N are connected with one-way roads. Each road has two parameters associated with it: the road length and the toll that needs to be paid for the road (expressed in the number of coins). Bob and Alice used to live in the city 1. After noticing that Alice was cheating in the card game they liked to play, Bob broke up with her and decided to move away - to the city N. He wants to get there as quickly as possible, but he is short on cash. We want to help Bob to find the shortest path from the city 1 to the city N that he can afford with the amount of money he has.

Input

The input begins with the number t of test cases. Then t test cases follow. The first line of the each test case contains the integer K, 0 <= K <= 10000, maximum number of coins that Bob can spend on his way. The second line contains the integer N, 2 <= N <= 100, the total number of cities. The third line contains the integer R, 1 <= R <= 10000, the total number of roads. Each of the following R lines describes one road by specifying integers S, D, L and T separated by single blank characters : S is the source city, 1 <= S <= N D is the destination city, 1 <= D <= N L is the road length, 1 <= L <= 100. T is the toll (expressed in the number of coins), 0 <= T <= 100 Notice that different roads may have the same source and destination cities.

Output

For each test case, output a single line contain the total length of the shortest path from the city 1 to the city N whose total toll is less than or equal K coins. If such path does not exist, output -1.

Example

Input:
2
5
6
7
1 2 2 3
2 4 3 3
3 4 2 4
1 3 4 1
4 6 2 1
3 5 2 0
5 4 3 2
0
4
4
1 4 5 2
1 2 1 0
2 3 1 1
3 4 1 0

Output:
11
-1
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define ll long long

struct node
{
	int destination;
	int distance;
	int toll;
	struct node *next;
};

struct node *start[110], *end[110], *ptr;
int visited[110], numOfRoads, numOfCities, maxToll;
ll cdist, ctoll, minDist, minToll, dp[101][10010]; // cdist :- current distance : ctoll :- current toll

void init()
{
	int i, j;

	for(i = 0 ; i < 110 ; i++)
	{
		start[i] = end[i] = NULL;
		visited[i] = 0;
	}
	for(i = 0 ; i < 101 ; i++)
		for(j = 0 ; j < 10005 ; j++)
			dp[i][j] = LLONG_MAX;
}

void insert(int source, int destination, int distance, int toll)
{
	if(start[source] == NULL)
	{
		start[source] = (struct node *)malloc(sizeof(struct node));
		start[source]->destination = destination;
		start[source]->distance = distance;
		start[source]->toll = toll;
		start[source]->next = NULL;
		end[source] = start[source];
	}
	else
	{
		ptr = (struct node *)malloc(sizeof(struct node));
		ptr->destination = destination;
		ptr->distance = distance;
		ptr->toll = toll;
		ptr->next = NULL;
		end[source]->next = ptr;
		end[source] = ptr;
	}
}

void recFun(int pos)
{
	struct node *temp;

	if(pos == numOfCities)
	{
		if(cdist <= minDist)
		{
			if(cdist == minDist && ctoll < minToll && ctoll <= maxToll)
				minToll = ctoll;
			else if(cdist < minDist && ctoll <= maxToll)
			{
				minDist = cdist;
				minToll = ctoll;
			}
		}
	}
	else
	{
		temp = start[pos];
		while(temp != NULL)
		{
			if(!visited[temp->destination])
			{
				visited[temp->destination] = 1;
				cdist += temp->distance;
				ctoll += temp->toll;
				if(ctoll <= maxToll && cdist <= minDist && cdist <= dp[temp->destination][maxToll - ctoll])
				{
					dp[temp->destination][maxToll - ctoll] = cdist;
					recFun(temp->destination);
				}
				cdist -= temp->distance;
				ctoll -= temp->toll;
				visited[temp->destination] = 0;
			}
			temp = temp->next;
		}
	}
}

void calculate()
{
	struct node *temp = start[1];

	visited[1] = 1;
	minToll = minDist = LLONG_MAX;
	while(temp != NULL)
	{
		cdist = temp->distance;
		ctoll = temp->toll;
		visited[temp->destination] = 1;
		if(cdist <= dp[temp->destination][maxToll - ctoll])
			recFun(temp->destination);
		visited[temp->destination] = 0;
		temp = temp->next;
	}
}

/*
void print()
{
	int i, j;
	struct node *temp;

	for(i = 1 ; i <= numOfCities ; i++)
	{
		for(j = 0 ; j <= maxToll ; j++)
		{
			if(dp[i][j] == LLONG_MAX)
				printf("-1\t");
			else
				printf("%lld\t", dp[i][j]);
		}
		printf("\n");
	}
}
*/

ll findMin()
{
	int i;
	ll min = LLONG_MAX;
	
	for(i = 0 ; i <= maxToll ; i++)
		if(min > dp[numOfCities][i])
			min = dp[numOfCities][i];

	return min;
}

int main()
{
	int i, testCases, source, destination, distance, toll;
	ll result;

	scanf("%d", &testCases);

	while(testCases--)
	{
		init();

		scanf("%d %d %d", &maxToll, &numOfCities, &numOfRoads);
		for(i = 0 ; i < numOfRoads ; i++)
		{
			scanf("%d %d %d %d", &source, &destination, &distance, &toll);
			insert(source, destination, distance, toll);
		}

		calculate();
		result = findMin();
		//print();
		if(result != LLONG_MAX)
			printf("%lld\n", result);
		else
			printf("-1\n");
	}

	return 0;
}