/*
19148. Kill them All

Problem code: INS14G

For his training, Digo is asked to solve the following challenge.

There is a mock terrorist situation. There are N terrorists and Digo is teamed up with his friend Sharry. They have to kill all the terrorists. Since this was too easy a task for this dynamic duo, Digo decided to have some fun with this challenge. At any given instant, Digo wants that the number of terrorists killed by him should be more than those killed by Sharry. The terrorists come in a fixed order. Any terrorist can be killed by either Digo or Sharry. Give the total number of ways in which the terrorists can be killed by them such that at every instant terrorists killed by Digo is more than the number of terrorists killed by Sharry. Give your answer modulo 10^9+7.

Input Format:-

The first line consists of a single integer T, denoting the number of test cases.
T lines follow each consisting of an integer N denoting the total number of terrorists.

Output Format:-

For each test case print the total number of possible ways modulo 10^9 + 7.

Constraints:-

1 <= t <= 100000
1 <= n <= 1000000

Sample Input:-

2
1
3

Sample Output:-

1
2
*/

#include <stdio.h>
#define MOD 1000000007

long long int arr[1000010] = {0};
long long int input[100010];
long long int max = -1;

void preprocessing(long long int a, long long int b, long long int c)
{
	if(c == 0)
		return;

	if(a == b || a == (b + 1))
	{
		arr[max - c + 1] = (arr[max - c + 1] + 1) % MOD;
		//printf("%lld %lld\n",arr[max - c + 1], max - c + 1);
		preprocessing(a + 1, b, c - 1);
	}
	else
	{
		arr[max - c + 1] = (arr[max - c + 1] + 2) % MOD;
		//printf("%lld %lld\n",arr[max - c + 1], max - c + 1);
		preprocessing(a + 1, b, c - 1);
		preprocessing(a, b + 1, c - 1);
	}
}

int main()
{
	long long int testCases, i;

	scanf("%lld",&testCases);

	for(i = 0 ; i < testCases ; i++)
	{
		scanf("%lld",&input[i]);
		if(max < input[i])
			max = input[i];
	}

	preprocessing(0, 0, max);

	for(i = 0 ; i < testCases ; i++)
		printf("%lld\n",arr[input[i]] % MOD);

	return 0;
}