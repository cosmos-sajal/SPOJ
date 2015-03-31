/*
11458. Ninja

Problem code: VUDBOL5

A ninja is practicing and he is very fast he can make two cuts in one second and his master give he a new challenge. The master take a cube, thrown through the air and quickly says four numbers. The ninja has to think fast to make two cuts and get desired values.

Given a cube of size N*N*N, he need to cut it into four entire pieces of size A, B, C and D. He needs to divide the cube in these pieces with only two cuts, one vertical and one horizontal.

Input

The input consists in multiple test cases.
Each test case begins a line containing five integers N (2 <= N <= 1000000), A, B, C y D (1 <= A, B, C, D <= 2^63).
The end of input is indicated by a line with five zeros. This is not a part of any test cases.
Output

For each test case print "Possible" if it is possible to obtain the pieces and print "Impossible" if it is not possible to obtain the pieces with two cuts.

Example

Input:
2 5 1 1 1
2 2 2 2 2
3 12 3 6 6
0 0 0 0 0

Output:
Impossible
Possible
Possible
*/

#include <stdio.h>
#include <math.h>
#define ull unsigned long long

int main()
{
	ull n, a, b, c, d, vol1, area, vol;
	double x, y1, y2;

	while(1)
	{
		scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &c, &d);

		if(!n && !a && !b && !c && !d)
			break;

		area = n * n;
		vol = area * n;
		
		if(vol != (a + b + c +d))
		{
			printf("Impossible\n");
			continue;
		}

		vol1 = a + b;	// a, b are above the horizontal cut, c,d are below the horizontal cut
		x = (double)vol1 / (double)area;
		if(x == floor(x))
		{
			y1 = (double)a / (double)(n * x); // now the vertical cut of a, b
			if(y1 == floor(y1))
			{
				y2 = (double)c / (double)(n * (n - x));
				if(y2 == floor(y2) && ((y1 == y2) || (y1 == (n - y2))))
				{
					printf("Possible\n");
					continue;
				}
			}
		}
		vol1 = a + c;
		x = (double)vol1 / (double)area;
		if(x == floor(x))
		{
			y1 = (double)a / (double)(n * x);
			if(y1 == floor(y1))
			{
				y2 = (double)b / (double)(n *(n - x));
				if(y2 == floor(y2) && ((y1 == y2) || (y1 == (n - y2))))
				{
					printf("Possible\n");
					continue;
				}	
			}
		}
		vol1 = a + d;
		x = (double)vol1 / (double)area;
		if(x == floor(x))
		{
			y1 = (double)a / (double)(n * x);
			if(y1 == floor(y1))
			{
				y2 = (double)b / (double)(n *(n - x));
				if(y2 == floor(y2) && ((y1 == y2) || (y1 == (n - y2))))
				{
					printf("Possible\n");
					continue;
				}	
			}
		}
		printf("Impossible\n");
	}

	return 0;
}