/*
Codechef

Reach The Point
Problem code: RETPO

Recently Chef bought a bunch of robot-waiters. And now he needs to know how much to pay for the electricity that robots use for their work. All waiters serve food from the kitchen (which is in the point (0, 0)) and carry it to some table (which is in some point (x, y)) in a shortest way. But this is a beta version of robots and they can only do the next moves: turn right and make a step forward or turn left and make a step forward. Initially they look in direction of X-axis. Your task is to calculate for each query the number of moves they’ll do to reach corresponding table.
 
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows. For each test case there is a sing line containing two space-separated integers - x and y.
Output

For each test case, output a single line containing number of moves that robot will make to reach point (x, y)
Constraints

1 ≤ T ≤ 105
-109 ≤ x, y ≤ 109
 
Example

Input:
2
3 3
3 4

Output:
6
7
 
Explanation

Example case 1. Sequence of moves would be LRLRLR
*/

#include <stdio.h>
#define ll long long

int main()
{
	ll x, y, moves, diff, testCases;

	scanf("%lld", &testCases);

	while(testCases--)
	{
		scanf("%lld %lld", &x, &y);
		if(x < 0)
			x *= -1;
		if(y < 0)
			y *= -1;

		if(x == y)
			moves = x + y;
		else if(x > y)
		{
			moves = 2 * y;
			diff = x - y;
			if(diff % 2) // odd
				moves += (diff * 2 + 1);
			else		// even
				moves += (diff * 2);

		}
		else
		{
			moves = 2 * x;
			diff = y - x;
			if(diff == 1)
				moves++;
			else if(diff % 2) // odd
				moves += (diff * 2 - 1);
			else
				moves += (diff * 2);
		}
		printf("%lld\n", moves);
	}

	return 0;
}