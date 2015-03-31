/*
10463. COUNT PAREN

Problem code: PAREN

You are given a boolean expression consisting of a string of the symbols 'true', 'false', 'and', 'or', and 'xor'. Count the number of ways to parenthesize the expression such that it will evaluate to true.

"and" "or" and "xor" are of the same priority.

Input

An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a space seperated string consisting of T,F,and,or and xor of length less than 100 characters

Output

For each string given at input, display a line with the number of ways to parenthesize the expression such that it will evaluate to true.

Example

 Sample input:

1
T and F 
 Sample output:

0
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ll long long

ll T[100][100], F[100][100];
char str[110], TFArr[100], oprArr[100];
ll TFArrLen, oprArrLen, totParenthesis = 0;

void init()
{
	int i, j;

	for(i = 1 ; i <= TFArrLen ; i++)
	{
		for(j = 1 ; j <= TFArrLen ; j++)
		{
			if(i == j)
				if(TFArr[i - 1] == 'T')
				{
					T[i][i] = 1;
					F[i][i] = 0;
				}
				else
				{
					T[i][i] = 0;
					F[i][i] = 1;	
				}
			else
				T[i][j] = -1;
		}
	}
	for(i = 0 ; i < TFArrLen - 1 ; i++)
	{
		if(oprArr[i] == 'o')
		{
			if(TFArr[i] == 'T' || TFArr[i + 1] == 'T')
			{
				T[i + 1][i + 2] = 1;
				F[i + 1][i + 2] = 0;
			}
			else
			{
				T[i + 1][i + 2] = 0;
				F[i + 1][i + 2] = 1;	
			}
		}
		else if(oprArr[i] == 'a')
		{
			if(TFArr[i] == 'T' && TFArr[i + 1] == 'T')
			{
				T[i + 1][i + 2] = 1;
				F[i + 1][i + 2] = 0;
			}
			else
			{
				T[i + 1][i + 2] = 0;
				F[i + 1][i + 2] = 1;	
			}
		}
		else
		{
			if((TFArr[i] == 'T'  && TFArr[i + 1] == 'F') || (TFArr[i] == 'F' && TFArr[i + 1] == 'T'))
			{
				T[i + 1][i + 2] = 1;
				F[i + 1][i + 2] = 0;
			}
			else
			{
				T[i + 1][i + 2] = 0;
				F[i + 1][i + 2] = 1;	
			}
		}
	}
}

void recFun(int start, int end)
{
	int k;

	for(k = start ; k <= end - 1 ; k++)
	{
		if(oprArr[k - 1] == 'o')
		{
			if(T[start][k] == -1)
				recFun(start, k);
			if(T[k + 1][end] == -1)
				recFun(k + 1, end);
			totParenthesis = totParenthesis + ((T[start][k] + F[start][k]) * (T[k + 1][end] + F[k + 1][end])) - (F[start][k] * F[k + 1][end]);
			T[start][end] = ((T[start][k] + F[start][k]) * (T[k + 1][end] + F[k + 1][end])) - (F[start][k] * F[k + 1][end]);
			F[start][end] = (F[start][k] * F[k + 1][end]);
		}
		else if(oprArr[k - 1] == 'a')
		{
			if(T[start][k] == -1)
				recFun(start, k);
			if(T[k + 1][end] == -1)
				recFun(k + 1, end);
			totParenthesis = totParenthesis + (T[start][k] * T[k + 1][end]);
			T[start][end] = (T[start][k] * T[k + 1][end]);
			F[start][end] = ((T[start][k] + F[start][k]) * (T[k + 1][end] * F[k + 1][end])) - (T[start][k] * T[k + 1][end]);
		}
		else if(oprArr[k - 1] == 'x')
		{
			if(T[start][k] == -1)
				recFun(start, k);
			if(T[k + 1][end] == -1)
				recFun(k + 1, end);
			totParenthesis = totParenthesis + (T[start][k] * F[k + 1][end]) + (F[start][k] * T[k + 1][end]);
			T[start][end] = (T[start][k] * F[k + 1][end]) + (F[start][k] * T[k + 1][end]);
			F[start][end] = (T[start][k] * T[k + 1][end]) + (F[start][k] * F[k + 1][end]);
		}
	}
}

int main()
{
	int  i, j, l, strLen, testCases;
	
	scanf("%d", &testCases);
	getc(stdin);

	while(testCases--)
	{
		gets(str);

		strLen = strlen(str);
		totParenthesis = 0;
		for(i = 0, j = 0, l = 0 ; i < strLen ;)
		{
			if(str[i] == 'T' || str[i] == 'F')
			{
				TFArr[j++] = str[i];
				i += 2;
			}
			else if(str[i] == 'a')
			{
				oprArr[l++] = 'a';
				i += 4;
			}
			else if(str[i] == 'o')
			{
				oprArr[l++] = 'o';
				i += 3;	
			}
			else if(str[i] == 'x')
			{
				oprArr[l++] = 'x';
				i += 4;	
			}
			else
				i++;
		}
		TFArrLen = j;
		oprArrLen = l;
		init();
		recFun(1, TFArrLen);

		printf("%lld\n", totParenthesis);
	}

	return 0;
}