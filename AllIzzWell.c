/*
10283. ALL IZZ WELL

Problem code: ALLIZWEL

ALL IZZ WELL


 Problem Description:


                Mr.ESP used to tell “ALL IZZ WELL” whenever he gets into any trouble.

So his friends and the people around him used to laugh at him. But Mr.ESP is very

strong in his belief. He believes that the term “ALL IZZ WELL” will make everything

fine. Now your task is to ignore the story above and find whether there is a path in

the given matrix which makes the sentence “ALL IZZ WELL”


There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.


Input Specification:


                The first line consists of an integer t representing the number of test cases.

The first line of each test case consists of two integers R and C representing the number

 of rows and number of columns in the matrix. The description of the matrix follows.


Output Specification:


                For each test case print “YES” if there is a path which makes the sentence “ALLIZZWELL”.

Else print “NO”.


Note: Take care of 4th test case 

There is a new line after every test case in the input.



Input constraints:

t<=1000

R<=100

C<=100


Sample Input:


5

3 6

AWE.QX

LLL.EO

IZZWLL



1 10

ALLIZZWELL



2 9

A.L.Z.E..

.L.I.W.L.



3 3

AEL

LWZ

LIZ



1 10

LLEWZZILLA

 

Sample Output:


YES

YES

NO

NO

YES
*/

#include <stdio.h>

char word[20] = "ALLIZZWELL";
char matrix[110][110];
int visited[110][110];
int rows, cols;

int recFun(int, int, int);

int right(int i, int j, int pos)
{
	int retVal;
	if(matrix[i][j + 1] == word[pos] && visited[i][j + 1] == 0)
	{
		retVal = recFun(i, j + 1, pos + 1);
		return retVal;
	}
	else
	{
		return -1;
	}
}

int down(int i, int j, int pos)
{
	int retVal;
	if(matrix[i + 1][j] == word[pos] && visited[i + 1][j] == 0)
	{
		retVal = recFun(i + 1, j, pos + 1);
		return retVal;
	}
	else
	{
		return -1;
	}	
}

int diagonalDownRight(int i, int j, int pos)
{
	int retVal;
	if(matrix[i + 1][j + 1] == word[pos] && visited[i + 1][j + 1] == 0)
	{
		retVal = recFun(i + 1, j + 1, pos + 1);
		return retVal;
	}
	else
	{
		return -1;
	}
}

int left(int i, int j, int pos)
{
	int retVal;
	if(matrix[i][j - 1] == word[pos] && visited[i][j - 1] == 0)
	{
		retVal = recFun(i, j - 1, pos + 1);
		return retVal;
	}
	else
	{
		return -1;
	}	
}

int diagonalDownLeft(int i, int j, int pos)
{
	int retVal;
	if(matrix[i + 1][j - 1] == word[pos] && visited[i + 1][j - 1] == 0)
	{
		retVal = recFun(i + 1, j - 1, pos + 1);
		return retVal;
	}
	else
	{
		return -1;
	}
}

int up(int i, int j, int pos)
{
	int retVal;
	if(matrix[i - 1][j] == word[pos] && visited[i - 1][j] == 0)
	{
		retVal = recFun(i - 1, j, pos + 1);
		return retVal;
	}
	else
	{
		return -1;
	}	
}

int diagonalUpRight(int i, int j, int pos)
{
	int retVal;
	if(matrix[i - 1][j + 1] == word[pos] && visited[i - 1][j + 1] == 0)
	{
		retVal = recFun(i - 1, j + 1, pos + 1);
		return retVal;
	}
	else
	{
		return -1;
	}	
}

int diagonalUpLeft(int i, int j, int pos)
{
	int retVal;
	if(matrix[i - 1][j - 1] == word[pos] && visited[i - 1][j - 1] == 0)
	{
		retVal = recFun(i - 1, j - 1, pos + 1);
		return retVal;
	}
	else
	{
		return -1;
	}	
}

int recFun(int i, int j, int pos)
{
	int retVal;
	visited[i][j] = 1;
	if(pos == 10)
		return 1;

	if(i == 0)
	{
		if(j == 0)
		{
			retVal = right(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = down(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = diagonalDownRight(i, j, pos);
			if(retVal == 1)
				return 1;
			visited[i][j] = 0;
			return -1;
		}
		else if(j == cols - 1)
		{
			retVal = left(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = down(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = diagonalDownLeft(i, j, pos);
			if(retVal == 1)
				return 1;
			visited[i][j] = 0;
			return -1;
		}
		else
		{
			retVal = left(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = down(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = diagonalDownLeft(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = right(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = diagonalDownRight(i, j, pos);
			if(retVal == 1)
				return 1;
			visited[i][j] = 0;
			return -1;	
		}
	}
	else if(i == rows - 1)
	{
		if(j == 0)
		{
			retVal = right(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = up(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = diagonalUpRight(i, j, pos);
			if(retVal == 1)
				return 1;
			visited[i][j] = 0;
			return -1;	
		}
		else if(j == cols - 1)
		{
			retVal = left(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = up(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = diagonalUpLeft(i, j, pos);
			if(retVal == 1)
				return 1;
			visited[i][j] = 0;	
			return -1;
		}
		else
		{
			retVal = right(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = up(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = diagonalUpRight(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = left(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = diagonalUpLeft(i, j, pos);
			if(retVal == 1)
				return 1;
			visited[i][j] = 0;
			return -1;				
		}	
	}
	else
	{
		if(j == 0)
		{
			retVal = down(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = up(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = diagonalUpRight(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = right(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = diagonalDownRight(i, j, pos);
			if(retVal == 1)
				return 1;
			visited[i][j] = 0;
			return -1;
		}
		else if(j == cols - 1)
		{
			retVal = down(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = up(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = diagonalUpLeft(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = left(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = diagonalDownLeft(i, j, pos);
			if(retVal == 1)
				return 1;
			visited[i][j] = 0;
			return -1;
		}
		else
		{
			retVal = up(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = diagonalUpRight(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = right(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = diagonalDownRight(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = down(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = diagonalDownLeft(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = left(i, j, pos);
			if(retVal == 1)
				return 1;
			retVal = diagonalUpLeft(i, j, pos);
			if(retVal == 1)
				return 1;
			visited[i][j] = 0;
			return -1;		
		}
	}
	return -1;
}

int calculate()
{
	int i, j, retVal;
	for(i = 0 ; i < rows ; i++)
	{
		for(j = 0 ; j < cols ; j++)
		{
			if(matrix[i][j] == 'A')
			{
				retVal = recFun(i, j, 1);
				if(retVal == 1)
					return 1;
			}
		}
	}

	return -1;
}

int main()
{
	int testCases, retVal, i, j;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%d %d", &rows, &cols);

		for(i = 0 ; i < rows ; i++)
			scanf("%s", matrix[i]);
		for(i = 0 ; i < rows ; i++)
			for(j = 0 ; j < cols ; j++)
				visited[i][j] = 0;
		retVal = calculate();
		if(retVal == 1)
			printf("YES\n");
		else if(retVal == -1)
			printf("NO\n");
	}

	return 0;
}