/*
15555. Check the coprimeness

Problem code: IITKWPCB

Find largest non-negative number less than or equal to floor (N/2) which is coprime to N.

    Two number a and b are considered to coprime if gcd (a, b) = 1.

Input

    T : numbr of test  cases (T <= 1000)

    For next T lines, every line contains n >= 1 && n <= 10^12;

Output

    For each test case, output as described in the problem statement.

Example

Input:
4
3
4
5
100 

Output:
1
1
2
49

*/

#include <stdio.h>

unsigned long long int gcd(unsigned long long int a, unsigned long long int b)
{
	unsigned long long int r;
	while(b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

unsigned long long int findGCD(unsigned long long int a, unsigned long long int b)
{
	unsigned long long int i, retVal;

	for(i = b; i >= 1 ; i--)
	{
		retVal = gcd(a, i);
		if(retVal == 1)
			return i;
	}

	return 1;
}


int main()
{
	int testCases;
	unsigned long long int num, result;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%lld", &num);
		result = findGCD(num, num / 2);
		printf("%lld\n", result);

	}

	return 0;
}