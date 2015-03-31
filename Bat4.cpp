/*
By Cosmos

13646. BATMAN4

Problem code: BAT4

" Batman: A hero can be anyone. Even a man doing something as simple and reassuring as putting a coat around a little boy's shoulder to let him know that the world hadn't ended. "

 

THE BOMB IS TRIGGERED !! , IT WOULD BLOW OFF IN A FEW MINUTES !!
BATMAN resorts to his BAT and decides to head towards the ocean with the bomb . 
However in front of him lies a huge grid of tall buildings . Starting from the top-leftmost grid he needs to move to the bottom right-most grid to reach the ocean . Since the fuel of BAT has nearly exhausted , BATMAN decides to chose a path where the maximum up distance travelled at a time is minimized .   However , each movement of the BAT up or down the building takes one unit of time . (Horizontal movements can be made in no time) . The clock keeps ticking , So BATMAN decides to choose a path reaching the destination minimizing the maximum up distance and with as much time left as possible. 
Every Hero Has a Journey. Every Journey Has an End !
 

" CatWoman : You dont owe these people anymore . You've given them everything 
  BatMan : Not everything , Not Yet . " 

 

NOTES :

BatMan requires to take the first jump on (1,1)
Print NO is no time is left
minimum max up-distance is the first priority.

Input

t , number of testcases
n,T denoting the size of the grid , T time left.
n rows and n colums denoting the heigths of the buildingOutput

If BATMAN could reach the destination,
print "YES" , the maximum up distance travelled and the maximum time left with BATMAN 

If he could not reach the destination within time print "NO" 

Constraints 

1 <= n <= 20

1 <= t <= 100

Example

Input:
1
3 40
2 4 3
4 5 3
2 4 6

Output:
YES : 2 32
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 9999999999999
#define ll long long

struct node
{
	ll minUpDis;
	ll timeLeft;
};

int n;
ll mat[30][30];
struct node helperMatrix[30][30];

void recFun(int i, int j, int timeLeft)
{
	if(i + 1 < n && mat[i + 1][j] - mat[i][j] >= 0 && mat[i + 1][j] - mat[i][j] < helperMatrix[i + 1][j].minUpDis)
	{
		helperMatrix[i + 1][j].minUpDis = mat[i + 1][j] - mat[i][j];
		helperMatrix[i + 1][j].timeLeft = timeLeft - (mat[i + 1][j] - mat[i][j]);
		recFun(i + 1, j, timeLeft - (mat[i + 1][j] - mat[i][j]));
	}
	else if(i + 1 < n && mat[i + 1][j] - mat[i][j] >= 0 && mat[i + 1][j] - mat[i][j] == helperMatrix[i + 1][j].minUpDis)
	{
		if(timeLeft - (mat[i + 1][j] - mat[i][j]) > helperMatrix[i + 1][j].timeLeft)
			helperMatrix[i + 1][j].timeLeft = timeLeft - (mat[i + 1][j] - mat[i][j]);
		recFun(i + 1, j, helperMatrix[i + 1][j].timeLeft);
	}
	else if(i + 1 < n && mat[i + 1][j] - mat[i][j] < 0)
	{
		helperMatrix[i + 1][j].minUpDis = helperMatrix[i][j].minUpDis;
		helperMatrix[i + 1][j].timeLeft = timeLeft - abs(mat[i + 1][j] - mat[i][j]);
		recFun(i + 1, j, timeLeft - abs(mat[i + 1][j] - mat[i][j]));
	}
	if(j + 1 < n && mat[i][j + 1] - mat[i][j] >= 0 && mat[i][j + 1] - mat[i][j] < helperMatrix[i][j + 1].minUpDis)
	{
		helperMatrix[i][j + 1].minUpDis = mat[i][j + 1] - mat[i][j];
		helperMatrix[i][j + 1].timeLeft = timeLeft - (mat[i][j + 1] - mat[i][j]);
		recFun(i, j + 1, timeLeft - (mat[i][j + 1] - mat[i][j]));
	}
	else if(j + 1 < n && mat[i][j + 1] - mat[i][j] >= 0 && mat[i][j + 1] - mat[i][j] == helperMatrix[i][j + 1].minUpDis)
	{
		if(timeLeft - (mat[i][j + 1] - mat[i][j]) > helperMatrix[i][j + 1].timeLeft)
			helperMatrix[i][j + 1].timeLeft = timeLeft - (mat[i][j + 1] - mat[i][j]);
		recFun(i, j + 1, helperMatrix[i][j + 1].timeLeft);
	}
	else if(j + 1 < n && mat[i][j + 1] - mat[i][j] < 0)
	{
		helperMatrix[i][j + 1].minUpDis = helperMatrix[i][j].minUpDis;
		helperMatrix[i][j + 1].timeLeft = timeLeft - abs(mat[i][j + 1] - mat[i][j]);
		recFun(i, j + 1, timeLeft - abs(mat[i][j + 1] - mat[i][j]));
	}
}

void calculate(int timeLeft)
{
	helperMatrix[0][0].minUpDis = mat[0][0];
	helperMatrix[0][0].timeLeft = timeLeft;

	recFun(0, 0, timeLeft);
}

int main()
{
	int i, j, testcases, timeLeft;

	scanf("%d", &testcases);

	while(testcases--)
	{
		scanf("%d %d", &n, &timeLeft);
		for(i = 0 ; i < n ; i++)
			for(j = 0 ; j < n ; j++)
			{
				scanf("%lld", &mat[i][j]);
				helperMatrix[i][j].minUpDis = MAX;
			}

		calculate(timeLeft);
		if(helperMatrix[n - 1][n - 1].timeLeft < 0)
			printf("NO\n");
		else
			printf("YES : %lld %lld\n", helperMatrix[n - 1][n - 1].minUpDis, helperMatrix[n - 1][n - 1].timeLeft);
	}

	return 0;
}