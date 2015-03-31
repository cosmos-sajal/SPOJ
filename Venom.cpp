/*
18937. Touch of Venom

Problem code: VENOM

Sometimes you have to try fighting even though you know that your enemy is very powerful than you. Your hero with initial health H is about to fight against a venomous enemy who has a poisonous value of P. The enemy's poison deals i*P damage at it's ith attacking chance(i>=1). The hero dies when his health becomes <=0. After enemy's attack, if the hero survives, he heals himself with a health of A by using his skills. Then the enemy gets the chance again and the cycle continues till the hero dies. Find the survival time of the hero. You can safely assume that the hero is mortal.

Example Scenario:

Initial Health(H) = 10, Poison (P) = 2, Heal value(A) = 1

At time 1, enemy does 1*2 damage reducing the hero's health to 8

At time 2, hero heals himself by 1 increasing his health to 9

At time 3, enemy does 2*2 damage reducing the hero's health to 5

At time 4, hero heals himself by 1 increasing his health to 6

At time 5, enemy does 3*2 damage and kill the hero.

The hero survived 5 units of time.

Input:

The first line consists of an integer t, the number of test cases. For each test case there is a line with 3 integers H, P and A.

Output:

For each test case, find the survival time of the hero.

Input Constraints:

1<=t<=10^6

1<=H<=10^6

1<=P<=10^6

0<=A<P

Sample Input:

3

3 7 2

81 4 1

87 8 4

Sample Output:

1

13

9
*/

#include <stdio.h>
#include <math.h>
#define gc getchar_unlocked
#define ll long long

void scanint(int &x)
{
register int c = gc();
x = 0;
int neg = 0;
for(;((c<48 || c>57) && c != '-');c = gc());
if(c=='-') {neg=1;c=gc();}
for(;c>47 && c<58;c = gc()) {x = (x << 1) + (x << 3) + c - 48;}
if(neg) x=-x;
}

int main()
{
	ll testCases;
	double result, b, d;
	int h, p, a;

	scanf("%lld", &testCases);

	while(testCases--)
	{
		//scanf("%d %d %d", &h, &p, &a);
		scanint(h); scanint(p); scanint(a);
		
		if(h<=p)
        {
            printf("1\n");
            continue;
        }		
		b = (p - (2 * a));
		d = sqrt((b * b) + (8 * p * (h - a)));
		result = ((-1 * b) + d) / (2 * p);
		result = ceil(result);

		printf("%.0lf\n", result * 2 - 1);
	}

	return 0;
}