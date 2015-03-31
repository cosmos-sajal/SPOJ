#include <stdio.h>
#define ll long long

ll max(ll a, ll b)
{
	ll max = a >= b ? a : b;
	return max;
}

ll min(ll a, ll b)
{
	ll min = a <= b ? a : b;
	return min;
}

ll GCD(ll a, ll b)
{
	ll i, maximum, minimum;

	maximum = max(a, b);
	minimum = min(a, b);

	for(i = minimum / 2 ; i > 1 ; i--)
		if(!(maximum % i))
			break;

	return i;
}

int main()
{
	int testCases;
	ll x, y, z, gcd;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%lld %lld %lld", &x, &y, &z);

		if(z > x && z > y)
			printf("NO\n");
		else
		{
			gcd = GCD(x, y);
			if(z % gcd)
				printf("NO\n");
			else
				printf("YES\n");
		}

	}

	return 0;
}