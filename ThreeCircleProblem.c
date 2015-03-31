/*
SPOJ Problem Set (classical)
14441. Three Circle Problem (EASY)
Problem code: CIRCLE_E

Given 3 distinct circles with positive integer radius R1, R2, and R3, and arranged like in the picture below:

Three Circle Problem

Now, your task is to compute radius of small circle that can be created like yellow circle in the picture above. All circles in the picture above tangent each other.
Input

The first line in the input data, there is an integer T(0 < T ≤ 103) denoting number of test cases, than T lines follow.

For each lines, there are three integer R1, R2, and R3, (0 < {R1,R2,R3} < 109) denoting radius of each circle like in the picture above.
Output

For each test case, output radius of small circle that can be made, like in the picture above. Any output with absolute error less than 10-6 is accepted.
Example

Input:

3

1 1 1

10 10 10

23 46 69

Output:

0.154701

1.547005

6.000000
*/

#include <stdio.h>
#include <math.h>

int main()
{
	int testCases;

	long long int r1,r2,r3;

	double r4;

	scanf("%d",&testCases);

	while( testCases-- )
	{
		scanf("%lld %lld %lld",&r1,&r2,&r3);

		r4 = (r1*r2*r3) / ( r1*r2 + r2*r3 + r1*r3 + 2*sqrt( r1*r2*r3*( r1 + r2 + r3 ) ) );

		printf("%.6f\n",r4);

	}

	return 0;
}