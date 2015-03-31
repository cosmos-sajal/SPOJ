/*
18243. Maggu and Strings

Problem code: IITWPC4A

Maggu and Coder were playing a game with strings. In each turn of the game, Maggu gives Coder a string. Coder can replace m consecutive 'a' in the string by n consecutive 'b' any number of times. This way he has to create 2 strings, one of maximum possible length and one of minimum possible length.

Maggu and Coder were playing a game with strings. In each turn of the game, Maggu gives Coder a string. Coder can replace m consecutive 'a' in the string by n consecutive 'b' any number of times. This way he has to create 2 strings, one of maximum possible length and one of mimimum possible length.   
 

Input

First line of input contains a single integer T : number of test cases.(1<=T<=100).
For each test case there are exactly two lines.
First line contains a string s (1 <= length(s) <= 10^5) containing letters only from 'a' to 'z'.
Second line contains two space separated integers representing m and n respectively.(1 <= m,n <= 10^5).
Sum of length(s) over all test cases is <= 10^6. 

Output

For each test case, print in a single line containing two space separated integers representing minimum and maximum length of string s that Coder can obtain.

Example

Input:
3
abc
1 2
aa
1 2
aba
1 1

Output:
3 4
2 4
3 3
Explanation

For the first test case, you can convert abc to abc (by not changing at all), bbbc (changing 'a' to 'bb'). minimum length of s is 3 and maxium length is 4.
*/

#include <stdio.h>
#include <string.h>

long long int returnLen(char * str, long long int len, long long int m, long long int n)
{
	long long int returnVal = len;
	long long int counter = 0, i, flag = 0;

	for(i = 0 ; i < len ; i++)
	{
		if(flag && str[i] != 'a')
		{
			if(counter < m)
			{
				flag = 0;
				counter = 0;
				continue;
			}
		}

		if(flag)
			counter++;

		if(flag && counter == m)
		{
			flag = 0;
			counter = 0;
			returnVal = returnVal - m + n;
			continue;
		}

		if(!flag && str[i] == 'a')
		{
			flag = 1;
			counter = 1;

			if(m == 1)
			{
				flag = 0;
				counter = 0;
				returnVal = returnVal - m + n;
			}
		}

	}

	return returnVal;
}

int main()
{
	int testCases;
	long long int m, n;
	char str[100010];
	long long int minLen, maxLen, strlength;

	scanf("%d",&testCases);

	while(testCases--)
	{
		scanf("%s",str);
		scanf("%lld %lld", &m, &n);

		strlength = strlen(str);

		if(m < n)
		{
			minLen = strlength;
			maxLen = returnLen(str, strlength, m, n);
		}
		else if(m > n)
		{
			minLen = returnLen(str, strlength, m, n);
			maxLen = strlength;
		}
		else
		{
			minLen = maxLen = strlength;
		}

		printf("%lld %lld\n",minLen,maxLen);


	}

	return 0;
}