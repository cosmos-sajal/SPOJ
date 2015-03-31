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

long long int *arr;
long long int *cost;
long long int x,y;
struct node **posStart;
struct node **posEnd;
struct node *ptr;
long long int *validity;
//int *map;
//long long int *posArr;

struct node
{
	long long int data;
	struct node * next;
};


void insert(long long int a,long long int b)
{
	if( posStart[a-1] == NULL )
	{
		ptr = (struct node *)malloc(sizeof(struct node));
		ptr->next = NULL;
		ptr->data = b;
		posStart[a-1] = ptr;
		posEnd[a-1] = ptr;
	}
	else
	{
		ptr = (struct node *)malloc(sizeof(struct node));
		ptr->next = NULL;
		ptr->data = b;
		posEnd[a-1]->next = ptr;
		posEnd[a-1] = ptr;
	}
}

void print(long long int n)
{
	long long int i;

	for( i = 0 ; i < n ; i++ )
	{
		ptr = posStart[i];

		printf("%lld--->",i );

		while(ptr!=NULL)
		{
			printf("%lld ",ptr->data);
			ptr = ptr->next;
		}

		printf("\n");
	}

}


int main()
{
	long long int n,m,p;
	long long int i,j;
//	long long int posArrPosition = 0;

	scanf("%lld%lld%lld",&n,&m,&p);

	cost = (long long int *)malloc(sizeof(long long int)*n);

	validity = (long long int *)malloc(sizeof(long long int)*n); 

	arr = (long long int *)malloc(sizeof(long long int)*m);

	posStart = (struct node **)malloc(sizeof(struct node *)*n);

	posEnd = (struct node **)malloc(sizeof(struct node *)*n);

//	map = (int *)malloc(sizeof(int)*n); 

//	posArr = (long long int *)malloc(sizeof(long long int)*n); 

	for( i = 0 ; i < n ; i++ )
	{	
		posStart[i] = NULL;
		posEnd[i] = NULL;
		cost[i] = m - 1;
		validity[i] = 0;
//		map[i] = 0;
	}


	for( i = 0 ; i < p ; i++ )
	{
		scanf("%lld%lld",&x,&y);

		//insert(x,y);

		if( posStart[x-1] == NULL )
		{
			ptr = (struct node *)malloc(sizeof(struct node));
			ptr->next = NULL;
			ptr->data = y;
			posStart[x-1] = ptr;
			posEnd[x-1] = ptr;
		}
		else
		{
			ptr = (struct node *)malloc(sizeof(struct node));
			ptr->next = NULL;
			ptr->data = y;
			posEnd[x-1]->next = ptr;
			posEnd[x-1] = ptr;
		}
	
/*		if( map[x-1] == 0 )
		{
			map[x-1]++;
			posArr[posArrPosition++] = x-1;
		}
*/
	}

	//print(n);

	if( m > 1 )
	{	
		for( i = 0 ; i < n ; i++ )
		{
			if( posStart[i] != NULL )
			{

				//printf("posArr-->%lld\n",posArr[i]);

				for( j = 0 ; j < m ; j++ )
					arr[j] = j+1;

				//ptr = posStart[posArr[i]];

				ptr = posStart[i];
				//x = posArr[i]+1;
				x = i + 1;

				while( ptr != NULL )
				{
					
				//	x= i+1;
					y = ptr->data;

				//	printf("x=%lld y=%lld\n",x,y );

				//	if( m > 1 )
					{
					//	printf("m = %lld\n",m);

						if( y == 1 )
						{
							if( arr[y-1] == arr[y] )
							{
								validity[x-1]--;
							}

							cost[x-1] -= ( arr[y] - arr[y-1] );
							arr[y-1]++;
							cost[x-1] += ( arr[y] - arr[y-1] );

						}
						else if( y == m )
						{
							if( ( arr[y-2] == arr[y-1] + 1 ) )
							{
								validity[x-1]++;
								//printf("validity increased = %lld\n",validity[x-1]);
							}	

							cost[x-1] -= ( arr[y-1] - arr[y-2] );
							arr[y-1]++;
							cost[x-1] += ( arr[y-1] - arr[y-2] ) ;
						}
						else
						{
							if( arr[y-1] == arr[y] )
							{
								validity[x-1]--;
								//printf("validity decreased = %lld\n",validity[x-1]);
							}

							if( ( arr[y-1] + 1 ) == arr[y-2] )
							{
								validity[x-1]++;
								//printf("validity increased = %lld\n",validity[x-1]);
							}

							cost[x-1] = cost[x-1] - ( arr[y] - arr[y-1] ) - ( arr[y-1] - arr[y-2] ) ;
							//printf("cost=%lld\n",cost[x-1] );
							arr[y-1]++;
							cost[x-1] += ( ( arr[y-1] - arr[y-2] ) + ( arr[y] - arr[y-1] ) );
							//printf("cost=%lld\n",cost[x-1] );
						}
					}
					

					ptr = ptr->next;

				}

			}

			if( validity[i] < 0 )
			{	
					//cost[x-1] = -1;
				printf("-1\n");
			}
			else
			{
				printf("%lld\n",cost[i] );
			}

		free(posStart[i]);
		}
	}
	else
	{
		for( i = 0 ; i < n ; i++ )
		{
			printf("0\n");
		}	
	}

/*	if( m > 1 )
		{
		
			if( y == 1 )
			{
				cost[x-1] = cost[x-1] - ( arr[x-1][y] - arr[x-1][y-1] );
				arr[x-1][y-1]++;
				cost[x-1] = cost[x-1] + ( arr[x-1][y] - arr[x-1][y-1] );

			}
			else if( y == m )
			{
				cost[x-1] = cost[x-1] - ( arr[x-1][y-1] - arr[x-1][y-2] );
				arr[x-1][y-1]++;
				cost[x-1] = cost[x-1] + ( arr[x-1][y-1] - arr[x-1][y-2] ) ;
			}
			else
			{
				cost[x-1] = cost[x-1] - ( arr[x-1][y] - arr[x-1][y-1] ) - ( arr[x-1][y-1] - arr[x-1][y-2] );
				arr[x-1][y-1]++;
				cost[x-1] = cost[x-1] + ( arr[x-1][y-1] - arr[x-1][y-2] ) + ( arr[x-1][y] - arr[x-1][y-1] );
			}
		}
		else
		{
			arr[x-1][y-1]++;
		}
*/
/*	for( i = 0 ; i < n ; i++ )
	{
		if( arr[i] != NULL )
		{
			for( j = 0 ; j < m ; j++ )
				printf("%lld ",arr[i][j] );
		}

		printf("\n");
	}
*/

/*	if( m > 1 )
	{
		for( i = 0 ; i < n ; i++ )
		{
			printf("%lld\n",cost[i] );
		}
	}
	else
	{
		for( i = 0 ; i < n ; i++ )
		{
			printf("0\n");
		}	
	}
*/
	/*
	if( m > 1 )
	{
		for( i = 0 ; i < n ; i++ )
		{
			flag = 1;

			if( arr[i] != NULL  )
			{	
				for( j = m-1 ; j > 0 ; j-- )
				{
					
					if( arr[i][j] < arr[i][j-1] )
					{
						printf("-1\n");
						flag = 0;
						break;
					}
				}
			}

			if( flag )
			{
				printf("%lld\n",cost[i] );
				
			}

			free(arr[i]);
		}
	}
	else
	{
		for( i = 0 ; i < n ; i++ )
		{
			//printf("%lld\n",arr[i][0] );
			printf("0\n");
		}
	}

	free(arr);
	free(cost);
	*/
	return 0;
}