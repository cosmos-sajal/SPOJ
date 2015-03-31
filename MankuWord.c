/*
13381. Manku Word

Problem code: MAY99_2

Manku loves Codechef's Lucky Number and now he decided to start Manku words :)

Manku words are those words which have only letters 'm','a','n','k','u'.

Generally in english ,
a comes before k, k comes before m and so on but in Manku's dictionary 'm' comes before 'a' , 'a' comes before 'n' , 'n' comes before 'k' , 'k' comes before 'u'.

Thus according to manku

1st manku word is m
2nd manku word is a
3rd manku word is n
4th manku word is k
5th manku word is u
6th manku word is mm
7th manku word is ma
   
and so on ...       


Your task is very simple
For given value of n , write the nth manku word

1<=n<=10^18

Input


First line of input contains an integer t (1<=t<=100)

Each test case contains an integer n

Output

For every test case print the nth manku word on separate line

Example

Input:

5
10
4
16
17
31

Output:

mu
k
nm
na
mmm
*/

#include <stdio.h>
#define ll long long

int main()
{
	int testCases;
	ll n, i, len, modVal;
	char map[6] = {'u', 'm', 'a', 'n', 'k'};
	char str[10000];

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%lld", &n);

		len = 0;
		while(n > 0)
		{
			modVal = n % 5;
			if(modVal == 0)
				n--;
			str[len++] = map[modVal];
			n /= 5;
		}

		for(i = len - 1 ; i >= 0 ; i--)
			printf("%c", str[i]);
		printf("\n");
	}

	return 0;
}