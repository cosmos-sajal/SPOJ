/*
4942. Integer Factorization (15 digits)

Problem code: FACT0

This is a problem to test the robustness of your Integer Factorization algorithm.

Given some integers, you need to factor them into product of prime numbers.

The largest integer given in the input file has 15 digits. FACT1 is a harder version of this problem (the numbers are larger).

You may need to use a general factorization algorithm since no special numbers (e.g. Fermat numbers) are considered when designing the input data.

Input

There are several numbers given, each one in a line.

The input ends with a number 0.

The number of test cases is about 10.

Output

For each number, print in a line the factorization of it. See examples below for the output format.

Example

Input:
3111989
13091989
77145199750673
0

Output:
317^1 9817^1
17^2 89^1 509^1
328439^1 234884407^1
*/

#include <stdio.h>
#include <math.h>
#define ll long long

int main()
{
	ll i, p, num, temp;

	while(1)
	{
		scanf("%lld", &num);

		if(!num)
			break;
		temp = num;
		p = 0;
		if(num % 2 == 0)
		{
			while(num % 2 == 0)
			{
				p++;
				num /= 2;
			}
			printf("2^%lld ", p);
		}

		for(i = 3 ; i * i <= temp && num != 1 ; i += 2)
		{
			if(num % i == 0)
			{
				p = 0;
				while(num % i == 0)
				{
					p++;
					num /= i;
				}
				printf("%lld^%lld ", i, p);
			}
				
		}
		if(num > 1)
			printf("%lld^1", num);
		printf("\n");
	}

	return 0;
}