/*
14138. Amazing Factor Sequence

Problem code: AFS

Bhelu is the classmate of Bablu who made the Amazing Prime Sequence .

He felt jealous of his classmate and decides to make his own sequence. Since he was not very imaginative, he came up with almost the same definition just making a difference in f(n):

a[0] = a[1] = 0;

For n > 1, a[n] = a[n - 1] + f(n), where f(n) is the sum of natural numbers in the following set S.

S = {x | x < n and n % x = 0}

Now, Bablu asked him to make a code to find f(n) as he already had the code of his sequence. So, Bhelu asks for your help since he doesn't know Programming. Your task is very simple, just find a[n] for a given value of n(< 10^6).

Input

Your code will be checked for multiple Test Cases.

First Line of Input contains T (<= 100), the number of Test Cases.

Next T lines contain a single number N. (1 < N < 10^6).

Output

Single line containing a[n] i.e. nth number of the sequence for each test case.

Example

Input:
3
3
4
5
Output:
2
5
6
Explanation:
f(2) = 1 {1}
f(3) = 1 {1}
f(4) = 3 {1, 2}
f(5) = 1 {1}
*/


#include <stdio.h>

long long int a[1000010];
long long int f[1000010];

void preprocessing(long long int n)
{
	long long int i, j;

	for(i = 4 ; i <= n ; i += 2)
	{
		f[i] = 2;
	}

	for(i = 3 ; i <= n / 2 ; i++)
	{
		for(j = 2 * i ; j <= n ; j += i )
		{
			if(f[j] == 0)
				f[j] = i;
			else
				f[j] += i;
		}
	}
}

int main()
{
	int testCases;
	long long int i, max = -1;
	long long int input[110];

	scanf("%d",&testCases);

	for(i = 0 ; i < testCases ; i++)
	{
		scanf("%lld",&input[i]);
		if(input[i] > max)
			max = input[i];
	}

	preprocessing(max);

	a[0] = a[1] = 0;
	f[0] = f[1] = 0;

	for(i = 2 ; i <= max ; i++)
	{
		f[i]++;
		a[i] = a[i - 1] + f[i];

		printf("%lld\t",f[i]);
	}

	for(i = 0 ; i < testCases ; i++)
		printf("%lld\n",a[input[i]]);

	return 0;

}