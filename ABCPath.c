/*
9921. ABC Path

Problem code: ABCPATH

You will be given a 2-dimensional grid of letters. Find the length of the longest path of consecutive letters, starting at 'A'. Paths can step from one letter in the grid to any adjacent letter (horizontally, vertically, or diagonally).

For example, in the following grid, there are several paths from 'A' to 'D', but none from 'A' to 'E':


A 	B 	E

C 	F 	G

B 	D 	H

A 	B 	C

one such path is:

A --B 	E
   / 
C 	F 	G
  \
B 	D 	H

A 	B 	C

Input:

Each test case will start with a line contains two integers H, W the height and width of the grid respectively 1 <= H, W <= 50. Then H lines follow each of W uppercase letters only. Input terminates with H = 0 and W = 0.

 

Output:

For each test case print “Case C: X” without quotes where C is the case number starting with 1 and X is the solution.

 

Sample Input:

4  3

ABE

CFG

BDH

ABC

0 0

 

Sample Output:

Case_1:_4

 

Note: The underscore '_' symbol is only for clarity you should print space instead.
*/

#include <stdio.h>
#include <stdlib.h>

long long int max;
char matrix[110][110];
long long int scoreMatrix[100][100];

long long int recursiveFun(long long int row, long long int col, long long int i, long long int j, long long int pathLength, char currChar)
{
	int flag = 0;
	long long int temp = -1;

	if(i == 0)
	{
		if(j == 0)
		{
			if(matrix[i + 1][j] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i + 1][j] != 0)
					scoreMatrix[i][j] = scoreMatrix[i + 1][j] + 1;
				else
				{
					temp = recursiveFun(row, col, i + 1, j, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i + 1][j + 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i + 1][j + 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i + 1][j + 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i + 1, j + 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i][j + 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i][j + 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i][j + 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i , j + 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}

			if(!flag)
			{
				scoreMatrix[i][j] = 1;
				return 2;
			}
			else
				return (scoreMatrix[i][j] + 1);
		}
		else if(j == col - 1)
		{
			if(matrix[i + 1][j] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i + 1][j] != 0)
					scoreMatrix[i][j] = scoreMatrix[i + 1][j] + 1;
				else
				{
					temp = recursiveFun(row, col, i + 1, j, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i + 1][j - 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i + 1][j - 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i + 1][j - 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i + 1, j - 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i][j - 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i][j - 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i][j - 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i , j - 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;	
				}
			}

			if(!flag)
			{
				scoreMatrix[i][j] = 1;
				return 2;
			}
			else
				return (scoreMatrix[i][j] + 1);
		}
		else
		{
			if(matrix[i + 1][j] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i + 1][j] != 0)
					scoreMatrix[i][j] = scoreMatrix[i + 1][j] + 1;
				else
				{
					temp = recursiveFun(row, col, i + 1, j, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i + 1][j + 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i + 1][j + 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i + 1][j + 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i + 1, j + 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i][j + 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i][j + 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i][j + 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i , j + 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;	
				}
			}
			if(matrix[i + 1][j - 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i + 1][j - 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i + 1][j - 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i + 1, j - 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i][j - 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i][j - 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i][j - 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i , j - 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;	
				}
			}

			if(!flag)
			{
				scoreMatrix[i][j] = 1;
				return 2;
			}
			else
				return (scoreMatrix[i][j] + 1);
		}
	}
	else if(i == row - 1)
	{
		if(j == 0)
		{
			if(matrix[i - 1][j] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i - 1][j] != 0)
					scoreMatrix[i][j] = scoreMatrix[i - 1][j] + 1;
				else
				{
					temp = recursiveFun(row, col, i - 1, j, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i - 1][j + 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i - 1][j + 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i - 1][j + 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i - 1, j + 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i][j + 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i][j + 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i][j + 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i , j + 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;	
				}
			}

			if(!flag)
			{
				scoreMatrix[i][j] = 1;
				return 2;
			}
			else
				return (scoreMatrix[i][j] + 1);
		}
		else if(j == col - 1)
		{
			if(matrix[i - 1][j] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i - 1][j] != 0)
					scoreMatrix[i][j] = scoreMatrix[i - 1][j] + 1;
				else
				{
					temp = recursiveFun(row, col, i - 1, j, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i - 1][j - 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i - 1][j - 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i - 1][j - 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i - 1, j - 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i][j - 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i][j - 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i][j - 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i , j - 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;	
				}
			}

			if(!flag)
			{
				scoreMatrix[i][j] = 1;
				return 2;
			}
			else
				return (scoreMatrix[i][j] + 1);
		}
		else
		{
			if(matrix[i - 1][j] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i - 1][j] != 0)
					scoreMatrix[i][j] = scoreMatrix[i - 1][j] + 1;
				else
				{
					temp = recursiveFun(row, col, i - 1, j, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i - 1][j + 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i - 1][j + 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i - 1][j + 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i - 1, j + 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i][j + 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i][j + 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i][j + 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i , j + 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;	
				}
			}
			if(matrix[i - 1][j - 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i - 1][j - 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i - 1][j - 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i - 1, j - 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i][j - 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i][j - 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i][j - 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i , j - 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;	
				}
			}

			if(!flag)
			{
				scoreMatrix[i][j] = 1;
				return 2;
			}
			else
				return (scoreMatrix[i][j] + 1);						
		}
	}
	else
	{
		if(j == 0)
		{
			if(matrix[i - 1][j] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i - 1][j] != 0)
					scoreMatrix[i][j] = scoreMatrix[i - 1][j] + 1;
				else
				{
					temp = recursiveFun(row, col, i - 1, j, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i - 1][j + 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i - 1][j + 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i - 1][j + 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i - 1, j + 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i][j + 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i][j + 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i][j + 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i , j + 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;	
				}
			}
			if(matrix[i + 1][j + 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i + 1][j + 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i + 1][j + 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i + 1, j + 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;

				}
			}
			if(matrix[i + 1][j] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i + 1][j] != 0)
					scoreMatrix[i][j] = scoreMatrix[i + 1][j] + 1;
				else
				{
					temp = recursiveFun(row, col, i + 1, j, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;	
				}
			}

			if(!flag)
			{
				scoreMatrix[i][j] = 1;
				return 2;
			}
			else
				return (scoreMatrix[i][j] + 1);
		}
		else if(j == col - 1)
		{
			if(matrix[i - 1][j] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i - 1][j] != 0)
					scoreMatrix[i][j] = scoreMatrix[i - 1][j] + 1;
				else
				{
					temp = recursiveFun(row, col, i - 1, j, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i - 1][j - 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i - 1][j - 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i - 1][j - 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i - 1, j - 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i][j - 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i][j - 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i][j - 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i , j - 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;	
				}
			}
			if(matrix[i + 1][j - 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i + 1][j - 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i + 1][j - 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i + 1 , j - 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;	
				}
			}
			if(matrix[i + 1][j] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i + 1][j] != 0)
					scoreMatrix[i][j] = scoreMatrix[i + 1][j] + 1;
				else
				{
					temp = recursiveFun(row, col, i + 1 , j, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;	
				}
			}

			if(!flag)
			{
				scoreMatrix[i][j] = 1;
				return 2;
			}
			else
				return (scoreMatrix[i][j] + 1);

		}
		else
		{
			if(matrix[i - 1][j] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i - 1][j] != 0)
					scoreMatrix[i][j] = scoreMatrix[i - 1][j] + 1;
				else
				{
					temp = recursiveFun(row, col, i - 1, j, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i - 1][j - 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i - 1][j - 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i - 1][j - 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i - 1, j - 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;
				}
			}
			if(matrix[i][j - 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i][j - 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i][j - 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i , j - 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;	
				}
			}
			if(matrix[i + 1][j - 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i + 1][j - 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i + 1][j - 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i + 1 , j - 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;	
				}
			}
			if(matrix[i + 1][j] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i + 1][j] != 0)
					scoreMatrix[i][j] = scoreMatrix[i + 1][j] + 1;
				else
				{
					temp = recursiveFun(row, col, i + 1 , j, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;	
				}
			}
			if(matrix[i + 1][j + 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i + 1][j + 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i + 1][j + 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i + 1 , j + 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;	
				}
			}
			if(matrix[i][j + 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i][j + 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i][j + 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i , j + 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;	
				}
			}
			if(matrix[i - 1][j + 1] == (currChar + 1))
			{
				flag = 1;
				if(scoreMatrix[i - 1][j + 1] != 0)
					scoreMatrix[i][j] = scoreMatrix[i - 1][j + 1] + 1;
				else
				{
					temp = recursiveFun(row, col, i - 1 , j + 1, pathLength + 1, currChar + 1);
					if(temp > scoreMatrix[i][j])
						scoreMatrix[i][j] = temp;	
				}
			}

			if(!flag)
			{
				scoreMatrix[i][j] = 1;
				return 2;
			}
			else
				return (scoreMatrix[i][j] + 1);

		}
	}
}

