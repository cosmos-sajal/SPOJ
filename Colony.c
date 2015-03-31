/*
16554. Linearian Colony

Problem code: COLONY

Description

Linearians are pecurliar creatures. They are odd in several ways:
Every Linearian is either red or blue.
A Linearian colony is a straight line, aligned N-S with the magentic field.
A colony starts with single red Linearian.
Every year, each Linearian produces an offspring of the opposite color. After birth, the parent moves just south of the offspring. (Since everyone is born at once, this does make for a lot of jostling, but everyone stays in order.)
So a colony grows as follows:
N ----------- S

Year 0: R
Year 1: BR
Year 2: RBBR
Year 3: BRRBRBBR
Year 4: RBBRBRRBBRRBRBBR
Given a year and a position along the N-S axis, determine what the color of the Linearian there will be.
Input

The first line is the year Y (0 <= Y <= 51). The second line is the position P from north to south, 0-indexed (0 <= P < 2^Y).
Ouput

The color of the Linearian, either red or blue.
Input	Input
3
6
51
123456789012345
Output	Output
blue
red

*/

#include <stdio.h>
#define ll long long

int main()
{
	int year;
	ll n, numOf1s;

	scanf("%d %lld", &year, &n);

	numOf1s = 0;
	while(n >= 1)
	{
		if(n % 2 != 0)
			numOf1s++;
		n /= 2;
	}
	//printf("numOf1s = %lld\n", numOf1s);
	if(year % 2)
	{
		if(numOf1s % 2)
			printf("red\n");
		else
			printf("blue\n");
	}
	else
	{
		if(numOf1s % 2)
			printf("blue\n");
		else
			printf("red\n");
	}

	return 0;
}