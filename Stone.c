/*
Roman has no idea, why this problem is called Stone. He also has no idea on how to solve the followong problem: given array of N integers A and a number K. During a turn the maximal value over all Ai is chosen, let's call it MAX. Then Ai =
MAX - Ai is done for every 1 <= i <= N. Help Roman to find out how will the array look like after K turns.
Input

The numbers N and K are given in the first line of an input. Then N integers are given in the second line which denote the array A.
Output

Output N numbers on a single line. It should be the array A after K turns.
Constraints

 
1 <= N <= 10^5
0 <= K <= 10^9
Ai does not exceed 2 * 10^9 by it's absolute value.
 
Example

Input:
4 1
5 -1 7 0

Output:
2 8 0 7
*/

#include <stdio.h>

int main()
{
	long long int max = -999999999999 , min = 999999999999;
	long long int arr[100000];
	long long int numberOfElementsInTheArray,k,i;
	long long int minPos , maxPos;

	scanf("%lld%lld",&numberOfElementsInTheArray,&k);

	for( i = 0 ; i < numberOfElementsInTheArray ; i++ )
	{
		scanf("%lld",&arr[i]);

		if( arr[i] < min )
		{	
			min = arr[i];
			minPos = i;
		}
		if( arr[i] > max )
		{
			max = arr[i];
			maxPos = i;
		}
	}

	//printf("Max = %lld, Min = %lld\n",arr[maxPos] , arr[minPos] );

	max = arr[maxPos];

	if( k == 0 )
	{
		for( i = 0 ; i < numberOfElementsInTheArray ; i++ )
		{
			printf("%lld ",arr[i] );
		}

		printf("\n");
	}
	else
	{
		for(  i = 0 ; i < numberOfElementsInTheArray ; i++ )
		{
			arr[i] = max - arr[i];
			//printf("%lld\n",arr[i] );
		}

		
		if( k % 2 == 1 )
		{
			for( i = 0 ; i < numberOfElementsInTheArray ; i++ )
			{
				printf("%lld ",arr[i] );
			}

			printf("\n");
		}
		else
		{
			min = arr[minPos];

			for(  i = 0 ; i < numberOfElementsInTheArray ; i++ )
			{
				arr[i] = min - arr[i];
			}

			for( i = 0 ; i < numberOfElementsInTheArray ; i++ )
			{
				printf("%lld ",arr[i] );
			}

			printf("\n");		
		}
	}	
	return 0;
}