void calculation(long long int row, long long int col)
{
	long long int i, j;
	long long int temp;

	for(i = 0 ; i < row ; i++)
	{
		for(j = 0 ; j < col ; j++)
		{
			if(matrix[i][j] == 'A')
			{
				temp = recursiveFun(row, col, i, j, 1, 'A') - 1;
				if(temp > max)
					max = temp;
			}
		}
	}
}


int main()
{
	long long int row, col, i, j, testCaseNum = 1;
	//char **matrix;
	//long long int **scoreMatrix;



	while(1)
	{
		max = 0;

		scanf("%lld %lld",&row, &col);

		if(row == 0 && col == 0)
			break;

		/*
		scoreMatrix = (long long int **)malloc(sizeof(long long int *) * row);
		matrix = (char **)malloc(sizeof(char *) * row);

		for(i = 0 ; i < row ; i++)
		{	
			scoreMatrix[i] = (long long int *)calloc(sizeof(long long int) * col,0);
			matrix[i] = (char *)malloc(sizeof(char) * (col + 10));
		}
		*/

		for(i = 0 ; i < row ; i++)
			for(j = 0 ; j < col ; j++)
				scoreMatrix[i][j] = 0;
		

		for(i = 0 ; i < row ; i++)
		{
			scanf("%s",matrix[i]);
		}

		calculation(row, col);

		printf("Case %lld: %lld\n",testCaseNum++,max);

		/*
		for(i = 0 ; i < row ; i++)
		{
			free(matrix[i]);
			free(scoreMatrix[i]);
		}

		free(matrix);
		free(scoreMatrix);

		matrix = NULL;
		scoreMatrix = NULL;
		*/
	}
	return 0;
}