/*
SPOJ Problem Set (classical)
10069. Kompići
Problem code: KOMPICI

 
After successfully solving his math homework from the previous task, Mirko has become bored, so he 
has made a list of N large integers. On the list there are some pairs of numbers that he likes, and some 
pairs he doesn’t like. 
Mirko has named the pairs that he likes pals. Two numbers are pals if they have at least one digit in 
common (not necessarily in the same position). 
Help Mirko count how many pairs of numbers in his list are pals. 
INPUT 
The first line of input contains the positive integer N (1 ≤ N ≤ 1 000 000). 
Each of the next N lines contains a positive integer from the range [1, 10
18
], a number from Mirko’s 
list. No two numbers in the list will be equal. 
OUTPUT 
The first and only line of output must contain the number of pairs that are pals. 

After successfully solving his math homework from the previous task, Mirko has become bored, so he has made a list of N large integers. On the list there are some pairs of numbers that he likes, and some pairs he doesn’t like. Mirko has named the pairs that he likes pals. Two numbers are pals if they have at least one digit in common (not necessarily in the same position). 

Help Mirko count how many pairs of numbers in his list are pals
Input

The first line of input contains the positive integer N (1 ≤ N ≤ 500 000).Each of the next N lines contains a positive integer from the range [1, 10^18], a number from Mirko’s list. No two numbers in the list will be equal.
Output

The first and only line of output must contain the number of pairs that are pals.
Example

Input:
3
4
20
44

Output:
1


*/

#include <stdio.h>

char numbers[500001][19];
int map1[5000001][10];

int main()
{
	long long int n , i , j , k , count = 0 ;

	//int map[10] = { 0,0,0,0,0,0,0,0,0,0 };

	scanf("%lld",&n);

	for( i = 0 ; i < n ; i++ )
	{
		for( k = 0 ; k < 10 ; k++ )
			map1[i][k] = 0;

		scanf("%s",numbers[i]);

		for( k = 0 ; numbers[i][k] != '\0' ; k++ )
		{
			map1[i][ numbers[i][k] - '0' ]++;
		}

	}

	for( i = 0 ; i < n-1 ; i++ )
	{
		for( j = i+1 ; j < n ; j++ )
		{
			for( k = 0 ; k < 10 ; k++ )
			{
				if( map1[i][k] != 0 && map1[j][k] != 0 )
				{
					count++;
					break;
				}
			}
		}
	}


/*	for( i = 0 ; i < n - 1 ; i++ )
	{

		for( k = 0 ; numbers[i][k] != '\0' ; k++ )
		{
			map[ numbers[i][k] - '0' ]++;
		}

		for( j = i+1 ; j < n ; j++ )
		{
			
			for( k = 0 ; numbers[j][k] != '\0' ; k++ )
			{
				if( map[ numbers[j][k] - '0' ] != 0 )
				{
					count++;
					break;
				}
			}
			
		}

		for( k = 0 ; k < 10 ; k++ )
		{
			map[k] = 0;
		}
	}
*/
	printf("%lld\n", count );

	return 0;
}