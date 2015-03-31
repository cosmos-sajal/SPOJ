/*
8551. Colours A, B, C, D

Problem code: ABCD

Consider a table with 2 rows and 2N columns (a total of 4N cells). Each cell of the first row is coloured by one of the colours A, B, C, D such that there are no two adjacent cells of the same colour. You have to colour the second row using colours A, B, C, D such that:

• There are exactly N cells of each colour (A, B, C and D) in the table.

• There are no two adjacent cells of the same colour. (Adjacent cells share a vertical or a horizontal side.)

It is guaranteed that the solution, not necessarily unique, will always exist.

Input

[a natural number N ≤ 50000]

[a string of 2N letters from the set {A, B, C, D}, representing the first row of the table]

Output

[a string of 2N letters from the set {A, B, C, D}, representing the second row of the table]

Example

Input

1

CB

Output

AD

 

Input

2

ABAD 

Output

BCDC
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, j, k;
	char *firstRow, *secondRow;
	int doubleN;
	char tempResult[2];
	int tempHash[4] = {0};
	char temp;

	scanf("%d",&n);

	doubleN = 2 * n;

	firstRow = (char*)malloc(sizeof(char *) * (doubleN + 10));
	secondRow = (char*)malloc(sizeof(char *) * (doubleN + 10));

	scanf("%s",firstRow);

	tempHash[firstRow[0] - 'A']++;
	tempHash[firstRow[1] - 'A']++;
	k = 0;

	for(j = 0 ; j < 4 ; j++)
	{
		if(tempHash[j] == 0)
			tempResult[k++] = 'A' + j;

		tempHash[j] = 0;
	}

	secondRow[0] = tempResult[0];
	secondRow[1] = tempResult[1];

	for(i = 2 ; i < doubleN - 1 ; i = i + 2)
	{
		tempHash[firstRow[i] - 'A']++;
		tempHash[firstRow[i+1] - 'A']++;
		k = 0;

		for(j = 0 ; j < 4 ; j++)
		{
			if(tempHash[j] == 0)
				tempResult[k++] = 'A' + j;
					

			tempHash[j] = 0;
		}

		if(secondRow[i-1] == tempResult[0])
		{
			temp = tempResult[0];
			tempResult[0] = tempResult[1];
			tempResult[1] = temp;
		}

		secondRow[i] = tempResult[0];
		secondRow[i + 1] = tempResult[1];
	}
	
	printf("%s\n",secondRow);

	return 0;
}