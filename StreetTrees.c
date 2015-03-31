/*
8132. Street Trees

Problem code: STREETR

A group of trees is planted along a straight line.

KOI is planning to plant more trees so that the distance between two adjacent trees is equal for all trees.

For simplicity, each tree can only be planted on an integer coordinate.

For example, if 4 trees were originally planted on coordinates (1,3,7,13), and if KOI plants 3 more trees on coordinates (5,9,11), then the distance between two adjacent trees will equal for all trees.

Your task is to calculate the minimal number of trees that KOI can plant so that the distance between two adjacent trees will equal for all trees.

Input

The first line is an integer N (3<=N<=100,000), which denotes the number of already planted trees.

The next N lines will have an integer X (1<=X<=1,000,000,000), which denotes the coordinate of each tree. 

You can safely assume that the value of X will be unique. 

Output

Output the minimal number of trees that must be planted.

Example

Input:
4
1
3
7
13
Output:
3
Input:
4
2
6
12
18
Output:
5
*/

#include <stdio.h>

int arr[100010], diffArr[100010];

int gcd(int a, int b)
{
	int r;
	while(b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main()
{
	int numOfTrees, i, val, treesToBePlanted;

	scanf("%d", &numOfTrees);
	scanf("%d", &arr[0]);
	for(i = 1 ; i < numOfTrees ; i++)
	{
		scanf("%d", &arr[i]);
		diffArr[i - 1] = arr[i] - arr[i - 1];
	}

	val = gcd(diffArr[0], diffArr[1]);
	for(i = 2 ; i < numOfTrees - 1 ; i++)
		val = gcd(val, diffArr[i]);
	treesToBePlanted = 0;
	for(i = 0 ; i < numOfTrees - 1 ; i++)
		treesToBePlanted += ((diffArr[i] / val) - 1);

	printf("%d\n", treesToBePlanted);

	return 0;
}