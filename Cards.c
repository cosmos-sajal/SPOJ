/*
10509. Cards

Problem code: CRDS

Maricruz have a lot of cards, she always uses her cards to build pyramids as shown
in the following image:

A pyramid card of 3 leves.
She always wonder how many cards does she need to make a pyramid card of N
levels. Your task is to answer that question.
Input
The first line of the input contains an integer 1<= T <= 1,000. Each of the
following T lines will have an integer 1<= N <= 1,000,000.
Output
For each case, output a single line consisting of the number of cards needed to
build a pyramid card of level N modulo 1,000,007.


Input Example
2

3

7
Output Example
15
77

URL: http://www.spoj.com/problems/CRDS/
*/

#include <stdio.h>
#define PRIME_NO 1000007
#define ll long long

int main()
{
	int testCases;
	ll level, temp1, temp2; // temp1 will store the sum of 1s and temp2 will store the sum of 2s

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%lld", &level);

		temp1 = ((((level - 1) * (level))) / 2);
		temp2 = (level * (1 + level));

		printf("%lld\n", (temp1 + temp2) % 1000007);
	}

	return 0;
}
