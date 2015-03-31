/*
SPOJ Problem Set (classical)
7406. Beehive Numbers
Problem code: BEENUMS

A beehive is an enclosed structure in which some honey bee species live and raise their
young. In this problem we consider a two-dimensional sketch of the beehives. Each
beehive is composed of a certain number of cells, where each cell is a regular hexagon.
Each cell may have some neighbors, which are other cells that share a side with that cell.
A cell with exactly 6 neighbors is an internal cell, while a cell with fewer neighbors is an
external one. Notice that an external cell can always be changed to internal by adding
some neighbor cells.


We are interested in a particular class of beehives. This class of valid beehives is defined
recursively as follows: a) a single cell is a valid beehive; and b) given a valid beehive B,
if we add the minimum number of cells such that each external cell of B becomes an
internal cell, the result is a valid beehive.

The number of cells in a valid beehive is called a beehive number. Given an integer N ,
you must decide whether it is a beehive number.
Input

Each test case is described using a single line. The line contains an integer N (1 ≤ N ≤
109 ). The end of input is indicated with a line containing a single −1.
Output

For each test case, output a single line containing an uppercase “Y” if N is a beehive
number, or an uppercase “N” otherwise.
Example

Input:
43
1
7
19
15
-1
Output:
N
Y
Y
Y
N

*/

#include <stdio.h>

int main()
{
	long long int beehiveNumber;

	int remainder;

	long long int quotient;

	long long int map[1000000];

	map[0] = 0;

	int flag = 0 , i;

	long long int start = 0 , middle , end = 1000000;

	for ( i = 1 ; i < 1000000 ; i++ )
	{
		map[i] = map[i-1] + i;
	}

	while(1)
	{
		scanf("%lld",&beehiveNumber);

		start = 0;
		end = 1000000;

		flag = 0;

		if( beehiveNumber == -1 )
			break;

		remainder = (beehiveNumber - 1) % 6 ;

		if( remainder != 0 )
		{
			printf("N\n");
			continue;
		}

		quotient =  (beehiveNumber - 1) / 6;

		//printf("%lld\n",quotient );

		while( start <= end )
		{
			middle = (start + end) / 2;

			//printf("%lld\n",map[middle] );

			if( map[middle] == quotient )
			{
				printf("Y\n");
				flag = 1;
				break;
			}
			if( map[middle] > quotient )
				end = middle - 1;
			else
				start = middle + 1;
		}

		if(flag == 0)
			printf("N\n");



	}

	return 0;

}