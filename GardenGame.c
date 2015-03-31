/*
Codechef

Garden Game

All bandits are afraid of Sheriff. Sheriff constantly fights crime, but when bandits lay low, he is getting bored and starts to entertain himself.
This time Sheriff gathered all the bandits in his garden and ordered them to line up. After the whistle all bandits should change the order in which they stand.
Sheriff gave all the bandits numbers from 1 to N. For each place i he determined the unique position j. After whistling the bandit staying on position i should run to the j-th position. Sheriff loved seeing how the bandits move around, and he continued whistling until the evening. He finished the game only when he noticed that the bandits are in the same order in which they were standing originally.
Now the Sheriff asks the question: How many times has he whistled?
 
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the number of bandits. The second line contains N space-separated integers A1, A2, ..., AN denoting that the bandit staying on position i should run to the Ai-th position after the whistle.
 
Output

For each test case, output a single line containing number of times the sheriff had to whistle, print it modulo 10^9 + 7.
 
Constraints

1 ≤ T ≤ 5
1 ≤ N ≤ 100000
All Ai are distinct numbers from 1 to N
 
Example

 

Input:

2
3
1 2 3
5
2 3 1 5 4

Output:

1
6

 
Explanation

 

Example case 2.
the bandits positions are:
0. 1 2 3 4 5
1. 3 1 2 5 4
2. 2 3 1 4 5
3. 1 2 3 5 4
4. 3 1 2 4 5
5. 2 3 1 5 4
6. 1 2 3 4 5.
*/

#include <stdio.h>
#define MOD 1000000007
#define ll long long

ll LCM(ll a, ll b)
{
	ll r, lcm = (a * b) % MOD;
	while(b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	lcm /= a;

	return lcm;
}

int main()
{
	ll i, j, n, moves, testCases, arr[100010];
	ll movesArr[100010], lcm;

	scanf("%lld", &testCases);

	while(testCases--)
	{
		scanf("%lld", &n);
		for(i = 1 ; i <= n ; i++)
		{
			scanf("%lld", &arr[i]);
			movesArr[i] = 0;
		}

		if(n == 1)
		{
			printf("1\n");
			continue;
		}

		for(i = 1 ; i <= n ; i++)
		{
			moves = 1;
			j = arr[i];
			while(j != i)
			{
				j = arr[j];
				moves = (moves + 1) % MOD;
			}
			movesArr[i] = moves;
		}

		for(i = 1 ; i <= n ; i++)
			printf("%lld ", movesArr[i]);
		printf("\n");

		lcm = LCM(movesArr[1], movesArr[2]);
		for(i = 3 ; i <= n ; i++)
			lcm = LCM(lcm, movesArr[i]);

		printf("%lld\n", lcm);
	}

	return 0;
}
