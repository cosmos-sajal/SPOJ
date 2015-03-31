/*
12030. Blackout

Problem code: BLACKOUT

Caracas, as any other city, never sleeps, however, this is about to change as the Chief Officer Marcos “the little one” is scheduling some blackouts to search an important criminal and bring it to justice (If you like to know the criminal is known as “El Pran Malandroso”), the criminal is known for fainting when he doesn't see any source of light, so this is a perfect plan for Marcos “the little one” to trap him and capture him.
Marcos will give you the map where he is searching the criminal, the zone is given in a matrix and each value represents a block, surrounded by streets, where the number at the i-th row and j-th column denotes the number of people living in this block.
As Marcos “the little one” is a good officer, he doesn't wants to bother more than a specific number of people, as when he darken the zone, the people will going to be mad. That's what he called you for, Marcos will give you the north-west corner and the south-east corner, he will search in this specific area, causing a blackout.
Marcos will perform a series of blackouts in the city during the night, he will perform each blackout in a given zone, he will return the city all of its light and then he will perform another blackout, so on until he does Q blackouts, as the criminal is constantly moving in the city, the blackout will be independent and the area of searching will be always considered different.
Knowing this, can you maximize the area searched without exceeding the limit that Marcos gives you? (Citizens will be going mad when a blackout occurs)
 
INPUT:
The first line will contain 4 integers N, M, Q and K, denoting, respectively the N and M matrix size denoting an aerial view of the city, Q blackouts that Marcos the little one will do and K people that he wants to bother as much.
Then, N lines follow, each containing M integers, representing the people living in the block.
After that, Q lines will follow, each one containing four integers denoting the (i,j) point of the north-west corner and the (i,j) point of the south-east corner.
 
OUTPUT:
The first and only line of output should contain a number, representing the maximum area that Marcos can look for the criminal.
 
SAMPLE1:
INPUT

OUTPUT

3 3 2 20

1 2 3

4 5 6

7 8 9

1 1 3 3

1 1 2 2

4

Is important to note that each blackout is independent from the other, so, blackout affecting the zone (1,1) to (3,3) will lead to 45 people angry and 9 units of area, while a blackout from the zone (1,1) to (2,2) will get 12 people angry and 4 units of area. If the limit were 57, you could perform the two blackouts, giving a total result of 13.
SAMPLE2:
INPUT

OUTPUT

4 3 3 76

1 4 9

5 5 2

2 1 9

9 1 9

2 1 4 3

1 1 4 3

2 1 3 2

16

 
CONSTRAINTS:
1 <= N,M <= 2000
1 <= Q <= 1000
1 <= K <= 1000
0 <= (Ni,Mj) <= 1000
It is safe to say that there will be always an answer to this problem. (You will always find at least one blackout that doesn't bother more than K citizens)

url: http://www.spoj.com/problems/BLACKOUT/
*/

#include <stdio.h>

long long int cityMatrix[2010][2010], rowSumMatrix[2010][2010], colSumMatrix[2010][2010], sum[2010][2010];
long long int area[1010], peopleDisturbed[1010], K[2010][2010];

long long int max(long long int a, long long int b)
{
	long long int max = a > b ? a : b;
	return max;
}

void calculateBlackouts1(long long int q)
{
	long long int i, x1, y1, x2, y2;
	
	for(i = 0 ; i < q ; i++)
	{
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		peopleDisturbed[i] = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
		area[i] = (y2 - y1 + 1) * (x2 - x1 + 1);
	}
	
}

void calculateBlackouts(long long int q)
{
	long long int i, j, x1, y1, x2, y2;
	long long int rowSum, colSum, rowDiff, colDiff;
	
	for(i = 0 ; i < q ; i++)
	{
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		rowDiff = x2 - x1;
		colDiff = y2 - y1;
		if(rowDiff < colDiff)
		{
			if(y1 != 1)
			{
				rowSum = 0;
				for(j = x1 - 1 ; j < x2 ; j++)
					rowSum += rowSumMatrix[j][y2 - 1] - rowSumMatrix[j][y1 - 2];
			}
			else
			{
				rowSum = 0;
				for(j = x1 - 1 ; j < x2 ; j++)
					rowSum += rowSumMatrix[j][y2 - 1];	
				
			}
			peopleDisturbed[i] = rowSum;
			area[i] = (y2 - y1 + 1) * (x2 - x1 + 1);
		}
		else
		{
			if(x1 != 1)
			{
				colSum = 0;
				for(j = y1 - 1 ; j < y2 ; j++)
					colSum += colSumMatrix[x2 - 1][j] - colSumMatrix[x1 - 2][j];
			}
			else
			{
				colSum = 0;
				for(j = y1 - 1 ; j < y2 ; j++)
					colSum += colSumMatrix[x2 - 1][j];	
				
			}
			peopleDisturbed[i] = colSum;
			area[i] = (y2 - y1 + 1) * (x2 - x1 + 1);	
		}
			
	}
}

long long int calculateMaxArea(long long int rows, long long int cols, long long int W, long long int n)
{
	long long int i, w;

	for(i = 0; i <= n; i++)
   	{
       for(w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (peopleDisturbed[i-1] <= w)
                 K[i][w] = max(area[i-1] + K[i-1][w- peopleDisturbed[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   	}
 
   return K[n][W];
}

int main()
{
	long long int rows, cols, q, k, w;
	long long int i, j;

	scanf("%lld %lld %lld %lld", &rows, &cols, &q, &k);

	for(i = 0 ; i < rows ; i++)
		sum[i][0] = 0;
	for(i = 0 ; i < cols ; i++)
		sum[0][i] = 0;
	for(i = 1 ; i <= rows ; i++)
	{
		//rowSum = 0;
		for(j = 1 ; j <= cols ; j++)
		{
			scanf("%lld", &cityMatrix[i][j]);
			//rowSum += cityMatrix[i][j];
			//rowSumMatrix[i][j] = rowSum;
			//if(i == 0)
			//	colSumMatrix[i][j] = cityMatrix[i][j];
			//else
			//	colSumMatrix[i][j] = colSumMatrix[i - 1][j] + cityMatrix[i][j];
			sum[i][j] = cityMatrix[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}

	calculateBlackouts1(q);
	for(i = 0; i <= q; i++)
   	{
       for(w = 0; w <= k; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (peopleDisturbed[i-1] <= w)
                 K[i][w] = max(area[i-1] + K[i-1][w- peopleDisturbed[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   	}
   	printf("%lld\n", K[q][k]);
	//printf("%lld\n", calculateMaxArea(rows, cols, k, q));

	return 0;
}
