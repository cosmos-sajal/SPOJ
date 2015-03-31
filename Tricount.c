/*
1724. Counting Triangles

Problem code: TRICOUNT

Task: Your task is very easy. All you have to do is to count all triangles in the biggest one (Level N).

Input

The first line of the input contains an integer T (T ≤ 10000) - the number of test cases and T lines follow. Each line contains an integer N (1 ≤ N ≤ 106) which is the level of the triangle in that test case.

Output

For each test case, you should write a seperate line: the number of triangles in the biggest one (Level N). (All answers will fit within the range of a 64-bit integer)

Example

Input:
3
1
2
3

Output:
1
5
13

URL : http://www.spoj.com/problems/TRICOUNT/
*/

#include <stdio.h>
#define ll long long

ll preprocessingArr[1000010], oppositeTri[1000010];

void preprocessing()
{
	ll i, tempCount = 1;

	preprocessingArr[1] = oppositeTri[1] = 1, oppositeTri[0] = 0;
	for(i = 2 ; i <= 1000010 ; i++)
	{	
		tempCount += i;
		preprocessingArr[i] = tempCount + preprocessingArr[i - 1];
		oppositeTri[i] = tempCount + oppositeTri[i - 2];
	}
}

int main()
{
	int i, n, testCases;
	ll triangleCount;

	scanf("%d", &testCases);

	preprocessing();
	while(testCases--)
	{
		scanf("%d", &n);

		triangleCount = preprocessingArr[n] + oppositeTri[n - 1];

		printf("%lld\n", triangleCount);
	}

	return 0;
}