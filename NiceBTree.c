/*
13384. Nice Binary Trees

Problem code: NICEBTRE

Binary trees can sometimes be very difficult to work with. Fortunately, there is a class of trees with some really nice properties. A rooted binary tree is called “nice”, if every node is either a leaf, or has exactly two children.

For example, the following tree is nice,

nice tree

but the following tree is not.

not a nice binary tree

The leaves of a nice binary tree are labeled by the letter ‘l’, and other nodes are labeled by the letter ‘n’.

Given the pre-order traversal of a nice binary tree, you are required to find the depth of the tree.

Notes : 

1. The depth of a tree is defined as the length of the longest path with one end at the root.

2. The pre-order traversal of the tree in the first image above produces the string “nlnnlll”.

 

Input

The first line contains the number of test cases T. T lines follow. Each line contains a string, which represents the pre-order traversal of a “nice” binary tree. Leaves are represented by the letter ‘l’ and other nodes by the letter ‘n’. The input is guaranteed to be the preorder traversal of a nice binary tree.

 

Output

Output one line for each test case, containing a single integer, the depth of tree.

 

Constraints

0 < T < 20

Length of the input string in each test case is at most 10000.

 

Example

Input:
3
l
nlnll
nlnnlll


Output:
0
2
3

URL : http://www.spoj.com/problems/NICEBTRE/
*/

#include <stdio.h>

int maxDepth;
char str[10010];

int max(int a, int b)
{
	int max = a >= b ? a : b;
	return max;
}

void init()
{
	maxDepth = 0;
}

int recFun(int posL, int depth)
{
	int posR, retVal;

	maxDepth = max(maxDepth, depth);
	if(str[posL] == 'l')
		return posL + 1;
	posR = recFun(posL + 1, depth + 1);
	retVal = recFun(posR , depth + 1);

	return retVal;
}

int main()
{
	int testCases;

	scanf("%d", &testCases);
	getc(stdin);

	while(testCases--)
	{
		gets(str);
	
		init();
		recFun(0, 0);

		printf("%d\n", maxDepth);
	}

	return 0;
}