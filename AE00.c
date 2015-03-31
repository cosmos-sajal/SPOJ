/*
4300. Rectangles

Problem code: AE00

Byteman has a collection of N squares with side 1. How many different rectangles can he form using these squares?

Two rectangles are considered different if none of them can be rotated and moved to obtain the second one. During rectangle construction, Byteman can neither deform the squares nor put any squares upon any other ones.

Input

The first and only line of the standard input contains one integer N (1 ≤ N ≤ 10000).

Output

The first and only line of the standard output should contain a single integer equal to the number of different rectangles that Byteman can form using his squares.

Example

For the input data:

6
the correct result is:

8
*/

#include <stdio.h>

int main()
{
	int n, i, j;
	int hash[10000] = {0};
	long long int totalSum = 0, tempSum;
	long long int divisionValue;
	int limit;
	int arr[10000];

	scanf("%d",&n);

	for(i = 1 ; i <= n ; i++)
	{
		tempSum = 1;
		limit = 0;

		for(j = 2 ; j <= i/2 ; j++)
		{
			if(i % j == 0)
			{
				divisionValue = i/j;
				if(hash[divisionValue] == 0)
				{
					tempSum++;
					hash[divisionValue] = 1;
					hash[j] = 1;
					arr[limit++] = divisionValue;
				}
				else
					break;
			}
		}

		totalSum += tempSum;

//		printf("%lld\n",tempSum );

		for(j = 0 ; j < limit ; j++)
		{
			hash[arr[j]] = 0;
		}
	}

	printf("%lld\n",totalSum);


	return 0;
}