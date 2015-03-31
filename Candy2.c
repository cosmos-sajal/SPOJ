/*
2136. Candy II

Problem code: CANDY2

Little Michael loves candies. Most of all, he likes chocolate, strawberry and banana flavored ones. No wonder that he has candy bags everywhere - there are at least four bags on his table, one or two in the pockets of his jeans, and one under his bed (just in case). Each bag contains some candies of all three flavors. Whenever he wants to eat a candy, he finds the nearest bag (which is usually is not very far because he has really A LOT of them) and eats the candy he wants.

Yesterday, he wanted a strawberry one, so he opened one of his bags and... It is almost impossible to describe how great his disappointment was when he found out that there were no strawberry candies left in that bag. To make the matters worse, there were also none in the second bag he found. He was sure that he had lots of strawberry candies left, but he didn't know in which bags they were. Therefore, he decided to reorganize his candies, and keep the candies of the three different flavors in three distinct bags. He brought all his bags into the center of his room and realized, that there are really an awful lot of them.

Michael has N bags full of candies. He knows the number of candies of each flavor in each bag. He wants to put all chocolate ones into one bag, all strawberry ones into another bag and all banana ones into yet another bag. He has to move the candies one-by-one, because he always has to look at it to determine its flavor. Moving one candy from one bag into another takes 1 second. Your task is to select the bag for each flavor, so that the total time required for Michael to move all the candies into their bags would be minimal.

Input file specification

The first line of the input file contains a single integer N - the number of bags (N<=5000). Each of the following N lines consists of three numbers ci, si, bi - the numbers of chocolate, strawberry and banana candies in the i-th bag. The bags are numbered from 0 to N-1 in the order in which they appear in the input.

Output file specification

Output file should contain three lines with the following text:

C[Bag for chocolate candies]
S[Bag for strawberry candies]
B[Bag for banana candies]
The numbers C, S, B have to be such that the total number of the required moves is minimal. If there are more solutions, you may choose any of them.

Example

Input file:
5
10 10 10
40 39 40
10 20 30
30 20 10
1 2 27

Output file:
3
1
2
Note: In this case Michael has to move 200 candies. If the bags for the different flavors were chosen in any other way, he would have to move more than 200 candies.

Note: the test data is very naive for this problem.
*/

#include <stdio.h>
#include <stdlib.h>

void findMax3ElementsInEachBag(long long int **a, int **b, int numOfBags)
{
	int max;
	int pos;
	int flag;
	int i, j, k;

	for(k = 0 ; k < 3 ; k++)
	{
		for(i = 0 ; i < 3 ; i++)
		{
			max = a[k][i];
			pos = i;
			b[k][i] = i;
			flag = 0;

			for(j = i + 1 ; j < numOfBags ; j++)
			{
				if(a[k][j] > max)
				{
					max = a[k][j];
					pos = j;
					flag = 1;
				}
			}

			if(flag)
			{
				a[k][pos] = a[k][i];
				a[k][i] = max;
				b[k][i] = pos; 
			}
		}
	}
}

int main()
{
	int numOfBags, i, j, k;
	long long int **candyMatrix;
	int **posMatrix;
	long long int totalCandies[3] = {0,0,0};
	long long int min = 9999999999999, temp;
	int pos1, pos2, pos3;

	candyMatrix = (long long int **)malloc(sizeof(long long int *) * 3);
	posMatrix = (int **)malloc(sizeof(int *) * 3);

	for(i = 0 ; i < 3 ; i++)
		posMatrix[i] = (int *)malloc(sizeof(int) * 3);

	scanf("%d",&numOfBags);

	for(i = 0 ; i < 3 ; i++)
		candyMatrix[i] = (long long int *)malloc(sizeof(long long int) * numOfBags);

	for(i = 0 ; i < numOfBags ; i++)
	{	
		for(j = 0 ; j < 3 ; j++)
		{
			scanf("%lld",&candyMatrix[j][i]);
			totalCandies[j] += candyMatrix[j][i];
		}

	}

	findMax3ElementsInEachBag(candyMatrix, posMatrix, numOfBags);

	for(i = 0 ; i < 3 ; i++)
	{
		
		for(j = 0 ; j < 3 ; j++)
		{
		
			for(k = 0 ; k < 3 ; k++)
			{
		
				if(posMatrix[0][i] == posMatrix[1][j] || posMatrix[0][i] == posMatrix[2][k] || posMatrix[1][j] == posMatrix[2][k])
					continue;

				temp = totalCandies[0] - candyMatrix[0][i] + totalCandies[1] - candyMatrix[1][j] + totalCandies[2] - candyMatrix[2][k];
				//temp = candyMatrix[0][i] + candyMatrix[1][j] + candyMatrix[2][k];
				if(temp < min)
				{
					min = temp;
					pos1 = posMatrix[0][i];
					pos2 = posMatrix[1][j];
					pos3 = posMatrix[2][k];
				}
			}
		}
	}

	printf("%d\n%d\n%d\n",pos1,pos2,pos3);

	return 0;
}