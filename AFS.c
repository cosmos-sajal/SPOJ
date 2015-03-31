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
long long int f[1000010] = {0};

long long int power(long long int x, long long int n) 
{
	long long int power = (n > 0) ? n : -1 * n;
	long long int result = 1;
	long long int base = x;

	while(power > 0)
	{
		if(1 == power % 2)
		{
			if(n > 0)
				result *= base;
			else
				result /= base;
		}
		
		base = base * base;
		power /= 2;
	}

	return result;
}

long long int sumOfFactors(long long int n)
{
	long long int num = n;
	long long int factorsSum = 1, tempFactors = 0;
	long long int i;
	int flag = 0;

	if(n % 2 == 0)
	{
		if((n / 2) % 2 == 0)
		{
			if(f[n/2] != 0)
			{
				f[n] = f[n/2] + n/2;
				return f[n];
			}
		}
		else
		{
			if(f[n/2] != 0)
			{
				f[n] = f[n/2] + n/2 + 2;
				return f[n];
			}	
		}
	}

	while(n % 2 == 0)
	{
		flag = 1;
		n /= 2;
		tempFactors++;
	}

	if(flag)
	{
		tempFactors++;
		factorsSum *= (power(2,tempFactors) - 1);
	}

	for(i = 3 ; i * i <= n ; i += 2)
	{
		flag = 0;
		tempFactors = 0;
		
		while(n % i == 0)
		{
			flag = 1;
			n /= i;
			tempFactors++;
		}

		if(flag)
		{
			tempFactors++;
			factorsSum *= ((power(i,tempFactors) - 1)/(i - 1));
		}
	}

	if(n > 2)
	{
		if(!flag)
			factorsSum = 1;
		else
		{
			factorsSum *= ((power(n,2) - 1)/(n - 1));
			factorsSum -= num;
		}

	}
	else
		factorsSum -= num;

	f[num] = factorsSum;

	return factorsSum;

}

int main()
{
	int testCases;
	long long int i, factors; 
	long long int input[110];
	long long int max = -1;

	scanf("%d",&testCases);

	for(i = 0 ; i < testCases ; i++)
	{
		scanf("%lld",&input[i]);
		if(max < input[i])
			max = input[i];
	}

	a[0] = a[1] = 0;
	f[0] = f[1] = 0;

	for(i = 2 ; i <= max ; i++)
	{
		factors = sumOfFactors(i);

		a[i] = a[i-1] + factors;

		printf("%lld\t",factors );
	}


	for(i = 0 ; i < testCases ; i++)
		printf("%lld %lld\n",a[input[i]],f[input[i]]);

	return 0;
}