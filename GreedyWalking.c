/*
15433. Greedy Walking

Problem code: UCV2013E

Reginald is an N-dimensional traveler who wants to return to Filipistonia's Kingdom. He has an Obsessive-compulsive disorder in the way he travels so he can only do it following particular rules:

Every step is exactly one unit long.
He only moves in one dimension at a time.
He only travels along the positive direction for each dimension.
For example, when traveling on a two-dimensional place. He can travel along either the X or the Y axis at any given time, but never on both at the same time. Moreover, since he only travels along the positive direction and every step is one unit long, his only possible moves are (+1, 0) and (0, +1).

As you can see, he is a Greedy Walker: once he makes a decision he assumes it is the correct and he never goes back.


Given a starting position in an N-dimensional space (x1i, x2i, ... ,xni) your task is to count the number of different travels he can make to position (x1f, x2f, ... , xnf) modulo 1000000007.

Input

The input contains several test cases, each one corresponding to a single travel. Each test case consists of a single line with one integer (1 <= N <=  50) followed by two lines each one with N integers, first line will be initial position and second line will be target position.


You can assume that 0 <= xki <= x1f <= 500 for all k, 1 <= k <= N and Sum(xki-xkf) <= 500.

The end of input is indicated by a test case with N = 0.

Output

For each travel output a single line with one integer, the number of different travels that exist from the initial position to the final position modulo 1000000007.

Example

Input:
2
2 1
5 5
4
0 0 0 0
1 2 3 4
5
1 2 3 4 5
8 5 6 4 8
5
0 0 0 0 0
100 100 100 100 100
0

Output:
35
12600
19219200
257055440
*/

#include <stdio.h>
#define ull unsigned long long
#define MOD 1000000007

int GCD(int a, int b)
{
    if (b==0)
        return a;
    else
        return GCD(b,a%b);
}


int main()
{
	 		// size of factorial array is determined by the fact that max difference between start point and end point can be
																								// 500(lets take 501 to be on a safe side), and the max no. of dimensions can be 50, so the total sum will not
																								// exceed 501 * 50 = 25050
	ull sum, result, startPoint[510], endPoint[510], factorial[25050], denominator[51], i, j , k, d, n, gcd;

	while(1)
	{
		scanf("%lld", &n);

		if(!n)
			break;
		for(i = 0 ; i < n ; i++)
			scanf("%lld", &startPoint[i]);
		for(i = 0 ; i < n ; i++)
			scanf("%lld", &endPoint[i]);
		sum = 0;
		for(i = 0 ; i < n ; i++)
		{
			denominator[i] = endPoint[i] - startPoint[i];
			sum += denominator[i];
		}
		for(i = 0 ; i <= sum ; i++)
			factorial[i] = i;
		for(i = 0 ; i < n ; i++)
		{
			for(j = 2 ; j <= denominator[i] ; j++)
			{
				d = j;
				for(k = 2 ; k <= sum ; k++)
				{
					gcd = GCD(d, factorial[k]);
					factorial[k] /= gcd;
					d /= gcd;
					if(d == 1)
						break;
					/*
					if(factorial[k] % d == 0)
					{
						factorial[k] /= d;
						break;
					}
					else if(d % factorial[k] == 0)
					{
						d /= factorial[k];
						factorial[k] = 1;
					}
					*/
				}
			}
		}
		result = 1;
		for(i = 2 ; i <= sum ; i++)
			result = (result % MOD * factorial[i] % MOD) % MOD;

		printf("%lld\n", result);
	}

	return 0;
}