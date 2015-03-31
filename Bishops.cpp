/*
328. Bishops

Problem code: BISHOPS

Yesterday was Sam's birthday. The most interesting gift was definitely the chessboard. Sam quickly learned the rules of chess and defeated his father, all his friends, his little sister, and now no one wants to play with him any more. 

So he decided to play with another birthday gift – a Book of Math Problems for Young Mathematicians. He opened the book somewhere in the middle and read the following problem: "How many knights can be placed on a chessboard without threatening each other?" After a while he realized that this was trivial and moved on to the next problem: "How many bishops can be placed on a chessboard without threatening each other?". Sam is in trouble here. He is not able to solve this problem and needs your help.

Sam's chessboard has size N x N. A bishop can move to any distance in any of the four diagonal directions. A bishop threatens another bishop if it can move to the other bishop's position. Your task is to compute the maximum number of bishops that can be placed on a chessboard in such a way that no two bishops threaten each other. 
Input

The input file consists of several lines. The line number i contains a single number N representing the size of the i-th chessboard. [N <= 10^100]

Output

The output file should contain the same number of lines as the input file. The i-th line should contain one number – the maximum number of bishops that can be placed on i-th chessboard without threatening each other.

Example

Input:
2
3

Output:
2
4
*/

#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	char num[110];
	int carry = 0, temp, len, i, j;

	while(cin >> num)
	{
		carry = 0;
		len = 1;

		for(i = 0 ; num[i] != '\0' ; i++){}

		len = i;

		if(len == 1 && num[0] == '1')
		{
			printf("1\n");
			continue;
		}
		else if(len == 1 && num[0] == '0')
		{
			printf("0\n");
			continue;
		}

		if(num[len - 1] >= '1')
			num[len - 1]--;
		else
		{
			for(i = len - 1 ; num[i] == '0' ; i--)
			{
				num[i] = '9';
			}
			num[i]--;
		}

		for(j = len - 1 ; j >= 0 ; j--)
		{
			temp = 2 * (num[j] - '0') + carry;
			if(temp > 9)
			{
				carry = 1;
				temp = temp - 10;
			}
			else
				carry = 0;

			switch(temp)
			{
				case 0 : num[j] = '0'; break;
				case 1 : num[j] = '1'; break;
				case 2 : num[j] = '2'; break;
				case 3 : num[j] = '3'; break;
				case 4 : num[j] = '4'; break;
				case 5 : num[j] = '5'; break;
				case 6 : num[j] = '6'; break;
				case 7 : num[j] = '7'; break;
				case 8 : num[j] = '8'; break;
				case 9 : num[j] = '9'; break;

			} 
		}

		if(carry == 1)
		{
			printf("1");
			printf("%s\n",num);
		}
		else
			printf("%s\n",num);

	}

	return 0;
}