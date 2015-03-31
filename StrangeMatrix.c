/*
Spring is interesting season of year. Chef is thinking about different things, but last time he thinks about interesting game - "Strange Matrix".
Chef has a matrix that consists of n rows, each contains m elements. Initially, the element aij of matrix equals j. (1 ≤ i ≤ n, 1 ≤ j ≤ m).
Then p times some element aij is increased by 1.
Then Chef needs to calculate the following:
For each row he tries to move from the last element (with number m) to the first one (with the number 1).
While staying in aij Chef can only move to aij - 1 only if aij - 1 ≤ aij.
The cost of such a movement is aij - aij - 1.
Otherwise Chef can't move and lose (in this row).
If Chef can move from the last element of the row to the first one, then the answer is the total cost of all the movements.
If Chef can't move from the last element of the row to the first one, then the answer is -1.
Help Chef to find answers for all the rows after P commands of increasing.
Input

 
The first line contains three integers n, m and p denoting the number of rows, the number of elements a single row and the number of increasing commands.
Each of next p lines contains two integers i and j denoting that the element aij is increased by one.
 
Output

For each row in a single line print the answer after the P increasing commands.
 
Constraints

1 ≤ n, m, p ≤ 10 ^ 5
1 ≤ i ≤ n
1 ≤ j ≤ m
 
Example

Input:
4 4 6
2 2
3 2 
3 2 
4 3
4 4
4 3

Output:
3
3
-1
4

 
Explanation

Here is the whole matrix after P commands:

1 2 3 4
1 3 3 4
1 4 3 4
1 2 5 5
 Explanations to the answer: 


The first line is without changes: 4-3=1, 3-2=1, 2-1=1. answer = 3. 

The second line: 4-3=1, 3-3=0, 3-1=2. The answer is 3. 

The third line: 4-3=1, 3-4=-1, Chef can't move to the first number here. Therefore, the answer is -1. 

The fourth line: 5-5=0, 5-2=3, 2-1=1. The answer is 4. 


*/

#include <stdio.h>
#include <stdlib.h>

long long int **arr;
long long int *cost,*validity;
long long int x,y;

/*void printArr(long long int n,long long int m)
{
	long long int i,j;

	printf("-----------\n");

	for( i = 0 ; i < n ; i++ )
	{
		for( j = 0 ; j < m ; j++ )
		{
			printf("%lld ",arr[i][j] );
		}
	

		printf("validity = %lld\n",validity[i]);
	}

	printf("-----------\n");
	
}
*/

int main()
{
	long long int n,m,p;
	long long int i,j;
	//int flag;

	scanf("%lld%lld%lld",&n,&m,&p);

	cost = (long long int *)malloc(sizeof(long long int)*n);
	validity = (long long int *)malloc(sizeof(long long int)*n);

	arr = (long long int **)malloc(sizeof(long long int*)*n);


	for( i = 0 ; i < n ; i++ )
		arr[i] = NULL;
	//	arr[i] = (long long int *)malloc(sizeof(long long int)*m);


	for( i = 0 ; i < n ; i++ )
	{
		cost[i] = m - 1;
		validity[i] = 0;
	}

	for( i = 0 ; i < p ; i++ )
	{
		scanf("%lld%lld",&x,&y);

		if( arr[x-1] == NULL )
		{
			arr[x-1] = ( long long int * )malloc( sizeof(long long int)*m );

			for( j = 0 ; j < m ; j++ )
				arr[x-1][j] = j+1;
		}


		if( m > 1 )
		{
			if( y == 1 )
			{
				cost[x-1] = cost[x-1] - ( arr[x-1][y] - arr[x-1][y-1] );

				if( arr[x-1][y-1] > arr[x-1][y] )
				{
						if(  ( arr[x-1][y-1] + 1 ) <= arr[x-1][y]  )
						{
							validity[x-1] += 1;	
						//	printArr(n,m);
						}

						arr[x-1][y-1] += 1;
						cost[x-1] = cost[x-1] + ( arr[x-1][y] - arr[x-1][y-1] );

				}
				else
				{
					arr[x-1][y-1] += 1;

					if( arr[x-1][y-1] > arr[x-1][y] )
					{
						validity[x-1] = validity[x-1] - 1;
						//printArr(n,m);
					}

					cost[x-1] = cost[x-1]  + ( arr[x-1][y] - arr[x-1][y-1] );			
				}

			}
			else if( y == m )
			{
				cost[x-1] = cost[x-1] - ( arr[x-1][y-1] - arr[x-1][y-2] );

				if( arr[x-1][y-1] < arr[x-1][y-2] )
				{
						if( ( arr[x-1][y-1] + 1 ) >= arr[x-1][y-2] )
						{
							validity[x-1] += 1;
						//	printArr(n,m);	
						}

						arr[x-1][y-1] += 1;
						cost[x-1] = cost[x-1] + ( arr[x-1][y-1] - arr[x-1][y-2] ) ;

				}
				else
				{
					arr[x-1][y-1] += 1;

					if( arr[x-1][y-1] < arr[x-1][y-2] )
					{
						validity[x-1] -= 1;
						//printArr(n,m);
					}

					cost[x-1] = cost[x-1] + ( arr[x-1][y-1] - arr[x-1][y-2] );			
				}
			}
			else
			{
				cost[x-1] = cost[x-1] - ( arr[x-1][y] - arr[x-1][y-1] ) - ( arr[x-1][y-1] - arr[x-1][y-2] );

				if( ( arr[x-1][y-1] > arr[x-1][y] ) || ( arr[x-1][y-1] < arr[x-1][y-2] ) )
				{

		//				flag = 0;

						if( ( ( arr[x-1][y-1]  ) < arr[x-1][y-2] )  && ( ( arr[x-1][y-1] + 1 ) >= arr[x-1][y-2] ) )
						{
							validity[x-1] += 1;
		//					flag = 1;
							//printArr(n,m);	
						}
						

						if( arr[x-1][y-1] < arr[x-1][y-2] && ( arr[x-1][y-1] == arr[x-1][y] ) )
						{
							//arr[x-1][y-1]++;
		//					flag = 1;
							validity[x-1] -= 1;
							//printArr(n,m);
						}

						
						arr[x-1][y-1] += 1;

						//if(flag)
						//	printArr(n,m);
						cost[x-1] = cost[x-1] + ( arr[x-1][y-1] - arr[x-1][y-2] ) + ( arr[x-1][y] - arr[x-1][y-1] );

				}
				else
				{
					arr[x-1][y-1] += 1;

					if( ( arr[x-1][y-1] > arr[x-1][y] ) || ( arr[x-1][y-1] < arr[x-1][y-2] ) )
					{
						validity[x-1] -= 1;
						//printArr(n,m);
					}

					cost[x-1] = cost[x-1] + ( arr[x-1][y-1] - arr[x-1][y-2] ) + ( arr[x-1][y] - arr[x-1][y-1] );			
				}

			}
		}
		else
		{
			arr[x-1][y-1]++;
		}
	}

	/*for( i = 0 ; i < n ; i++ )
	{
		for( j = 0 ; j < m ; j++ )
			printf("%lld ",arr[i][j] );

		printf("validity = %lld\n",validity[i] );
	}*/
	


	if( m > 1 )
	{
		for( i = 0 ; i < n ; i++ )
		{
			if( validity[i] >= 0 )
			{
				printf("%lld\n",cost[i] );
			}
			else
			{
				printf("-1\n");
			}
		}
	}
	else
	{
		for( i = 0 ; i < n ; i++ )
		{	
			printf("0\n");
			//printf("%lld\n",arr[i][0]);

		}
	}

	return 0;
}