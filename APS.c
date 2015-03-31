/*
13753. Amazing Prime Sequence

Problem code: APS

Bablu is very fond of Series and Sequences...

After studying Fibonacci Series in Class IX, he was impressed and he designed his own sequence as follows...

a[0] = a[1] = 0 

For n > 1, a[n] = a[n - 1] + f(n), where f(n) is smallest prime factor of n.

He is also very fond of programming and thus made a small program to find a[n], but since he is in Class IX, he is not very good at programming. So, he asks you for help. Your task is to find a[n] for the above sequence....

Input

Your code will be checked for multiple Test Cases.

First Line of Input contains T (<= 100), the number of Test Cases.

Next T lines contain a single number N. (1 < N < 10^7).

Output

Single line containing a[n] i.e. nth number of the sequence for each test case.

Example

Input:
3
2
3
4

Output:
2
5
7
*/

#include <stdio.h>

long long int f[10000010];
long long int a[10000010];

void preprocessing(long long int n)
{
	long long int i, j;

	for(i = 2 ; i <= n ; i += 2)
	{
		f[i] = 2;
	}

	for(i = 3 ; (i - 1) * (i - 1) <= n ; i += 2)
	{
		for(j = i ; j <= n ; j += i )
		{
			if(f[j] == 0)
				f[j] = i;
		}
	}
}

int main()
{
	int testCases;
	long long int input[110];
	long long int max = -1, i;

	scanf("%d",&testCases);

	for(i = 0 ; i < testCases ; i++)
	{
		scanf("%lld",&input[i]);
		if(max < input[i])
			max = input[i];
	}

	preprocessing(max);

	a[0] = a[1] = 0;
	f[0] = 0;
	f[1] = 1;

	for(i = 2 ; i <= max ; i++)
	{
		if(f[i] == 0)
			a[i] = a[i - 1] + i;
		else
			a[i] = a[i - 1] + f[i];
	} 

	for(i = 0 ; i < testCases ; i++)
		printf("%lld\n",a[input[i]]);

	return 0;
}