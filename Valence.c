/*
15438. Valences

Problem code: UCV2013J

Mr. White has found a way to maximize the purity of crystals based on certain chemical compounds. He has observed that each compound is made of molecules that are linked together following the structure of a complete binary tree where every level, except possibly the last, is completely filled, and all nodes are as far left as possible. Each node of the tree stores the valence of a molecule and is represented as an integer number. Mr. White uses an electronic microscope that dumps the molecule structure as a stream of integer numbers and would like to have your help on automatically obtaining the total valence of only the leaves of the given tree. For example, the sequence 4-3-2-6-0-3 represents the tree shown in the figure and the total valence of the leaves is 9.

Input

The input contains several test cases, each one corresponding to a particular compound. Each test case consists of a single line starting with an integer N (1  <= N  <= 1000000), followed by N integer numbers Vi representing the valences of each molecule separated by blank spaces (0 <= Vi <= 100).


The end of input is indicated by a test case with N = 0.

Output

For each compound output a single line with the sum of the valences of the leaves of the tree.

Example

Input:
6 4 3 2 6 0 3
7 1 1 1 2 1 2 1
0

Output:
9
6
 
URL : http://www.spoj.com/problems/UCV2013J/
*/

#include <stdio.h>
#define SIZE 1000010
#define ll long long
/*
ll calculate(int n, int *arr)
{
	int i;
	ll sum = 0;

	for(i = 1 ; i <= n ; i++)
		if((2 * i) > n)
			sum += arr[i];

	return sum;
}
*/
int main()
{
	int n, i, arr[SIZE];
	ll sum;

	while(1)
	{
		scanf("%d", &n);
		if(!n)
			break;
		sum = 0;
		for(i = 1 ; i <= n ; i++)
		{
			scanf("%d", &arr[i]);
			if((2 * i) > n)
				sum += arr[i];
		}

		printf("%lld\n", sum);
	}

	return 0;
}