/*
20047. Subsequence Problem

Problem code: SUBP

Given a string S which contains only digit-characters. How many subsequences(P) can be obtained from S such that every digit is strictly greater than all previous digits in that subsequence.

As for example if S=7598 then there are 8 subsequences which follow the above constraint. These are 7,5,9,8,79,78,59,58. Notice that 7598 is not a required subsequence because 7>5 and 9>8.

Note: A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.

 

Input

Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case contains a string S. The length of S does not exceed 100. S does not contain any leading zeros.

Output

For each case, print the case number and P.

Sample Input

Output for Sample Input

2

4

7598

Case 1: 1
Case 2: 8

 Problem Setter: Md Abdul Alim,Dept. of CSE,BUBT
*/

#include <stdio.h>
#define ll long long

char str[10010];
unsigned ll dp[10010];

int main()
{
	int testCases, i, j, k;
	unsigned ll result;

	scanf("%d", &testCases);

	for(k = 1 ; k <= testCases ; k++)
	{
		scanf("%s", str);

		for(i = 0 ; str[i] != '\0' ; i++)
		{
			dp[i] = 1;
			for(j = 0 ; j < i ; j++)
			{
				if(str[j] < str[i])
					dp[i] += dp[j];
			}
		}
		result = 0;
		for(i = 0 ; str[i] != '\0' ; i++)
			result += dp[i];

		printf("Case %d: %lld\n", k, result);
	}

	return 0;
}