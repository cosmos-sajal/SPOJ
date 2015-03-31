/*
4177. Herding

Problem code: HERDING

Oh no! A number of stray cats have been let loose in the city, and as the City Cat Catcher, you have been assigned the vital task of retrieving all of the cats. This is an ideal opportunity to test your latest invention, a cat trap which is guaranteed to retrieve every cat which walks into a square-shaped subsection of the city.

Fortunately, you have the assistance of one of the world's foremost cat psychologists, who has the amazing ability of predicting, given a square subsection of the city, exactly which of the four cardinal directions (north, east, south or west) the cat will head. While this information is handy, you still don't know where all the cats currently are.

In order to prove the cost-effectiveness of your method to the City it would, of course, be important to minimize the number of traps used.

Input

The input will begin with a line consisting of two numbers n and m, separated by a space (1 ≤ n, m ≤ 1000). The city will be an n x m grid of square subsections. The next n lines will each consist of a string of length m, consisting of the letters 'N', 'E', 'S', or 'W', representing north, east, south and west, respectively. (The first character of the first line will be the northwesternmost point.) The direction in the square is the direction which cats will head if they are in that square. The cat psychologist assures you that cats have no interest in leaving the city.

Output

Output the minimum number of traps needed.

Example

Input:
3 4
SWWW
SEWN
EEEN

Output:
2
*/

#include <stdio.h>

char cityMatrix[1010][1010];
long long int visitedMatrix[1010][1010];
int n, m;
long long int numOfTraps = 0;

void recFun(int x, int y, long long int pathNum)
{
	if(visitedMatrix[x][y] == 0)
	{
		visitedMatrix[x][y] = pathNum;
		switch(cityMatrix[x][y])
		{
			case 'N' : recFun(x - 1, y, pathNum);
					   break;
			case 'E' : recFun(x, y + 1, pathNum);
					   break;
			case 'S' : recFun(x + 1, y, pathNum);
					   break;
			case 'W' : recFun(x, y - 1, pathNum);
					   break;
		}
	}
	else if(visitedMatrix[x][y] == pathNum)
	{
		numOfTraps++;
		return; 
	}
	else
		return;
}

void calculateTraps()
{
	int i, j;
	long long int pathNum = 0;
	for(i = 0 ; i < n ; i++)
		for(j = 0 ; j < m ; j++)
			if(visitedMatrix[i][j] == 0)
			{
				pathNum++;
				recFun(i, j, pathNum);
			}
}

int main()
{
	int i, j;

	scanf("%d %d", &n, &m);
	
	for(i = 0 ; i < n ; i++)
		scanf("%s", cityMatrix[i]);

	for(i = 0 ; i < n ; i++)
		for(j = 0 ; j < m ; j++)
			visitedMatrix[i][j] = 0;

	numOfTraps = 0;
	calculateTraps();

	printf("%lld\n", numOfTraps);	
	

	return 0;
}