/*
15208. Minimum Cost

Problem code: MC

Problem Statement :

Given two string S and T. you can delete a character  from  S  with  cost 15 and  a Character T with cost 30. Your goal is to make the string equal (same). It is not mandatory  to delete  character .

For example :  S = a5b and  T = 2ab . Now , if we delete X from S and Y from T, then total cost  =  15+30 = 45.  And  S and T will become ab.

Another example : S = ab , T = cd , Now  total cost = 15  + 15 + 30 + 30 = 90.

Another example : S = abcd , T = acdb , Now  total cost = 15 + 30 = 45.

Input:

Input consists of pairs of lines. The first line of a pair contains the first string S and the second line contains the second string T. Each string is on a separate line and consists of at most 1,000 characters . The end of input occurs when the first sequence starts with an "#"character (without the quotes).

Output:

For each subsequent pair of input lines, output a line containing one integer number which  the minimum cost to make the string equal (same).

 

Sample Input/Output:

 

Sample Input

Sample Output

 axb

 yab

 ab

 cd

 ko

 p

 abcd

 acdb

 # 

 45

 90

 60

 45


*/

#include <stdio.h>
#include <string.h>
#define ll long long

char str1[1010], str2[1010];
int DP[2][1010];

void LCS(int len1, int len2)
{
	int i, j;

	for(i = 0 ; i <= len2 ; i++)
		DP[0][i] = 0;
	DP[1][0] = 0;
	for(i = 1 ; i <= len1 ; i++)
	{
		if(i % 2) //odd
		{
			for(j = 1 ; j <= len2 ; j++)
			{
				if(str1[i - 1] == str2[j - 1])
					DP[1][j] = DP[0][j - 1] + 1;
				else if(DP[0][j] >= DP[1][j - 1])
					DP[1][j] = DP[0][j];
				else
					DP[1][j] = DP[1][j - 1];
			}
		}
		else //even
		{
			for(j = 1 ; j <= len2 ; j++)
			{
				if(str1[i - 1] == str2[j - 1])
					DP[0][j] = DP[1][j - 1] + 1;
				else if(DP[1][j] >= DP[0][j - 1])
					DP[0][j] = DP[1][j];
				else
					DP[0][j] = DP[0][j - 1];
			}
		}
	}
}

int main()
{
	int len1, len2;
	ll cost;

	while(1)
	{
		gets(str1);

		if(str1[0] == '#')
			break;
		gets(str2);

		len1 = strlen(str1);
		len2 = strlen(str2);
		LCS(len1, len2);
		if(len1 % 2) //odd
			cost = (len1 - DP[1][len2]) * 15 + (len2 - DP[1][len2]) * 30;
		else //even
			cost = (len1 - DP[0][len2]) * 15 + (len2 - DP[0][len2]) * 30;
		printf("%lld\n", cost);
	}

	return 0;
}