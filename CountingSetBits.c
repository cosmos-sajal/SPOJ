/*
counting the set bits in an integer
*/


#include <stdio.h>

int countSetBits(int num)
{
	int count = 0;

	while(num)
	{
		count += num & 1;
		num >>= 1;
	}

	return count;
}

int main()
{
	int num, testCases;

	scanf("%d", &testCases);

	while(testCases--)
	{
		scanf("%d", &num);
		printf("%d\n", countSetBits(num));
	}

	return 0;
}